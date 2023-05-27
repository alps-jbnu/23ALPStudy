#include<iostream>
#include<vector>
using namespace std;
int n;
int lc[30];
int rc[30];

void preorder(int cur){
    cout << char(cur+'A'-1);
    if(lc[cur] !=0) preorder(lc[cur]);
    if(rc[cur] !=0) preorder(rc[cur]);
}
void inoreder(int cur){
    if(lc[cur] !=0) inoreder(lc[cur]);
    cout << char(cur+'A'-1);
    if(rc[cur] !=0) inoreder(rc[cur]);
}
void postoreder(int cur){
    if(lc[cur] !=0) postoreder(lc[cur]);
    if(rc[cur] !=0) postoreder(rc[cur]);
    cout << char(cur+'A'-1);
    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i =1; i<=n; i++){
        char c,l,r;
        cin >> c>> l>>r;
        if(l!='.') lc[c-'A'+1]  = l-'A'+1;
        if(r!='.') rc[c-'A'+1]  = r-'A'+1;
    }
    preorder(1); cout << "\n";
    inoreder(1); cout << "\n";
    postoreder(1); cout << "\n";
    
}
