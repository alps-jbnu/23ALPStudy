#include <bits/stdc++.h>

using namespace std;

vector<int> inpt;
int seq[13];

void sequence_recursion(int N, int M, int floor, int cur){

    for (int i=cur;i<(int)inpt.size();i++){

        seq[floor] = inpt[i];

        if (floor == M){
            for (int j=1;j<=M;j++){
                cout << seq[j] << ' ';
            }
            cout << '\n';
        }
        else {
            sequence_recursion(N,M,floor+1,i);
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,a;

    cin >> N >> M;

    for (int i=0;i<N;i++){
        cin >> a;
        inpt.push_back(a);
    }

    sort(inpt.begin(),inpt.end());

    inpt.erase(unique(inpt.begin(),inpt.end()),inpt.end());

    sequence_recursion(N,M,1,0);
    
    return 0;
}
