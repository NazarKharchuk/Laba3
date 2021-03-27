#include "functions.h"
#include "queue.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int col, row;
	char** labyrinth = read_file(col, row);

	print_lab(labyrinth, row, col);

	koordinats S{ 6,1 }, E{ 1,6 };		//Start and end point

	int num_of_vert = vert_num(labyrinth, row, col);
	cout << num_of_vert<<" - recommended capacity."<< endl;

	int used_vert = 0;
	point_passport* using_points = alg_dijkstra(labyrinth, row, col, num_of_vert, S, E, used_vert);

	show_path(labyrinth, row, col, using_points, used_vert, E);
	print_lab(labyrinth, row, col);

	delete [] using_points;
	delete_matr(labyrinth, row);
}