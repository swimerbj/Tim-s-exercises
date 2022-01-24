#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define MAXN 100

int ret_mult_gl[200];
int AC[200];
int BD[200];
/*
int mult_gl(int x[], int y[], int size) {

	memset(ret_mult_gl, 0, sizeof(ret_mult_gl));

	int tmp_ret;
	if (size == 1) {
		tmp_ret = x[0] * y[0];
		ret_mult_gl[0] = tmp_ret % 10;
		ret_mult_gl[1] = tmp_ret / 10;
		return (bool)ret_mult_gl[1] + 1;
	}

	int* A = &x[size / 2];
	int* B = &x[0];
	int* C = &y[size / 2];
	int* D = &y[0];
	size /= 2;

	int AC_size = mult_gl(A, C, size);
	for (int i = 0; i < AC_size; i++) AC[i] = ret_mult_gl[i];
	int BD_size = mult_gl(B, D, size);
	for (int i = 0; i < BD_size; i++) BD[i] = ret_mult_gl[i];

	int i = 0, tmp_sum = 0;
	for (i = 0; i < size; i++)	{
		tmp_sum = A[i] + B[i];
		SumAC[i] += tmp_sum % 10;
		SumAC[i + 1] = tmp_sum / 10;
	}
//	if SumAC[i + 1] ;

	if (size_x == 1) {
		int i, carry = 0;
		for (i = 0; i < size_y; i++) {
			ret_mult_gl[i] = x[0] * y[i] + carry;
			carry = ret_mult_gl[i] / 10;
			ret_mult_gl[i] %= 10;
		}
		ret_mult_gl[i] += carry;
		return;
	}

	if (size_y == 1) {
		int i, carry = 0;
		for (i = 0; i < size_x; i++) {
			ret_mult_gl[i] = y[0] * x[i] + carry;
			carry = ret_mult_gl[i] / 10;
			ret_mult_gl[i] %= 10;
		}
		ret_mult_gl[i] += carry;
		return;
	}


	int size_x1, size_x2;
	int size_y1, size_y2;

	size_x1 = std::min(size_x, size_y) / 2;
	size_x2 = size_x - size_x1;
	size_y1 = size_x2;
	size_y2 = size_y - size_y1;

	int s1[MAXN], s2[MAXN], s3[MAXN];
	int size_s1 = std::max(size_x1, size_y1);
	int size_s2 = size_x2;
	int size_s3;

	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	memset(s3, 0, sizeof(s1));

	mult(x, size_x1, y, size_y1);

	for (int i = 0; i < size_s1 + 1; i++)
		s1[i] = ret_mult_gl[i], ret_mult_gl[i] = 0;
	if (s1[size_s1]) size_s1++;


	mult(x + size_x1, size_x2, y + size_y1, size_y2);

	for (int i = 0; i < size_s2 + 1; i++)
		s2[i] = ret_mult_gl[i], ret_mult_gl[i] = 0;
	if (s2[size_s2]) size_s2++;

	int p1[MAXN / 2], p2[MAXN / 2];
	int size_p1, size_p2;

	memset(p1, 0, sizeof(p1));
	memset(p2, 0, sizeof(p2));

	int c;

	c = 0;
	for (int i = 0; i < size_x2; i++)
		p1[i] = x[i] + x[i + size_x1], c = p1[i] / 10, p1[i] %= 10;
	p1[size_x2] = c;

	size_p1 = size_x1;
	if (c) size_p1++;

	c = 0;
	for (int i = 0; i < size_y2; i++)
		p2[i] = y[i] + y[i + size_y1], c = p2[i] / 10, p2[i] %= 10;
	p2[size_y2] = c;

	size_p2 = size_x2;
	if (c) size_p2++;

	mult(p1, size_p1, p2, size_p2);

	for (int i = 0; i < size_p1 + size_p2; i++)
		s3[i] = ret_mult_gl[i], ret_mult_gl[i] = 0;
	size_s3 = size_p1 + size_p2;

	c = 0;
	int s4[MAXN];
	memset(s4, 0, sizeof(s4));
	int size_s4 = size_x2 + size_y2;
	for (int i = 0; i < size_s4; i++)
		s4[i] = s1[i] + s2[i], c = s4[i] / 10, s4[i] %= 10;
	s4[size_s4] = c;
	if (c) size_s4++;

	c = 0;
	for (int i = 0; i < size_x2 + size_y2; i++) {
		s3[i] -= s4[i] + c;
		if (s3[i] < 0) c = 1, s3[i] += 10;
		else c = 0;
	}
	if (c) size_s3--;

	c = 0;
	for (int i = 0; i < size_x + size_y + 1; i++) {
		ret_mult_gl[i] = s1[i] + c;
		if (i >= size_x1)
			ret_mult_gl[i] += s3[i - size_x1];
		if (i >= 2 * size_x1)
			ret_mult_gl[i] += s2[i - 2 * size_x1];
		c = ret_mult_gl[i] / 10;
		ret_mult_gl[i] %= 10;
	}
	ret_mult_gl[size_x + size_y] = c;
}
*/

/*
int main() {
	int a[4] = { 6, 6, 7, 8 };
	int b[4] = { 1, 2, 3, 4 };
	mult(a, b, 4);
	for (int i = 0; i < 9; i++)
		std::cout << ret[i];
	return 0;
}
*/