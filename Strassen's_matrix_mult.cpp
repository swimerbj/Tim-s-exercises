#include <iostream>
#include <math.h>
#include <algorithm>

#define MAXN 2

int ret_matrix[MAXN][MAXN];

void matrix_add(int a[MAXN][MAXN], int b[MAXN][MAXN], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret_matrix[i][j] = a[i][j] + b[i][j];
}

void matrix_minus(int a[MAXN][MAXN], int b[MAXN][MAXN], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret_matrix[i][j] = a[i][j] - b[i][j];
}

void matrix_mult(int a[MAXN][MAXN],  int b[MAXN][MAXN], int n) {
	if (n == 1) {
		ret_matrix[0][0] = a[0][0] * b[0][0];
		return;
	}

	int tmp1[MAXN][MAXN], tmp2[MAXN][MAXN];
	memset(tmp1, 0, sizeof(tmp1));
	memset(tmp2, 0, sizeof(tmp2));

	int A[MAXN][MAXN];
	memset(A, 0, sizeof(A));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			A[i][j] = a[i][j];

	int B[MAXN][MAXN];
	memset(B, 0, sizeof(B));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			B[i][j] = a[i][j + n / 2];

	int C[MAXN][MAXN];
	memset(C, 0, sizeof(C));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			C[i][j] = a[i + n / 2][j];

	int D[MAXN][MAXN];
	memset(D, 0, sizeof(D));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			D[i][j] = a[i + n / 2][j + n / 2];

	
	int E[MAXN][MAXN];
	memset(E, 0, sizeof(E));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			E[i][j] = b[i][j];

	int F[MAXN][MAXN];
	memset(F, 0, sizeof(F));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			F[i][j] = b[i][j + n / 2];

	int G[MAXN][MAXN];
	memset(G, 0, sizeof(G));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			G[i][j] = b[i + n / 2][j];

	int H[MAXN][MAXN];
	memset(H, 0, sizeof(H));
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			H[i][j] = b[i + n / 2][j + n / 2];


	int p1[MAXN][MAXN];
	memset(p1, 0, sizeof(p1));
	matrix_minus(F, H, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p1[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(p1, A, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p1[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	int p2[MAXN][MAXN];
	memset(p2, 0, sizeof(p2));
	matrix_add(A, B, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p2[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(p2, H, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p2[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	int p3[MAXN][MAXN];
	memset(p3, 0, sizeof(p3));
	matrix_add(C, D, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p3[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(p3, E, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p3[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	int p4[MAXN][MAXN];
	memset(p4, 0, sizeof(p4));
	matrix_minus(G, E, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p4[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(p4, D, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p4[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	int p5[MAXN][MAXN];
	memset(p5, 0, sizeof(p5));
	matrix_add(A, D, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			tmp1[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_add(E, H, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			tmp2[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(tmp1, tmp2, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p5[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	int p6[MAXN][MAXN];
	memset(p6, 0, sizeof(p6));
	matrix_minus(B, D, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			tmp1[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_add(G, H, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			tmp2[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(tmp1, tmp2, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p6[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	int p7[MAXN][MAXN];
	memset(p7, 0, sizeof(p7));
	matrix_minus(A, C, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			tmp1[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_add(E, F, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			tmp2[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;
	matrix_mult(tmp1, tmp2, n / 2);
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			p7[i][j] = ret_matrix[i][j], ret_matrix[i][j] = 0;

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			ret_matrix[i][j] = p5[i][j] + p4[i][j] + p6[i][j] - p2[i][j];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			ret_matrix[i][j + n / 2] = p1[i][j] + p2[i][j];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			ret_matrix[i + n / 2][j] = p3[i][j] + p4[i][j];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			ret_matrix[i + n / 2][j + n / 2] = p1[i][j] + p5[i][j] - p3[i][j] - p7[i][j];
	
}

/*
int main() {
	int n = 2;
	int a[MAXN][MAXN] = { 1, 2, 3, 4 };
	int b[MAXN][MAXN] = { 5, 6, 7, 8 };
	matrix_mult(a, b, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << ret_matrix[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}
*/