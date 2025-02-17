#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
vector<int> operators;
int n;
long minimum = 10000000000, maximum = -10000000000;

void operate(int k, long total)
{
    if (k == n)
    {
        if (total > maximum)
            maximum = total;
        if (total < minimum)
            minimum = total;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (operators[i])
        {
            long bum;
            operators[i]--;
            if (i == 0)
                bum = total + num[k];
            else if (i == 1)
                bum = total - num[k];
            else if (i == 2)
                bum = total * num[k];
            else
                bum = total / num[k];
            operate(k + 1, bum);
            operators[i]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        num.push_back(x);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        operators.push_back(x);
    }
    operate(1, num[0]);
    cout << maximum << '\n'
         << minimum << '\n';
    return 0;
}