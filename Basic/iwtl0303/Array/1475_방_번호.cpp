#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    int freq[10]={0, }, max=0, len,num,sum;
    cin>>n;
    len = n.length();
    num=stoi(n);

    for (int i =0 ;i<len;i++){
        freq[num%10]++;
        num /=10;
    }
    sum=freq[6]+freq[9];
    freq[6] = ceil((double)sum/2);
    freq[9] = ceil((double)sum/2);

    for (int i=0;i<10;i++){
        if(max<freq[i]) max = freq[i];
    }
    cout << max;
    return 0;
}
