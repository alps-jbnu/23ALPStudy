#include <iostream>

using namespace std;

int main() {
    int num[26] = { 0 };
    string a, b, c;
    cin >> a;
    for (int i = 0;i < a.length();i++) {
        if (a[i] == 'a') {
            num[0] += 1;
        }
        else if (a[i] == 'b') {
            num[1] += 1;
        }
        else if (a[i] == 'c') {
            num[2] += 1;
        }
        else if (a[i] == 'd') {
            num[3] += 1;
        }
        else if (a[i] == 'e') {
            num[4] += 1;
        }
        else if (a[i] == 'f') {
            num[5] += 1;
        }
        else if (a[i] == 'g') {
            num[6] += 1;
        }
        else if (a[i] == 'h') {
            num[7] += 1;
        }
        else if (a[i] == 'i') {
            num[8] += 1;
        }
        else if (a[i] == 'j') {
            num[9] += 1;
        }
        else if (a[i] == 'k') {
            num[10] += 1;
        }
        else if (a[i] == 'l') {
            num[11] += 1;
        }
        else if (a[i] == 'm') {
            num[12] += 1;
        }
        else if (a[i] == 'n') {
            num[13] += 1;
        }
        else if (a[i] == 'o') {
            num[14] += 1;
        }
        else if (a[i] == 'p') {
            num[15] += 1;
        }
        else if (a[i] == 'q') {
            num[16] += 1;
        }
        else if (a[i] == 'r') {
            num[17] += 1;
        }
        else if (a[i] == 's') {
            num[18] += 1;
        }
        else if (a[i] == 't') {
            num[19] += 1;
        }
        else if (a[i] == 'u') {
            num[20] += 1;
        }
        else if (a[i] == 'v') {
            num[21] += 1;
        }
        else if (a[i] == 'w') {
            num[22] += 1;
        }
        else if (a[i] == 'x') {
            num[23] += 1;
        }
        else if (a[i] == 'y') {
            num[24] += 1;
        }
        else if (a[i] == 'z') {
            num[25] += 1;
        }
    }
    for (int i = 0;i < 26;i++) {
        cout << num[i] << " ";
    }
}
