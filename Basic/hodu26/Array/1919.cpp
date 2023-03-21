#include <bits/stdc++.h>

using namespace std;

int alphabets[33]; // a~z -> 26

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int changes = 0;
   string str1, str2;

   cin >> str1 >> str2;

   for (int i=0;i<str1.length();i++){
      alphabets[str1[i]-'a'] += 1;
   }

   for (int i=0;i<str2.length();i++){
      alphabets[str2[i]-'a'] -= 1;
   }

   for (int i=0;i<26;i++){
      if (alphabets[i] < 0){
         changes -= alphabets[i];
      }

      if (alphabets[i] > 0){
         changes += alphabets[i];
      }
   }

   cout << changes;

   return 0;
}
