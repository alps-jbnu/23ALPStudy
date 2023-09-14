#include <bits/stdc++.h>

using namespace std;

list<char> text_cpy;

int main(){
   ios::sync_with_stdio(0);cin.tie(0);  // Linked_List practice

   int N,M,list_len;
   char inpt;
   string text,order;

   cin >> text;

   for (int i=0;i<text.length();i++){
      text_cpy.push_back(text[i]);
   }

   auto cursor = text_cpy.end();  // auto -> list<char>::iterator

   cin >> M;

   while (M--){
      cin >> order;

      if (order == "L" && cursor != text_cpy.begin()){  // cursor(iterator) can't use operator(<,> ...)
         cursor--;
      }

      if (order == "D" && cursor != text_cpy.end()){
         cursor++;
      }

      if (order == "B" && cursor != text_cpy.begin()){
         cursor--;
         cursor = text_cpy.erase(cursor);  // list.erase() -> return cursor+1;   /   do not return -> cursor point erased list
      }

      if (order == "P"){
         cin >> inpt;
         text_cpy.insert(cursor,inpt);
      }
   }

   for (auto i : text_cpy){
      cout << i;
   }

   return 0;
}
