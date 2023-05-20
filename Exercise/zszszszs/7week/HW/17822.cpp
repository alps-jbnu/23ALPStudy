#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define endl "\n"
#define MAX 50 + 5
using namespace std;

int N, M, T, Sum, Total, Answer, Avre;
int Circle[MAX][MAX];   // 현재 원판을 저장.
int C_Circle[MAX][MAX]; // 원판 회전 시, 임시 저장공간.
bool Visit[MAX][MAX];   // BFS탐색 시, 방문 체크를 위한 Visit 배열.
vector<pair<pair<int, int>, int>> Cmd;

void CopyMAP(int A[][MAX], int B[][MAX])
{
    /* 맵 복사 함수 */
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = B[i][j];
        }
    }
}

void Input()
{
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Circle[i][j];
        }
    }
    Total = N * M;

    for (int i = 0; i < T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Cmd.push_back(make_pair(make_pair(a, b), c));
    }
}

void Turning_Circle(int Idx, int Dir, int K)
{
    /* 원판을 회전시키는 함수
    1. 원판의 상태를 임시 원판에 복사해준다.
    2. 원본의 값들을 이용해서 임시 원판의 값들을 바꿔준다.
    3. 임시 원판을 다시 원본에 복사해준다.
    */
    CopyMAP(C_Circle, Circle);
    if (Dir == 0)
    {
        for (int i = 0; i < M; i++)
        {
            int Value = Circle[Idx][i];
            int Pos = (i + K) % M;
            C_Circle[Idx][Pos] = Value;
        }
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            int Value = Circle[Idx][i];
            int Temp_K = K % M;
            int Pos = i - Temp_K;
            if (Pos < 0)
                Pos = Pos + M;
            C_Circle[Idx][Pos] = Value;
        }
    }
    CopyMAP(Circle, C_Circle);
}

bool BFS(int a, int b)
{
    /* 인접한 값이 있는지 없는지 탐색하는 BFS 함수. */
    queue<pair<int, int>> Q;  // BFS에서 사용할 Queue
    vector<pair<int, int>> V; // 인접한 값들의 위치를 저장할 Vector
    Q.push(make_pair(a, b));
    V.push_back(make_pair(a, b)); // 현재 값은 무조건 넣어주고 시작. (초기사이즈 = 1)
    Visit[a][b] = true;

    while (Q.empty() == 0)
    {
        int C_Num = Q.front().first;
        int Idx = Q.front().second;
        Q.pop();

        int Left_Idx = Idx - 1;       // 같은 원판의 왼쪽 값
        int Right_Idx = Idx + 1;      // 같은 원판의 오른쪽 값
        int Left_Circle = C_Num - 1;  // 왼쪽 원판의 값
        int Right_Circle = C_Num + 1; // 오른쪽 원판의 값

        if (Left_Idx < 0)
            Left_Idx = M - 1;
        if (Right_Idx >= M)
            Right_Idx = Right_Idx % M;

        if (Circle[C_Num][Idx] == Circle[C_Num][Left_Idx])
        {
            if (Visit[C_Num][Left_Idx] == false)
            {
                Visit[C_Num][Left_Idx] = true;
                Q.push(make_pair(C_Num, Left_Idx));
                V.push_back(make_pair(C_Num, Left_Idx));
            }
        }
        if (Circle[C_Num][Idx] == Circle[C_Num][Right_Idx])
        {
            if (Visit[C_Num][Right_Idx] == false)
            {
                Visit[C_Num][Right_Idx] = true;
                Q.push(make_pair(C_Num, Right_Idx));
                V.push_back(make_pair(C_Num, Right_Idx));
            }
        }
        if (Left_Circle > 0)
        {
            if (Circle[C_Num][Idx] == Circle[Left_Circle][Idx])
            {
                if (Visit[Left_Circle][Idx] == false)
                {
                    Visit[Left_Circle][Idx] = true;
                    Q.push(make_pair(Left_Circle, Idx));
                    V.push_back(make_pair(Left_Circle, Idx));
                }
            }
        }
        if (Right_Circle <= N)
        {
            if (Circle[C_Num][Idx] == Circle[Right_Circle][Idx])
            {
                if (Visit[Right_Circle][Idx] == false)
                {
                    Visit[Right_Circle][Idx] = true;
                    Q.push(make_pair(Right_Circle, Idx));
                    V.push_back(make_pair(Right_Circle, Idx));
                }
            }
        }
    }

    if (V.size() == 1) // 크기가 1이다. = 인접한 값들 중 똑같은 값을 가진 놈이 없다.
    {
        return false;
    }
    else // 그게 아니면 인접한 값들 중 똑같은 값을 가진 놈이 있다.
    {
        for (int i = 0; i < V.size(); i++)
        {
            int x = V[i].first;
            int y = V[i].second;
            Circle[x][y] = 0;
        }
        return true;
    }
}

bool Check_Adjacency()
{
    /* 인접한 곳에 같은 값이 있는지 체크하는 함수 */
    memset(Visit, false, sizeof(Visit));
    bool Flag = false;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            /* 모든 좌표를 돌면서,
            1. 아직 방문 하지 않은 좌표이고
            2. 0이 아닌 좌표들에 대해서 탐색 시작.
            */
            if (Visit[i][j] == false && Circle[i][j] != 0)
            {
                bool T = BFS(i, j);
                if (T == true)
                    Flag = true;
            }
        }
    }

    return Flag;
}

void Change_Value(double Avr)
{
    /* 인접한 값이 없을 경우, 나머지 값들을 평균 값에 따라 ++ , -- 해주는 함수 */
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Circle[i][j] == 0)
                continue;
            if ((double)(Circle[i][j]) > Avr)
                Circle[i][j]--;
            else if ((double)(Circle[i][j]) < Avr)
                Circle[i][j]++;
        }
    }
}

pair<int, int> Calculate()
{
    pair<int, int> R;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            R.first = R.first + Circle[i][j];
            if (Circle[i][j] != 0)
                R.second++;
        }
    }
    return R;
}

void Solution()
{
    for (int i = 0; i < T; i++)
    {
        int Num = Cmd[i].first.first;
        int Dir = Cmd[i].first.second;
        int K = Cmd[i].second;

        for (int j = Num; j <= N; j = j + Num)
            Turning_Circle(j, Dir, K);
        bool T = Check_Adjacency();
        if (T == false)
        {
            pair<int, int> Temp = Calculate();
            Temp = Calculate();
            double Average = (double)(Temp.first) / (double)(Temp.second);
            Change_Value(Average);
        }
    }

    Answer = Calculate().first;
}

void Solve()
{
    Input();
    Solution();

    cout << Answer << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
