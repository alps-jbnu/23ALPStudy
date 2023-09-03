#define Mildred 0
#define Elsie 1
#define Bessie 2
#include <iostream>
#include <algorithm>
using namespace std;

int milks[3];
int cnt;

class Display {
    public:
    bool displayed[3];
    Display() {
        for(int i{}; i<3; i++) displayed[i] = false;
    }
    bool is_same(Display nxt) {
        bool flag{true};
        for(int i{}; i<3; i++) {
            if(displayed[i] != nxt.displayed[i]) flag = false;
        }
        return flag;
    }
};

Display cur, bef;
void max_check() {
    int cur_max = *max_element(milks, milks+3);
    for(int i{}; i<3; i++) {
        if(milks[i] == cur_max) cur.displayed[i] = true;
        else cur.displayed[i] = false;
    }
    // cout<<bef_max<<","<<bef_cnt<<"\n";
    // cout<<cur_max<<","<<cur_cnt<<"\n";
    if(!cur.is_same(bef)) cnt++;
    for(int i{}; i<3; i++) {
        bef.displayed[i] = cur.displayed[i];
    }
}

class Info {
    public:
    int day;
    int name;
    int change;
    Info(int d, int n, int c) {
        day = d;
        name = n;
        change = c;
    }
    Info() {
        day = 0;
        name = 0;
        change = 0;
    }
};

int N;
Info infos[101];

void init() {
    for(int i{}; i<3; i++) {
        milks[i] = 7;
    }
}

bool cmp(Info a, Info b) {
    return a.day < b.day;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    cin>>N;
    for(int i{}; i<N; i++) {
        int d, c;
        string n;
        cin>>d>>n>>c;
        int name;
        if(n == "Mildred") name = Mildred;
        else if (n == "Elsie") name = Elsie;
        else name = Bessie;
        infos[i] = Info(d, name, c);
    }
    sort(infos, infos+N, cmp);
    for(int i{}; i<N; i++) {
        auto name = infos[i].name;
        auto day = infos[i].day;
        auto change = infos[i].change;
        milks[name] += change;
        // cout<<name<<","<<day<<","<<change<<"\n";
        max_check();
    }

    cout<<cnt;

    return 0;
}