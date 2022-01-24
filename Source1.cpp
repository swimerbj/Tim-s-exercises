#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

#define m_max_digit 100

class Int {
private:
	const int mod = 10;
public:
	int num[m_max_digit];
	int digit;
	int neg = 1;

	Int() { 
		memset(num, 0, sizeof(num)); 
		digit = 0; 
	}

	Int(const int* arr, int d) {
		digit = d;
		memset(num, 0, sizeof(num));
		for (int i = 0; i < d; i++)
			num[i] = arr[i];
	}

	Int(const Int& a) {
		digit = a.digit;
		for (int i = 0; i < digit; i++)
			num[i] = a.num[i];
		neg = a.neg;
	}

	bool operator <= (Int& a) {
		if (digit > a.digit) return false;
		if (digit == a.digit)
			for (int i = digit - 1; i >= 0; i--)
				if (num[i] > a.num[i])
					return false;
		return true;
	}

	bool operator >= (Int& a) { return a <= *this; }

	bool operator == (Int& a) { 
		if (digit != a.digit) return false;
		for (int i = 0; i < digit; i++)
			if (num[i] != a.num[i])
				return false;
		return true;
	}

	bool operator < (Int& a) { return (*this <= a) && !(*this == a); }
	bool operator > (Int& a) { return (*this >= a) && !(*this == a); }

	Int operator + (Int& a) {
		Int ret;
		int carry = 0;
		for (int i = 0; i < std::max(digit, a.digit); i++) {
			ret.num[i] = a.num[i] + num[i] + carry;
			carry = ret.num[i] / mod;
			ret.num[i] %= 10;
		}
		if (carry) ret.num[std::max(digit, a.digit)] += 1;
		ret.digit = std::max(digit, a.digit) + carry;
		return ret;
	}
	
	void copy(Int& a) {
		for (int i = 0; i < digit; i++)
			num[i] = 0;
		digit = a.digit;
		for (int i = 0; i < digit; i++)
			num[i] = a.num[i];
		neg = a.neg;
	}

	friend void swap(Int* a, Int* b) {
		Int c(*b);
		(*b).copy((*a));
		(*a).copy(c);
	}

	Int operator - (Int& a) {
		Int ret;
		int carry = 0;
		if (*this < a) ret.neg = -1, swap(&a, this);
		for (int i = 0; i < std::max(digit, a.digit); i++) {
			ret.num[i] = num[i] - a.num[i] - carry;
			if (ret.num[i] < 0) ret.num[i] += 10, carry = 1;
		}
		for(int i = std::max(digit, a.digit); i >= 0; i--)
			if (ret.num[i]) {
				ret.digit = i + 1;
				break;
			}
		return ret;
	}

	void operator = (Int& a) { this->copy(a); }

	void pow_10(int power) {
		digit += power;
		for (int i = digit - 1; i >= power; i--)
			num[i] = num[i - power];
	}

	Int operator * (Int& a) {
		int average_digit = (a.digit + digit) / 4;
		Int a1(num, average_digit), a2(num + average_digit, digit - average_digit);
		Int b1(a.num, average_digit), b2(a.num + average_digit, a.digit - average_digit);
		Int sum1 = a1 * b1;
		Int sum2 = a2 * b2;
		Int sum3 = a1 + b1;
		Int sum4 = a2 + b2;
		Int sum5 = sum3 * sum4;
		Int sum6 = sum5 - sum1;
		Int sum7 = sum6 -sum2;
		sum2.pow_10(2 * average_digit);
		sum7.pow_10(average_digit);
		sum3 = sum7 + sum2;
	}

	void print() {
		if (neg == -1) std::cout << "-";
		for (int i = digit - 1; i >= 0; i--)
			std::cout << num[i];
	}

	void read() {
		std::cin >> digit;
		char tmp;
		for (int i = digit - 1; i >= 0; i--)
			std::cin >> tmp, num[i] = tmp - '0';
	}

};
/*
int main() {
	Int a, b;
	a.read(), b.read();
	a.print();
	std::cout << std::endl;
	b.print();
	std::cout << std::endl;
	Int c = a * b;
	c.print();
	std::cout << std::endl;
	return 0;
	int a, b = 0;
	a = b;
}
*/