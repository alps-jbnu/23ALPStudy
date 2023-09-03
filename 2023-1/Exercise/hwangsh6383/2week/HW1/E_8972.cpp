#include <bits/stdc++.h>

using namespace std;

int R, C;
pair<int, int> arduino;
vector<pair<int,int>> crazyArduino;
char board[101][101];
bool check[101][101];

int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool moveArduino(int n) {
    arduino.first += dx[n];
    arduino.second += dy[n];
    for(int j = 0; j < crazyArduino.size(); j++)
    {
        if(crazyArduino[j] == arduino)
            return true;
    }
    vector<pair<int, int>> needBoom;
    for(int i = 0; i <= 100; i++)
        fill(check[i], check[i] + 100, false);
    for(int j = 0; j < crazyArduino.size(); j++)
    {
        pair<int, int> temp = {-1, 200};
        for (int k = 0; k < 9; k++)
        {
            int nx = crazyArduino[j].first + dx[k];
            int ny = crazyArduino[j].second + dy[k];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            int val = abs(arduino.first - nx) + abs(arduino.second - ny);
            if (temp.second > val)
            {
                temp = make_pair(k, val);
            }
        }
        crazyArduino[j].first += dx[temp.first];
        crazyArduino[j].second += dy[temp.first];
        if(check[crazyArduino[j].first][crazyArduino[j].second])
        {
            needBoom.push_back(make_pair(crazyArduino[j].first, crazyArduino[j].second));
        }
        check[crazyArduino[j].first][crazyArduino[j].second] = true;
    }
    for(int j = 0; j < crazyArduino.size(); j++)
    {
        if(crazyArduino[j] == arduino)
            return true;
    }
    for(int j = 0; j < needBoom.size(); j++)
    {
        check[needBoom[j].first][needBoom[j].second] = false;
        if(find(crazyArduino.begin(), crazyArduino.end(), needBoom[j]) != crazyArduino.end())
        {
            crazyArduino.erase( std::remove( crazyArduino.begin(), crazyArduino.end(), needBoom[j] ), crazyArduino.end() );
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'I')
                arduino = make_pair(i, j);
            else if(board[i][j] == 'R')
                crazyArduino.push_back(make_pair(i, j));
        }
    }
    string s; cin >> s;
    int count = 0;
    for(int i = 0; i < s.length(); i++)
    {
        count++;
        if(s[i] == '1')
        {
            if(moveArduino(0))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '2')
        {
            if(moveArduino(1))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '3')
        {
            if(moveArduino(2))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '4')
        {
            if(moveArduino(3))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '5')
        {
            if(moveArduino(4))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '6')
        {
            if(moveArduino(5))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '7')
        {
            if(moveArduino(6))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '8')
        {
            if(moveArduino(7))
            {
                cout << "kraj " << count;
                break;
            }
        }
        else if(s[i] == '9')
        {
            if(moveArduino(8))
            {
                cout << "kraj " << count;
                break;
            }
        }
        if(i == s.length() - 1)
        {
            for(int j = 0; j < R; j++)
            {
                for(int k = 0; k < C; k++)
                {
                    if(check[j][k])
                        cout << 'R';
                    else if(j == arduino.first && k == arduino.second)
                        cout << 'I';
                    else
                        cout << '.';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
