#include<iostream>
#include<stack>
using namespace std;
typedef int T;

class DoubleStack_Queue
{
public:
	DoubleStack_Queue()
	{}
	~DoubleStack_Queue()
	{}
	void Push(T x)
	{
		s1.push(x);
	}
	void Pop()
	{
		if (!s2.empty())
		{
			s2.pop();
		}
		else
		{
			if (!s1.empty())
			{
				//将s1除最后一个元素逐个倒入s2
				while (s1.size() > 1)
				{
					s2.push(s1.top());
					s1.pop();
				}
				s1.pop();
			}
			else
			{
				cout << "empty" << endl;
			}
		}
	}
	bool Empty()
	{
		if (s1.empty() && s2.empty())
		{
			return true;
		}
		return false;
	}
	T& Front()
	{
		if (!s2.empty())
		{
			return s2.top();
		}
		if (!s1.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
	}
	T& Back()
	{
		if (!s1.empty())
		{
			return s1.top();
		}
		if (!s2.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
			return s1.top();
		}
	}
	void Print()
	{
		while (!Empty())
		{
			cout << Front() << ' ';
			Pop();
		}
	}	
private:
	stack<T> s1;
	stack<T> s2;
};

void Test()
{
	DoubleStack_Queue dq;
	dq.Push(1);
	dq.Push(2);
	dq.Push(3);
	dq.Push(4);
	dq.Push(5);
	dq.Print();
}

int main()
{
	Test();
	system("pause");
	return 0;
}