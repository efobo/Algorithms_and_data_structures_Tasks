// taskO
// Долой списывание!

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<int>* lkshats;
int* lkshat_status;
bool answer = true;


void assign_status(int index, int status)
{
    lkshat_status[index] = status;
    for (int l : lkshats[index]) 
    {
        if (!lkshat_status[l]) 
        {
            if (status == 1)
                assign_status(l, 2);
            else assign_status(l, 1);

            if (!answer) return;
        }
        if (lkshat_status[l] == status)
        {
            answer = false;
            return;
        }
    }
}

int main()
{
    ifstream fin;
    int n; // количество лкшат
    int m; // количество пар лкшат, обменивающихся записками
    fin.open("input.txt");
    fin >> n >> m;
    lkshats = new vector<int>[n];
    lkshat_status = new int[n] {0};
    for (int i = 0; i < m; i++)
    {
        int l1, l2;
        fin >> l1 >> l2;
        l1--;
        l2--;
        lkshats[l1].push_back(l2);
        lkshats[l2].push_back(l1);
    }
    fin.close();



    for (int i = 0; i < n; ++i)
    {
        if (!answer) break;
        if (lkshat_status[i] == 0)
            assign_status(i, 1);
    }

    if (!answer)
        cout << "NO";
    else
        cout << "YES";

}


