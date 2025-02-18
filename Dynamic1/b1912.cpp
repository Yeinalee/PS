#include <iostream>
#include <vector>
using namespace std;

vector<int> total;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, sum = 0;
    int max = -1000;
    cin >> n;
    while (n--)
    {
        cin >> x;
        // 양수인 경우
        if (x > 0)
            sum += x;

        // 음수인 경우
        else
        {
            if (sum)
            {
                total.push_back(sum);
                sum = 0;
            }
            total.push_back(x);
        }
    }
    if (sum)
        total.push_back(sum);

    // for (int i = 0; i < total.size(); i++)
    //     cout << total[i] << ' ';
    // cout << '\n';

    sum = 0;
    for (int i = 0; i < total.size(); i++)
    {
        int now = sum + total[i];
        if (now > sum || now > 0)
            sum = now;

        // else if (sum < 0 && total[i] > 0)
        //     sum = total[i];

        else
            sum = 0;

        if (max < now)
            max = now;
    }
    cout << max << '\n';
    return 0;
}