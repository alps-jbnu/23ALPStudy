#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        int arr1[26] = {};
        int arr2[26] = {};
        for (int i = 0; i < a.length(); i++) {
            int tmp = a[i] - 'a';
            arr1[tmp]++;
        }
        for (int i = 0; i < b.length(); i++) {
            int tmp = b[i] - 'a';
            arr2[tmp]++;
        }
        bool possible = true;
        for (int i = 0; i < 26; i++) { 
            if (arr1[i] != arr2[i]) {
                cout << "Impossible\n";
                possible = false;
                break;
            }
        }
        if (possible)
            cout << "Possible\n";
    }
}
