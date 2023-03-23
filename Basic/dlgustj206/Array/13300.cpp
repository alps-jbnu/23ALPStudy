#include <iostream>
using namespace std;

int student[7][2];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, s, y, sum=0;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>s>>y;
        student[y][s]++;
    }
    for(int i=0; i<7; i++){
        for(int j=0; j<2; j++){
            if(student[i][j]!=0){
                if(student[i][j]%k==0) sum+=student[i][j]/k;
                else sum+=student[i][j]/k+1;
            }
        }
    }
    cout<<sum;
}