#define MAX 1048577
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, k;
int bst[MAX];
set<vector<bool>> s;

void insert_bst(int num, int cur) {
    if(bst[cur] == 0) {
        bst[cur] = num;
        return;
    }
    if(bst[cur] > num) insert_bst(num, cur * 2);
    else insert_bst(num, cur * 2 + 1);
}

vector<bool> binarization(int bst[]) {
    vector<bool> ret;
    for(int i{0}; i<=MAX; i++) {
        ret.push_back(bst[i] != 0);
    }
    return ret;
}

void init(int bst[]) {
    fill(bst, bst+(MAX), 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    for(int i{}; i<n; i++) {
        init(bst);
        for(int j{}; j<k; j++) {
            int num;
            cin>>num;
            insert_bst(num, 1);
        }
        s.insert(binarization(bst));
    }
    cout<<s.size();

    return 0;
}