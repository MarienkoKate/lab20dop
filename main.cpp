#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <iostream>
#include "Header.h"

typedef std::vector<int> adjacent_t;
typedef std::vector<adjacent_t> graph_t;

int main()
{
    graph_t g;
	int vert = 0.;
	g = read_file("input.txt", &vert);
    write_dot("g.dot", g);
    system("dot g.dot -Tpng -og.png");
}