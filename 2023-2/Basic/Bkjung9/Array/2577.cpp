#include <iostream>
using namespace std;

int main(int argc, const char *argv[]){
    int a, b, c;
    cin >> a >> b >> c;

    int num = a * b * c;
    int count[10] = {};

    while(num != 0){
        count[num % 10]++;
        num /= 10;
    }

    for(int i : count)
        cout << i << "\n";

    return 0;
}
