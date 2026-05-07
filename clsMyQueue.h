#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class t>
class clsMyQueue
{
protected:
	clsDblLinkedList <t> _list;

public:
	void push(t data)
	{
		_list.insertAtEnd(data);
	}

	void pop()
	{
		_list.deleteFirstNode();
	}

	int size()
	{
		return _list.size();
	}

	t front()
	{
		return _list.findNodeDataByindex(0);
	}

	t back()
	{
		return _list.findNodeDataByindex(size() - 1);
	}

	void print()
	{
		_list.printList();
	}

	t findQueueDataByindex(int index)
	{
		return _list.findNodeDataByindex(index);
	}

	void reverse()
	{
		_list.reverse();
	}

	bool updateItemByindex(int index, t newData)
	{
		return _list.updateItemByIndex(index, newData);
	}

	bool insertAfterIndex(int index, t newData)
	{
		return _list.insertAfterIndex(index, newData);
	}

	void insertAtFront(t data)
	{
		_list.insertAtBeginning(data);
	}

	void insertAtEnd(t data)
	{
		_list.insertAtEnd(data);
	}

	void clear()
	{
		_list.clear();
	}
};