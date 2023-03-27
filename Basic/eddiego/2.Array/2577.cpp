#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int result = 0;
    cin >> a >> b >> c;

    result = a*b*c;

    int arr[10]={0,};

    while (result>0){
        arr[result%10]++;
        result/=10;
    }

    for(int i = 0; i<10; i++)
        cout << arr[i] << '\n';
}
