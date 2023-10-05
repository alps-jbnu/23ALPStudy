#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        Q.push(i);
    }
    while(Q.size() > 1){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front();
    return 0;
}
