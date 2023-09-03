#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
string abc[26] =
{
    "a", "b", "c", "d", "e", "f",
    "g", "h", "i", "j", "k", "l",
    "m", "n", "o", "p", "q", "r",
    "s", "t", "u", "v", "w", "x", "y", "z"
};

vector<int> check(26);

void checking()
{
    int i, j;

    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < str.size(); j++)
        {
            if (str.at(j) == abc[i][0])
            {
                check[i]++;
            }
        }
    }
}

int main(void)
{
    int i;
    cin >> str;

    checking();

    for (i = 0; i < 26; i++)
    {
        cout << check[i] << " ";
    }

    return 0;
}
