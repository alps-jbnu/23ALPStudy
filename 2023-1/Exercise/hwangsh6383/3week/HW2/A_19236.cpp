#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> fish[4];
int answer = 0;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

void sharkFishMove(int x, int y, int value) {
    value += fish[x][y].first;
    fish[x][y].first = -1;

    for(int i = 1; i <= 16; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(fish[j][k].first == i)
                {
                    for(int m = 0; m <= 7; m++)
                    {
                        int nx = j + dx[(fish[j][k].second - 1 + m) % 8];
                        int ny = k + dy[(fish[j][k].second - 1 + m) % 8];
                        if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
                        if(fish[nx][ny].first == -1) continue;
                        auto temp = fish[nx][ny];
                        fish[nx][ny] = fish[j][k];
                        fish[nx][ny].second = (fish[j][k].second -1 + m) % 8 + 1;
                        fish[j][k] = temp;
                        break;
                    }
                    j = 4; break;
                }
            }
        }
    }
    fish[x][y].first = 0;
    int tempdx = dx[fish[x][y].second - 1];
    int tempdy = dy[fish[x][y].second - 1];
    vector<pair<int,int>> fishBackup[4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            fishBackup[i].push_back(fish[i][j]);
        }
    }
    while(true)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                fish[i][j] = fishBackup[i][j];
            }
        }
        x += tempdx;
        y += tempdy;
        if(x < 0 || y < 0 || x >= 4 || y >= 4)
        {
            answer = max(answer, value);
            return;
        }
        else
        {
            if(fish[x][y].first == 0) continue;
            sharkFishMove(x, y, value);
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int a, b; cin >> a >> b;
            fish[i].push_back(make_pair(a,b));
        }
    }
    sharkFishMove(0, 0, 0);
    cout << answer;
    return 0;
}
