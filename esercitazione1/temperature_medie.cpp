#include <iostream> 
#include <fstream>
#include <string>

using namespace std; 
int main(int argc, const char *argv[]) 
{ 
	if (argc<2)
	{
		cerr << "Errore: non è stato specificato il nome del file\n";
		return 1;
	}
	
	string filename=argv[1];
	ifstream ifs(filename);
	if (!ifs.is_open()) 
	{ 
		cerr <<"Errore: il file " << filename <<" non si è aperto correttamente\n";
		return 1;
	}
	string citta; 
	double t1;
	double t2;
	double t3;
	double t4;
	while (ifs >> citta >> t1 >> t2 >> t3 >>t4)
	{
		double media=(t1+t2+t3+t4)/4.0;
		cout << citta <<"  " << media << "\n"; 
	} 
	return 0; 
}

