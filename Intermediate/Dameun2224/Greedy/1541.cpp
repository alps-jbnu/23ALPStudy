#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

vector<int> num;
vector<char> op;
vector<int> result;
string str;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            num.push_back((stoi(str.substr(j, i - j))));
            op.push_back(str[i]);
            j = i + 1;
        }
    }
    num.push_back((stoi(str.substr(j, str.length() - j))));

    // num의 길이가 n이면 op의 길이는 n-1
    int key = 0;
    for (int i = 0; i < num.size(); i++) {
        if (key == 0) result.push_back(num[i]);
        else if (key == 1) result.back() += num[i];
        if (i == num.size() - 1) break;

        if (op[i] == '+') key = 1;
        else if (op[i] == '-') key = 0;
    }

    int ans = result.front();
    for (int i = 1; i < result.size(); i++) ans -= result[i];
    cout << ans << '\n';

    return 0;
}
