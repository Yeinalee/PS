#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sol(vector<int> arr, int mid, int n)
{
    vector<int> temp;
    int cnt = 1;
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];

        if ((max - min) > mid)
        {
            cnt++;
            min = arr[i];
            max = arr[i];
        }
    }
    return cnt;
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
    int res = end;

    while (start <= end) // 이분탐색
    {
        int mid = (start + end) / 2;
        if (sol(arr, mid, n) <= m)
        {
            if (res > mid)
                res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << res;
}