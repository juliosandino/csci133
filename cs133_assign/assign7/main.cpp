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
				if (tokens.size() == 2 && graphs[tokens.at(1)]) {
					string name = tokens.at(1);

					graphs[name]->print();
				} else {
					cout << "Wrong amount of arguments" << std::endl;
				}
			}
			else if (command == "arc") {
			//arc code
			}
			else if (command == "biarc") {
			//biarc code
			}
			else if (command == "bfs") {
			//breadth-first command
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
