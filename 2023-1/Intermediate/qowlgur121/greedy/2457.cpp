#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int N;
    std::cin >> N;

    // 꽃들의 피는 날짜들을 저장하는 벡터
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        std::pair<int, int> a, b;
        std::cin >> a.first >> a.second >> b.first >> b.second;

        // MMdd 형식으로 날짜를 합쳐서 저장
        v.push_back({ a.first * 100 + a.second, b.first * 100 + b.second });
    }

    // 꽃이 피는 날짜가 앞서는 순서대로 정렬
    std::sort(v.begin(), v.end());

    int idx = -1; // 선택된 꽃 중 가장 늦게 지는 꽃의 인덱스
    int temp = 0; // 이전에 선택된 꽃 중 가장 늦게 지는 꽃의 종료일
    int result = 0; // 선택된 꽃의 수

    // 3월 1일부터 11월 30일까지
    for (int i = 301; i <= 1130 && idx < N; i = temp)
    {
        bool flag = false; // 꽃을 선택했는지 여부를 나타내는 플래그
        idx++;

        // 선택 가능한 꽃 중 가장 늦게 지는 꽃을 선택
        for (int j = idx; j < v.size(); j++)
        {
            if (v[j].first > i)
            {
                break;
            }

            if (temp < v[j].second)
            {
                temp = v[j].second;
                idx = j;
                flag = true;
            }
        }

        // 선택 가능한 꽃이 없으면 종료
        if (flag)
        {
            result++;
        }
        else
        {
            std::cout << 0 << "\n";
            return 0;
        }
    }

    std::cout << result << "\n";
    return 0;
}
