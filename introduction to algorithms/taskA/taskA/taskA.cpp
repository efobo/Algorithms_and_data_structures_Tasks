//taskA
// Агроном-любитель

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n;

    vector <int> flowers;
    flowers.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        flowers.push_back(x);
    }

    int counter = 1;
    int prev_flower = flowers[0];
    int first_n = 0;

    int max_length = 1;
    int index_max_length = 0;

    for (int i = 1; i < n; ++i)
    {
        if (prev_flower == flowers[i])
            counter++;
        else
            counter = 1;

        int length = i - first_n + 1;

        if (counter == 3)
            length--;

        if (length > max_length)
        {
            max_length = length;
            index_max_length = first_n;
        }

        if (counter == 3)
        {
            first_n = i - 1;
            counter = 2;
        }

        prev_flower = flowers[i];
    }

    cout << index_max_length + 1 << " " << index_max_length + max_length << endl;
}

