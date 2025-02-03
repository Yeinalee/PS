#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    vector<int> divisor;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        divisor.push_back(x);
    }
    sort(divisor.begin(), divisor.end());
    int answer = divisor[0] * divisor[divisor.size() - 1];
    for (int i = 0; i < n; i++)
    {
        if (!answer % divisor[i])
            answer *= divisor[i];
    }
    cout << answer << '\n';
}