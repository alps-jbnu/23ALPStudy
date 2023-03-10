#include <iostream>

using namespace std;

#define inpt_num 9

typedef struct {
   int num;
   int idx;
} Number;

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   Number nums[13];
   Number t[3];

   for (int i=0;i<inpt_num;i++){
      cin >> nums[i].num;
      nums[i].idx = i+1;
   }

   for (int i=0;i<inpt_num;i++){
      for (int j=i;j<inpt_num;j++){
         if (nums[i].num < nums[j].num){
            t[0] = nums[i];
            nums[i] = nums[j];
            nums[j] = t[0];
         }
      }
   }

   cout << nums[0].num << '\n' << nums[0].idx;
   return 0;
}
