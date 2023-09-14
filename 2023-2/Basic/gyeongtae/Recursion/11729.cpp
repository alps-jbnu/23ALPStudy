#include <iostream>
#include <cmath>

using namespace std;

int s = 0;

void re(int start,int mid,int end,int n) {
    if (n == 1) {
        cout << start << " " << end << "\n";
    }
    else {
        re(start,end, mid,  n - 1);
        cout << start << " " << end << "\n";
        re( mid,start, end, n - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    cin >> a;
    cout << (int)pow(2, a) -1 << "\n";
    re(1,2,3,a);
}
