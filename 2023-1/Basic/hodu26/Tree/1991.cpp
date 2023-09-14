#include <bits/stdc++.h>

using namespace std;

vector<int> tree[33];
// int parent[100003];

void traversal_dfs(int cur, string order){
    if (cur == -1) return ;

    char curC = cur+'A';

    if (order == "pre") cout << curC;
    traversal_dfs(tree[cur][0], order);
    if (order == "in") cout << curC;
    traversal_dfs(tree[cur][1], order);
    if (order == "post") cout << curC;
    return ;
}   

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    char node,left,right;

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> node >> left >> right;

        if (left != '.'){
            tree[node-'A'].push_back(left-'A');
        } 
        else {
            tree[node-'A'].push_back(-1);
        }

        if (right != '.'){ 
            tree[node-'A'].push_back(right-'A');
        } 
        else{ 
            tree[node-'A'].push_back(-1);
        }
    }

    traversal_dfs(0,"pre"); cout << '\n';
    traversal_dfs(0,"in"); cout << '\n';
    traversal_dfs(0,"post");

    return 0;
}
