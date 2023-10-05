#include <iostream>
#include <queue>

struct stru2 {
    int value;
    int node;

    bool operator>(stru2 const& a) const {
        return this->value > a.value;
    }

};

int i_n, i_l;

std::queue<int> q;

std::priority_queue<stru2, std::vector<stru2>, std::greater<stru2>> m_h;

void caculate();



int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> i_n >> i_l;

    int d;

    for (int i = 0; i < i_n; i++) {
        std::cin >> d;
        q.push(d);
    }

    caculate();

}

void caculate() {
    int n = i_n - i_l;

    for (int i = 0; i < i_n; i++) {

        m_h.push({ q.front(),i });
        q.pop();

        while (m_h.top().node < i - i_l + 1)
            m_h.pop();
        std::cout << m_h.top().value << ' ';
        
        
    }

}
