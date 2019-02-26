/*
Scivere un programma che realizzi un semplice menù:
l'utente fornisce in ingresso due numeri interi A e B ed ha la possibilità di scegliere tra tre opzioni .
in corrispondenza della prima viene effettuata la somma A+B
in corrispondenza della seconda viene effettuato il prodotto A*B,
in corrispondenza della terza viene effettuata la differenza A-B.
in corrispondenza della quarta viene riconosciuta se vocale o consonante


*/




#include <iostream>
#include <Windows.h>
#include "colori.hpp"

using namespace std;


class Data {
	public:
		int somma = 0;
		int prodotto = 1;
		int differenza = 0;
		int n = 0;
		int n2 = 0;
		bool valid = false;
		

};


void intro() //Semplice intro animata 
{
	string testo = "               Benvenuto Utente \n\n\n               Caricamento del menu'...";
	int i = 0;
	
	cout << endl;
	
	while ( testo[i] != '\0') //Ciclo per animazione testo
	{
		cout << colore::cyan << testo[i] << colore::reset;
	
		Sleep(100);
		i++;
	}

	Sleep(2000);
}

void somma() //Funzione per la somma, di tipo void 
{
	Data data;

	
	do
	{
		system("cls");
		cout << "Inserire \"" << colore::yellow << "0" << colore::reset << "\" per uscire dal programma." << endl;
		cout << endl;
		cout << "La somma e': " << colore::cyan << data.somma << colore::reset << endl;
		cout << endl;
		cout << "Inserire il numero: " << colore::cyan;
		cin >> data.n;
		cout << colore::reset;
		
		
		
		data.somma += data.n;
		
		
		
	}while(data.n != 0);
}

void prodotto() // funzione per il prodotto, di tipo void 
{
	Data data;
	
	do
	{
		system("cls");
		cout << "Inserire \"" << colore::yellow << "0" << colore::reset << "\" per uscire dal programma." << endl;
		cout << endl;
		cout << "Il prodotto e': " << colore::cyan << data.prodotto << colore::reset << endl;
		cout << endl;
		cout << "Inserire il numero: " << colore::cyan;
		cin >> data.n;
		cout << colore::reset;
		
		data.prodotto *= data.n;

		
	}while(data.n != 0);
}

void differenza() //Funzione per la differenza, di tipo void 
{
	Data data;
	
	do
	{
		system("cls");
		cout << "Inserire \"" << colore::yellow << "0" << colore::reset << "\" per uscire dal programma." << endl;
		cout << endl;
		cout << "La differenza e': " << colore::cyan << data.differenza << colore::reset  << endl;
		cout << endl;
		cout << "Inserire il primo numero: " << colore::cyan;
		cin >> data.n;
		cout << colore::reset;
		cout << "Inserire il secondo numero: " << colore::cyan;
		cin >> data.n2;
		cout << colore::reset;
		
		
		data.differenza = data.n - data.n2;
		
	}while(data.n != 0);
}






void menu()//Funzione per il menu di tipo void 
{
	system("cls");
	
	Data data;
	
	int menu_choose;

	do
	{
		data.valid = true; //Assumo che il cin sarà un integer.
		
		cout << "Menu'" << endl;
		cout << colore::green << "1." << colore::reset << " Somma." << endl;
		cout << colore::green << "2." << colore::reset << " Prodotto." << endl;
		cout << colore::green << "3." << colore::reset << " Differenza." << endl;
		cout << colore::green << "4." << colore::reset << " Consonante o vocale." << endl;
		cout << colore::green << "00." << colore::reset << " Esci dal programma." << endl;
		cout << endl;
		cout << "Scelta: " << colore::green;
		cin >> menu_choose;
		cout << colore::reset;
			
	
		if(cin.fail()) //cin.fail() cerca se la value dentro il cin è un tipo coretto (int), se no ritorna true,oppure falso.
		{
			cin.clear(); //Sistema lo stream.
			cin.ignore(); //Questo salta i rimasugli inseriti prima.
			system("cls");
			cout << colore::red << "[ERRORE]: " << colore::reset << "L'opzione non e' valida..." << endl;
			data.valid = false; //il cin non era un int quindi prova di nuovo
		}
		else
		{
			break;//Esce
		}
		
	}while(!data.valid);

	
	
	
	switch(menu_choose) //Switch per la decisione della funzione 
	{
	case 1:
		somma();
		menu();
		break;
	case 2:
		prodotto();
		menu();
		break;
	case 3:
		differenza();
		menu();
		break;
	case 00:
		
		for(int i = 5; i >= 0; i--) {
			system("cls");
			cout << "   " << endl;
			cout << "   " << endl;
			cout << "            Il programma si chiudera' tra: " << colore::yellow << i << colore::reset << "..." << endl;
			cout << "   " << endl;
			cout << "               Made with " << colore::red << "<3" << colore::reset << " by Fede.Tensi"<<endl;
			Sleep(1000);
		}
		
		system("exit");
		
		break;
	default:

		break;
	}
	
	system("cls");
	

}




int main() {
	
	intro();
	menu();
	
	
	return 0;
}
