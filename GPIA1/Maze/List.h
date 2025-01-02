#pragma once
#include <iostream>

using namespace std;

class Node
{
	using T = int;
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}

public:
	int data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class List
{
public:
	List()
	{
		_head = new Node(0);
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node* node = _head;
		while (node)
		{
			Node* deleteNode = node;
			node = node->next;
			delete deleteNode;
		}
	}

	Node* AddAtHead(int data)
	{
		Node* node = new Node(data);
		Node* nextNode = _head->next;
	
		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);
		Node* prevNode = _tail->prev;

		node->prev = prevNode;
		prevNode->next = node;
		_tail->prev = node;
		node->next = _tail;

		return node;
	}

	Node* GetNode(int index)
	{
		Node* node = _head->next;
		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; ++i)
		{
			if (node == _tail->prev)
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	void Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);
		Node* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

	void Remove(Node* node)
	{
		Node* prevNode = node->prev;
		Node* nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};

