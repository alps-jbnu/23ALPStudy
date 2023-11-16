#include <iostream>
#include <cmath>
void cacul();

long long a_in, b_in, c_in;

long long remain = 1;

int main()
{
    std::cin >> a_in >> b_in >> c_in;

    if (a_in > c_in)
        a_in = a_in % c_in;
    if (a_in == 0) {
        std::cout << "0";
        return 0;
    }
    while (b_in != 0) {
        cacul();

    }

    std::cout << remain;

}


void cacul() {

    int a = int(log2(b_in));
    long long temp = a_in;
    for (int i = 0; i < a; i++) {
        temp = (temp * temp) % c_in;
    }

    remain = (remain * temp) % c_in;

    b_in = b_in - pow(2, a);

}
