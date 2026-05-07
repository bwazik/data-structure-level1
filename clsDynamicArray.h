#pragma once
#include <iostream>

using namespace std;

template <class t>
class clsDynamicArray
{
protected:
	int _size;
	t* _tempArr = NULL;

public:
	t* arr;

	clsDynamicArray(int size = 0)
	{
		if (size < 0)
			size = 0;

		_size = size;

		arr = new t[_size];
	}

	~clsDynamicArray()
	{
		delete[] arr;
	}

	bool setItem(int index, t value)
	{
		if (index < 0 || index >= _size)
			return false;
		arr[index] = value;
		return true;
	}

	int size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return _size == 0;
	}

	void printList()
	{
		for (int i = 0; i <= _size - 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void resize(int newSize)
	{
		if (newSize < 0)
			newSize = 0;

		_tempArr = new t[newSize];

		if (newSize < _size)
			_size = newSize;

		for (int i = 0; i < _size; i++)
		{
			_tempArr[i] = arr[i];
		}

		_size = newSize;

		delete[] arr;
		arr = _tempArr;
	}

	t getItem(int index)
	{
		if (index < 0 || index >= _size)
			return;
		return arr[index];
	}

	void reverse()
	{
		_tempArr = new t[_size];

		int counter = 0;

		for (int i = _size - 1; i >= 0; i--)
		{
			_tempArr[counter] = arr[i];
			counter++;
		}

		delete[] arr;
		arr = _tempArr;
	}

	void clear()
	{
		_size = 0;
		_tempArr = new t[0];
		delete[] arr;
		arr = _tempArr;
	}

	void deleteItem(int index)
	{
		if (index < 0 || index >= _size)
			return;

		_tempArr = new t[_size - 1];

		int counter = 0;
		for (int i = 0; i < _size; i++)
		{
			if (index != i)
			{
				_tempArr[counter] = arr[i];
				counter++;
			}
		}
		_size--;
		delete[] arr;
		arr = _tempArr;
	}

	void deleteFirstItem()
	{
		deleteItem(0);
	}

	void deleteLastItem()
	{
		deleteItem(_size - 1);
	}

	int getItemByVal(t value)
	{
		for (int i = 0; i < _size; i++)
		{
			if (arr[i] == value)
				return i;
		}
		return -1;
	}

	bool deleteItemByVal(t value)
	{
		int index = getItemByVal(value);
		if (index == -1)
			return false;

		deleteItem(index);
		return true;
	}

	void insertAt(int index, t value)
	{
		if (index < 0 || index >= _size)
			return;

		_size++;
		_tempArr = new t[_size];

		for (int i = 0; i < index; i++)
		{
			_tempArr[i] = arr[i];
		}

		_tempArr[index] = value;

		for (int i = index; i < _size - 1; i++)
		{
			_tempArr[i + 1] = arr[i];
		}

		delete[] arr;
		arr = _tempArr;
	}

	void insertAtBeginning(t value)
	{
		insertAt(0, value);
	}

	void insertBeforeItem(int index, t value)
	{
		if(index < 1)
			insertAt(0, value);
		else 
			insertAt(index - 1, value);
	}

	void insertAfterItem(int index, t value)
	{
		if (index >= _size)
			insertAt(_size - 1, value);
		else
			insertAt(_size + 1, value);
	}

	void insertAtEnd(t value)
	{
		insertAt(_size, value);
	}
};

