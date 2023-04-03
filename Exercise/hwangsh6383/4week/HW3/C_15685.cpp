#include <bits/stdc++.h>

using namespace std;

bool check[101][101];

void func(int x, int y, vector<int>& direct, int count) {
    if(count == 0)
    {
        return;
    }
    for(int i = direct.size() - 1; i >= 0; i--)
    {
        if(direct[i] == 0)
        {
            direct.push_back(1);
            y -= 1;
            if(y < 0) continue;
        }
        else if(direct[i] == 1)
        {
            direct.push_back(2);
            x -= 1;
            if(x < 0) continue;
        }
        else if(direct[i] == 2)
        {
            direct.push_back(3);
            y += 1;
            if(y > 100) continue;
        }
        else
        {
            direct.push_back(0);
            x += 1;
            if(x > 100) continue;
        }
        check[x][y] = true;
    }
    func(x, y, direct, count - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<pair<int,int>, pair<int,int>>> input;
    for(int i = 0; i < N; i++)
    {
        int x, y, d, g; cin >> x >> y >> d >> g;
        input.push_back(make_pair(make_pair(x,y), make_pair(d, g)));
    }
    for(int i = 0; i < N; i++)
    {
        vector<int> direct; direct.push_back(input[i].second.first);
        int x = input[i].first.first, y = input[i].first.second;
        check[x][y] = true;
        if(input[i].second.first == 0)
        {
            check[x + 1][y] = true;
            func(x + 1, y, direct, input[i].second.second);
        }
        else if(input[i].second.first == 1)
        {
            check[x][y - 1] = true;
            func(x, y - 1, direct, input[i].second.second);
        }
        else if(input[i].second.first == 2)
        {
            check[x - 1][y] = true;
            func(x - 1, y, direct, input[i].second.second);
        }
        else
        {
            check[x][y + 1] = true;
            func(x, y + 1, direct, input[i].second.second);
        }
    }

    int answer = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0 ; j < 100; j++)
        {
            if(check[i][j] && check[i][j + 1] && check[i + 1][j] && check[i + 1][j + 1])
                answer++;
        }
    }
    cout << answer;
    return 0;
}
