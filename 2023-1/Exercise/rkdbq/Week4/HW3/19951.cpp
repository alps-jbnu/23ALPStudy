#define MAX 100002
#include <iostream>
using namespace std;

int N, M;
int H[MAX];
int arr[MAX];
int cumsum[MAX];

void order(int a, int b, int k) {
    arr[a] += k;
    arr[b+1] -= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    for(int i{1}; i<=N; i++) cin>>H[i];
    for(int i{1}; i<=M; i++) {
        int a, b, k;
        cin>>a>>b>>k;
        order(a,b,k);
    }
    for(int i{1}; i<=N; i++) {
        cumsum[i] = arr[i] + cumsum[i-1];
    }
    for(int i{1}; i<=N; i++) {
        H[i] += cumsum[i];
        cout<<H[i]<<" ";
    }

    return 0;
}