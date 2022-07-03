#include <iostream>
#include"Stack.cpp"





int main()
{
	char str[]{ "({x-y-z}*[x+2y}-(z+4x))" };
	Stack<char> stc(strlen(str));
	stc.check(str);
}
