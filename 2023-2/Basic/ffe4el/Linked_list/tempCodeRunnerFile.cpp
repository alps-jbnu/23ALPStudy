#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >>tc;

    for(int i=0; i<tc; i++){
        // list<char> L;
        // char L[1000001];
        list<char> R; 

        string w;
        cin >>w;

        auto t = R.begin(); //커서

        for(int i=0; i<w.size(); i++){
            if(w[i]=='<' && t!=R.begin()){
                t--;
            }
            else if(w[i]=='>' && t!=R.end()){
                t++;
            }
            else if(int(w[i])>47 && int(w[i])<58){//숫자일때
                R.insert(t, w[i]);
            }
            else if(int(w[i])>64 && int(w[i])<91){//대문자일때
                R.insert(t, w[i]);
            }
            else if(int(w[i])>96 && int(w[i])<123){//소문자일때
                R.insert(t, w[i]);
            }
            else if(w[i]=='-' && t!=R.begin()){//백스페이스일때
                t--;
                R.erase(t);
            }
        }
        
        for(auto i : R) cout <<i;
        cout<<'\n';
    }

    
    return 0;
}