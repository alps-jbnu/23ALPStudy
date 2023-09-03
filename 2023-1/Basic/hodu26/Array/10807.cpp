#include <bits/stdc++.h>

using namespace std;

int nums[203];

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int N, v, inpt;

   cin >> N;

   while (N--){
      cin >> inpt;
      nums[inpt+100] += 1;
   }

   cin >> v;

   cout << nums[v+100];

   return 0;
}
