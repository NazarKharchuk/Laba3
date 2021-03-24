#pragma once

#include <iostream>
#include "queue.h"
#include <fstream>
#include <iomanip>

using namespace std;

struct koordinats {
	int i;
	int j;
};

struct point_passport {
	koordinats point;
	int step;
	koordinats parent;
};

char** read_file(int&,  int&);
void delete_matr(char**, int);
point_passport* alg_dijkstra(char **, int, int, int, koordinats, koordinats, int&);
int vert_num(char**, int, int);
int find_point(point_passport*, int, koordinats);
void print_lab(char**, int, int);
char character(int);
void show_path(char**, int, int, point_passport*, int, koordinats);

