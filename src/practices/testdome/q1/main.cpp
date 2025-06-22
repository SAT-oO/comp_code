#include <cmath>
#include <iostream>

class Problem {
public:
	static int *flipShift(int a, int b) {
		int *arr = new int[3];
		// a_prime
		int up_bound = log2(a) + 1;
		int low_bound = log2(a);
		int a_prime = 0;
		if (pow(2, up_bound) - a <= pow(2, low_bound) - a) {
			a_prime = pow(2, up_bound);

		} else {
			a_prime = pow(2, low_bound);
		}
		// arr[0]
		int flips_bi = a ^ a_prime;
		int flips = 0;
		for (int i = up_bound; i >= 0; i--) {
			flips += flips_bi % 2;
			flips_bi = flips_bi >> 1;
		}
		arr[0] = flips;

		// b_prime
		int b_prime = 0;
		up_bound = log2(b) + 1;
		low_bound = log2(b);
		if (pow(2, up_bound) - b <= pow(2, low_bound) - b) {
			b_prime = pow(2, up_bound);
		} else {
			b_prime = pow(2, low_bound);
		}
		// std::cout << "a_prime: " << a_prime << ", b_prime: " << b_prime << std::endl;

		// arr[1]
		flips_bi = b ^ b_prime;
		flips = 0;
		for (int i = up_bound; i >= 0; i--) {
			flips += flips_bi % 2;
			flips_bi = flips_bi >> 1;
		}
		arr[1] = flips;

		// arr[2]
		int shift = 0;
		for (int i = 0; i < up_bound; i++) {
			int a_shift = a << i;
			if (a_shift == b) {
				shift = i;
				break;

			}
		}
		arr[2] = shift;

		return arr;
	}
};

#ifndef RunTests
int main() {
	// test your code if you wish
	std::cout << Problem::flipShift(2, 1);
    
}
#endif