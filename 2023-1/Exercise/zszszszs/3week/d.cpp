#include <bits/stdc++.h>
using namespace std;

int N, I, M;
pair<int, int> fish[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> I >> M;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> fish[i].first >> fish[i].second; // 물고기 위치잡기
    }
    sort(fish, fish + M); // 높이를 픽스하고 문제를 풀어나가기 위해 소팅함.
    for (int h = 1; h < I / 2; h++)
    {
        int w = I / 2 - h;
        if (h > N - 1 || w > N - 1) // 크기가 변을 넘어가면 종료
            continue;
        for (int i = 0; i < M; i++)
        {
            int y = fish[i].first;
            int x = fish[i].second;
            for (int k = 0; k <= w; k++) // 그물의 너비
            {
                int cnt = 1;
                for (int j = i + 1; j < M; j++)
                {
                    int ny = fish[j].first, nx = fish[j].second;
                    if (ny > y + h)
                        break;
                    if (x - k <= nx && nx <= x - k + w) // 만약 w가 2이면 왼쪽 0 오른쪽2 왼쪽1 오른쪽1 왼쪽2 오른쪽 0 모든 케이스를 고려하기위해 다음과 같은 조건을 작성
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}