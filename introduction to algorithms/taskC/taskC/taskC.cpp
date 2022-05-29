#include <map>
#include <string>
#include <fstream>
#include <stack>
#include <set>

using namespace std;

unsigned long long encode_str_to_uint64(const string& str)
{
    unsigned long long result = 1;

    for (size_t i = 0; i < str.size(); ++i)
    {
        result *= 27;
        result += (str[i] - 'a' + 1);
    }

    return result;
}

void add_value(map<unsigned long long, stack<int>>& vars, stack<set<unsigned long long>>& changes, unsigned long long var_num, int value)
{
    set<unsigned long long>& this_level = changes.top();

    if (this_level.find(var_num) == this_level.end())
    {
        this_level.insert(var_num);
        vars[var_num].push(value);
    }
    else
    {
        vars[var_num].pop();
        vars[var_num].push(value);
    }
}

int main()
{
    ifstream fin;
    fin.open("input.txt");

    ofstream fout;
    fout.open("output.txt");

    map<unsigned long long, stack<int>> vars;
    stack<set<unsigned long long>> changes;
    changes.push(set<unsigned long long>());

    string temp;

    while (!fin.eof())
    {
        getline(fin, temp, '\n');

        if (temp.empty())
            break;

        if (temp[0] == '{')
        {
            changes.push(set<unsigned long long>());
            continue;
        }

        if (temp[0] == '}')
        {
            for (unsigned long long i : changes.top())
                vars[i].pop();

            changes.pop();

            continue;
        }

        auto x = temp.find('=');

        if (x == string::npos)
            break;

        string var_name = temp.substr(0, x);
        string var_value = temp.substr(x + 1, temp.length() - x);

        unsigned long long var_num = encode_str_to_uint64(var_name);

        if (isdigit(var_value[0]) || var_value[0] == '-')
        {
            int new_value = atoi(var_value.c_str());
            add_value(vars, changes, var_num, new_value);
        }

        else
        {
            int new_value = 0;

            unsigned long long value_num = encode_str_to_uint64(var_value);

            stack<int>& find_result = vars[value_num];

            if (!find_result.empty())
                new_value = find_result.top();

            add_value(vars, changes, var_num, new_value);

            fout << new_value << endl;
        }
    }

    fin.close();
    fout.close();
}


