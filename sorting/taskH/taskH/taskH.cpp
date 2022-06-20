// taskH
// Магазин

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(int& num1, int& num2)
{
    if (num1 > num2) return true;

    return false;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;

    vector<int> products;
    products.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        products.push_back(x);
    }
    sort(products.begin(), products.end(), sorting);
    vector<int> in_one_check;
    in_one_check.reserve(k);
    int sum = 0;
    int counter = 0;

    for (int i = 0; i < n; ++i)
    {
        if (counter == k)
        {
            counter = 0;
            for (int j = 0; j < k - 1; ++j)
            {
                sum += in_one_check[j];
            }
            in_one_check.clear();
            i--;
        }
        else
        {
            in_one_check.push_back(products[i]);
            counter++;
        }
    }
    if (counter != 0)
    {
        for (int i = 0; i < counter - 1; ++i)
        {
            sum += in_one_check[i];
        }
        if (counter % k != 0) sum += in_one_check[counter - 1];
    }
    cout << sum;
}
