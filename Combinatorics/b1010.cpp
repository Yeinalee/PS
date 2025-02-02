#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, answer;
    cin >> t;
    while (t--)
    {
        answer = 1;
        cin >> n >> m; // mCn
        for (int i = 0; i < n; i++)
        {
            answer *= (m - i);
            answer /= (i + 1);
        }
        cout << answer << '\n';
    }
}