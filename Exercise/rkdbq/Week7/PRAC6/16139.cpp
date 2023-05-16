#define MAX 200001
#include <iostream>
using namespace std;

int cumsum[MAX][27];
string S;
int q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>S;
    cin>>q;

    cumsum[0][S[0]-'a'] = 1;
    for(int i{1}; i<S.length(); i++) {
        for(int j{}; j<27; j++) {
            if(S[i]-'a' == j) cumsum[i][j] = cumsum[i-1][j] + 1;
            else cumsum[i][j] = cumsum[i-1][j];
        }
    }

    // for(int i{}; i<S.length(); i++) {
    //     cout<<cumsum[i][0]<<" ";
    // }

    for(int i{}; i<q; i++) {
        char a;
        int l, r;
        cin>>a>>l>>r;

        if(l!=0) {
            cout<<cumsum[r][a-'a'] - cumsum[l-1][a-'a']<<"\n";
        }
        else {
            cout<<cumsum[r][a-'a']<<"\n";
        }
    }

    return 0;
}