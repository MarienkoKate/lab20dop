#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "Header.h"

std::vector<int> from_string(std::string str) {

	std::vector<int> list;

	std::stringstream strr(str);
	int i = 0;
	while (!strr.eof()) {
		int k = 0;
		strr >> k;

		list.push_back(k);


	}

	return list;
}

void print2(std::vector<int> v) {
	for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";
	std::cout << std::endl;
}

void print(graph_t g) {
	for (auto it = g.begin(); it != g.end(); ++it) print2(*it);
}

graph_t read_file(const std::string& file_name, int* vertex) {

	std::vector<std::vector<int>> v;
	std::ifstream file(file_name);
	std::string str, name;
	int j = 0;
	std::vector<int> vv;

	if (!file.is_open()) std::cout << "error\n";

	else {
		while (true) {

			if (!file.eof()) {

				std::getline(file, str);

				if (j == 0) {
					name = str;
					*vertex = std::stoi(name);

				}
				else if (str == "-") {
					v.resize(j);
				}
				else {
					v.push_back(from_string(str));
				}
				j++;
				str.clear();
			}
			else break;
		}

		file.close();
		print(v);
		return v;
	}

}



void write_dot(const char* fname, const graph_t& g)
{
	std::ofstream out(fname);
	out << "digraph {\n";
	for (size_t i = 0; i < g.size(); ++i) {
		out << "  " << i << ";\n";
	}
	for (size_t v = 0; v < g.size(); ++v) {
		for (auto u : g[v]) {
			out << "  " << v << " -> " << u << ";\n";
		}
	}
	out << "}\n";
}
