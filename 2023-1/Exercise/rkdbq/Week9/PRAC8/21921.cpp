#define MAX 250001
#include <iostream>
using namespace std;

int N, X;
long long cumsum[MAX];

long long most_vis;
int most_vis_cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>X;
    for(int i{1}; i<=N; i++) {
        int vis;
        cin>>vis;
        cumsum[i] = cumsum[i-1]+vis;
    }
    for(int i{X}; i<=N; i++) {
        auto cur{cumsum[i] - cumsum[i-X]};
        if(most_vis<cur) {
            most_vis = cur;
            most_vis_cnt = 1;
        }
        else if(most_vis==cur) {
            most_vis_cnt++;
        }
    }

    if(most_vis > 0) {
        cout<<most_vis<<"\n";
        cout<<most_vis_cnt<<"\n";
    }
    else cout<<"SAD\n";

    return 0;
}