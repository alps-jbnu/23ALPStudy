#include <iostream>
#include <vector>
using namespace std;

int total;
vector<int> gt;

void find(vector<int> ans, int correct) {
    if(ans.size()>=3) {
        if(ans[ans.size()-1] == ans[ans.size()-2] && ans[ans.size()-2] == ans[ans.size()-3]) return;
    }

    if(ans.size() == 10) {
        if(correct >= 5) total++;
        return;
    }

    vector<int> nxtAns;
    for(int i{}; i<(int)ans.size(); i++) {
        nxtAns.push_back(ans[i]);
    }
    for(int i{}; i<5; i++) {
        nxtAns.push_back(i);
        if(nxtAns[nxtAns.size()-1] == gt[nxtAns.size()-1]) {
            find(nxtAns, correct+1);
        }
        else {
            find(nxtAns, correct);
        }
        nxtAns.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i{}; i<10; i++) {
        int ans;
        cin>>ans;
        gt.push_back(ans-1);
    }

    vector<int> ans;
    find(ans, 0);

    cout<<total;

    return 0;
}