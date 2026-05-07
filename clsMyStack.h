#pragma once
#include <iostream>
#include "clsMyQueue.h"

using namespace std;

template <class t>
class clsMyStack : public clsMyQueue <t>
{
public:
	void push(t data)
	{
		clsMyQueue <t>::_list.insertAtBeginning(data);
	}

	t top()
	{
		return clsMyQueue <t>::front();
	}
	
	t bottom()
	{
		return clsMyQueue <t>::back();
	}
};