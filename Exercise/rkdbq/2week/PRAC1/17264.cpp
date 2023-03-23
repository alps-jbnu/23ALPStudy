#include <iostream>
#include <vector>
using namespace std;

int N, P;
int W, L, G;
vector<string> hacked;
vector<string> match;

int point;

bool search(string key) {
    for(int i{}; i<hacked.size(); i++) {
        if (hacked[i] == key) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>P;
    cin>>W>>L>>G;

    for(int i{}; i<P; i++) {
        string key;
        string info;
        cin>>key>>info;
        // cout<<"\n";
        // cout<<"key: "<<key<<"\n";
        // cout<<"info: "<<info<<"\n";
        if(info[0] == 'W') hacked.push_back(key);
        // cout<<hacked.size()<<"\n";
    }
    for(int i{}; i<N; i++) {
        string key;
        cin>>key;
        match.push_back(key);
    }

    for(int i{}; i<N; i++) {
        auto cur = match[i];
        if(search(cur)) {
            point += W;
        }
        else {
            point -= L;
            if(point<0) point = 0;
        }
        
        // cout<<point<<"\n";
        if(point>= G) break;
    }

    if(point>=G) cout<<"I AM NOT IRONMAN!!";
    else cout<<"I AM IRONMAN!!";

    return 0;
}