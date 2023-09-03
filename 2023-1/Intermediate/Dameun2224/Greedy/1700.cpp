#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
int schedule[101];
int multiTap[101] = { 0, };

int main() 
{
    int answer = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++) 
        cin >> schedule[i];

    for (int i = 0; i < k; i++)
    {
        bool flag = false;
        //1) 이미 꽂혀 있다면 pass
        for (int j = 0; j < n; j++)
        {
            if (multiTap[j] == schedule[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;

        //2)빈칸이 있으면 꼽아
        for (int j = 0; j < n; j++)
        {
            if (multiTap[j] == 0)
            {
                multiTap[j] = schedule[i];
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;


        //3) 빈칸 필요
        int last_need = -1; // 가장 늦게 다가올 차례
        int index = -1; // 뺄 멀티탭 자리
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            for (int t = i+1;t < k; t++)
            {
                if (schedule[t] == multiTap[j])
                {
                    break;
                }
                tmp++;
            }
            if (tmp > last_need)
            {
                last_need = tmp;
                index = j;
            }
        }

        multiTap[index] = schedule[i];
        answer++;

    }
    cout << answer << endl;
}
