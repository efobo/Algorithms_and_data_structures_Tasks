// task1

#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    string ans = "YES";

    ifstream fin;
    fin.open("input.txt");
    
    
    bool ascending = true;
    bool  order_undefined = true;
    int cur_pers;
    int prev_pers;
    fin >> prev_pers >> cur_pers;

    for (int i = 2; i < 4; i++) {
        if (order_undefined) {
            if (prev_pers < cur_pers) {
                ascending = true;
                order_undefined = false;
            }
            else if (prev_pers > cur_pers) {
                ascending = false;
                order_undefined = false;
            }
        }
        else {
            if ((ascending && prev_pers > cur_pers) || (!ascending && prev_pers < cur_pers)) {
                ans = "NO";
                break;
            }
            
        }

        prev_pers = cur_pers;
        
        fin >> cur_pers;
    }
    fin.close();

    cout << ans;

}

