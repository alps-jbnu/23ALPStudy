#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<int> sh[n + m];
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            sh[i + n].push_back(x - 1);
            sh[x - 1].push_back(i + n);
        }
    }
    
    queue<int> que;
    int shvi[n + m];
    for(int i = 0; i < n + m; i++)
    {
        shvi[i] = -1;
    }
    
    shvi[0] = 1;
    que.push(0);
    
    while(1)
    {
        if(que.empty())
        {
            if(shvi[n - 1] == -1)
                cout << -1 << endl;
            else
                cout << shvi[n - 1] / 2 + 1 << endl;
            exit(0);
        }
        else
        {
            int current = que.front();
            que.pop();
            
            for(int i = 0; i < sh[current].size(); i++)
            {
                if(shvi[sh[current][i]] == -1)
                {
                    shvi[sh[current][i]] = shvi[current] + 1;
                    que.push(sh[current][i]);
                }
            }
        }
    }
}
