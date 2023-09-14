#include <bits/stdc++.h>
using namespace std;

int n, st, ed, tmp;
long long ans;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;
    vector<pair<int,int>> v(n,{0,0});

    for(int i = 0; i < n; i++){
        cin >> st >> ed;
        if(st > ed){ //x, y가 각각 시작점, 끝점이라는 보장 없음
            st = tmp;
            st = ed;
            ed = tmp;
        }
        v[i] = {st,ed};
    }

    sort(v.begin(),v.end());
    st = v[0].first;
    ed = v[0].second;

    for(int i = 1; i < n; i++){
        if(ed > v[i].first){
            if(v[i].second > ed) ed = v[i].second;
        }else{
            ans += ed-st;
            st = v[i].first;
            ed = v[i].second;
        }
    }

    ans += ed - st;
    cout << ans;
}

/*
벡터로 받아 정렬해서 
1. first 값보다 ed가 크면 겹치는 선분이 있음
2. second 값보다 ed가 작다면 second 값을 가진 선분이 더 크다는 의미로
두 조건 동시에 만족하면 업데이트해 줌
만일 second 값보다 ed가 크다면 더 작은 선분이기 때문에 넘어감
first 값보다 ed가 작다면 겹치는 게 없다는 뜻
이때는 ed-st를 길이로 저장하고 해당 선분의 값을 st, ed로 설정
남은 선분 길이 계산해서 더하기
*/