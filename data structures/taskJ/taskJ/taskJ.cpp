// taskJ
// Гоблины и очереди

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	
	list<int> first_half_of_queue;
	list<int> second_half_of_queue;
	int n; // количество запросов
	ifstream fin;
	fin.open("input.txt");
	fin >> n;

	char action;
	int num;
	fin >> action >> num;
	first_half_of_queue.push_back(num);
	for (int i = 1; i < n; ++i)
	{
		fin >> action;
		if (action == '+')
		{
			fin >> num;
			second_half_of_queue.push_back(num);
		}
		else if (action == '*')
		{
			fin >> num;
			second_half_of_queue.insert(second_half_of_queue.begin(), num);
		}
		else if (action == '-')
		{
			cout << first_half_of_queue.front() << endl;
			first_half_of_queue.pop_front();
		}

		if (first_half_of_queue.size() < second_half_of_queue.size())
		{
			first_half_of_queue.push_back(second_half_of_queue.front());
			second_half_of_queue.pop_front();
		}
	}


	fin.close();

}

