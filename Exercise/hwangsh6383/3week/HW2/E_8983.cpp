#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> animals;
vector<int> guns;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, L; cin >> M >> N >> L;
    for(int i = 0; i < M; i++)
    {
        int x; cin >> x;
        guns.push_back(x);
    }
    sort(guns.begin(), guns.end());
    for(int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        animals.push_back(make_pair(x, y));
    }
    int answer = 0;
    for(auto animal : animals)
    {
        int start = 0, end = M - 1;
        while(start<=end)
        {
            int mid = (start + end) / 2;
            if(L >= abs(guns[mid] - animal.first) + animal.second)
            {
                answer++;
                break;
            }
            if(guns[mid] <= animal.first)
                start = mid + 1;
            else end = mid - 1;
        }
    }
    cout << answer;
    return 0;
}
