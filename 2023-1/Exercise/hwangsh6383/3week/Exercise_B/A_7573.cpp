#include <bits/stdc++.h>

using namespace std;

bool check[10001][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, I, M; cin >> N >> I >> M;

    vector<pair<int,int>> fish;
    for(int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        fish.push_back(make_pair(x, y));
        check[x][y] = true;
    }

    vector<pair<int,int>> rect;
    for(int i = 1; i < I; i++)
    {
        if(i * 2 >= I) break;
        rect.push_back(make_pair(i, (I - 2 * i) / 2));
    }

    int answer = 0;
    for(auto f : fish)
    {
        for(auto r : rect)
        {
            for(int i = f.first - r.first; i <= f.first; i++)
            {
                if(i < 1 || i + r.first > N) continue;
                for(int j = f.second - r.second; j <= f.second; j++)
                {
                    if(j < 1 || j + r.second > N) continue;
                    int count = 0;
                    for(int k = i; k <= i + r.first; k++)
                    {
                        for(int m = j; m <= j + r.second; m++)
                        {
                            if(check[k][m]) count++;
                        }
                    }
                    answer = max(answer, count);
                }
            }
        }
    }

    cout << answer;
    return 0;
}
