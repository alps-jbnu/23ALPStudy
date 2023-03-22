#include <bits/stdc++.h>

using namespace std;

list<char> passwd;

int main(){
   ios::sync_with_stdio(0);cin.tie(0);  // Linked_List practice

   int L,cases;
   string inpt;

   cin >> cases;

   while (cases--){

      cin >> inpt;

      L = inpt.length();
      auto cursor = passwd.end();

      for (int i=0;i<L;i++){

         string a;
         a.push_back(inpt[i]);                 // convert char to string

         if (a == "<" && cursor != passwd.begin()){  
            cursor--;
         }
         
         if (a == ">" && cursor != passwd.end()){
            cursor++;
         }
         
         if (a == "-" && cursor != passwd.begin()){
            cursor--;
            cursor = passwd.erase(cursor);
         }

         if (a != "<" && a != ">" && a != "-"){
            passwd.insert(cursor,inpt[i]);
         }
      }

      for (auto i : passwd){
         cout << i;
      }
      cout << '\n';

      passwd.clear();
   }

   return 0;
}
