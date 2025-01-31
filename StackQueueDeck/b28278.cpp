#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, command, x;
    vector<int> stack;
    cin >> n;

    while (n--)
    {
        cin >> command;
        switch (command)
        {
        case 1:
            cin >> x;
            stack.push_back(x);
            break;
        case 2:
            if (!stack.empty())
            {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
            else
            {
                cout << "-1\n";
            }
            break;
        case 3:
            cout << stack.size() << '\n';
            break;
        case 4:
            cout << (stack.empty() ? "1\n" : "0\n");
            break;
        case 5:
            if (!stack.empty())
            {
                cout << stack.back() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
            break;
        }
    }
}