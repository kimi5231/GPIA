#include <iostream>
using namespace std;

class Node
{
public:
	Node(int data) : data(data) {}

public:
	int data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
}