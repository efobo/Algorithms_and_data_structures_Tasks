// taskB
// Зоопарк Глеба

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isFit(char symbol1, char symbol2)
{
    if (islower(symbol1) && isupper(symbol2) && (toupper(symbol1) == symbol2))
        return true;
    if (isupper(symbol1) && islower(symbol2) && (tolower(symbol1) == symbol2))
        return true;
    return false;
}



int main()
{
    string n;
    cin >> n;


    stack<char> stack;
    string::const_iterator it(n.begin());

    std::stack<int> animal_number_stack;
    std::stack<int> places_for_numbers;
    int animal_number = 1;
    vector<int> answer;
    answer.reserve(n.length() / 2);
    for (int i = 0; i < (n.length() / 2); ++i)
        answer.push_back(0);
    

    for (; it < n.end(); ++it) 
    {
        if (islower(*it))
        {
            animal_number_stack.push(animal_number);
            animal_number++;
        }
        else
        {
            places_for_numbers.push(it - n.begin() - (animal_number - 1));
        }

        if (stack.empty())
        {
            stack.push(*it);
            continue;
        }

        if (isFit(stack.top(), *it))
        {
            stack.pop();
           
                answer[places_for_numbers.top()] = animal_number_stack.top();
                places_for_numbers.pop();
            animal_number_stack.pop();
        } 
        else
        {
            stack.push(*it);
        }
      
    }

    if (stack.empty())
    {
        std::cout << "Possible" << endl;
        for (int i = 0; i < answer.size();++i)
            cout << answer[i] << " ";
    }
    else
        std::cout << "Impossible" << endl;

}