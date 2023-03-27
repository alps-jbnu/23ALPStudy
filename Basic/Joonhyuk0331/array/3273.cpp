#include <iostream>
using namespace std;
int arr[100001];
int occur[2000001]={};

int func2(int arr[], int n, int sum) {//(수열,수열의 길이,합)
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (sum - arr[i] < 0) {
            
        }
        else if (occur[sum - arr[i]] == 1){
            result++;
        }
        occur[arr[i]] = 1;
    }
    return result;
}

int main(void)
{   
    int n=0, sum=0;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
    }
    cin >> sum;
    cout << func2(arr, n, sum);
}
