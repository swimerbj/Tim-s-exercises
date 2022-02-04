#include "graph.h"

void bfs(int start) {
	std::queue<int> q;
	bool* visited = new bool[n];
	q.push(start);
	while (q.empty()) {
		int node = q.front();
		q.pop();

		for(int i = 0; i < graph[node].size(); i++)
			if (!visited[graph[node][i].to]) {
				q.push(graph[node][i].to);
				visited[graph[node][i].to] = true;
			}
	}
}