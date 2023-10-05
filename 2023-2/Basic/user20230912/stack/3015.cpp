#include <iostream>
#include <stack>

struct stru2 {
    int value;
    int degener;
};

int i_n;

long long count = 0;

void caculate();

std::stack<int> s1;

std::stack<stru2> s2;

stru2 same;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> i_n;

    int d;

    for (int i = 0; i < i_n; i++) {
        std::cin >> d;
        s1.push(d);
    }

    caculate();

    std::cout << count;
}

void caculate() {
    int a, b, deg = 0;
    stru2 temp;
    a = i_n - 1;
    b = a;
    

    while (b != -1) {
        deg = 0;
            if (!s2.empty()) {
                count++;

                while (s2.top().value < s1.top() || s2.top().value == s1.top()) {

                    if (s2.top().value == s1.top()) {
                        deg = s2.top().degener + 1;
                        count += s2.top().degener + 1;
                        s2.pop();
                        if (s2.empty()) {
                            count--;
                            break;
                        }
                        
                    }

                    else if (s2.top().value < s1.top()) {
                        if (s2.top().degener != 0) 
                            count += s2.top().degener;
   
                        s2.pop();
                        count++;
                        if (s2.empty()) {
                            count--;
                            break;
                        }
                    }
                }
                
            }

            s2.push({ s1.top(),deg });
            s1.pop();
            b--;

    }
}
