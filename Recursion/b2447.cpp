#include <iostream>
#include <vector>
using namespace std;

void drawstar(vector<vector<char>> &pattern, int a, int b)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            pattern[a + i][b + j] = '*';
        }
    }
}

void star(vector<vector<char>> &pattern, int a, int b, int x)
{
    int t = x / 3;
    if (t < 3)
    {
        drawstar(pattern, a, b);
        return;
    }
    star(pattern, a, b, t);
    star(pattern, a, b + t, t);
    star(pattern, a, b + 2 * t, t);

    star(pattern, a + t, b, t);
    star(pattern, a + t, b + 2 * t, t);

    star(pattern, a + 2 * t, b, t);
    star(pattern, a + 2 * t, b + t, t);
    star(pattern, a + 2 * t, b + 2 * t, t);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> pattern(n, vector<char>(n, ' '));
    star(pattern, 0, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << pattern[i][j];
        }
        cout << '\n';
    }
    return 0;
}