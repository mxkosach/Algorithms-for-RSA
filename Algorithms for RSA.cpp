#include <iostream>
#include "Algorithms for RSA.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//int a = 35, b = 15;
	int a, b, n;
	char* in = new char[64];
	cout << "Extended Euclidean algorithm\n";
	cout << "Enter the numer a: ";
	cin >> in;
	a = atoi(in);
	cout << "Enter the numer b: ";
	cin >> in;
	b = atoi(in);
	extendedEuclideanAlgorithm(a, b);
	cout << "*********************************\n";

	cout << "Fast Power Algorithm\n";
	cout << "Enter the number: ";
	cin >> in;
	a = atoi(in);
	cout << "Enter the power: ";
	cin >> in;
	n = atoi(in);
	cout << a << "^" << n << " = " << fastPower(a, n) << endl;

	cout << endl;
	system("pause");
}

int fastPower(unsigned int a, unsigned int n) {
	long long res = 1;
	while (n)
	{
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

void extendedEuclideanAlgorithm(int a, int b)
{
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	int r, r1 = b, r0 = a, y, y1 = 1, y0 = 0, x, x1 = 0, x0 = 1, q;

	while (r0 > 0) {
		q = r1 / r0;

		r = r1 - q * r0;
		r1 = r0;
		r0 = r;

		x = x1 - q * x0;
		x1 = x0;
		x0 = x;

		y = y1 - q * y0;
		y1 = y0;
		y0 = y;
	}

	int gcd = r1;
	cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
	cout << a << "x" << (b > 0 ? "+" : "") << b << "y=" << gcd << endl;
	cout << "x = " << x1 << " + " << b / gcd << "t" << endl;
	cout << "y = " << y1 << " - " << a / gcd << "t" << endl;
}
