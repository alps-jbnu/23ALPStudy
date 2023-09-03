#include <bits/stdc++.h>

using namespace std;

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int n, x, pairs=0;
   cin >> n;

   int a[n] = {};

   for (int i=0;i<n;i++){
      cin >> a[i];
   }

   cin >> x;

   sort(a, a+n);

   int start=0, end=n-1;
   while (start != end){
      if (a[start]+a[end]==x && a[start]!=a[end]){
         pairs++;
         start ++;
      }
      else if (a[start]+a[end] > x){
         end--;
      }
      else {
         start++;
      }
   }

   cout << pairs;

   return 0;
}
