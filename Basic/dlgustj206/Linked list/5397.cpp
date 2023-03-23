#include <iostream>
#include <list>
#include <string>
using namespace std;

list<char> L;
list<char>::iterator cur;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin>>n;
    while(n--){
        cin>>str;
        L.clear();
        cur=L.begin();
        for(int i=0; i<str.length(); i++){
            if(str[i]=='<'){
                if(cur!=L.begin())
                    cur--;
            }
            else if(str[i]=='>'){
                if(cur!=L.end())
                    cur++;
            }
            else if(str[i]=='-'){
                if(cur!=L.begin())
                    cur=L.erase(--cur);
            }
            else
                L.insert(cur, str[i]);
        }
        for(cur=L.begin(); cur!=L.end(); cur++) cout<<*cur;
        cout<<"\n";
    }
}