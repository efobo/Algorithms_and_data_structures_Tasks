// taskG
// Кошмар в замке

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool sorting(pair<char, int>& pair1, pair<char, int>& pair2)
{
	if (pair1.second > pair2.second) return true;
	return false;
}

int main()
{
	ifstream fin;
	fin.open("aurora.in");

	string text;

	//getline(fin, text, '\n');
	fin >> text;

	int occurrence_counter[26] = { 0 };


	for (int i = 0; i < text.length(); ++i)
	{
		int temp = text[i] - 'a';
		occurrence_counter[temp]++;
	}

	vector<pair<char, int>> alphabet;
	alphabet.reserve(26);

	char cur_letter = 'a';
	string cur_weight_str;
	int cur_weight;

	for (int i = 0; i < 26; ++i)
	{
		getline(fin, cur_weight_str, ' ');

		cur_weight = atoi(cur_weight_str.c_str());
		alphabet.push_back({ cur_letter, cur_weight });
		cur_letter++;
	}
	fin.close();

	sort(alphabet.begin(), alphabet.end(), sorting);

	int left_index = 0;
	int right_index = text.length() - 1;
	string new_text = text;
	for (int i = 0; i < 26; ++i)
	{
		int temp = alphabet[i].first - 'a';
		if (occurrence_counter[temp] > 1)
		{
			int index = text.find(alphabet[i].first);
			text.erase(index, 1);
			index = text.find(alphabet[i].first);
			text.erase(index, 1);
			new_text[left_index] = alphabet[i].first;
			new_text[right_index] = alphabet[i].first;
			left_index++;
			right_index--;
		}
	}

	new_text.replace(left_index, text.length(), text);
	cout << new_text << endl;
}
