#include <bits/stdc++.h>

using namespace std;

int alphabets[33]; // a~z -> 26

void clearAlphabets(){
   for (int i=0;i<26;i++){
      alphabets[i] = 0;
   }
   return ;
}

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int N, continueFlag;
   string str1, str2;

   cin >> N;

   while (N--){
      cin >> str1 >> str2;

      continueFlag = 0;

      if (str1.length() != str2.length()){
         cout << "Impossible\n";
         continue;
      }

      for (int i=0;i<str1.length();i++){
         alphabets[str1[i]-'a'] += 1;
      }

      for (int i=0;i<str2.length();i++){
         alphabets[str2[i]-'a'] -= 1;

         if (alphabets[str2[i]-'a'] < 0){
            cout << "Impossible\n";
            clearAlphabets();
            continueFlag = 1;
            break;
         }
      }

      if (continueFlag == 1){
         continue;
      }

      cout << "Possible\n";
      clearAlphabets();
   }

   return 0;
}
