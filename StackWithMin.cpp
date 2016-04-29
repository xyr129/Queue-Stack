#include<iostream>
#include<stack>
using namespace std;
typedef int T;


class StackWithMin
{
public:
	StackWithMin()
	{}
	~StackWithMin()
	{}
	void Push(T x)
	{
		s1.push(x);
		if (s2.empty() || x <= s2.top())
		{
			s2.push(x);
		}
	}
	void Pop()
	{
		if (s1.top() == s2.top())
		{
			s2.pop();
		}
		s1.pop();
	}
	T Min()
	{
		if (!s2.empty())
		{
			return s2.top();
		}
	}
	void Print()
	{
		while (!s1.empty())
		{
			cout << s1.top() << "->";
			s1.pop();
		}
		cout << endl;
		while (!s2.empty())
		{
			cout << s2.top() << "->";
			s2.pop();
		}
		cout << endl;
	}
private:
	stack<T> s1, s2;
};

void Test()
{
	StackWithMin  s;
	s.Push(4);
	s.Push(3);
	s.Push(5);
	s.Push(2);
	s.Push(1);
	s.Push(1);
	s.Print();
}

int main()
{
	Test();
	system("pause");
	return 0;
}