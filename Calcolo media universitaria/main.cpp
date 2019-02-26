/*
*	Calcolare i voti di uno studente universistario e determinare se promosso o bocciato
*	
*	Federico Tensi 3AI
*/

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;


int main()
{
	string nome;
	int scritto1 = 0, scritto2 = 0, scritto3 = 0, orale = 0,
	credito = 0, tipoIst = 0, bonus = 0, voti = 0, punteggio = 0;
	

	cout << "Inseritre il nome: ";
	cin >> nome;
	cout << "\nInserire voto del primo scritto: ";
	cin >> scritto1;
	cout << "\nInserire il voto del secondo scritto: ";
	cin >> scritto2;
	cout << "\nInserire il voto del terzo scritto: ";
	cin >> scritto3;
	cout << "\nInserire il voto della prova orale: ";
	cin >> orale;
	cout << "\nInserire il credito: ";
	cin >> credito;
	
	
	system("cls");
	cout << "ISTITUTI:" << endl;
	cout << "1. Diploma di istruzione tecnica." << endl;
	cout << "2. Diploma liceale." << endl;
	cout << "3. Diploma di istruzione tecnica." << endl;
	cout << "4. Diploma di instruzione professionale." << endl;
	cout << "5. Istituto non previsto." << endl;
	cout << " " << endl;
	cout << "\nInserire il tipo di istituto: ";
	cin >> tipoIst;
	system("cls");

	
	voti = scritto1 + scritto2 + scritto3 + orale;
	
	if(voti >= 70 && credito >= 15)
	{
		cout << "Inserire il bonus: ";
		cin >> bonus;
		punteggio = voti + credito + bonus;
	}
	else
	{
		punteggio = voti + credito;
	}
	
	
	cout << nome;
	
	if(punteggio >= 60)
	{
		if(punteggio > 100)
		{
			cout << " e' stato promosso.\nPunteggio: 100 e lode." << endl;
		}
		else
		{
			cout << " e' stato promosso. Punteggio: " << punteggio << "." << endl;
		}
		
		cout << "  con: ";
		
		switch(tipoIst) {
			case 1:
				cout << "diploma di istruzione tecnica." << endl;
				break;
			case 2:
				cout << "diploma liceale." << endl;
				break;
			case 3:
				cout << "diploma di istruzione tecnica." << endl;
				break;
			case 4:
				cout << "diploma di instruzione professionale." << endl;
				break;
			
			default:
				cout << "Istituto non previsto." << endl;
				break;
		}
	}
	else
	{
		cout << " non e' stato promosso." << endl;
	}

	cout<<"  "<<endl;
	system("pause");
	return 0;
}
