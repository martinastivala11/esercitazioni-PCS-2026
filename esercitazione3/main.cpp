#include <iostream>
#include "header.hpp"

int main(void)
{
	rational<int> a(-3,6);
	rational<int> b(4,3);
	
	rational<int> s=a+b;
	rational<int> d=a-b;
	rational<int> p=a*b;
	rational<int> r=a/b;
	
	std::cout << a << "\n";
	std::cout << "la somma è " << s << "\n";
	std::cout << "la differenza è " << d << "\n";
	std::cout << "il prodotto è " << p << "\n";
	std::cout << "il rapporto è " << r << "\n";
	return 0;
}
