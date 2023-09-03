#include <iostream>
using namespace std;

int main(void)
{
    int N;              // 총 학생 수
    int K;              // 방 최대 인원 수

    int sex;
    int grade;
    int room[2][6] = { 0 };
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> sex >> grade;
        room[sex][grade - 1]++;
    }
    int total = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            total += room[i][j] / K;
            if ((room[i][j] % K) > 0)
                total++;
        }
    }
    cout << total;
    
    return 0;
}