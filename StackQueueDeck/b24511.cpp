#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n, b, m;
    bool x;
    deque<bool> qu;
    deque<int> queuestack;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        qu.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        if (qu[i] == 0)
            queuestack.push_back(b);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        queuestack.push_front(b);
    }
    for (int i = 0; i < m; i++)
    {
        cout << queuestack.back() << ' ';
        queuestack.pop_back();
    }
    return 0;
}