#include<iostream>
using namespace std;
int n,m;
int seq[10];
bool isused[10];
void f(int k){
    if(k==m){
        for(int i=0;i<m;i++)
            cout<<seq[i]<<" ";
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){  //Idea★★★★★
        if(!isused[i]){
            seq[k]=i;   isused[i]=1;    //insert element in sequence & mark as used
            //Debugging
//            cout<<"insert("<<i<<"), and call f("<<i<<")\n";
            f(k+1);   //determine next element of sequence
            //Debugging
//            cout<<"f("<<i<<") finished. GO BACK!\n";
            isused[i]=0;    //initializing
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    f(0);
}