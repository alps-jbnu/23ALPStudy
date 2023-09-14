// Baekjoon - 2170번 선긋기

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector <pair<int,int>> vec;
int n;
int stpoint, endpoint;
pair<int,int> input;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input.first >> input.second;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    stpoint = vec[0].first;
    endpoint = vec[0].second;

    for(int i=1; i<=n; i++) {
        if(i==n) { // 마지막이면 값 더하기 
            ans += (endpoint-stpoint);
            break;
        }
        if(endpoint>= vec[i].first) {  //이어서 그리기
            endpoint = max(endpoint,vec[i].second);
        }
        else { //떼서 그리기
            ans += (endpoint-stpoint);
            stpoint = vec[i].first;
            endpoint = vec[i].second;
        }
    }
    cout << ans;
    
}