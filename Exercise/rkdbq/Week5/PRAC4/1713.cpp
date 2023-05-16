#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Info {
    public:
    int num;
    int rec;
    int date;
    Info() {

    }
    Info(int n, int r, int d) {
        num = n;
        rec = r;
        date = d;
    }
};

int n;
Info pics[21];
int rec_num;
int rec[1001];

vector<int> ans;

bool is_full() {
    for(int i{}; i<n; i++) {
        if(pics[i].num == -1) return false;
    }
    return true;
}

int pop() {
    int idx{};
    for(int i{1}; i<n; i++) {
        if(pics[idx].rec > pics[i].rec) idx = i;
        else if(pics[idx].rec == pics[i].rec) {
            if(pics[idx].date > pics[i].date) idx = i;
        }
    }
    pics[idx] = Info(-1, -1, -1);
    return idx;
}

void do_rec(int num, int date) {
    bool flag{false};
    for(int i{}; i<n; i++) {
        if(pics[i].num == num) {
            pics[i].rec++;
            flag = true;
            break;
        }
    }
    if(!flag) {
        if(is_full()) {
            int idx{pop()};
            pics[idx] = Info(num, 1, date);
        }   
        else {
            for(int i{}; i<n; i++) {
                if(pics[i].num == -1) {
                    pics[i] = Info(num, 1, date);
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    cin>>rec_num;
    for(int i{}; i<n; i++) {
        pics[i] = Info(-1, -1, -1);
    }
    for(int i{}; i<rec_num; i++) {
        cin>>rec[i];
    }
    for(int i{}; i<rec_num; i++) {
        do_rec(rec[i], i);
    }
    for(int i{}; i<n; i++) {
        if(pics[i].num != -1) ans.push_back(pics[i].num);
    }
    sort(ans.begin(), ans.end());
    for(int i{}; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}