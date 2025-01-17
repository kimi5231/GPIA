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
	Node* root = new Node("R1 개발실");

	{
		Node* node = new Node("디자인");
		root->childern.push_back(node);
		{
			Node* leaf = new Node("전투");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("경제");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("스토리");
			node->childern.push_back(leaf);
		}
	}
	{
		Node* node = new Node("프로그래밍");
		root->childern.push_back(node);
		{
			Node* leaf = new Node("클라");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("서버");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("엔진");
			node->childern.push_back(leaf);
		}
	}
	{
		Node* node = new Node("아트");
		root->childern.push_back(node);
		{
			Node* leaf = new Node("배경");
			node->childern.push_back(leaf);
		}
		{
			Node* leaf = new Node("캐릭터");
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