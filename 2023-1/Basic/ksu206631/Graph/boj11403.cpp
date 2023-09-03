#include <iostream>
#define m 101

using namespace std;

int n;
int adj[m][m];
void flo(){
    for(int k = 1; k<=n; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
                if(adj[i][k] && adj[k][j])
                    adj[i][j] =1;
    return;
            
}

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> adj[i][j];
        }
    }
    flo();
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
    
}

