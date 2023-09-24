#include <iostream>
#include <list>
using namespace std;

int main(){
    int n,k;
    list<int> l;

    for(int i=0; i<n; i++){
        l.push_back(i);
    }

    auto t = l.begin();

    cout << "<";
    for(int i=0; i<n-1; i++){
        for(int j=0; j<k-1; j++){
            l.push_back(l.front());
            l.pop_front();
        }
        cout << l.front() << ", ";
        l.pop_front();
    }
    cout << l.front() << ">" <<endl;

    return 0;
}