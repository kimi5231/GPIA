#include <iostream>
#include <vector>

using namespace std;

void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	bool connected = false;

	int size = v[0].edges.size();
	for (int i = 0; i < size; ++i)
	{
		Vertex* vertex = v[0].edges[i];
		if (vertex == &v[3])
		{
			connected = true;
		}
	}
}

void CreateGraph_2()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	vector<vector<int>> adjacent;
	adjacent.resize(6);

	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	bool connected = false;
	for (int i = 0; i < adjacent[0].size(); ++i)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
		{
			connected = true;
		}
	}
}

void CreateGraph_3()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	vector<bool> v2(6, false);

	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][2] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	bool connected = adjacent[0][3];

	vector<vector<int>> adjacent2 =
	{
		{-1, 15, -1, 35, -1, -1},
		{15, -1, +5, 10, -1, -1},
		{-1, +5, -1, -1, -1, -1},
		{35, 10, -1, -1, +5, -1},
		{-1, -1, -1, +5, -1, +5},
		{-1, -1, -1, -1, +5, -1},
	};
}

int main()
{
	vector<int> v;


}