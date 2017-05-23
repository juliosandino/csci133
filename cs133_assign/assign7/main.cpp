/*
main.cpp
this is where the registry part of the program runs

Julio Sandino

May-14 first submission
May-17 resubmission:
	Finished the registry commands in main() function
	Fixed the distance algorithm in bfs() function
	Added a throw in create_edge() function
	Moved member function definitions outside of class adj_list
	registry program catches all the throws of adj_list functinons
	Added the registry in the comments
*/

/*
Registry Commands:
create 10 r
arc 0 2 r
arc 1 0 r
arc 2 1 r
arc 3 2 r
arc 3 1 r
arc 3 4 r
arc 4 7 r
arc 4 5 r
biarc 5 6 r
arc 7 3 r
arc 8 7 r
arc 8 9 r
arc 9 7 r
*/

#include "graph.cpp"
#include <sstream>
using std::string;
using std::cout;
using std::map;

vector<string> split_words(string line);

int main() {
	map<string, adj_list*> graphs;
	string line;
	vector<string> tokens;
	while (true) {
		cout << "> ";
		std::getline(std::cin, line);
		tokens = split_words(line);
		
		if (tokens.size() != 0) {
			string command = tokens.at(0);
			
			if (command == "create") {
				if (tokens.size() == 3) {
					try {
						int graph_size = std::stoi(tokens.at(1));
						string name = tokens.at(2);

						graphs[name] = new adj_list(graph_size);
					} catch (std::exception e) {
						cout << "Invalid Argument" << std::endl;
					}
				} else {
					cout << "Wrong amount of arguments" << std::endl;
				}
			}
			else if (command == "print") {
					//checks if the graph exists
				if (tokens.size() == 2 && graphs[tokens.at(1)]) {
					string name = tokens.at(1);

					graphs[name]->print();
				} else {
					cout << "Error. Graph doesn't exist or Invalid Arguments" << std::endl;
				}
			}
			else if (command == "arc") {
				if (tokens.size() == 4) {
					if (graphs[tokens.at(3)]) {
						try {
							int source = std::stoi(tokens.at(1));
							int destination = std::stoi(tokens.at(2));

							graphs[tokens.at(3)]->create_edge(source, destination);
						} catch (std::exception e) {
							cout << "Error. Invalid Arguments" << std::endl;
						}
					} else {
						cout << "Error. Register doesn't exist" << std::endl;
					}
				} else {
					cout << "Wrong amount of arguments" << std::endl;
				}
			}
			else if (command == "biarc") {
				if (tokens.size() == 4) {
					if (graphs[tokens.at(3)]) {
						try {
							int source = std::stoi(tokens.at(1));
							int destination = std::stoi(tokens.at(2));

							graphs[tokens.at(3)]->create_edge(source, destination);
							graphs[tokens.at(3)]->create_edge(destination, source);
						} catch (std::exception e) {
							cout << "Error. Invalid Arguments" << std::endl;
						}
					} else {
						cout << "Error. Register doesn't exist" << std::endl;
					}
				} else {
					cout << "Wrong amount of arguments" << std::endl;
				}
			}
			else if (command == "bfs") {
				if (tokens.size() == 4) {
					if (graphs[tokens.at(3)]) {
						try {
							int source = std::stoi(tokens.at(1));
							int destination = std::stoi(tokens.at(2));

							graphs[tokens.at(3)]->bfs(source, destination);
						} catch (std::exception e) {
							cout << "Error. Invalid Arguments" << std::endl;
						}
					} else {
						cout << "Error. Register doesn't exist" << std::endl;
					}
				} else {
					cout << "Wrong amount of arguments" << std::endl;
				}
			}

		} else {
			continue;
		}
	}
}

vector<string> split_words(string line) {
	vector<string> words;
	string current_word;

	std::stringstream in(line);

	while (in >> current_word) {
		words.push_back(current_word);
	}

	return words;
}
