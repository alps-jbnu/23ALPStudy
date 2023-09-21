#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;
int t;
string keyLog;
list <char> li;
int main() {
    cin >> t;
    while (t--) {
        li.clear();
        cin >> keyLog;

        auto head = li.begin();

        for (int i = 0; i < keyLog.size(); i++) {
            if (keyLog[i] == '>' && head != li.end()) head++;
            if (keyLog[i] == '<' && head != li.begin()) head--;
            if (keyLog[i] == '-' && head != li.begin()) head = li.erase(--head);
            if (keyLog[i] != '>' && keyLog[i] != '<' && keyLog[i] != '-') li.insert(head, keyLog[i]);
        }

        for (auto l : li) cout << l;
        cout << "\n";
    }
    return 0;
}
