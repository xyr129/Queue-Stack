#include<iostream>
#include<queue>
using namespace std;
typedef int T;

class DoubleQueue_Stack
{
public:
	DoubleQueue_Stack()
	{}
	~DoubleQueue_Stack()
	{}
	void Push(T x)
	{
		q1.push(x);
	}
	void Pop()
	{
		if (!q1.empty())
		{
			//将q1除最后一个元素逐个倒入q2
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
		else if (!q2.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
		else
		{
			cout << "empty" << endl;
		}
	}
	bool Empty()
	{
		if (q1.empty() && q2.empty())
		{
			return true;
		}
		return false;
	}
	T& Top()
	{
		if (!q1.empty())
		{
			return q1.back();
		}
		if (!q2.empty())
		{
			return q2.back();
		}
	}
	void Print()
	{
		while (!Empty())
		{
			cout << Top() << ' ';
			Pop();
		}
	}
private:
	queue<T> q1;
	queue<T> q2;
};

void Test()
{
	DoubleQueue_Stack ds;
	ds.Push(1);
	ds.Push(2);
	ds.Push(3);
	ds.Push(4);
	ds.Push(5);
	ds.Push(6);
	ds.Print();
}
int main()
{
	Test();
	system("pause");
	return 0;
}