#include <iostream>
#include <math.h>
#include <algorithm>

class point {
public:
	double x;
	double y;
};

bool comp_x(point& a, point& b) { return a.x < b.x; }
bool comp_y(point& a, point& b) { return a.y < b.y; }

double d(std::pair<point, point> a) { 
	return std::sqrt((a.first.x - a.second.x) * (a.first.x - a.second.x) + (a.first.y - a.second.y) * (a.first.y - a.second.y));
}

std::pair<point, point> closest_split_pair(point arr1[], point arr2[], double& best, int& size) {
	point Sy[100];
	double min_x = arr1[size / 2 - 1].x - best, max_x = arr1[size / 2].x + best;
	int k = 0;
	while (arr1[k].x < min_x) k++;
	int size_Sy;
	for (size_Sy = k; size_Sy < size && arr1[size_Sy].x <= max_x; size_Sy++)
		Sy[size_Sy - k] = arr1[size_Sy];
	std::sort(Sy, Sy + size_Sy, comp_y);
	int g = best;
	std::pair<point, point> b;
	for(int i = 0; i < size_Sy; i++)
		for (int j = 0; j < std::min(7, size_Sy - i); j++) {
			point m = Sy[i], n = Sy[i + j + 1];
			std::pair<point, point> tmp(m, n);
			if (d(tmp) < best)
				b = tmp, g = d(tmp);
		}
	return b;
}

void copy(std::pair<point, point>* k, std::pair<point, point>& a) {
	(*k).first.x = a.first.x;
	(*k).first.y = a.first.y;
	(*k).second.x = a.second.x;
	(*k).second.y = a.second.y;
}

std::pair<point, point> closest_pair(point arr1[], point arr2[], int size) {
	if (size <= 1) {
		point a;
		a.x = 0, a.y = 0;
		point b;
		b.x = INT_MAX, b.y = INT_MAX;
		std::pair<point, point> k(a, b);
		return k;
	}
	std::pair<point, point> left_half = closest_pair(arr1, arr2, size / 2);
	std::pair<point, point> right_half = closest_pair(arr1 + size / 2, arr2 + size / 2, (size + 1) / 2);
	double best = std::min(d(left_half), d(right_half));
	std::pair<point, point> greatest;
	if (d(left_half) < d(right_half)) copy(&greatest, left_half);
	else copy(&greatest, right_half);
	std::pair<point, point> split = closest_split_pair(arr1, arr2, best, size);
	if (d(split) < d(greatest)) copy(&greatest, split);
	return greatest;
}

std::pair<point, point> closest_pair(point arr[], int size) {
	point sorted_by_x[100];
	for (int i = 0; i < size; i++)
		sorted_by_x[i].x = arr[i].x, sorted_by_x[i].y = arr[i].y;
	std::sort(sorted_by_x, sorted_by_x + size, comp_x);

	point sorted_by_y[100];
	for (int i = 0; i < size; i++)
		sorted_by_y[i].x = arr[i].x, sorted_by_y[i].y = arr[i].y;
	std::sort(sorted_by_y, sorted_by_y + size, comp_y);

	std::pair<point, point> ret = closest_pair(sorted_by_x, sorted_by_y, size);

	return ret;
}

/*
int main() {
	int size = 3;
	point a;
	a.x = 1, a.y = 1;
	point b;
	b.x = 3, b.y = 2;
	point c;
	c.x = 0, c.y = 0;
	point point_set[100] = { a, b, c };

	std::pair<point, point> best = closest_pair(point_set, size);

	std::cout << best.first.x << " " << best.first.y << std::endl;
	std::cout << best.second.x << " " << best.second.y << std::endl;

	return 0;
}
*/