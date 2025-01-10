#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

vector<bool> visited;

void CreateGraph()
{
	vertices.reserve(6);

	// 인접 리스트
	/*adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{1, 1, 0, 0, 1, 0},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0},
	};
}

void Dfs(int here)
{
	visited[here] = true;
	cout << "Visited: " << here << endl;

	/*const int size = adjacent[here].size();
	for (int i = 0; i < size; ++i)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}*/

	for (int there = 0; there < 6; ++there)
	{
		if (adjacent[here][there] == 0)
			continue;

		if(visited[there] == false)
			Dfs(there);
	}
}

void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; ++i)
		if (visited[i] == false)
			Dfs(i);
}

int main()
{
	CreateGraph();

	/*visited = vector<bool>(6, false);
	Dfs(0);*/

	DfsAll();
}