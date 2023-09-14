// Baekjoon - 2457번 공주님의 정원

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<pair<int,int>>& flower1, vector<pair<int,int>>& flower2) { //꽃이 피는 날짜가 앞인 얘 앞으로
    if(flower1[0].first ==flower2[0].first) {
        return flower1[0].second < flower2[0].second;
    }
    return flower1[0].first < flower2[0].first;

}
pair<int,int> maxday(pair<int,int>& day1, pair<int,int>& day2) {
    if(day1.first < day2.first) {
        return day2;
    }
    else if( day1.first == day2.first) {
        if(day1.second < day2.second) return day2;
    }
    return day1;
}

vector<vector<pair<int,int>>> vec;
int n;
int smonth,sday, emonth, eday;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count =0;
    int check =0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> smonth >> sday >> emonth >> eday;
        vector<pair<int,int>> pav;
        pav.push_back(make_pair(smonth,sday));
        pav.push_back(make_pair(emonth,eday));
        vec.push_back(pav);
    }
    sort(vec.begin(), vec.end(), cmp);
    pair<int,int> spoint = {3,1}; //시작을 3월 1일로 둠
    pair<int,int> epoint = {12,1}; //끝을 12월 1일로 둠
    pair<int,int> temp = {1,1};
   
    for(int i=0; i<n; i++) {
        if(maxday(spoint,vec[i][0]) == spoint) {  //spoint와 시작날짜 중 spoint가 더 큰경우
            temp = maxday(temp, vec[i][1]); //spoint보다 먼저 피는 꽃들중 제일 늦게 지는 경우
            if(maxday(temp, epoint) == temp) { //지는 시기가 12월1일이 지난경우 
                check = 1;
                break;
            }
        }
        else {
            spoint = temp; //기준위치를 temp로 바꿈
            count++;
            //기준 위치보다 다음 꽃의 날짜가 앞에 있을 때 
            if(maxday(spoint, vec[i][0]) == spoint) {
                temp = vec[i][1];
                //12월 1일보다 날짜가 뒤일 때
                if(maxday(temp,epoint) == temp) {
                    check = 1;
                    break;
                }
            }
            //기준 위치보다 다음 꽃의 날짜가 뒤에 있을 때 
            else break;
        }
    }
    if(check == 0) { 
        cout <<"0\n";
    }
    else cout << count + 1;
    
    
    
}

