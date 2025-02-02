#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, x;
    set<int> card;
    cin >> n;
    while (n--)
    {
        cin >> x;
        card.insert(x);
    }
    cin >> m;
    while (m--)
    {
        cin >> x;
        if (card.find(x) == card.end())
            cout << 0 << ' ';
        else
            cout << 1 << ' ';
    }
}