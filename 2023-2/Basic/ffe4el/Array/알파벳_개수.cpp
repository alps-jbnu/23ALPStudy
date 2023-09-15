#include <iostream>
using namespace std;

int main(){
    string w;
    cin>>w;

    int alpha[26]={};

    for(int i=0; i<w.size(); i++){
        int a = w[i]-'a';
        alpha[a]++;
    }

    for(int i=0; i<26; i++){
        cout<<alpha[i]<<" ";
    }
    
    cout<< endl;
    return 0;
}