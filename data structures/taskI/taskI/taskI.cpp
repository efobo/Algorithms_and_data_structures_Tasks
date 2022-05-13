// taskI
// Машинки

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <list>
#include <iterator>
#include <queue>

using namespace std;



int n; // количество машинок
int k; // максимальное на полу
int p; // В следующих P строках записаны номера машинок в том порядке, в котором Петя захочет играть с ними.

int* history;
list<int>* history_list;
int* heap;
int* on_the_floor;
int number_of_cars_on_the_floor = 0;
int number_of_operations = 0;



int main()
{


    ifstream fin;
    fin.open("input.txt");
    fin >> n >> k >> p;

    history = new int[p + 1];
    history_list = new list<int>[n + 2];

    for (int i = 1; i <= p; ++i)
    {
        int x;
        fin >> x;
        history[i] = x;
        history_list[x].push_back(i);
    }
    fin.close();


    on_the_floor = new int[n + 1]{ 0 };




    //  следующее вхождение, номер машинки
    priority_queue<pair<int, int>> queue;

    for (int i = 1; i <= p; ++i)
    {
        int cur_car = history[i];
        history_list[cur_car].pop_front();
        if (on_the_floor[cur_car] == 0)
        {
            if (number_of_cars_on_the_floor == k)
            {
                on_the_floor[queue.top().second] = 0;
                queue.pop();
            }
            else
            {
                number_of_cars_on_the_floor++;
            }
            on_the_floor[cur_car] = 1;
            number_of_operations++;
        }

        if (!history_list[cur_car].empty())
        {
            queue.push({ history_list[cur_car].front(), cur_car });
        }
        else
        {
            queue.push({ 2147483647, cur_car });
        }

    }

    cout << number_of_operations;
}