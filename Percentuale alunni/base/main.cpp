#include <iostream>

using namespace std;


int totm, totf, classe, ptot;


void getClasse()
{
	float pf, pm, nf,nm, tot;
	
	cout << "Numero maschi: ";
	cin >> nm;
	
	cout << "Numero femmine: ";
	cin >> nf;
	
	tot = nf + nm;
	
	pm = (nm / tot) * 100;
	pf = (nf / tot) * 100;
	
	totm += pm;
	totf += pf;
	
	system("cls");
	cout << "Percentuale maschi: " << pm << "\nPercentuale femmine: " << pf << "\n";
	
}




int main() {
	
	
	
	cout << "Quante classe: ";
	cin >> classe;
	
	for(int i = 0; i < classe; i++ )
	{
		getClasse();
		system("pause");
		system("cls");
		
	}
	cout << "" << endl;
	cout << "Totale maschi: " << totm << "\nTotale femmine: " << totf;
	return 0;
}
