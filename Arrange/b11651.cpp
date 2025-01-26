#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool yx(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    int n, x, y;
    vector<pair<int, int>> coord;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        coord.push_back({x, y});
    }
    sort(coord.begin(), coord.end(), yx);
    for (int i = 0; i < n; i++)
    {
        cout << coord[i].first << ' ' << coord[i].second << '\n';
    }
    return 0;
}