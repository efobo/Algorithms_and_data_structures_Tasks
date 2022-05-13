// taskL
// Минимум на отрезке

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main()
{
    int n;
    int k;
    ifstream fin;
    fin.open("input.txt");
    fin >> n >> k;

    list<pair<int, int>> numbers;


    int cur_num;
    fin >> cur_num;
    numbers.push_back({ 0, cur_num });
    for (int i = 1; i < n; i++)
    {
        fin >> cur_num;
        if (i >= k)
            cout << numbers.front().second << " ";
        while (!numbers.empty() && cur_num < numbers.back().second)
        {
            numbers.pop_back();
        }
        numbers.push_back({ i, cur_num });

        if (!numbers.empty())
        {
            if (numbers.front().first < (i - k + 1))
            {
                numbers.pop_front();
            }

        }


    }
    fin.close();
    cout << numbers.front().second;

}


