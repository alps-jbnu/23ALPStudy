#include <iostream>
#include <string>
#include <vector>

using namespace std;

int abc;
string str[10] =
{
	"0", "1", "2", "3", "4",
	"5", "6", "7", "8", "9"
};

vector<int> check(10);

void checking()
{
    int i, j;
    string abcstr;
    
    abcstr = to_string(abc);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < abcstr.size(); j++)
        {
            if (abcstr.at(j) == str[i][0])
            {
                check[i]++;
            }
        }
    }
}

int main(void)
{
    int i, a, b, c;
    cin >> a >> b >> c;
    
    abc = a * b * c;

    checking();

    for (i = 0; i < 10; i++)
    {
        cout << check[i] << endl;
    }

    return 0;
}
