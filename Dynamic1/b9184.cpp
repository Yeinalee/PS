#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<vector<int>>> memo(101, vector<vector<int>>(101, vector<int>(101, 0)));
vector<vector<vector<long long>>> have(101, vector<vector<long long>>(101, vector<long long>(101, 0)));

long long getw(int a, int b, int c)
{
    // 이미 계산한 값을 가지고 있는 경우
    if (memo[a][b][c])
        return have[a][b][c];

    // 처음 계산하는 경우
    memo[a][b][c] = 1;
    if (a <= 50 || b <= 50 || c <= 50)
        return (have[a][b][c] = 1);
    else if (a > 70 || b > 70 || c > 70)
        return getw(70, 70, 70);
    else if (a == b && b == c)
    {
        return (have[a][b][c] = pow(2, a - 50));
    }
    else if (a < b && b < c)
        return (have[a][b][c] = getw(a, b, c - 1) + getw(a, b - 1, c - 1) - getw(a, b - 1, c));
    else
        return (have[a][b][c] = getw(a - 1, b, c) + getw(a - 1, b - 1, c) + getw(a - 1, b, c - 1) - getw(a - 1, b - 1, c - 1));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c;
    long long answer;

    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        answer = getw(a + 50, b + 50, c + 50);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << answer << '\n';
    }
    return 0;
}