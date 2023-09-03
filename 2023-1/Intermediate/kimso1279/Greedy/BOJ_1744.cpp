#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> p,m; // 양수, 음수
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        if(c > 0) p.push_back(c);
        else m.push_back(c);
    }
    sort(p.begin(), p.end(), greater<>()); // 내림차순으로 정렬
    sort(m.begin(), m.end());

    int sum = 0;

    if(p.size() % 2 != 0) sum += p[p.size()-1];
    for(int i=0; i < (int) p.size()-1; i+=2){
        if(p[i+1] == 1) sum += p[i] + p[i+1];
        else if(p[i+1] > 0) sum += p[i] * p[i+1];
    }

    if(m.size() % 2 != 0) sum += m[m.size()-1];
    for(int i=0; i < (int) m.size()-1; i+=2){
        sum += m[i] * m[i+1];
    }

    cout << sum << "\n";
}

