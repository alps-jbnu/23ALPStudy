#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    deque <int> d2; 
    int a, b, c, d; 
    cin >> a >> b; 
    int idx;
    for (int i = 1;i <= a;i++) {
        d2.push_back(i); 
    } 
    int count = 0;
    for (int i = 0;i < b;i++) { 
        cin >> c; 

        for (int i = 0; i < d2.size(); i++) {
            if (d2[i] == c) {
                idx = i;
                break;
            }
        }

        if (idx <= d2.size() / 2) {
            while (1) {
                d = d2.front();
                if (d == c) {
                    d2.pop_front();
                    break;
                }
                d2.push_back(d);
                d2.pop_front();
                count++;
            }
        }
        else {
            while (1) {
                d = d2.back();

                count++;
                d2.push_front(d);
                d2.pop_back();
                if (d == c) {
                    d2.pop_front();
                    
                    break;
                }
            }
        }
    }
    cout << count;
    return 0;
}
