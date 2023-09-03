#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int count = 1;
    string str;
    stack<int> s;
    while (n > 0)
    {
        n--;
        int num;
        cin >> num;
        while (count <= num)
        {
            s.push(count);
            count++;
            str += "+\n";
        }
        if (s.top() != num)
        {
            cout << "NO" << endl;
            return 0;
        }
        s.pop();
        str += "-\n";
    }
    /*for (int i = 0; i < str.size(); i++)
        cout << str[i] << endl;*/                 // push_back으로 +,-하나씩 넣고 for문으로 출력하면 시간초과
    cout << str << endl;

    return 0;
}

//시간초과 실패
//int main(void)
//{
//	cin.tie(0);
//	ios::sync_with_stdio(0);
//	int N;
//	cin >> N;
//	int index = 0;
//	stack<int> s;	
//	queue<int> queue;				//queue는 불필요
//	vector<int> result;
//	string ch;
//
//	for (int i = 1; i <= N; i++)
//		queue.push(i);
//	for (int i = 0; i < N; i++)
//	{
//		int input;
//		cin >> input;
//		result.push_back(input);
//	}
//	//최초 1회 push
//	s.push(queue.front());
//	queue.pop();
//	ch.push_back('+');
//
//	while (true)
//	{
//		if (queue.empty())
//			break;
//		if (result[index] == s.top())
//		{
//			s.pop();
//			ch.push_back('-');
//			index++;
//			if (s.empty())
//			{
//				s.push(queue.front());
//				queue.pop();
//				ch.push_back('+');
//			}
//		}
//		else
//		{
//			s.push(queue.front());
//			queue.pop();
//			ch.push_back('+');
//		}
//	}
//	while (!s.empty())
//	{
//		if (s.top() != result[index])
//		{
//			cout << "NO" << endl;
//			return 0;
//		}
//		s.pop();
//		ch.push_back('-');
//		index++;
//	}
//	for (int i = 0; i < ch.size(); i++)
//		cout << ch[i] << endl;
//
//	return 0;
//}