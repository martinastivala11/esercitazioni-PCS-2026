#include <iostream> 

int main() 
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};     
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7}; 
	int ai[3] = {0, 1, 2};  
	
	int x = 1; 
	float y = 1.1; 
	
	(&y)[1] = 0;   
	             
	std::cout << x << "\n";
	std::cout <<"indirizzo base di ad " << &ad[3] << "\n";
	std::cout <<"indirizzo base di af " << &af[7] << "\n";
	std::cout <<"indirizzo base di ai " << &ai[2] << "\n";
	
	std::cout <<"indirizzo x " << &x << "\n";
	std::cout <<"indirizzo di y " << &y << "\n";	
	
	return 0; 
}
