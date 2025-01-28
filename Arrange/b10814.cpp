#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortage(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    int n, age;
    string name;
    cin >> n;
    vector<pair<int, string>> mem;
    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        mem.push_back({age, name});
    }
    stable_sort(mem.begin(), mem.end(), sortage);

    for (int i = 0; i < n; i++)
    {
        cout << mem[i].first << ' ' << mem[i].second << '\n';
    }
    return 0;
}