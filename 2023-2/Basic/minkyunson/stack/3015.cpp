#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long pair = 0;                       //쌍의 수
    vector<int> arr;                    //키의 배열
    vector<int> arrp;                   //연속되는 같은 키에 대한 가중치
    int n;                              //입력 수
    cin >> n;
    
    int input;                          //입력되는 키의 값
    cin >> input;
    arr.push_back(input);
    arrp.push_back(1);
    for(int i = 1; i < n; i++)
    {
        cin >> input;
        if(input == arr.back())
        {
            arrp.back()++;
            pair += arrp.back() - 1;
        }
        else
        {
            arr.push_back(input);
            arrp.push_back(1);
        }
    }
    
    stack<int> s;
    
    s.push(0);
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[s.top()] > arr[i])
        {
            pair += arrp[i];
            s.push(i);
        }
        else
        {
            while(1)
            {
                pair += arrp[s.top()];
                s.pop();
                if(s.empty())
                    break;
                else if(arr[s.top()] > arr[i])
                {
                    pair += arrp[i];
                    break;
                }
                else if(arr[s.top()] == arr[i])
                {
                    pair += arrp[s.top()] * arrp[i];
                    arrp[s.top()] += arrp[i];
                    if(s.size() > 1)
                    {
                        pair += arrp[i];
                    }
                    goto end;
                }
            }
            s.push(i);
        end:
            ;
        }
    }
    
    cout << pair;
}
