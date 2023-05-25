#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cost[10001]; // i번째 작업의 작업 소요 시간
int end_time[10001]; // i번째 작업이 끝나는 시간 기록
vector<int> pre_idx[10001]; // i번째 작업의 선행 작업 

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        int cnt;
        cin >> cnt; // i번째 작업의 선행 작업 개수
        for (int j = 1; j <= cnt; j++) {
            int tmp;
            cin >> tmp;
            pre_idx[i].push_back(tmp);
        }
    }

    for (int i = 1; i <= N; i++) {
        int cur = 0;
        for (int j = 0; j < pre_idx[i].size(); j++) // 현재 작업의 선행 작업 중 가장 늦게 끝나는 작업 시간 구하기
            cur = max(cur, end_time[pre_idx[i][j]]);
        end_time[i] = cur + cost[i];
    }

    int res = 0; //결과 구하기
    for (int i = 1; i <= N; i++)
        res = max(res, end_time[i]);

    cout << res;
}
