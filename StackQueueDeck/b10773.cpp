#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x;
    long int answer = 0;
    vector<int> stack;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (!x)
            stack.pop_back();
        else
            stack.push_back(x);
    }
    for (int k : stack)
        answer += k;
    cout << answer << '\n';
    return 0;
}