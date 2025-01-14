#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> x;
    unordered_map<int, int> y;
    int x1, y1;
    for (int i = 0; i < 3; i++)
    {
        cin >> x1 >> y1;
        x[x1]++;
        y[y1]++;
    }
    for (const auto &idx : x)
    {
        if (idx.second == 1)
        {
            cout << idx.first << ' ';
            break;
        }
    }
    for (const auto &idx : y)
    {
        if (idx.second == 1)
        {
            cout << idx.first << '\n';
            break;
        }
    }
    return 0;
}