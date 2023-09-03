#include <bits/stdc++.h>

using namespace std;

int nums[13];

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int N, max = 0;
   cin >> N;

   string N_str = to_string(N);

   for (int i=0;i<N_str.length();i++){
      nums[N_str[i]-'0'] += 1;
   }

   int nums_69 = (nums[6]+nums[9])/2 + (nums[6]+nums[9])%2;
   nums[6] = nums_69;

   for (int i=0;i<9;i++){
      if (max < nums[i]){
         max = nums[i];
      }
   }

   cout << max;

   return 0;
}
