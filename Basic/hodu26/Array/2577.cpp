#include <bits/stdc++.h>

using namespace std;

int nums[13];

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int A, B, C, sum_0=0;
   cin >> A >> B >> C;

   int ABC_int = A*B*C;

   string ABC_str = to_string(ABC_int);

   for (int i=0;i<ABC_str.length();i++){
      nums[ABC_str[i]-'0'] += 1;
   }

   for (int i=0;i<10;i++){
      cout << nums[i] << '\n';
   }

   return 0;
}
