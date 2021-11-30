#ifndef grviz
#define grviz

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>

typedef std::vector<int> vi;
typedef std::vector<vi> graph_t;

std::vector<int> from_string(std::string str);
void print2(std::vector<int> v);
void print(graph_t g);
graph_t read_file(const std::string& file_name, int* vertex);
void write_dot(const char* fname, const graph_t& g);

#endif grviz


