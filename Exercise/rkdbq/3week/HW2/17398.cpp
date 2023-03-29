#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, Q;
vector<pair<int, int>> links;
bool q_check[100001];
vector<int> queries;
int parents[100001];
long long sizes_[100001];

void init() {
    for(int i{}; i<100001; i++) {
        parents[i] = i;
        sizes_[i] = 1;
    }
}

int find(int x) {
    if(parents[x] == x) return parents[x];
    else {
        int root = find(parents[x]);
        parents[x] = root;
        return root;
    }
}

bool union_(int x, int y) {
    int root_of_x = find(x);
    int root_of_y = find(y);

    if(root_of_x == root_of_y) return false;

    if(root_of_x < root_of_y) {
        parents[root_of_y] = root_of_x;
        sizes_[root_of_x] += sizes_[root_of_y];
    }
    else {
        parents[root_of_x] = root_of_y;
        sizes_[root_of_y] += sizes_[root_of_x];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    cin>>N>>M>>Q;
    for(int i{}; i<M; i++) {
        pair<int, int> link;
        cin>>link.first>>link.second;
        links.push_back(link);
    }
    for(int i{}; i<Q; i++) {
        int query;
        cin>>query;
        q_check[query-1] = true;
        queries.push_back(query-1);
    }
    for(int i{}; i<M; i++) {
        if(!q_check[i]) {
            union_(links[i].first, links[i].second);
        }
    }
    reverse(queries.begin(), queries.end());
    long long ans = 0;
    for(int i{}; i<Q; i++) {
        auto link = links[queries[i]];
        pair<int, int> root = {find(link.first), find(link.second)};
        pair<long long, long long> size_ = {sizes_[root.first], sizes_[root.second]};
        if(union_(link.first, link.second)) {
            ans += (size_.first * size_.second);
        }
    }

    cout<<ans;

    return 0;
}