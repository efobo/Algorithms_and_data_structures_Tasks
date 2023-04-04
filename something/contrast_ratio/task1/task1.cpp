// task1
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n; // кол-во дней
    int min;
    int min_index;
    int max;
    int max_index;

    //ifstream fin;
    //fin.open("input.txt");
    //fin >> n;
    cin >> n;
    
    int num1, num2;
    
    //fin >> num1 >> num2;
    cin >> num1 >> num2;
    if (num1 > num2) {
        max = num1;
        max_index = 1;
        min = num2;
        min_index = 2;
    }
    else {
        max = num2;
        max_index = 2;
        min = num1;
        min_index = 1;
    }

    for (int i = 3; i < n+1; i++) {
        cin >> num1;
        if (num1 >= max) {
            max = num1;
            max_index = i;
        }
        else if (num1 < min) {
            min = num1;
            min_index = i;
        }
    }

    //fin.close();
    cout << max_index << " " << min_index;
}


