#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie();

    stack<int> buildings;
    stack<pair<int,int>> see;                 // taller buildings  // <hight, canSee>

    int N,h,top,s,canSee = 0;
    long long int sumSee = 0;                     // ** 최대 80000 ~ 1 까지의 합이 들어가야함

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> h;
        buildings.push(h);
    }

    see.push(make_pair(buildings.top(),canSee));
    buildings.pop();

    while (!buildings.empty()){
        top = buildings.top();
        buildings.pop();

        if (top <= see.top().first){
            canSee = 0;
            see.push(make_pair(top,canSee));
        }
        else {
            canSee = see.top().second + 1;                      // calc smaller buildings
            sumSee += canSee;
            see.pop();

            while (!see.empty() && top > see.top().first){     // check with taller buildings
                canSee += see.top().second +1;
                sumSee += see.top().second +1;

                see.pop();
            }
            see.push(make_pair(top, canSee));
        }
    }

    cout << sumSee;

    return 0;
}
