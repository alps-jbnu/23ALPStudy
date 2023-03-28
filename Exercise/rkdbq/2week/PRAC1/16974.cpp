#include <iostream>
using namespace std;

class Burger {
    public:
    long long length;
    long long patties;
    Burger(long long l, long long p) {
        length = l;
        patties = p;
    }
    Burger() {
        length = 0;
        patties = 0;
    }
};

long long N, X;
Burger burgers[51];

void init() {
    burgers[0] = Burger(1, 1);
    for(int i{1}; i<51; i++) {
        auto bef = burgers[i-1];
        burgers[i] = Burger(bef.length*2+3, bef.patties*2+1);
    }
}

long long find(long long n, long long x) {
    if(n==0) return burgers[0].patties;
    if(x==0) return 0;
    else if(x<((burgers[n].length-1)/2)) return find(n-1, x-1);
    else if(x==((burgers[n].length-1)/2)) return burgers[n-1].patties + 1;
    else if(x<(burgers[n].length-1)) return burgers[n-1].patties + 1 + find(n-1, x-(burgers[n].length-1)/2-1);
    else return burgers[n-1].patties * 2 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin>>N>>X;
    cout<<find(N, X-1);
    
    return 0;
}