#include <cmath>
#include <iostream>
#include "point.h"


double Cos(double x1, double y1, double x2, double y2) {
	double scalar_prod = x1 * x2 + y1 * y2;
	double a1_len = sqrt(x1 * x1 + y1 * y1);
	double a2_len = sqrt(x2 * x2 + y2 * y2);

	double mult_of_len = a1_len * a2_len;

	if (mult_of_len == 0)
		return 0;
	else
		return scalar_prod / mult_of_len;
}

void JarvisAlgorithm(Point* data, Point* result, int size) {
	int first_p, prev_p, cur_p, next_p;
	bool* is_used;
	int *indexes;
	int k = 0;
	double max_cos, min_cos;

	indexes = new int[size];
	is_used = new bool[size];
	
	first_p = 0;

	for (int i = 0; i < size; i++) {
		indexes[i] = -1;
		is_used[i] = false;
	}

	//Looking for a first point
	for (int i = 0; i < size; i++) {
		if ((data[i].y < data[first_p].y) ||
			(data[i].y == data[first_p].y) && (data[i].x < data[first_p].x))
			first_p = i;
	}

	indexes[k++] = first_p;

	//Looking for a second point
	max_cos = -1;

	for (int i = 0; i < size; i++) {
		if (!is_used[i]) {
			double cur_cos = Cos(1, 0, data[i].x - data[first_p].x,
								data[i].y - data[first_p].y);

			if (cur_cos > max_cos) {
				cur_p = i;
				max_cos = cur_cos;
			}
		}
	}

	indexes[k++] = cur_p;
	is_used[cur_p] = true;

	//The remaining steps of computing the convex hull
	prev_p = first_p;

	do {
		min_cos = 1;

		for (int i = 0; i < size; i++) {
			if (!is_used[i]) {
				double cur_cos = Cos(data[prev_p].x - data[cur_p].x, data[prev_p].y - data[cur_p].y,
					data[i].x - data[cur_p].x, data[i].y - data[cur_p].y);

				if (cur_cos < min_cos) {
					next_p = i;
					min_cos = cur_cos;
				}
			}
		}

		if (next_p != first_p) {
			indexes[k++] = next_p;
			is_used[next_p] = true;
			prev_p = cur_p;
			cur_p = next_p;
		}
	}
	while (next_p != first_p);

	for (int i = 0; i < k; i++) {
		std::cout << indexes[i] << std::endl;
	}
}
