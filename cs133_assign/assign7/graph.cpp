#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <queue>
#include <string>
#include <map>
using std::queue;
using std::vector;
using std::list;

class adj_list {
	public:
		adj_list(unsigned int node_count) {
			edges = vector<list<edge_type>>  {node_count};
		}

		struct edge_type {
			int destination;
			float weight;
		};

	vector<list<edge_type>> edges;

	//member function
	void create_edge(int source, int destination, float w = 1);
	bool has_edge(int source, int destination);
	void print();
	void bfs(int start, int target);
};

void adj_list::create_edge(int source, int destination, float w) {
	if ((source < 0 || destination < 0) || (source > edges.size() || destination >edges.size()))
		throw std::exception();
	edges.at(source).push_back(edge_type{destination, w});
}

bool adj_list::has_edge(int source, int destination) {
	for (edge_type& e : edges.at(source))
		if (e.destination == destination)
			return true;

	return false;
}

void adj_list::print() {
	for (int i = 0; i < edges.size(); i++) {
		std::cout << i << " has an edge to: ";
		for (edge_type& e: edges.at(i)) {
			std::cout << e.destination << ", ";
		}

		std::cout << std::endl;
	}
}

void adj_list::bfs(int start, int target) {
	queue<int> q;
	vector<bool> explored(edges.size());
	vector<int> dist(edges.size());
	dist.at(start) = 0;

	q.push(start);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (n == target) {
			std::cout << "Distance: " << dist.at(n) << std::endl;
			return;
		}

		explored.at(n) = true;
		for (auto e: edges.at(n))
			if(!explored.at(e.destination)) {
				q.push(e.destination);
				dist.at(e.destination) = dist.at(n) + 1;
			}
	}

	std::cout << "No path found to " << target << std::endl;
}
