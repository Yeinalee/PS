#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, max = 0, mod, avg;
    double sum = 0;
    cin >> n;
    vector<int> su;
    vector<int> mode(8001, 0);
    vector<int> fordup;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
        su.push_back(x);
        mode[x + 4000]++;
    }

    // 산술 평균
    avg = round((float)sum / n);

    // 중앙값
    sort(su.begin(), su.end());

    // 최빈값
    fordup.push_back(0);
    for (int i = 1; i < mode.size(); i++)
    {
        if (mode[i] == 0) // 값 없을 때
            continue;
        if (mode[max] < mode[i])
        {
            fordup.clear();
            fordup.push_back(i);
            max = i;
        }
        else if (mode[max] == mode[i]) // 최빈값이 같은 경우
        {
            fordup.push_back(i);
        }
    }
    if (fordup.size() == 1)
    {
        mod = fordup[0] - 4000;
    }
    else
    {
        mod = fordup[1] - 4000;
    }
    cout
        << avg << '\n'
        << su[n / 2] << '\n'
        << mod << '\n'
        << su.back() - su.front() << '\n';
}