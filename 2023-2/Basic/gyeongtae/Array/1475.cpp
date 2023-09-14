#include <iostream>

using namespace std;

int main() {
    string a, b;
    int n, m;
    int num[1000] = { 0 };
    cin >> a;
    for (int i = 0;i < a.length();i++) {
        num[a[i]-'0'] +=1;
    }
    int sum = (num[6] + num[9]);
    if (sum % 2 == 0) {
        num[6] = sum / 2;
        num[9] = sum / 2;
    }
    else {
        num[6] = sum / 2 +1;
        num[9] = sum / 2 +1;
    }
    int max = 0;
    for (int i = 0;i < 10;i++) {
        if (max < num[i]) {
            max = num[i];
        }
    }
    cout << max;
}
