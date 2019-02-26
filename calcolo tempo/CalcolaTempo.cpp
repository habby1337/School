#include <iostream>

using namespace std;

const float prprimaora = 1.5;
const float proresuccessive = 1.2;
const float prezzogiorno = 9; 

int OraUscitaCasa, MUscitaCasa, OraArrivo, MArrivo, OraUscita, MUscita, OraArrivoCasa, MArrivoCasa;
int OrePermanenza, MinutiPermanenza;


int tempo(int o1, int m1, int o2, int m2)
{
	int minuti = ((o2*60)+m2) - ((o1*60)+m1);

	return minuti;
}

int permanenza(int minuti){
	
	int ore = 0;
	
	while(minuti>=60){
		ore = ore +1;
		minuti = minuti - 60;
	}
}

float calcolacosto(float ore, int minuti){
	int costo = 0;
	
	if(ore> 8){
		costo = prezzogiorno;
	}
	else if(minuti <= 60){
		costo = prprimaora;
	}else
	{
		costo = prprimaora;
		ore -= 1;
		do{
			costo += proresuccessive;
			ore -= 1;
		}while(ore > 0);
			
		
	}
	return costo;
}

int main()
{
	
	cout << "MUscitaCasa: ";
	cin>>OraUscitaCasa;
	cout << "MUscitaCasa: ";
	cin>>MUscitaCasa;
	
	cout << "OraArrivo: ";
	cin>>OraArrivo;
	cout << "MArrivo: ";
	cin>>MArrivo;
	
	cout << "OraUscita: ";
	cin>> OraUscita;
	cout << "MUscita: ";
	cin>> MUscita;
	
	cout << "OraArrivoCasa: ";
	cin>> OraArrivoCasa;
	cout << "MArrivoCasa: ";
	cin>>MArrivoCasa;
	
	
	cout << "Tragitto andata: " << permanenza(tempo(OraUscitaCasa, MUscitaCasa,OraArrivo, MArrivo)) << endl;
	cout << "Tempo per tornare a casa: " << permanenza(tempo(OraUscita, MUscita,OraArrivoCasa, MArrivoCasa)) << endl;
	cout << "Costo parcheggio: " << calcolacosto(permanenza(tempo(OraUscita, MUscita,OraArrivoCasa, MArrivoCasa), tempo(OraUscita, MUscita,OraArrivoCasa, MArrivoCasa))) << endl;
}
