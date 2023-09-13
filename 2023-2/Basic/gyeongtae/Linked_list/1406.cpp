#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    list <char> l;
    string b, c;
    cin >> b;
    //l.push_back(b);
    for (int i = 0;i < b.length();i++) {
        l.push_back(b[i]);
    }
    list <char>::iterator st = l.end();

    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> b;
        if (b == "P") {
            cin >> b;
            st=l.insert(st,b[0]);
            st++;
        }
        else if (b == "L") {
            if (st != l.begin()) {
                st--; 
            }
        }
        else if (b == "D") {
            if (st != l.end()) {
                st++; 
            }
        }
        else if (b == "B") {
            if (st != l.begin()) {
                st = l.erase(--st); 
            }
        }
    }
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it;
    }
}
