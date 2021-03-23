#include "functions.h"
#include "queue.h"

//Read file and creating matrix with labirinth
char** read_file(int& col, int& row) {
	col = row = 0;
	ifstream fin("3.txt");
	if (!fin.is_open()) {
		cout << "File open error!\n";
	}
	else {
		char item;
		while (fin.get(item)) {
			if ((item == 'X') && (row == 0)) col++;
			if (item == '\n')row++;
		}
	}

	char** labyrinth = new char* [row];
	for (int i = 0; i < row; i++) {
		labyrinth[i] = new char [col];
	}

	fin.close();

	ifstream fin2("3.txt");
	char item;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!fin2.eof()) {
				fin2.get(item);
				if(j!=0)fin2.get(item);
				if (item == '\n') fin2.get(item);
				labyrinth[i][j] = item;
			}
		}
	}

	fin2.close();

	return labyrinth;
}

//Delete dinamic matrix
void delete_matr(char** labyrinth, int row) {
	for (int i = 0; i < row; i++) {
		delete labyrinth[i];
	}
	delete[] labyrinth;
}

//Dijkstra’s algorithm
point_passport* alg_dijkstra(char** labyrinth, int row, int col, int vert_num) {
	point_passport* using_points = new point_passport[vert_num];

	koordinats S{ 6,1 }, E{ 1,6 };		//Start and end point

	queue<koordinats> our_queue;		//Queue
	our_queue.enqueue(S);
	using_points[0].point.i = S.i;
	using_points[0].point.j = S.j;
	using_points[0].step = 0;
	using_points[0].parent.i = S.i;
	using_points[0].parent.j = S.j;

	koordinats cur_point, neigh_point;
	int neighbours[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	int pos, X=1;
	int step_num;
	bool finish = false;

	while (!our_queue.is_empty()) {
		cur_point = our_queue.first_element();
		our_queue.dequeue();

		pos = find_point(using_points, X, cur_point);
		step_num = using_points[pos].step + 1 ;
		for (int n = 0; n < 4; n++) {
			neigh_point.i = cur_point.i + neighbours[n][0];
			neigh_point.j = cur_point.j + neighbours[n][1];
			if (labyrinth[neigh_point.i][neigh_point.j] == 'X')continue;
			if ((neigh_point.i == E.i) && (neigh_point.j == E.j)) {
				finish = true;
				using_points[X].point.i = neigh_point.i;
				using_points[X].point.j = neigh_point.j;
				using_points[X].step = step_num;
				using_points[X].parent.i = cur_point.i;
				using_points[X].parent.j = cur_point.j;
				X++;
				break;
			}

			pos = find_point(using_points, X, neigh_point);
			if (pos == -1) {
				using_points[X].point.i = neigh_point.i;
				using_points[X].point.j = neigh_point.j;
				using_points[X].step = step_num;
				using_points[X].parent.i= cur_point.i;
				using_points[X].parent.j = cur_point.j;
				X++;
				our_queue.enqueue(neigh_point);
			}
			else {
				if (step_num < using_points[pos].step) {
					using_points[pos].step = step_num;
					using_points[pos].parent.i = cur_point.i;
					using_points[pos].parent.j = cur_point.j;
				}
			}
		}
		if (finish)break;
	}

	for (int m = 0; m < X; m++) {
		cout << "(" << using_points[m].point.i << " " << using_points[m].point.j << ")  " << using_points[m].step << "   (" << using_points[m].parent.i << " " << using_points[m].parent.j << ")  " << endl;
	}

	return using_points;
}

//A function that looks for the number of vertices of a graph
int vert_num(char** labyrinth, int row, int col ) {
	int num = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++){
			if (labyrinth[i][j] == ' ') num++;
		}
	}
	return num;
}

//Did we use a this point?
int find_point(point_passport* using_points, int size, koordinats P) {
	int i = -1;
	for (int n = 0; n < size; n++) {
		if ((using_points[n].point.i == P.i) && (using_points[n].point.j == P.j)) i = n;
	}
	return i;
}
