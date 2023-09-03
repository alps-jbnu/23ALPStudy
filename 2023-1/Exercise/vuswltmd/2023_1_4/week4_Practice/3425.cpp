//3425 ∞ÌΩ∫≈√
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (1) {
        vector<string> order;
        vector<int> number;

        while (1) {
            string command;
            cin >> command;

            if (command == "QUIT") {
                return 0;
            }

            if (command == "NUM") {
                int num;
                cin >> num;
                number.push_back(num);
            }

            order.push_back(command);
            if (command == "END") break;
        }

        int count; cin >> count;

        while (count--) {
            int num;
            cin >> num;

            stack<long long> S; S.push(num);
            int c = 0;

            for (int i = 0; i < order.size(); i++) {
                if (order[i] == "NUM") {
                    S.push(number[c]);
                    c++;
                }
                else if (order[i] == "POP") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    S.pop();
                }
                else if (order[i] == "INV") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num = S.top(); S.pop();
                    num = num * -1;

                    if (abs(num) > 1'000'000'000) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    S.push(num);
                }
                else if (order[i] == "DUP") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num = S.top();
                    S.push(num);
                }
                else if (order[i] == "SWP") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num1 = S.top(); S.pop();

                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num2 = S.top(); S.pop();


                    S.push(num1);
                    S.push(num2);
                }
                else if (order[i] == "ADD") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num1 = S.top(); S.pop();
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num2 = S.top(); S.pop();

                    if (abs(num1 + num2) > 1'000'000'000) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    S.push(num1 + num2);
                }
                else if (order[i] == "SUB") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num1 = S.top(); S.pop();
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num2 = S.top(); S.pop();

                    if (abs(num2 - num1) > 1'000'000'000) {
                        cout << "ERROR" << '\n';
                        break;
                    }

                    S.push(num2 - num1);
                }
                else if (order[i] == "MUL") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num1 = S.top(); S.pop();
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num2 = S.top(); S.pop();
                    if (abs(num1 * num2) > 1'000'000'000) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    S.push(num2 * num1);
                }
                else if (order[i] == "DIV") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num1 = S.top(); S.pop();
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num2 = S.top(); S.pop();

                    if (num1 == 0) {
                        cout << "ERROR" << '\n';
                        break;
                    }

                    long long num1_sign;
                    if (num1 >= 0) num1_sign = 1;
                    else num1_sign = -1;

                    long long num2_sign;
                    if (num2 >= 0) num2_sign = 1;
                    else num2_sign = -1;

                    long long ans;

                    if (num1_sign == -1 && num2_sign == 1) ans = -1 * (abs(num2) / abs(num1));
                    else if (num1_sign == 1 && num2_sign == -1) ans = -1 * (abs(num2) / abs(num1));
                    else ans = abs(num2) / abs(num1);
                    S.push(ans);
                }
                else if (order[i] == "MOD") {
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num1 = S.top(); S.pop();
                    if (S.empty()) {
                        cout << "ERROR" << '\n';
                        break;
                    }
                    long long num2 = S.top(); S.pop();

                    if (num1 == 0) {
                        cout << "ERROR" << '\n';
                        break;
                    }

                    long long num1_sign;
                    if (num1 >= 0) num1_sign = 1;
                    else num1_sign = -1;

                    long long num2_sign;
                    if (num2 >= 0) num2_sign = 1;
                    else num2_sign = -1;

                    long long ans;

                    if (num2_sign == -1) ans = -1 * (abs(num2) % abs(num1));
                    else if (num2_sign == 1) ans = (abs(num2) % abs(num1));
                    S.push(ans);

                }
                else if (order[i] == "END") {
                    if (S.size() == 1) {
                        cout << S.top() << '\n'; S.pop();
                    }
                    else {
                        cout << "ERROR" << '\n';
                        break;
                    }
                }
            }


        }
        cout << '\n';
    }
}

