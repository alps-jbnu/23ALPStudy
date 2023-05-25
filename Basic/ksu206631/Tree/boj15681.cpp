#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100001];//인접 리스트 표현...
bool vis[100001] = {false, };
int num[100001];//서브트리 저장 배열
int node, q,s,e;
int dfs(int n){
    if(num[n]!=0) return num[n];//n노드의 서브트리의 크기가 계산된경우 처리->중복 계산을 피하기 위함.
    vis[n] = true;//방문 표시
    int ret = 1;//서브 트리의 크기를 나타내는 변수
    for(int i = 0; i< v[n].size();i++){
        int next = v[n][i];//다음 인접 노드 저장.
        if(vis[next]) continue;//이미 방문한 경우 스킵.
        ret+=dfs(next);
    }
    num[n] = ret;//서브트리의 크기를 저장하는 과정임.
    return ret;
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int root;
    cin >> node >> root>>q;
    for(int i =0; i< node-1;i++){//node-1만큼 반복하는 이유는 -> 트리의 간선의 개수는 노드수보다 항상 하나 작기 때문임.
        cin >>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
        
    }
    num[root] = dfs(root);
    for(int i =0; i<q; i++){
        cin >>s;
        cout << num[s]<<"\n";
        
    }
    return 0;
}
