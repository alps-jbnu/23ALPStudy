#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;
vector<int> vec;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num; cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    
    int temp;
    while(1)
    {
        temp = vec.size();
        if(temp == 1) break;
        
        vec[temp - 2] += vec[temp - 1];
        vec.pop_back();
        
        vec[0]--; cnt++;
        if(!vec[0]) 
        {
            for(int i = 1; i < temp; i++)
            {
                vec[i - 1] = vec[i];
            }
            vec.pop_back();
        }
    }
    
    cout << cnt;
    
    return 0;
}