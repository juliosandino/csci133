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
	void create_edge(int source, int destination, float w) {
		edges.at(source).push_back(edge_type{destination, w});
	}

	bool has_edge(int source, int destination) {
		for (edge_type& e : edges.at(source))
			if (e.destination == destination)
				return true;

		return false;
	}

	void print() {
		for (int i = 0; i < edges.size(); i++) {
			std::cout << i << " has an edge to: ";
			for (edge_type& e: edges.at(i)) {
				std::cout << e.destination << ", ";
			}

			std::cout << std::endl;
		}
	}

	void bfs(int start, int target) {
		queue<int> q;
		vector<bool> explored(edges.size());
		int distance = 0;

		q.push(start);

		while (!q.empty()) {
			int n = q.front();
			q.pop();

			if (n == target) {
				std::cout << "Distance: " << distance << std::endl;
			}

			distance++;

			explored.at(n) = true;
			for (auto e: edges.at(n))
				if(!explored.at(e.destination))
					q.push(e.destination);
		}
	}
};

//void adj_list::create_edge(int source, int destination, float w = 1) {
//	edges.at(source).push_back(edge_type{destination, w});
//}

//bool adj_list::has_edge(int source, int destination) {
//	for (edge_type& e : edges.at(source))
//		if (e.destination == destination)
//			return true;
//
//	return false;
//}

//void adj_list::print() {
//	for (int i = 0; i < edges.size(); i++) {
//		std::cout << i << " has an edge to: ";
//		for (edge_type& e: edges.at(i)) {
//			std::cout << e.destination << ", ";
//		}
//
//		std::cout << std::endl;
//	}
//}


//void adj_list::bfs(int start, int target) {
//	queue<int> q;
//	vector<bool> explored(edges.size());
//	int distance = 0;
//
//	q.push(start);
//
//	while (!q.empty()) {
//		int n = q.front();
//		q.pop();
//
//		if (n == target) {
//			std::cout << "Distance: " << distance << std::endl;
//		}
//
//		distance++;
//
//		explored.at(n) = true;
//		for (auto e: edges.at(n))
//			if(!explored.at(e.destination))
//				q.push(e.destination);
//	}
//}
