#include <bits/stdc++.h>

using namespace std;

int parking[101];
bool check[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> charge;
    for(int i = 1; i <= N; i++)
    {
        int R; cin >> R;
        charge.push_back(R);
    }
    vector<int> weight;
    for(int i = 1; i <= M; i++)
    {
        int W; cin >> W;
        weight.push_back(W);
    }
    queue<int> car;
    long long answer = 0;
    for(int i = 1; i <= 2 * M; i++)
    {
        int x; cin >> x;
        if(x < 0)
        {
            if(!car.empty())
            {
                for(int j = 1; j <= N; j++)
                {
                    if(parking[j] == -x)
                    {
                        answer += weight[car.front() - 1] * charge[j - 1];
                        parking[j] = car.front(); car.pop();
                        break;
                    }
                }
            }
            else
            {
                for(int j = 1; j <= N; j++)
                {
                    if(parking[j] == -x)
                    {
                        check[j] = false;
                        break;
                    }
                }
            }
        }
        else
        {
            bool full = true;
            for(int j = 1; j <= N; j++)
            {
                if(!check[j])
                {
                    check[j] = true;
                    answer += weight[x - 1] * charge[j - 1];
                    parking[j] = x;
                    full = false;
                    break;
                }
            }
            if(full)
                car.push(x);
        }
    }
    cout << answer;
    return 0;
}
