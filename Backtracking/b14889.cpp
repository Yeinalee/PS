#include <iostream>
#include <vector>
using namespace std;
int n, diff = 2000;

int main()
{
    int x;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            s[i][j] = x;
        }
    }
    return 0;
}