#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    char bef;
    for(int i{}; i<N; i++) {
        char cur;
        cin>>cur;
        if(bef != cur) cnt++;
        bef = cur;
    }
    cout<<cnt/2+1;

    return 0;
}