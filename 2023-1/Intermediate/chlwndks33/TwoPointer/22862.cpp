#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a;
    int ans = 0;
    vector<int> vec;
    cin >> n >> m;
    vector<bool> del(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    int num = 0; //삭제 횟수
    int en = 0;
    int st = 0;
    int maxlength = -1;
    int length = 0; //짝수 길이 
    while (st <= en)
    {
        if(en ==n) { //최고 갱신후 종료
            maxlength = max(length, maxlength);
            break;
        } 
        if (vec[en] % 2) // 홀수
            { 
                if (num < m) // 삭제 할수 있으면
                { 
                    del[en] = true;
                    num++;
                    en++;
                }
                else // 삭제 못함
                { 
                    maxlength = max(length, maxlength);
                    if (del[st]) //st를 지웠다면 
                    {
                        del[st] = false;
                        num--;
                    }
                    if(vec[st] % 2 == 0) { //st가 짝수였다면
                        length--;
                    }
                    st++;
                }
            }
            else  // 짝수
            {
                length++;
                en++;
            }
    }
    cout << maxlength;
}