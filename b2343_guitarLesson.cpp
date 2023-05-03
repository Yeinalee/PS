#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    long long arr[N];
    long long sum = 0, min = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];          // 최대값은 모든 배열의 합
        min = max(min, arr[i]); // 최솟값의 배열의 원소 중 최솟값
    }

    while (min <= sum)
    {
        long long cnt = 0, tempSum = 0;
        long long mid = (min + sum) / 2;

        for (int i = 0; i < N; i++)
        {
            if (tempSum + arr[i] > mid) // 블루레이가 가득차면
            {
                tempSum = 0; // 다음 블루레이에 넣기
                cnt += 1;    // 블루레이 개수 증가
            }
            tempSum += arr[i]; // 블루레이에 하나씩 넣기
        }

        if (tempSum != 0) // 남은 블루레이가 있다면 하나 추가
            cnt += 1;

        if (cnt <= M)
            sum = mid - 1;
        else
            min = mid + 1;
    }
    cout << min;
    return 0;
}