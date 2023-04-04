// taskC
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int main()
{
    int n;
    int k;
    int ans = 0;
    vector<int> seg;
    vector<int> prev_seg;
    bool not_first_seg = false;
    int counter = 0;
    ifstream fin;

    fin.open("input.txt");
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        fin >> num;

        seg.push_back(num);

        counter++;
        int prev_sum = num;
        bool zero_flag;
        if (num == 0) zero_flag = true;
        else zero_flag = false;
        

        if (num <= k) {
            ans++;
            for (int j = 1; j < seg.size(); j++) {
                /*if (seg[seg.size() - j - 1] == 0) {
                    if (zero_flag) break;
                    zero_flag = true;
                }*/
                prev_sum += seg[seg.size() - j - 1];
                if (prev_sum <= k) ans++;
                else break;
            }
            if (prev_sum <= k && not_first_seg && !zero_flag) {
                for (int j = 1; j < prev_seg.size(); j++) {
                    if (prev_seg[prev_seg.size() - j - 1] == 0) {
                        if (zero_flag) break;
                        zero_flag = true;
                    }
                    prev_sum += prev_seg[prev_seg.size() - j - 1];
                    if (prev_sum <= k) ans++;
                    else break;
                }
            }
        }
        
        
        if (num == 0 && i != 0) {
            prev_seg = seg;
            not_first_seg = true;
            seg.clear();
            seg.push_back(num);
            counter = 0;
        } 
        
    }
    fin.close();

   


    cout << ans;
}

