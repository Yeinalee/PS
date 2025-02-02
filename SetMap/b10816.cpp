#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    unordered_map<int, int> card;
    cin >> n;
    while (n--)
    {
        cin >> x;
        card[x]++;
    }
    cin >> m;
    while (m--)
    {
        cin >> x;
        cout << card[x] << ' ';
    }
    return 0;
}