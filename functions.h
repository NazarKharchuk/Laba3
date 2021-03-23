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
point_passport* alg_dijkstra(char **, int, int, int);
int vert_num(char**, int, int);
int find_point(point_passport*, int, koordinats);
