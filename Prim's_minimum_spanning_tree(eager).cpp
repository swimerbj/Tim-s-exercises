#include "graph.h"

bool contains(std::priority_queue<std::pair<line, int>, std::less<std::pair<line, int>>>* ipq, int node) {
	std::stack<std::pair<line, int>> tmp;
	bool check = false;
	for (int i = 0; i < ipq->size(); i++) {
		if (ipq->top().second == node) {
			check = true;
			break;
		}
		tmp.push(ipq->top());
	}
	while (!tmp.empty()) {
		ipq->push(tmp.top());
		tmp.pop();
	}
	return check;
}

void decrease_key(std::priority_queue<std::pair<line, int>, std::less<std::pair<line, int>>>* ipq, int node, line l) {
	std::stack<std::pair<line, int>> tmp;
	for (int i = 0; i < ipq->size(); i++) {
		if (ipq->top().first == l)
			break;
		tmp.push(ipq->top());
	}
	std::pair<line, int> k = ipq->top();
	ipq->pop();
	k.second = node;
	ipq->push(k);
	while (!tmp.empty()) {
		ipq->push(tmp.top());
		tmp.pop();
	}
}

void relax_edges_at_node(int node, bool* vis, std::priority_queue<std::pair<line, int>, std::less<std::pair<line, int>>>* ipq) {
	vis[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int dest_node = graph[node][i].to;
		if (vis[dest_node])
			continue;

		if (!contains(ipq, dest_node))
			ipq->push(std::pair<line, int>(graph[node][i], dest_node));

		else
			decrease_key(ipq, dest_node, graph[node][i]);
	}
}

std::pair<int, line*> prims_minimum_spanning_tree() {
	std::priority_queue<std::pair<line, int>, std::less<std::pair<line, int>>> ipq;
	bool* vis = new bool[n];
	memset(vis, false, sizeof(bool) * n);
	int mst_edge_cnt = 0;
	int start = 0;
	int edges = n - 1;
	line* mst_edges = new line[m];
	int cost = 0;

	relax_edges_at_node(start, vis, &ipq);

	while (!ipq.empty() && mst_edge_cnt != m) {
		line edge = ipq.top();
		int node = edge.to;

		mst_edges[mst_edge_cnt++] = edge;
		cost += edge.cost;
		relax_edges_at_node(node, vis, &ipq);
	}

	if (mst_edge_cnt != m)
		return std::pair<int, line*>(NULL, nullptr);
	return std::pair<int, line*>(cost, mst_edges);
}