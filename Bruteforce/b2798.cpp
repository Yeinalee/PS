#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, x, sum = 0;
    vector<int> card;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        card.push_back(x);
    }

    x = 0; // 최대 카드의 합
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (sum <= m && x < sum)
                    x = sum;
            }
        }
    }
    cout << x << '\n';
    return 0;
}