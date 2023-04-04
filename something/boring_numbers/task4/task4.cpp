#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int size = 2000010;

int main()
{
	int n;
	cin >> n;

	int* counts = new int[size];
	for (int i = 0; i < size; ++i) {
		counts[i] = 0;
	}
	
	int* counts_of_counts = new int[size];
	for (int i = 0; i < size; ++i) {
		counts_of_counts[i] = 0;
	}
	
	int max_count;
	
	int temp;
	int result = 0;
	int size = 0;
	
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		counts[temp] += 1;
		size += 1;
		
		if (counts[temp] == 1)
			counts_of_counts[1] += 1;

		else {
			counts_of_counts[counts[temp]] += 1;
			counts_of_counts[counts[temp] - 1] -= 1;
		}

		max_count = max(max_count, counts[temp]);

		if (max_count == 1)
			result = size;
		
		if (counts_of_counts[max_count] * max_count == size - 1 && counts_of_counts[1] == 1)
			result = size;

		if (counts_of_counts[max_count] == 1 && (counts_of_counts[max_count - 1] + 1) * (max_count - 1) == size - 1)
			result = size;
	}
	
	cout << result;
}
