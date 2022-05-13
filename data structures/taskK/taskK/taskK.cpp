// taskK
// Менеджер памяти-1

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <list>
#include <cmath>

using namespace std;

long long int n; // количество ячеек памяти
int m; // количество запросов
multimap<long long int, long long int> memory_segments_by_length;
map<long long int, long long int> memory_segments_by_start_cell;

void delete_border_by_start_cell_it(map<long long int, long long int>::iterator border_it)
{
    multimap<long long int, long long int>::iterator it = memory_segments_by_length.find(border_it->second);
    while (it->second != border_it->first)
        it++;
    memory_segments_by_length.erase(it);
    memory_segments_by_start_cell.erase(border_it);
}

void insert_with_r_and_l_border(map<long long int, long long int>::iterator right_border_it, map<long long int, long long int>::iterator left_border_it, const long long int start_segment_number, const long long int number_of_cells)
{
    long long int new_number_of_cells = right_border_it->second + left_border_it->second + number_of_cells;
    long long int new_start_cell = left_border_it->first;
    //удаляем правую границу
    delete_border_by_start_cell_it(right_border_it);

    //удаляем левую
    delete_border_by_start_cell_it(left_border_it);

    memory_segments_by_length.insert({ new_number_of_cells, new_start_cell });
    memory_segments_by_start_cell.insert({ new_start_cell, new_number_of_cells });
}

void insert_with_r_border(map<long long int, long long int>::iterator right_border_it, const long long int start_segment_number, const long long int number_of_cells)
{
    long long int new_number_of_cells = number_of_cells + right_border_it->second;

    delete_border_by_start_cell_it(right_border_it);

    memory_segments_by_length.insert({ new_number_of_cells, start_segment_number });
    memory_segments_by_start_cell.insert({ start_segment_number, new_number_of_cells });
}

void insert_with_l_border(map<long long int, long long int>::iterator left_border_it, const long long int start_segment_number, const long long int number_of_cells)
{
    long long int new_number_of_cells = left_border_it->second + number_of_cells;
    long long int new_start_cell = left_border_it->first;
    delete_border_by_start_cell_it(left_border_it);
    memory_segments_by_length.insert({ new_number_of_cells, new_start_cell });
    memory_segments_by_start_cell.insert({ new_start_cell, new_number_of_cells });
}

long long int find_free_cells(const long long int number_of_cells)
{

    multimap<long long int, long long int>::iterator it = memory_segments_by_length.lower_bound(number_of_cells);
    if (it == memory_segments_by_length.end())
        return -1;

    long long int new_segment_length = it->first - number_of_cells;
    long long int new_segment_start_index = it->second + number_of_cells;
    memory_segments_by_start_cell.erase(it->second);
    memory_segments_by_length.erase(it);
    if (new_segment_length > 0)
    {
        memory_segments_by_length.insert({ new_segment_length, new_segment_start_index });
        memory_segments_by_start_cell.insert({ new_segment_start_index, new_segment_length });
    }


    return new_segment_start_index - number_of_cells;
}

void release_cells(const long long int start_segment_number, const long long int number_of_cells)
{
    if (memory_segments_by_length.empty())
    {
        memory_segments_by_length.insert({ number_of_cells, start_segment_number });
        memory_segments_by_start_cell.insert({ start_segment_number, number_of_cells });
        return;
    }
    map<long long int, long long int>::iterator right_border_it = memory_segments_by_start_cell.lower_bound(start_segment_number);
    map<long long int, long long int>::iterator left_border_it;
    if (right_border_it != memory_segments_by_start_cell.begin())
    {
        left_border_it = prev(right_border_it);
        if (right_border_it != memory_segments_by_start_cell.end())
        {
            if ((start_segment_number + number_of_cells) == right_border_it->first)
            {
                if ((left_border_it->first + left_border_it->second) == start_segment_number)
                {
                    insert_with_r_and_l_border(right_border_it, left_border_it, start_segment_number, number_of_cells);
                }
                else
                {
                    insert_with_r_border(right_border_it, start_segment_number, number_of_cells);
                }
            }
            else
            {
                if ((left_border_it->first + left_border_it->second) == start_segment_number)
                {
                    insert_with_l_border(left_border_it, start_segment_number, number_of_cells);
                }
                else
                {
                    memory_segments_by_length.insert({ number_of_cells, start_segment_number });
                    memory_segments_by_start_cell.insert({ start_segment_number, number_of_cells });
                }
            }
        }
        else
        {
            if ((left_border_it->first + left_border_it->second) == start_segment_number)
            {
                insert_with_l_border(left_border_it, start_segment_number, number_of_cells);
            }
            else
            {
                memory_segments_by_length.insert({ number_of_cells, start_segment_number });
                memory_segments_by_start_cell.insert({ start_segment_number, number_of_cells });
            }
        }
    }
    else
    {
        if ((start_segment_number + number_of_cells) == right_border_it->first)
        {
            insert_with_r_border(right_border_it, start_segment_number, number_of_cells);
        }
        else
        {
            memory_segments_by_length.insert({ number_of_cells, start_segment_number });
            memory_segments_by_start_cell.insert({ start_segment_number, number_of_cells });
        }
    }


    /*cout << "DELETE" << endl;
    int index_it = 1;
    for (it = memory_segments.begin(); it != memory_segments.end(); ++it)
    {
        cout << index_it << ".  first = " << (*it).first << "  second = " << (*it).second << endl;
        index_it++;
    }*/

}

int main()
{
    ifstream fin;

    fin.open("input.txt");
    fin >> n >> m;

    memory_segments_by_length.insert({ n, 1 });
    memory_segments_by_start_cell.insert({ 1, n });

    //index, start cell, number of cells 
    long long int* start_cells = new long long int[m+1];
    long long int* number_of_cells = new long long int[m+1];



    for (int i = 1; i < m + 1; ++i)
    {
        long long int x;
        fin >> x;
        //cout << "\n" << i << "~~ INPUT: " << x << endl;
        if (x > 0)
        {
            long long int index = find_free_cells(x);
            //cout << "ANSWER: " << index << endl;
            cout << index << endl;
            start_cells[i] = index;
            if (index != -1)
            {
                number_of_cells[i] = x;
            }
        }
        else
        {
            x = abs(x);
            if (start_cells[x] != -1)
            {
                release_cells(start_cells[x], number_of_cells[x]);
                start_cells[x] = -1;
            }
        }
    }

    fin.close();
}
