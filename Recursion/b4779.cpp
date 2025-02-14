#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void change0(vector<char> &answer, int a, int b)
{
    for (int i = a; i <= b; i++)
        answer[i] = ' ';
}

void cantor(vector<char> &answer, int a, int b)
{
    int p = (b - a + 1) / 3;
    if (p < 1)
        return;
    cantor(answer, a, a + p - 1);
    change0(answer, a + p, a + (2 * p) - 1);
    cantor(answer, a + (2 * p), b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    while (cin >> x)
    {
        int length = pow(3, x);
        vector<char> answer(length, '-');
        cantor(answer, 0, length - 1);
        for (char c : answer)
            cout << c;
        cout << '\n';
    }
    return 0;
}