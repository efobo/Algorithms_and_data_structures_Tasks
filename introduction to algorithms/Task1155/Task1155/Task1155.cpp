 // Task1155
//

#include <iostream>
#include <ctime>

using namespace std;

void subtract(int* sum, int* first_num, int* second_num, char ch1, char ch2)
{
    std::cout << ch1 << ch2 << "-" << endl;
    (*first_num)--;
    (*second_num)--;
    (*sum)--;
}

void addition(int* sum, int* first_num, int* second_num, char ch1, char ch2)
{
    std::cout << ch1 << ch2 << "+" << endl;
    (*first_num)++;
    (*second_num)++;
    (*sum)++;
}

int main()
{
    int A; // B D E
    int B; // A C F
    int C; // B D G
    int D; // A C H
    int E; // A F H
    int F; // B E G
    int G; // C F H
    int H; // D E G
    cin >> A >> B >> C >> D >> E >> F >> G >> H;
    


    if ((A + C + F + H) != (B + D + E + G))
        std::cout << "IMPOSSIBLE" << endl;
    else
    {
        int sum = A + C + F + H;
        while (sum > 0)
        {
            if (E > 0)
            {
                if (F > 0) subtract(&sum, &E, &F, 'E', 'F');
                else if (A > 0) subtract(&sum, &E, &A, 'E', 'A');
                else if (H > 0) subtract(&sum, &E, &H, 'E', 'H');
                else if (C > 0)
                {
                    addition(&sum, &A, &D, 'A', 'D');
                    subtract(&sum, &A, &E, 'A', 'E');
                }
            }
            else if (D > 0)
            {
                if (C > 0) subtract(&sum, &D, &C, 'D', 'C');
                else if (H > 0) subtract(&sum, &D, &H, 'D', 'H');
                else if (A > 0) subtract(&sum, &D, &A, 'D', 'A');
                else if (F > 0)
                {
                    addition(&sum, &B, &C, 'B', 'C');
                    subtract(&sum, &C, &D, 'C', 'D');
                }
            }
            else if (B > 0)
            {
                if (A > 0) subtract(&sum, &B, &A, 'B', 'A');
                else if (C > 0) subtract(&sum, &B, &C, 'B', 'C');
                else if (F > 0) subtract(&sum, &B, &F, 'B', 'F');
                else if (H > 0)
                {
                    addition(&sum, &A, &D, 'A', 'D');
                    subtract(&sum, &A, &B, 'A', 'B');
                }
            }
            else if (G > 0)
            {
                if (H > 0) subtract(&sum, &G, &H, 'G', 'H');
                else if (C > 0) subtract(&sum, &G, &C, 'G', 'C');
                else if (F > 0) subtract(&sum, &G, &F, 'G', 'F');
                else if (A > 0)
                {
                    addition(&sum, &C, &D, 'C', 'D');
                    subtract(&sum, &C, &G, 'C', 'G');
                }
            }
        }
    }
    
}


