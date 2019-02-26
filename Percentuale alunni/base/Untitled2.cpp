#include <iostream>
#include <string>


using namespace std;

float prprimaora = 1.50;
float proresuccessive = 1.20;
float prezzogiorno = 9;
int or1, min1, or2, min2;

int tempo(int o1,int m1,int  o2,int  m2){
	
	int minuti = ((o2*60+m2)-((o1*60)+m1);
	
	return minuti;	
}

void permanenza(int minuti){
	
	int	ore = 0;
	
	while(minuti >= 60){
		
		ore += 1;
		
		minuti -= 60;
	
	}
}

float calcolaOre(ore){
	float costo;
	
	if(ore > 8){
		costo = prezzogiorno;
	}
	else{
		costo = prprimaora;
		ore -= 1;
		
		if(ore > 0){
			costo += proresuccessive;
			ore -= 1;
		}
	}
	
	return costo;
}

int main(){
	
	while(true){
		cout << "\nOra uscita di casa: ";
		cin>> or1;
		cout << "\nMinuti uscita di casa: ";
		cin>> min1;
		cout << "\nora arrivo: ";
		cin >> or2;
		cout << "\nmin arrivo: ";
		cin >> min2;
		cout << "\n"
		
		tempo(or1, min1, or2, min2);
		
	}
	
	return 0;
}
