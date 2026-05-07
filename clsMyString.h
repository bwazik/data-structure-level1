#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class clsMyString
{
private:
	string _str;
	stack <string> _undo;
	stack <string> _redo;

public:
	string getValue() { return _str; }
	void setValue(string str) { _undo.push(_str); _str = str; }
	__declspec(property(get = getValue, put = setValue)) string value;

	void undo()
	{
		if (!_undo.empty())
		{
			_redo.push(_str);
			_str = _undo.top();
			_undo.pop();
		}
	}

	void redo()
	{
		if (!_redo.empty())
		{
			_undo.push(_str);
			_str = _redo.top();
			_redo.pop();
		}
	}
};

