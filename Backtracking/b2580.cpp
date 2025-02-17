#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> stoku(9, vector<int>(9));
vector<pair<int, int>> blank;
bool success = false;

bool check(int a, int b, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (stoku[a][i] == value)
            return false;
        if (stoku[i][b] == value)
            return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (stoku[a / 3 * 3 + i][b / 3 * 3 + j] == value)
                return false;
    }

    return true;
}

void sol(int idx)
{
    if (success)
        return;

    if (idx == blank.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << stoku[i][j] << ' ';
            cout << '\n';
        }
        success = true;
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        int x = blank[idx].first, y = blank[idx].second;
        if (check(x, y, i))
        {
            stoku[x][y] = i;
            sol(idx + 1);
            stoku[x][y] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> x;
            stoku[i][j] = x;
            if (x == 0)
                blank.push_back({i, j});
        }
    sol(0);
    return 0;
}