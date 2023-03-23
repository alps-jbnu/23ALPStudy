#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;

        int arr[26]={};

        for(auto c : s1)
            arr[c-'a']++;
        for(auto c : s2)
            arr[c-'a']--;

        bool poss = true;

        for(int i : arr)
            if(i !=0)
                poss =false;

        if(poss == true)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}