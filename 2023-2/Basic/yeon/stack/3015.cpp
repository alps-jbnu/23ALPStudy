#include <iostream>
#include <stack>

using namespace std;

//A와 B 두 사람 사이에 A "또는" B보다 키 큰 사람이 존재하지 않으면 됨

int main()
{
    
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);    
    
    int n;
    cin >> n;
    
    stack <pair<int, int>> s; //키(h), 현재 스택에 같은 키를 가진 사람의 수(cnt)
    long long res = 0;
    
    while(n--){
        
        int h; 
        cin >> h; //현재 사람의 키 입력
        
        int cnt = 1; //같은 키를 가진 사람의 수
        
        while(!s.empty() && s.top().first <= h){
            //s.top().first < h인 경우에는스택에 담겨있을 의미가 없음
            
            res += s.top().second;
            
            if(s.top().first == h){
                //같은 키를 가진 경우
                cnt += s.top().second;
            }
            
            s.pop();
        }
        
        
        if(!s.empty()) res++;
        //s.top() > 현재 사람의 키)인 경우 s.top() 너머 사람을 볼 수 없음
        
        s.push({h, cnt}); //현재 사람의 키와 같은 키를 가진 사람의 수 push
    }
    
     cout << res << '\n';
    
    return 0;
}
