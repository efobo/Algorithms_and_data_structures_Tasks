// taskF
// Число

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool sorting(string& num1, string& num2)
{
	string full_num1 = num1 + num2;
	string full_num2 = num2 + num1;
	if (full_num1 > full_num2)
	{
		return true;
	}
	return false;
}

int main()
{
	ifstream fin;
	fin.open("number.in");

	vector<string> numbers;

	string x;
	while (fin >> x)
	{
		numbers.push_back(x);
	}
	fin.close();

	sort(numbers.begin(), numbers.end(), sorting);

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i];
	}


}

