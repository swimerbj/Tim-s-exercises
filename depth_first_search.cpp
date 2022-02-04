#include "graph.h"

void dfs(int at) {
	bool* visited = new bool[n];
	visited[at] = true;
	for (int i = 0; i < graph[at].size(); i++)
		if (!visited[graph[at][i].to])
			dfs(graph[at][i].to);
	delete[] visited;
}