#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> v[101];
vector<string> str; //순서 인덱스를 문자열로 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    int a;
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a;
           v[i].push_back(a);
        }
        vector<int> temp ={ v[i].begin(), v[i].end()}; // v[i] 벡터를 temp 벡터에 복사
        sort(temp.begin(),temp.end()); //정렬 
        string a="";
        for(int k=0; k<n; k++) {
            int num = lower_bound(temp.begin(),temp.end(), v[i][k]) - temp.begin(); //순서 인덱스 확인
            a+=to_string(num);
        }
        str.push_back(a);
    }
    sort(str.begin(), str.end()); //정렬
    int ans =0;
    for(int i=0; i<str.size()-1; i++) { //이중 for 문을 통해 같은 쌍 확인
        for(int j=i+1; j<str.size(); j++) {
            if(str[i]== str[j]) ans++;
        }
    }
    cout << ans;

}