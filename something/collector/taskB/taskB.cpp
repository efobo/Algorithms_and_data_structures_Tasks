// taskB
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <list>
#include <cmath>

using namespace std;

int main()
{
    int n;
    vector<int> x;
    map<int, vector<int>> x_paralel;
    map<int, vector<int>> y_paralel;
    vector<int> y;
    ifstream fin;

    fin.open("input.txt");
    fin >> n;
    for (int i = 0; i < n; i++) {
        int num1, num2;
        fin >> num1 >> num2;
        x.push_back(num1);
        y.push_back(num2);
        x_paralel.insert(num1, num2);
        y_paralel.insert(num2, num1);
    }




    fin.close();
    cout << "Hello World!";
}

