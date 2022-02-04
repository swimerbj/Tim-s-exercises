#include "graph.h"


void dfs(int at, std::vector<int>* vis, bool* V) {
	V[at] = true;
	for (int i = 0; i < graph[at].size(); i++)
		if (!V[graph[at][i].to])
			dfs(graph[at][i].to, vis);
	vis->push_back(at);
}

int* topological_sort() {
	int index = n - 1;
	bool* V = new bool[n];
	int* order = new int[n];
	for (int at = 0; at < n; at++) {
		if (!V[at]) {
			std::vector<int> visited_nodes;
			dfs(at, &(visited_nodes), V);
			for (int id = 0; id < visited_nodes.size(); id++)
				order[index--] = visited_nodes[id];
		}
	}
	delete[] V;
	return order;
}