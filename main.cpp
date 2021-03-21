#include "functions.h"
#include "queue.h"

int main() {
	int col, row;
	char** labyrinth = read_file(col, row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << labyrinth[i][j];
		}
		cout << endl;
	}
	delete_matr(labyrinth, row);
}