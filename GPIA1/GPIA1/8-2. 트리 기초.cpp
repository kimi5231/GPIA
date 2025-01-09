#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	Node(const char* data) : data(data) {}

public:
	const char* data;
	vector<Node*> childern;
};

Node* CreateTree()
{
	Node* root = new Node("R1 ���߽�");

	{
		Node* node = new Node("������");
		root->childern.push_back(node);
		{
			Node* leaf = new Node("����");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("���丮");
			node->childern.push_back(leaf);
		}
	}
	{
		Node* node = new Node("���α׷���");
		root->childern.push_back(node);
		{
			Node* leaf = new Node("Ŭ��");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->childern.push_back(leaf);
		}
	}
	{
		Node* node = new Node("��Ʈ");
		root->childern.push_back(node);
		{
			Node* leaf = new Node("���");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("ĳ����");
			node->childern.push_back(leaf);
		}
	}

	return root;
}

void PrintTree(Node* root, int depth = 0)
{
	for (int i = 0; i < depth; ++i)
		cout << "-";

	cout << root->data << endl;

	int size = root->childern.size();

	for (int i = 0; i < size; ++i)
	{
		PrintTree(root->childern[i], depth + 1);
	}
}

int GetHeight(Node* root)
{
	int ret = 1;

	int size = root->childern.size();
	for (int i = 0; i < size; ++i)
	{
		Node* node = root->childern[i];
		int h = GetHeight(node) + 1;

		if (ret < h)
			ret = h;
	}

	return ret;
}

int main()
{
	Node* root = CreateTree();

	PrintTree(root);

	cout << GetHeight(root) << endl;
}