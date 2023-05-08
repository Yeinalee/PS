#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> houses;
int main()
{
    cin >> n >> c;              // n개의 집, c개의 공유기
    for (int i = 0; i < n; i++) // 집 위치 벡터
    {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }

    sort(houses.begin(), houses.end()); // 이분 탐색 -> 정렬 필요

    int start = 1;                       // 최소 거리 1
    int end = houses[n - 1] - houses[0]; // 최대 거리
    int result = 0;

    while (start <= end) // 이분 탐색 진행
    {
        int mid = (start + end) / 2; // 공유기 간 거리
        int cnt = 1;                 // 공유기 개수
        int prev_house = houses[0];  // 이전 공유기 위치

        for (int i = 1; i < n; i++)
        {
            if (houses[i] - prev_house >= mid)
            {
                cnt++;
                prev_house = houses[i];
            }
        }

        if (cnt >= c)
        {
            result = max(result, mid);
            start = mid + 1;
        }

        else
            end = mid - 1;
    }
    cout << result;
    return 0;
}