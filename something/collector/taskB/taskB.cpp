#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Coordinates
{
	long long X;
	long long Y;
};

int sortByX(Coordinates& a, Coordinates& b) {
	return a.X < b.X;
}


int sortByY(Coordinates& a, Coordinates& b) {
	return a.Y < b.Y;
}

vector<Coordinates> get_y_coords_right(vector<Coordinates>& coords, long long i) {
	const long long left_x = coords[i].X;

	vector<Coordinates> result;
	
	while (i < coords.size() && coords[i].X == left_x) {
		result.push_back(coords[i]);
		++i;
	}

	return result;
}

unsigned long long get_sq(vector<Coordinates>& left, vector<Coordinates>& right) {
	int i = 0;
	int j = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i].Y == right[j].Y)
			break;
		if (left[i].Y > right[j].Y)
			++j;
		else
			++i;
	}

	if (i >= left.size() || j >= right.size())
		return 0;

	long long min_y = left[i].Y;

	i = left.size() - 1;
	j = right.size() - 1;

	while (i >= 0 && j >= 0 && left[i].Y > min_y && right[j].Y > min_y) {
		if (left[i].Y == right[j].Y) {
			long long max_y = left[i].Y;

			unsigned long long sq = 1;

			sq *= abs(right[0].X - left[0].X);
			sq *= abs(max_y - min_y);

			return sq;
		}
		
		if (left[i].Y > right[j].Y)
			--i;
		else
			--j;
	}

	return 0;
}

int main()
{
	int n;
	cin >> n;

	vector<Coordinates> coords;
	coords.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> coords[i].X;
		cin >> coords[i].Y;
	}

	sort(coords.begin(), coords.end(), sortByY);
	sort(coords.begin(), coords.end(), sortByX);

	vector<vector<Coordinates>> unique_x_coords;
	
	long long t = 0;
	while (t < n) {
		auto new_part = get_y_coords_right(coords, t);
		unique_x_coords.push_back(new_part);
		t += new_part.size();
	}

	unsigned long long max_sq = 0;

	for (int i = 0; i < unique_x_coords.size(); ++i) {
		for (int j = i + 1; j < unique_x_coords.size(); ++j) {

			auto sq = get_sq(unique_x_coords[i], unique_x_coords[j]);
			max_sq = max(sq, max_sq);
		}
	}
	
	cout << max_sq;
}
