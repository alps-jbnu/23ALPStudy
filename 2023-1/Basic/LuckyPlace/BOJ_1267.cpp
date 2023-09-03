#include <iostream>
#include <vector>
using namespace std;

int YeongSik(vector<int>& vec)
{
    int sum = 0;
    int quotient;       // ¸ò
    for (int i = 0; i < vec.size(); i++)
    {
        quotient = vec[i] / 30;
        sum += ((quotient + 1) * 10);
    }
    return sum;
}

int MinSik(vector<int>& vec)
{
    int sum = 0;
    int quotient;       // ¸ò
    for (int i = 0; i < vec.size(); i++)
    {
        quotient = vec[i] / 60;
        sum += ((quotient + 1) * 15);
    }
    return sum;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> vec;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int Ysum = YeongSik(vec);
    int Msum = MinSik(vec);
    if (Ysum > Msum)
    {
        cout << 'M' << ' ' << Msum << endl;
    }
    else if (Ysum < Msum)
    {
        cout << 'Y' << ' ' << Ysum << endl;
    }
    else
        cout << 'Y' << ' ' << 'M' << ' ' << Ysum << endl;

    return 0;
}