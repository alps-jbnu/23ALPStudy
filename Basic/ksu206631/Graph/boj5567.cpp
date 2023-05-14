#include <iostream>
#include <vector>

using namespace std;

const int m = 502;

vector<int> f[m];
bool fl[m];

void ff(int n){
    for(int i = 0; i<f[n].size(); i++){
        int next = f[n][i];
        fl[next] = true;
    }
    if(n==1){
        for(int i = 0; i<f[n].size(); i++){
            int next = f[n][i];
            ff(next);
        }
    }
}

int main(void){
    int n,m;
    cin >>n >> m;
    for(int i  = 0; i<m; i++){
        int a, b;
        cin >> a>> b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    ff(1);
    int cnt = 0;
    for(int i = 2; i<=n; i++)
        if(fl[i])
            cnt++;
    
    cout << cnt <<"\n";
    return 0;
    
}
