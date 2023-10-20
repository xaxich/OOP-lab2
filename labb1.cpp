#include <iostream>  
#include <limits>  
#include <cmath>
double fun1(double x, int n) {
	int i = 4;
	double k;
	k = x / (7 + x);
	if (n >= i) {
		for (i; i <= n; i++) {
			k *= (std::log(1 + (x / (7 + x)) * sqrt(i)));
		}
		return k;
	}
	return 0;
}
int main()
{
	double x, y;
	int n;
	std::cout << "enter x" << '\n';
	std::cin >> x;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input eror" << '\n';
	}
	else {
		std::cout << "enter n>=4" << '\n';
		std::cin >> n;
		if ((std::cin.fail()) || (n < 4)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input eror" << '\n';
		}
		else {
			y = x + fun1(x, n);
			std::cout << y;
			return 0;
		}
	}
}