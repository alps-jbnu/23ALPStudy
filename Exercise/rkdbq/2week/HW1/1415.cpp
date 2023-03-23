#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool isPrime[500001];
int candies[500001];
long long cases[500001];

void init() {
    for(int i{2}; i<500001; i++) isPrime[i] = true;
    for(int i{2}; i<500001; i++) {
        for(int j{i*2}; j<500001; j+=i) {
            isPrime[j] = false;
        }
    }
}

void update(int n, int iter) {
    long long cur[500001];
    for(int i{}; i<500001; i++) cur[i] = cases[i];
    for(int i{}; i<500001; i++) {
        if(cur[i] > 0 || i == 0) {
            for(int j{1}; j<=iter; j++) {
                cases[i+n*j] += cur[i];
                if(i == 0) cases[i+n*j] += 1;
            }
        }
    }
}

long long answer() {
    long long ret = 0;
    for(int i{}; i<500001; i++) {
        if(isPrime[i]) ret += cases[i];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin>>N;
    for(int i{}; i<N; i++) {
        cin>>candies[i];
    }
    sort(candies, candies+N);

    int cnt = 1;
    for(int i{}; i<N; i++) {
        if(candies[i] != candies[i+1]) {
            update(candies[i], cnt);
            cnt = 1;
        }
        else {
            cnt += 1;
        }
    }
    cout<<answer();

    return 0;
}