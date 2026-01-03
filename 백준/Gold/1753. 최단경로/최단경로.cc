/*
[1753] 최단경로
start:	20:58
end:	21:10
*/
#include<iostream>
#include<vector>
#include<queue>
#define INF 21e8

typedef struct{
	int v,cost;
}Edge;

int V, E;
int startNode;
std::vector<std::vector<Edge>> adj;
std::vector<int> dist;

struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

void dijkstra() {
	dist.resize(V + 1, INF);
	dist[startNode] = 0;

	std::priority_queue<Edge, std::vector<Edge>, compare> pq;
	pq.push({ startNode, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.v] < now.cost) continue;

		int u = now.v;
		int cost_u = now.cost;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].v;
			int cost_uv = adj[u][i].cost;

			if (dist[v] > cost_u + cost_uv) {
				dist[v] = cost_u + cost_uv;
				pq.push({ v, dist[v] });
			}
		}
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin
		>> V >> E
		>> startNode;
	
	adj.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			std::cout << "INF\n";
		else
			std::cout << dist[i] << "\n";
	}

	return 0;
}