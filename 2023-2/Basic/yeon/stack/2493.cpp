#include <iostream>
#include <stack>

using namespace std;

stack <pair<int, int>> s;

int main()
{
    
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);    
    
    int t;
    cin >> t;
    
    //탑들의 높이
    s.push({100000001, 0});
    
    for(int i=1; i<=t; i++){
        
        int h;
        cin >> h; //높이 입력
        
        while(s.top().first < h) s.pop(); //입력한 높이보다 작을 경우, 수신

        cout << s.top().second << ' '; //수신한 탑의 번호 출력
        
        s.push({h, i}); //높이와 탑의 번호 push
    }
    
    return 0;
}
