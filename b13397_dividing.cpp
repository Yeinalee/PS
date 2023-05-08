#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sol(vector<int> arr, int mid, int n, int m)
{
    vector<int> temp;
    int cnt = 1;
    int minV = arr[0];
    int maxV = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minV)
            minV = arr[i];
        if (arr[i] > maxV)
            maxV = arr[i];

        if ((maxV - minV) > mid)
        {
            cnt++;
            minV = arr[i];
            maxV = arr[i];
        }
    }
    return (m >= cnt);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) // 배열 입력 받기
        cin >> arr[i];

    int start = 0;                     // 최솟값 0
    int end = max(arr[0], arr[n - 1]); // 최댓값을 end으로 설정
    int res = INT_MAX;

    while (start <= end) // 이분탐색
    {
        int mid = (start + end) / 2;
        if (sol(arr, mid, n, m))
        {
            if (res > mid)
            {
                res = mid;
            }
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << res;
    return 0;
}