#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x, order = 1;
    vector<int> line;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (order == x)
            order++;
        else
            line.push_back(x);

        // 보조줄에서 바로 꺼내기!!!
        while (!line.empty() && line.back() == order)
        {
            order++;
            line.pop_back();
        }
    }

    cout << (line.empty() ? "Nice" : "Sad") << '\n';
    return 0;
}