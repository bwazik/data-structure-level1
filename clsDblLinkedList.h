#pragma once
#include <iostream>

using namespace std;

template <class t> class clsDblLinkedList
{
private:
	int _size = 0;

public:
	class node
	{
	public:
		t data;
		node* next;
		node* prev;
	};

	node* head = NULL;

	void insertAtBeginning(t data)
	{
		node* newNode = new node();

		newNode->data = data;
		newNode->next = head;
		newNode->prev = NULL;
		if (head != NULL)
			head->prev = newNode;

		head = newNode;
		_size++;
	}

	node* find(t value)
	{
		node* current = head;
			
		while (current != NULL) {
			if (current->data == value)
				return current;

			current = current->next;
		}

		return NULL;
	}

	void insertAfter(node* current, t data) {
		node* new_node = new node();
		new_node->data = data;
		new_node->next = current->next;
		new_node->prev = current;
		if (current->next != NULL)
			current->next->prev = new_node;

		current->next = new_node;
		_size++;
	}

	void insertAtEnd(t data)
	{
		node* new_node = new node();
		new_node->data = data;
		new_node->next = NULL;

		if (head == NULL) {
			new_node->prev = NULL;
			head = new_node;
			_size++;
			return;
		}

		node* lastNode = head;
		while (lastNode->next != NULL) {
			lastNode = lastNode->next;
		}

		lastNode->next = new_node;
		new_node->prev = lastNode;

		_size++;
	}

	void deleteNode(node*& nodeToDelete) {
		if (head == NULL || nodeToDelete == NULL)
			return;

		if (head == nodeToDelete)
			head = nodeToDelete->next;

		if (nodeToDelete->next != NULL)
			nodeToDelete->next->prev = nodeToDelete->prev;

		if (nodeToDelete->prev != NULL)
			nodeToDelete->prev->next = nodeToDelete->next;

		delete nodeToDelete; // Free from memory

		_size--;
	}

	void deleteFirstNode() {
		node* temp = head;

		if (head == NULL)
			return;

		head = temp->next;
		if (head != NULL)
			head->prev = NULL;

		delete temp; // Free from memory
		_size--;
		return;
	}

	void deleteLastNode()
	{
		if (head == NULL)
			return;

		if (head->next == NULL) {
			delete head;
			head = NULL;
			_size--;
			return;
		}

		node* current = head;
		// Find the key to be deleted
		while (current->next->next != NULL) {
			current = current->next;
		}

		// Remove the node
		node* temp = current->next;
		current->next = NULL;
		delete temp; // Free from memory
		_size--;
	}

	void printList()
	{
		node* current = head;

		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	//int size()
	//{
	//	int counter = 0;
	//	node* current = head;

	//	while (current != NULL) {
	//		counter++;
	//		current = current->next;
	//	}
	//	
	//	return counter;
	//}

	int size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return _size == 0;
	}

	void clear()
	{
		while(!isEmpty())
			deleteFirstNode();
	}

	void reverse()
	{
		node* current = head;
		node* temp = nullptr;

		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr) {
			head = temp->prev;
		}
	}

	node* findNodeByIndex(int index)
	{
		if (index < 0 || index > _size - 1)
			return NULL;

		node* current = head;
		int currentIndex = 0;

		while (current != NULL) {
			if (currentIndex == index)
				return current;
			current = current->next;
			currentIndex++;
		}

		return NULL;
	}

	t findNodeDataByindex(int index)
	{
		node* node = findNodeByIndex(index);

		if (node != NULL)
			return node->data;
		else
			return NULL;
	}

	bool updateItemByIndex(int index, t newData)
	{
		node* node = findNodeByIndex(index);

		if (node != NULL)
		{
			node->data = newData;
			return true;
		}

		return false;
	}

	bool insertAfterIndex(int index, t data) {
		node* new_node = findNodeByIndex(index);

		if (new_node != NULL)
		{
			insertAfter(new_node, data);
			return true;
		}

		return false;
	}
};

