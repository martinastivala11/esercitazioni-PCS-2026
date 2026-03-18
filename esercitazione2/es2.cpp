#include <iostream>
#include <cmath>

int main()
{
	static const int N = 10; 
	double arr[N]={3, 7.3, 32, 4, 25, 2.4, 54, 2, 8.9, 49};
	double minimo=arr[0];
	double massimo=arr[0];
	double somma=arr[0];
	for (int i=1; i<10; i++)
	{	
		somma=somma+arr[i];
		if (massimo<arr[i])
		{
			massimo=arr[i];
		}
		if (minimo>arr[i])
		{
			minimo=arr[i];
		}
	}
	double media=somma/N;
	double diff=0;
	for (int j=0; j<10; j++)
	{
		diff=diff+((arr[j]-media)*(arr[j]-media));
	}
	double devstd=sqrt(diff/N);
	std::cout << "il minimo e' " << minimo <<"\n";
	std::cout << "il massimo e' " << massimo <<"\n";
	std::cout << "la media e' " << media <<"\n";
	std::cout << "la deviazione standard e' " << devstd <<"\n";
	return 0;  
}
	