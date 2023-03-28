#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int num = 0;

    while (n--)
    {
        int err_test = 1;
        deque<int> DQ;
        DQ.clear();
        string RD;
        cin >> RD;
        int a;
        cin >> a;
        string intArr;
        cin >> intArr;
        for (int i = 1; i < intArr.size(); i++)
        {
            if (intArr[i] >= 48 && intArr[i] <= 57)
            {
                num = (num * 10) + ((int)intArr[i] - 48);
            }
            else
            {
                if (num != 0)
                {
                    DQ.push_back(num);
                    num = 0;
                }
            }
        }
        //assert(a == DQ.size());
        int R = 0;           // 짝수면 앞에서부터 홀수면 뒤에서부터 출력
        for (int i = 0; i < RD.size(); i++)
        {
            if (RD[i] == 'R')
                R++;
            else            // 'D'인 경우
            {
                if (DQ.empty())
                {
                    cout << "error" << '\n';
                    err_test = 0;
                    break;
                }
                else if (R % 2 == 0)
                    DQ.pop_front();
                else
                    DQ.pop_back();
            }
        }
        if (err_test == 0)
            continue;
        if (R % 2 == 0)
        {
            cout << "[";
            int sizeDQ = DQ.size();
            for (int i = 0; i < sizeDQ; i++)
            {
                if (i != (sizeDQ - 1))
                {
                    cout << DQ.front() << ',';
                    DQ.pop_front();
                }
                else
                {
                    cout << DQ.front();
                    DQ.pop_front();
                }
            }
            cout << "]" << '\n';
        }
        else
        {
            cout << "[";
            int sizeDQ = DQ.size();
            for (int i = 0; i < sizeDQ; i++)
            {
                if (i != (sizeDQ - 1))
                {
                    cout << DQ.back() << ',';
                    DQ.pop_back();
                }
                else
                {
                    cout << DQ.back();
                    DQ.pop_back();
                }
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}