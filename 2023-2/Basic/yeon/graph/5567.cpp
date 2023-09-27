#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//자신의 친구와 친구의 친구 초대 가능
//상근이의 학번은 1

int n, m, a, b; //동기 수, 리스트의 길이, 친구 관계 a,b
vector <int> v[501];
bool visit[501];
int cnt = 0; 

void dfs(){
    
    stack <int> s;
    s.push(1);
    
    while(!s.empty()){
        
        int cur = s.top();
        s.pop();
        visit[cur] = true; //방문 표시
        
        for(auto x: v[cur]){
            
            if(visit[x]) continue; //이미 방문했을 경우
            
            visit[x] = true; //방문 표시
            cnt++;
            
            if(cur == 1) s.push(x); //상근이의 이웃만 스택에 추가
        }
    }
}

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    while(m--){
        //그래프 입력
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs();
    
    cout << cnt << '\n';

    return 0;
}
