#include <bits/stdc++.h>

using namespace std;

list<int> swift_alg;

int main(){
   ios::sync_with_stdio(0);cin.tie(0);  // Linked_List practice

   int N,K;

   cin >> N >> K;

   for (int i=0;i<N;i++){
      swift_alg.push_back(i+1);
   }

   auto cur = swift_alg.begin();

   cout << "<";

   while (swift_alg.size() != 0){

      for (int i=1;i<K;i++){
         cur++;

         if (cur == swift_alg.end()){
            cur = swift_alg.begin();
         }
      }

      cout << *cur;
      if (swift_alg.size() != 1){
         cout << ", ";
      }

      cur = swift_alg.erase(cur);

      if (cur == swift_alg.end()){
         cur = swift_alg.begin();
      }
   }

   cout << ">";

   return 0;
}
