// taskM
// Цивилизация

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <set>
#include <map>


using namespace std;

pair<int, int> path;

struct cell
{
    int id;
    int time;
};

bool operator< (const cell& cell1, const cell& cell2) { return cell1.time > cell2.time; }


int main()
{
    ifstream fin;
    int n; // число строк в карте
    int m; // число столбцов
    int x, y; // координаты начального положения
    int xn, yn; // координаты конечного положения
    map<int, int> segments;
    fin.open("input.txt");
    fin >> n >> m >> x >> y >> xn >> yn;
    string* input_map = new string[n];
    for (int i = 0; i < n; ++i)
        fin >> input_map[i];
    fin.close();
    int start_index = y + (x - 1) * m - 1;
    int end_index = yn + (xn - 1) * m - 1;

    // id, время
    priority_queue<cell> queue;
    cell* visited_cells = new cell[n*m];
    queue.push({start_index, 0});
    for (int i = 0; i < n * m; ++i)
        visited_cells[i] = {-1,-1};

    while (!queue.empty())
    {
        cell cur_pair = queue.top();
        queue.pop();
        if (cur_pair.id == end_index) break;

        int x_in_input_map = cur_pair.id / m;
        int y_in_input_map = cur_pair.id % m;
        multiset<cell> pairs_to_check;
        

        if (input_map[x_in_input_map][y_in_input_map] == '#')
            continue;
        if ((x_in_input_map > 0) && (input_map[x_in_input_map - 1][y_in_input_map] != '#'))
        {
            int time = 1;
            if (input_map[x_in_input_map - 1][y_in_input_map] == 'W')
                time = 2;
            pairs_to_check.insert({ cur_pair.id - m, time });
        }
        if ((y_in_input_map > 0) && (input_map[x_in_input_map][y_in_input_map-1] != '#'))
        {
            int time = 1;
            if (input_map[x_in_input_map][y_in_input_map-1] == 'W')
                time = 2;
            pairs_to_check.insert({ cur_pair.id - 1, time });
        }
        if ((x_in_input_map + 1 < n) && (input_map[x_in_input_map + 1][y_in_input_map] != '#'))
        {
            int time = 1;
            if (input_map[x_in_input_map + 1][y_in_input_map] == 'W')
                time = 2;
            pairs_to_check.insert({ cur_pair.id + m, time });
        }
        if ((y_in_input_map + 1 < m) && (input_map[x_in_input_map][y_in_input_map + 1] != '#'))
        {
            int time = 1;
            if (input_map[x_in_input_map][y_in_input_map + 1] == 'W')
                time = 2;
            pairs_to_check.insert({ cur_pair.id + 1, time });
        }

        for (cell next_cell : pairs_to_check)
        {
            int new_time = next_cell.time + cur_pair.time;
            int next_cell_id = next_cell.id;
            if ( (visited_cells[next_cell_id].time > new_time) || (visited_cells[next_cell_id].time == -1))
            {
                visited_cells[next_cell_id].time = new_time;
                visited_cells[next_cell_id].id = cur_pair.id;
                queue.push({ next_cell_id, new_time });
            }

        }

    }
    int answer = visited_cells[end_index].time;
    cout << answer;
    if (answer != -1)
    {
        list<char> path;
        int cur_index = end_index;
        while (cur_index!= start_index)
        {
            int diff = cur_index - visited_cells[cur_index].id;
            if (diff == -m)
                path.push_front('N');
            if (diff == m)
                path.push_front('S');
            if (diff == 1)
                path.push_front('E');
            if (diff == -1)
                path.push_front('W');

            cur_index = visited_cells[cur_index].id;
        }
       
        cout << endl;
        for (char dir : path) 
            cout << dir;
    }
}


/*
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <list>
using namespace std;

struct vertex {
    int cost;
    int id;
};
bool operator< (const vertex& v1, const vertex& v2) { return v1.cost > v2.cost; }

int main() {
    ifstream fin;
    fin.open("input.txt");
    int N, M, start_x, start_y, goal_x, goal_y;
    fin >> N >> M >> start_x >> start_y >> goal_x >> goal_y;
    int size = N * M;
    string* grid = new string[N];
    for (int i = 0; i < N; i++) fin >> grid[i];

    int start = (start_x - 1) * M + (start_y - 1);
    int goal = (goal_x - 1) * M + (goal_y - 1);
    priority_queue<vertex> queue;
    queue.push({ 0, start });
    vertex* visited = new vertex[size];
    for (int i = 0; i < size; i++) visited[i] = { -1, -1 };

    while (!queue.empty()) {
        auto curr = queue.top();
        queue.pop();
        if (curr.id == goal) break;

        multiset<vertex> vertices;
        int x = curr.id / M;
        int y = curr.id % M;
        if (grid[x][y] == '#') continue;
        if (y + 1 < M && grid[x][y + 1] != '#')
            vertices.insert({ (grid[x][y + 1] == 'W') ? 2 : 1, curr.id + 1 });
        if (y - 1 >= 0 && grid[x][y - 1] != '#')
            vertices.insert({ (grid[x][y - 1] == 'W') ? 2 : 1, curr.id - 1 });
        if (x + 1 < N && grid[x + 1][y] != '#')
            vertices.insert({ (grid[x + 1][y] == 'W') ? 2 : 1, curr.id + M });
        if (x - 1 >= 0 && grid[x - 1][y] != '#')
            vertices.insert({ (grid[x - 1][y] == 'W') ? 2 : 1, curr.id - M });

        for (auto next : vertices) {
            int new_cost = curr.cost + next.cost;
            if (visited[next.id].cost == -1 || visited[next.id].cost > new_cost) {
                queue.push({ new_cost, next.id });
                visited[next.id].cost = new_cost;
                visited[next.id].id = curr.id;
            }
        }
    }

    cout << visited[goal].cost << endl;
    if (visited[goal].cost == -1) return 0;
    list<char> way;
    int curr = goal;
    while (curr != start) {
        int diff = curr - visited[curr].id;
        if (diff == 1) way.push_front('E');
        else if (diff == -1) way.push_front('W');
        else if (diff == M) way.push_front('S');
        else if (diff == -M) way.push_front('N');
        curr = visited[curr].id;
    }
    for (char x : way) cout << x;
    fin.close();
    return 0;
}
*/
