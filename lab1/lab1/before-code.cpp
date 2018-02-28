#include <cstdio>
#include <cstdlib>
#include "point.h"

void JarvisAlgorithm(Point* data, Point* result, int size);

int main(int argc, char* argv[]) {
	int size = 7;
	
	if (argc > 1)
		size = atoi(argv[1]);

	Point* data = new Point[size];
	Point* result = new Point[size];
	
	data[0].x = 2; data[0].y = 2;
	data[1].x = 0; data[1].y = 3;
	data[2].x = 1; data[2].y = 1;
	data[3].x = 2; data[3].y = 1;
	data[4].x = 3; data[4].y = 0;
	data[5].x = 0; data[5].y = 0;
	data[6].x = 3; data[6].y = 3;
	
	JarvisAlgorithm(data, result, size);

	return 0;
}