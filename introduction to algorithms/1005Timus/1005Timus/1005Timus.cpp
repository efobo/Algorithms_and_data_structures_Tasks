// 1005Timus
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int min_difference = 100000;

void find_min_difference(int n, vector<int>& w, int heap1, int heap2, int iteration)
{
    if (iteration == n) { 
        min_difference = min(min_difference, abs(heap2 - heap1)); 
    }
    else
    {
        find_min_difference(n, w, (heap1 + w[iteration]), heap2, iteration+1);
        find_min_difference(n, w, heap1, (heap2 + w[iteration]), iteration+1);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> w;
    w.reserve(n);


    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        w.push_back(x);

    }

    find_min_difference(n, w, w[0], 0, 1);

    cout << min_difference << endl;


}


