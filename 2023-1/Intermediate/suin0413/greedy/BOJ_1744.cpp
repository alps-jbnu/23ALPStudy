#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
    vector<int> p, m;
    for(int i = 0 ; i < n; i++){
        int c; cin >> c;
        if(c > 0) p.push_back(c);
        else m.push_back(c); 
    }
 
    sort(p.begin(), p.end(), greater<>());    // 양수는 내림차순으로 정렬
    sort(m.begin(), m.end());    // 음수는 오름차순으로 정렬
    
    int ans = 0;
    if(p.size() % 2 != 0) ans += p[p.size() - 1];   // 양수가 홀수개인 경우 마지막 요소를 더해준다.
    for(int i = 0; i < (int) p.size() - 1;){
        if(p[i + 1] == 1) ans += p[i] + p[i + 1];
        else if(p[i + 1] > 0) ans += p[i] * p[i + 1];   // 양수인 경우
        i+=2;
    }
 
    if(m.size() % 2 != 0) ans += m[m.size() - 1];   // 0 이하의 숫자가 홀수개인 경우 마지막 요소를 더해준다.
    for(int i = 0; i < (int) m.size() - 1; i+=2)
        ans+= m[i] * m[i + 1];  
 
    cout << ans << "\n";    
    }
