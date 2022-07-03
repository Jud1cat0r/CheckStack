#pragma once
template <typename T>
class Stack
{
	T* st = nullptr;
	int sizeSt = 0;
	int countElemets = 0;
public:
	Stack()
	{}
	Stack(int sizeSt)
	{
		this->sizeSt = sizeSt;
		st = new T[sizeSt];
	}

	Stack& operator =(const Stack& str)
	{
		delete[]st;
		this->sizeSt = str.sizeSt;
		this->countElemets = str.countElemets;
		st = new T[sizeSt];
		for (int i = 0; i < sizeSt; i++)
		{
			this->st[i] = str.st[i];
		}
		return *this;
	}

	T& top()
	{
		return st[countElemets - 1];
	}

	bool empty()
	{
		return !countElemets;
	}

	int size()
	{
		return countElemets;
	}

	void push(const T& value)
	{
		st[countElemets++] = value;
	}

	void push(T&& value)
	{
		st[countElemets++] = value;
	}

	void pop()
	{
		if (countElemets > 0) countElemets--;
	}

	void emplace(const T& value)
	{
		st[countElemets++] = value;
	}

	void check(const char* str)
	{
		bool flag = true;
		int a = 0;
		for (int i = 0; i < str[i] != '\0'; i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				this->push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (top() == '(') pop();
				else
				{
					flag = false;
					a = i;
					break;
				}
			}
			else if (str[i] == ']')
			{
				if (top() == '[') pop();
				else
				{
					flag = false;
					a = i;
					break;
				}
			}
			else if (str[i] == '}')
			{
				if (top() == '{') pop();
				else
				{
					flag = false;
					a = i;
					break;
				}
			}
		}
		if (flag) cout << "OK";
		else
		{
			cout << "error: " << endl;
			for (int i = 0; i <= a; i++)
			{
				cout << str[i];
			}
		}
	}
	~Stack()
	{
		delete[]st;
	}
};

