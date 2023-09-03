#include <bits/stdc++.h>

using namespace std;

int alphabets[33];

int main(){
   ios::sync_with_stdio(0);cin.tie();

   string S;
   cin >> S;

   for (int i=0;i<S.length();i++){
      alphabets[S[i]-97] += 1;  // ASCII CODE -> a == 97
   }

   for (int i=0;i<26;i++){
      cout << alphabets[i] << ' ';
   }
   return 0;
}
