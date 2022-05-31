// taskD
// Профессор Хаус

#include <iostream>

using namespace std;


int main()
{

    short a; // изначальное кол-во бактерий
    short b; // каждый день из каждой бактерии образуется b новых
    short c; // с уничтожаются
    short d; // в конце дня можно оставить только d бактерий
    long k; // k-ый день эксперимента
    cin >> a >> b >> c >> d >> k;

    short prev_a = 0;

    for (int i = 0; i < k; ++i)
    {
        a = a * b;
        if (a <= c)
        {
            a = 0;
            break;
        }
        a -= c;
        if (a > d) {
            a = d;
            if (i!=0) break;
        }
        if (a < 0) 
        { 
            a = 0;
            break; 
        }
        
        if (a == prev_a) break;
        prev_a = a;

    }

    cout << a;
    
    
}


