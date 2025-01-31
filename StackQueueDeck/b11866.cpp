#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> p;
    for (int i = 1; i <= n; i++)
        p.push(i);
    cout << '<';
    while (p.size())
    {
        for (int i = 0; i < k - 1; i++)
        {
            p.push(p.front());
            p.pop();
        }
        if (p.size() == 1)
            cout << p.front() << ">\n";
        else
            cout << p.front() << ", ";
        p.pop();
    }
}