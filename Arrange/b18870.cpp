#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> coord;
    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        coord.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coord[i] > coord[j])
            {
                answer[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return 0;
}