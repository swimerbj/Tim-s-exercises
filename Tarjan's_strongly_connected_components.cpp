#include "graph.h"

void dfs(int at, int* ids, int* low, bool* vis, int* sccs, int* id, int* sccs_cnt, std::stack<int>* s) {
	ids[at] = low[at] = *id++;
	s->push(at);

	for (int i = 0; i < graph[at].size(); i++) {
		if (ids[graph[at][i].to] == -1)
			dfs(graph[at][i].to, ids, low, vis, sccs, id, sccs_cnt, s);
		if (vis[graph[at][i].to])
			low[at] = std::min(low[at], low[graph[at][i].to]);
	}

	if (ids[at] == low[at]) {
		while (true) {
			int n = s->top();
			s->pop();
			vis[n] = false;
			sccs[n] = *sccs_cnt;
			if (n == at)
				break;
		}
		sccs_cnt++;
	}
}

std::multimap<int, std::list<int>>* Tarjan_strongly_connnected_components() {
	int* ids = new int[n];
	int* low = new int[n];
	int* sccs = new int[n];
	bool* vis = new bool[n];
	std::stack<int> s;
	int sccs_cnt;
	int id;
	std::multimap<int, std::list<int>>* multi_map = new std::multimap<int, std::list<int>>;

	sccs_cnt = 0;
	id = 0;
	memset(ids, -1, sizeof(int) * n);
	memset(vis, false, sizeof(bool) * n);

	for (int i = 0; i < n; i++)
		if (ids[i] == -1)
			dfs(i, ids, low, vis, sccs, &id, &sccs_cnt, &s);

	for (int i = 0; i < n; i++) {
		auto pos_key = multi_map->find(n);
		if (pos_key == multi_map->end())
			multi_map->emplace(sccs[i], new std::list<int>);
		auto pos = multi_map->equal_range(sccs[i]);
		std::multimap<int, std::list<int>>::iterator it;
		for (it = pos.first; it != pos.second; it++)
			if (it->first == sccs[i])
				it->second.push_back(i);
	}
	delete[] ids;
	delete[] low;
	delete[] sccs;
	delete[] vis;
	return multi_map;
}