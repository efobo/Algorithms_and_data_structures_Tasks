// taskE
// Коровы в стойла


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int k;
	cin >> n >> k;


	vector<int> coordinates;
	coordinates.reserve(n);


	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		coordinates.push_back(x);

	}

	int min_distance = 0;
	int max_distance = coordinates[n - 1] - coordinates[0] + 1;

	while (max_distance - min_distance > 1)
	{
		int cur_distance_for_check = (max_distance - min_distance) / 2 + min_distance;
		int cows_without_a_stall = k - 1;
		int prev_cow_coordinate = coordinates[0];

		for (int i = 1; i < n; i++)
		{
			if (cows_without_a_stall == 0) break;
			if (cows_without_a_stall > n - i) break;
			if ((coordinates[i] - prev_cow_coordinate) >= cur_distance_for_check)
			{
				cows_without_a_stall--;
				prev_cow_coordinate = coordinates[i];
			}
		}

		if (cows_without_a_stall == 0)
		{
			if (min_distance > cur_distance_for_check) break;
			min_distance = cur_distance_for_check;
		}
		else
		{
			max_distance = cur_distance_for_check;
		}
	}

	cout << min_distance;
}

