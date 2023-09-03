#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

#define MAX 100
using namespace std;
 
int N, Answer;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
vector<pair<int, int> > V;
 
void Make_LandLabel(int a, int b, int L)
{
    queue<pair<int, int> > Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
    MAP[a][b] = L;
 
    while (Q.empty() == 0)   
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (Visit[nx][ny] == false && MAP[nx][ny] == -1)
                {
                    Visit[nx][ny] = true;
                    MAP[nx][ny] = L;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
int bfs(int Num)
{
    int Result = 0;
    queue<pair<int, int> > Q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == Num)
            {
                Visit[i][j] = true;
                Q.push(make_pair(i, j));
            }
        }
    }
 
    while (Q.empty() == 0)
    {
        int S = Q.size();
        for (int i = 0; i < S; i++)
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
 
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
 
                if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                {
                    if (MAP[nx][ny] != 0 && MAP[nx][ny] != Num) return Result;
                    else if (MAP[nx][ny] == 0 && Visit[nx][ny] == false)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        Result++;
    }
}
 
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    Answer = 987654321;
    cin >> N;
    for (int i = 0; i < N; i++)   //입력받기 
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1)
            {
                MAP[i][j] = -1;
                V.push_back(make_pair(i, j));
            }
        }
    }
    
    int Land_Label = 1;
    for (int i = 0; i < V.size(); i++)
    {
        int x = V[i].first;
        int y = V[i].second;
 
        if (Visit[x][y] == false)
        {
            Make_LandLabel(x, y, Land_Label);
            Land_Label++;
        }
    }
 
    for (int i = 1; i < Land_Label; i++)
    {
    	if(Answer > bfs(i))
    		Answer = bfs(i);
        memset(Visit, false, sizeof(Visit));    // Visit 배열 모두 false로 설정  
    }
    cout << Answer << "\n";
 
    return 0;
}
