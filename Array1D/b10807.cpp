#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x, v, answer = 0;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        num.push_back(x);
    }
    cin >> v;
    for (int i = 0; i < n; i++)
    {
        if (v == num[i])
            answer++;
    }
    cout << answer << '\n';
    return 0;
}