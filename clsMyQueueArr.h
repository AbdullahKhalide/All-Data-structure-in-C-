#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;


template <class T>
class clsMyQueueArr
{

public:
	clsDynamicArray<T> _MyList;

	void Push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}
	void pop()
	{
		_MyList.DeleteFirstItem();
	}
	void Print()
	{
		_MyList.PrintList();
	}
	int Size()
	{
		return _MyList.Size();
	}
	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}
	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void Revers()
	{
		_MyList.Reverse();
	}
	void UpdateItem(int Index, T NewValue)
	{
		_MyList.SetItem(Index, NewValue);
	}
	void InsertAfter(int Index, T NewValue)
	{
		if (!_MyList.InsertAfter(Index, NewValue))
			cout << "\nThis item is Not her\n";
	}
	void InsertAtBeginning(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}
	void InsertAtBsck(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}
	void Clear()
	{
		_MyList.Clear();
	}
};

