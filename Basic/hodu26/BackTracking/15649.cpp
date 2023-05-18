#include <bits/stdc++.h>

using namespace std;

vector<int> outpt;
int vis[13];

void sequence_recursion(int N, int M, int floor){
    for (int i=1;i<=N;i++){
        if (vis[i]) continue;

        outpt.push_back(i);
        vis[i] = true;

        if (M == floor){
            for (int j=0;j<M;j++){
                cout << outpt[j] << ' ';
            }
            cout << '\n';
        }
        else {
            sequence_recursion(N,M,floor+1);
        }

        outpt.pop_back();
        vis[i] = false;
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M;

    cin >> N >> M;

    sequence_recursion(N,M,1);
    
    return 0;
}
