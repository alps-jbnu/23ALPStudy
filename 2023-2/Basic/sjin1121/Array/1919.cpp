#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int cnt = 0;

    string a, b;
    cin >> a >> b;
    int arr1[26] = {};
    int arr2[26] = {};
    for (int i = 0; i < a.length(); i++)
        arr1[a[i] - 'a']++;
    for (int i = 0; i < b.length(); i++)
        arr2[b[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (arr1[i] != arr2[i])
            cnt += abs(arr1[i] - arr2[i]);
    }
    cout << cnt;

    return 0;
    
}
