#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >>tc;

    for(int i=0; i<tc; i++){
        list<char> R; 

        string w;
        cin >>w;

        auto t = R.begin(); //커서

        for(auto c : w){
            if(c=='<' && t!=R.begin()){
                t--;
            }
            else if(c=='>' && t!=R.end()){
                t++;
            }
            else if(int(c)>47 && int(c)<58){//숫자일때
                R.insert(t, c);
            }
            else if(int(c)>64 && int(c)<91){//대문자일때
                R.insert(t, c);
            }
            else if(int(c)>96 && int(c)<123){//소문자일때
                R.insert(t, c);
            }
            else if(c=='-' && t!=R.begin()){//백스페이스일때
                t--;
                t = R.erase(t);
            }
        }
        
        for(auto i : R) cout <<i;
        cout<<'\n';
    }

    return 0;
}