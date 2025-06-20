#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int minv = 0, mini = 0, minj = 0;
    int x;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> x;
            if (x > minv)
            {
                minv = x;
                mini = i;
                minj = j;
            }
        }
    }
    cout << minv << '\n'
         << mini + 1 << ' ' << minj + 1 << '\n';
}