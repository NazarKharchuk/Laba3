#include "functions.h"
#include "queue.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int col, row;
	char** labyrinth = read_file(col, row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout <<setw(2)<< labyrinth[i][j];
		}
		cout << endl;
	}

	point_passport* using_points = alg_dijkstra(labyrinth, row, col);



	delete [] using_points;
	delete_matr(labyrinth, row);
	
}