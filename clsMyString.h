#pragma once
#include <iostream>
#include <string>
#include "clsMyStack.h"

using namespace std;


//template<class T>

class clsMyString
{
public:
	string _Value;

	clsMyStack<string> _Undo;
	clsMyStack<string> _Redo;
	//clsMyString S();

	void Set(string Value)
	{
		_Value = Value;
		_Undo.Push(Value);
	}

	string GetValue()
	{
		return _Value;
	}
	_declspec(property(get = GetValue, put = Set)) string Value;

	void Undo()
	{
		if (!_Undo.IsEmpty())
		{
			_Redo.Push(_Value);
			_Value = _Undo.Top();
			_Undo.pop();

		}

	}
	void Redo()
	{
		if (!_Redo.IsEmpty())
		{

			_Undo.Push(_Value);
			_Value = _Redo.Top();
			_Redo.pop();
		}
	}
};

