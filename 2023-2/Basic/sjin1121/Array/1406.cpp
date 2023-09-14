#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    string command;
    int t;
    list<char> l;
    list<char>::iterator iter;

    cin >> str >> t;
    for (const auto& x : str) l.push_back(x);
    iter = l.end();

    cin.ignore();
    while (t--) {
        getline(cin, command);

        if (command[0] == 'L') {
            if (distance(l.begin(), iter) > 0) --iter;
        }
        else if (command[0] == 'D') {
            if (distance(iter, l.end()) > 0) ++iter;
        }
        else if (command[0] == 'B') {
            if (iter != l.begin())
                iter = l.erase(--iter);
        }
        else if (command[0] == 'P') {
            iter = l.insert(iter, command[2]); 
            ++iter;
        }
    }

    for (const auto& x : l) cout << x;
}
