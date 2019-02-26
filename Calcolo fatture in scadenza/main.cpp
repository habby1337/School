#include <iostream>
#include <string>

using namespace std;


class Mesi {
	// Private section
	
	public:
		
	
		// Public Declarations
	protected:
		// Protected Declarations
};

int calcoloMeseDiff(int mese1, int mese2){
	
	int gio_tot = 0;
	int mese_mezz;
	
	for(int mese_mezz = mese1; mese_mezz <= mese2; mese_mezz++){
		
		switch(mese_mezz){
			case 1:
				gio_tot += 31;
				break;
			case 2:
				gio_tot += 28;
				break;
			case 3:
				gio_tot += 31;
				break;
			case 4:
				gio_tot += 30;
				break;
			case 5:
				gio_tot += 31;
				break;
			case 6: 
				gio_tot += 30;
				break;
			case 7:
				gio_tot += 31;
				break;
			case 8:
				gio_tot += 31;
				break;
			case 9:
				gio_tot += 30;
			break; 
			case 10:
				gio_tot += 31;
				break;
			case 11:
				gio_tot += 30;
				break;
			case 12:
				gio_tot += 31;
				break;
		}
	}

	return gio_tot;
}


int main() {
	//Fatture* newFattura[20];
	
	string nome_cons;
	int giorno_emis, mese_emis, anno_emis;
	int giorno_scad, mese_scad, anno_scad;
	int giorno_cons, mese_cons, anno_cons;
	int giorno_corr, mese_corr, anno_corr;
	int gio_tot;

	
	cin>>mese_emis;
	cin>>mese_scad;
	
	gio_tot = calcoloMeseDiff(mese_emis, mese_scad);
	cout << gio_tot;
	
	
	
	
	
	
	return 0;
}
