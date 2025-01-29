#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, x;
    cin >> n >> k;
    vector<int> score;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        score.push_back(x);
    }
    sort(score.begin(), score.end());
    cout << score[n - k] << '\n';
    return 0;
}