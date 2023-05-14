#include <bits/stdc++.h>

using namespace std;

vector<int> goParty[53]; // adjacency list 인접 리스트
vector<int> parties[53]; // adjacency list 인접 리스트
bool tellTruth[53];
bool truthParty[53];

stack<int> knowTruth;

void chkParty_dfs(int person){

    for (int party : goParty[person]){

        if (!truthParty[party]){
            truthParty[party] = true;
            
            for (int nxt : parties[party]){
                if (!tellTruth[nxt]){
                    tellTruth[nxt] = true;
                    chkParty_dfs(nxt);
                }
            }
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,knows,know,come,person,top, ans=0;

    cin >> N >> M;
    cin >> knows;

    while (knows--){
        cin >> know;
        knowTruth.push(know);
    }

    for (int party=1;party<=M;party++){
        cin >> come;

        while (come--){
            cin >> person;

            goParty[person].push_back(party);
            parties[party].push_back(person);
        }
    }

    while(!knowTruth.empty()){
        top = knowTruth.top();
        if (!tellTruth[top]){
            tellTruth[top] = true;
            chkParty_dfs(top);
        }
        knowTruth.pop();
    }

    for (int i=1;i<=M;i++){
        if (!truthParty[i]) ans++;
    }

    cout << ans;

    return 0;
}
