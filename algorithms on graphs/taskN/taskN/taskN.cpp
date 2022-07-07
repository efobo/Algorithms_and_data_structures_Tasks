// taskN
// Свинки-копилки

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

int answer;
int* status;
list<int>* piggy_banks;

void looking_for_the_key(int index) 
{
    status[index] = 1;
    for (int i : piggy_banks[index])
    {
        if (status[i] == 0) looking_for_the_key(i);
        if (status[i] == 1) answer++;
    }
    status[index] = 2;
}

int main()
{
    int n; // количество свинок-копилок
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    answer = 0;
    status = new int[n] {0};
    piggy_banks = new list<int>[n];

    for (int i = 0; i < n; ++i)
    {
        int x;
        fin >> x;
        x--;
        piggy_banks[x].push_back(i);
    }
    fin.close();

    for (int i = 0; i < n; i++)
    {
        if (status[i] == 0) looking_for_the_key(i);
    }
    cout << answer;
}
