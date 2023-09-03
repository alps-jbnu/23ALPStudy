#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 10000 + 1;
using namespace std;

int N, L, M;
int result = 0;
vector<pii> vec;

int main()
{
    cin >> N >> L >> M;
    
    for(int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        vec.push_back({ x, y });
    }
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 1; k < L / 2; k++)
            {
                int temp = 0;
                
                for(int l = 0; l < M; l++)
                {
                    if(vec[i].first <= vec[l].first && vec[i].first + k >= vec[l].first)
                    {
                        if(vec[j].second <= vec[l].second && vec[j].second + (L/2 - k) >= vec[l].second) temp++;
                    }
                    result = max(result, temp);
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}