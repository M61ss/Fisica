#include "math_functions.h"

/* ALGEBRAIC FUNCTIONS */

int Factorial(const int x) {
	int result = 1;
	for (int i = x; i > 1; i--) {
		result = result * i;
	}
	if (x < 0) {
		MATH_ERROR("%s (Factorial): line %d: x < 0.\n", __FILE__, __LINE__);
	}

	return result;
}

double Pitagora(const double x, const double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

double BinomialCoefficient(const int n, const int k) {
	if (k > n) {
		MATH_ERROR("%s (BinomialCoefficient): line %d: n > k.\n", __FILE__, __LINE__);
	}
	const int x = Factorial(n);
	const int y = Factorial(k);
	const int differenza = n - k;
	const int c = Factorial(differenza);

	return (double)x / ((double)y * (double)c);
}

double SymmetricBinomial(const int n, const int h, const int k) {
	double x = (double)Factorial(n);
	double y = (double)Factorial(h);
	double z = (double)Factorial(k);

	return x / (y * z);
}

double ScalarProductV(const double* v1, const double* v2, const size_t v1_size, const size_t v2_size) {
	if (v1 == NULL || v2 == NULL || v1_size == 0 || v2_size == 0) {
		INVALID_NULL_POINTER("%s (ScalarProductV): line %d: v is a NULL pointer or v_size <= 0.\n", __FILE__, __LINE__);
	}
	else if (v1_size != v2_size) {
		MATH_ERROR("%s (ScalarProductV): line %d: v1 and v2 have different sizes.\n", __FILE__, __LINE__);
	}
	double result = 0;
	for (size_t i = 0; i < v1_size; i++) {
		result += v1[i] * v2[i];
	}

	return result;
}

void ScalarProductS(double* v, const double k, const size_t v_size) {
	if (v == NULL || v_size == 0) {
		INVALID_NULL_POINTER("%s (ScalarProductS): line %d: v is a NULL pointer or v_size <= 0.\n", __FILE__, __LINE__);
	}
	for (size_t i = 0; i < v_size; i++) {
		v[i] *= k;
	}
}

/* AREA CALCULATIONS */

double TriangleArea(const double base, const double h) {
	return (base * h) / (double)2;
}

double SquareArea(const double side) {
	return pow(side, 2);
}

double ParallelogramArea(const double base, const double h) {
	return base * h;
}

double RhombusArea(const double d1, const  double d2) {
	return (d1 * d2) / (double)2;
}

double TrapezeArea(const double b1, const double b2, const double h) {
	return ((b1 + b2) * h) / (double)2;
}

double CircleArea(const double r) {
	return 3.14 * pow(r, 2);
}

double CircularCrownArea(const double rex, const double rin) {
	return ((pow(rex, 2) - pow(rin, 2)) * 3.14) / (double)2;
}

/* VOLUMES CALCULATIONS */

double RectangleVolume(const double l, const double p, const double h) {
	return ParallelogramArea(l, p) * h;
}

double CubeVolume(const double l) {
	return pow(l, 3);
}

double PiramidVolume(const double base, const double hb, const double h) {
	return (TriangleArea(base, hb) * h) / 3;
}