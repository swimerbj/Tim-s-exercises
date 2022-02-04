#include "graph.h"

void add_edges(int node, bool* vis, std::priority_queue<line>* pq) {
	vis[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
		if (!vis[graph[node][i].to])
			pq->push(graph[node][i]);
}

std::pair<int, line*> prims_minimum_spanning_tree() {
	std::priority_queue<line> pq;
	bool* vis = new bool[n];
	memset(vis, false, sizeof(bool) * n);
	int mst_edge_cnt = 0;
	int start = 0;
	int edges = n - 1;
	line* mst_edges = new line[m];
	int cost = 0;
	add_edges(start, vis, &pq);
	while (!pq.empty() && mst_edge_cnt != m) {
		line edge = pq.top();
		pq.pop();
		int node = edge.to;
		if (vis[node])
			continue;
		mst_edges[mst_edge_cnt++] = edge;
		cost += edge.cost;

		add_edges(node, vis, &pq);
	}
	delete[] vis;
	if (mst_edge_cnt != m)
		return std::pair<int, line*>(NULL, nullptr);
	return std::pair<int, line*>(cost, mst_edges);
}