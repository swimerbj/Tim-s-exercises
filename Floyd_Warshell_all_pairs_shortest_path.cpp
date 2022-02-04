#include "graph.h"

int** Floyd_Warshell_all_pairs_shortest_path() {
	int** dist = new int*[n];
	for (int i = 0; i < n; i++)
		dist[i] = new int[n], memset(dist[i], INT_MAX, sizeof(int) * n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < graph[i].size(); i++)
			dist[i][graph[i][j].to] = graph[i][j].cost;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (dist[i][j] + dist[j][k] < dist[i][k])
					dist[i][k] = dist[i][j] + dist[i][k];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (dist[i][j] != INT_MAX && dist[j][k] != INT_MAX && dist[j][j] < 0)
					dist[i][k] = -INT_MAX;
	return dist;
}