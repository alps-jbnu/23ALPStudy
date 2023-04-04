// Baekjoon - 1700번 멀티탭 스케줄링

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> vec[101];  //숫자가 나오는 인덱스 저장
int num[101]; //순서 저장 
bool ismulttap[101];  //멀티탭에 값이 있는지 확인
int ans =0;
vector<int> multtap;  //멀티탭에 꽂힌 숫자 저장 

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;
    for(int i=1; i<=n; i++) {
        cin >> num[i];
        vec[num[i]].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        if(ismulttap[num[i]]) { //값이 멀티탭에 꽂혀있을경우
            vec[num[i]].erase(vec[num[i]].begin());
            continue;
        }
        else {  //값이 멀티탭에 없을 경우
            if(multtap.size() == k) { //멀티탭구의 자리가 없는경우
                int maxpoint = 0;
                int changeidx = -1; //바꿔야할 인덱스
                for(int j=0; j<multtap.size(); j++) {
                    if(vec[multtap[j]].size() == 0){  //이제 안나오는 값 빼기
                        changeidx = j;
                        break;
                    }
                    else { // 그다음 나오는 인덱스가 늦는 값 빼기 
                        if(maxpoint < vec[multtap[j]].front()) {
                            maxpoint = vec[multtap[j]].front();
                            changeidx = j;
                        }
                    }
                }
                ismulttap[multtap[changeidx]] = false;  //뽑기
                multtap.erase(multtap.begin()+ changeidx);

                multtap.push_back(num[i]);  //꽂기
                ismulttap[num[i]] = true;
                vec[num[i]].erase(vec[num[i]].begin());
                ans++;
            }
            else { //자리가 있는 경우
                multtap.push_back(num[i]);
                ismulttap[num[i]] = true;
                vec[num[i]].erase(vec[num[i]].begin());
            }
        }
    }
    cout << ans;

}