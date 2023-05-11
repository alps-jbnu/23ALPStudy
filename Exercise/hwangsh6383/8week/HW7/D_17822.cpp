#include <iostream>
#include <deque>
#include <queue>

using namespace std;

deque<int> circles[51];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T; cin >> N >> M >> T;
    int answer = 0;
    int count = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            int n; cin >> n;
            answer += n;
            count += 1;
            circles[i].push_back(n);
        }
    }
    for(int i = 0; i < T; i++)
    {
        int x, d, k; cin >> x >> d >> k;
        for(int j = 1; j * x <= N ; j++)
        {
            int circleNum = x * j;
            for(int m = 0; m < k; m++)
            {
                if(d)
                {
                    circles[circleNum].push_back(circles[circleNum].front());
                    circles[circleNum].pop_front();
                }
                else
                {
                    circles[circleNum].push_front(circles[circleNum].back());
                    circles[circleNum].pop_back();
                }
            }
        }
        int countStore = count;
        for(int j = 1; j <= N; j++)
        {
            for(int m = 0; m < M; m++)
            {
                if(circles[j][m] != 0)
                {
                    int val = circles[j][m];
                    queue<pair<int,int>> q;
                    q.push(make_pair(j, m));
                    bool findsame = false;
                    while(!q.empty())
                    {
                        auto cur = q.front(); q.pop();
                        for(int l = 0; l < 4; l++)
                        {
                            int nx = cur.first + dx[l];
                            int ny = cur.second + dy[l];
                            if(ny == -1) ny = M - 1;
                            else if(ny == M) ny = 0;
                            if(nx < 1 || ny < 0 || nx > N || ny >= M) continue;
                            if(circles[nx][ny] != val) continue;
                            if(!findsame)
                            {
                                answer -= val;
                                count -= 1;
                                circles[cur.first][cur.second] = 0;
                            }
                            findsame = true;
                            circles[nx][ny] = 0;
                            answer -= val;
                            count -= 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        if(countStore == count)
        {
            double aver = answer /(double)count;
            for(int l = 1; l <= N; l++) {
                for (int n = 0; n < M; n++) {
                    if (circles[l][n] != 0) {
                        if(aver < circles[l][n])
                        {
                            circles[l][n]--;
                            answer--;
                        }
                        else if(aver > circles[l][n])
                        {
                            circles[l][n]++;
                            answer++;
                        }
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}
