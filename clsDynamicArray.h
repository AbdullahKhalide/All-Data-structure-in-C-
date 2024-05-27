#pragma once
#include <iostream>
using namespace std;

template<class T>

class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;
public:
	T* OriginalArray;
	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;
		_Size = Size;
		OriginalArray = new T[_Size];
	}
	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || _Size < 0)
		{
			return false;
		}
		OriginalArray[Index] = Value;
		return true;
	}
	bool IsEmpty()
	{
		return(_Size == 0 ? true : false);
	}
	int Size()
	{
		return _Size;
	}
	void PrintList()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete OriginalArray;
		OriginalArray = _TempArray;
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}
		_TempArray = new T[NewSize];
		if (NewSize < _Size)
		{
			_Size = NewSize;
		}

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void MyReverse()
	{
		T temp = 0;
		int Sw = _Size / 2;
		for (int i = 0; i < Sw; i++)
		{
			temp = OriginalArray[i];
			OriginalArray[i] = OriginalArray[_Size - (1 + i)];
			OriginalArray[_Size - 1 - i] = temp;
		}
	}
	void Reverse()
	{
		_TempArray = new T[_Size];
		int Counter = 0;
		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[Counter] = OriginalArray[i];
			Counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}
		_Size--;

		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}
	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}
	int Find(T Value)
	{

		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
			{
				return i;
			}
		}
		return -1;
	}
	bool MyDeleteItem(T Value)
	{
		return DeleteItemAt(Find(Value));
	}
	bool DeleteItem(T Value)
	{
		int index = Find(Value);
		if (index == -1)
		{
			return false;
		}
		DeleteItemAt(index);
		return true;
	}
	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
		{
			return false;
		}
		_Size++;

		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[Index] = Value;
		for (int i = Index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}
	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(Index - 1, Value);
	}
	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size, Value);
		else
			return InsertAt(Index + 1, Value);
	}
	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);

	}

};

