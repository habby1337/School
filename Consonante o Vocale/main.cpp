#include <iostream>
#include <windows.h>
#include <algorithm>    // std::find
#include <ctype.h> 		// putchar (toupper(variabile))
#include "colore.hpp"

using namespace std;


int exit()
{
		

	for(int i = 5; i >= 0; i--)
	{
		system("cls");
		cout << "   " << endl;
		cout << "   " << endl;
		cout << "            Il programma si chiudera' tra: " << colore::yellow << i << colore::reset << "..." << endl;
		cout << "   " << endl;
		cout << "               Made with " << colore::red << "<3" << colore::reset << " by Fede.Tensi"<<endl;
		Sleep(1000);
		
	}
	return 0;
}

void conArray(char lettera)
{
	char vocali[] = { 'A', 'E', 'I', 'O', 'U' };
	char alfabeto[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
	 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  	char * risultato1;
  	char * risultato2;
  	
  	
  	risultato1 = std::find (alfabeto, alfabeto+26, putchar (toupper(lettera)));
  	
  	if (risultato1 != alfabeto+26)
	{
		risultato2 = std::find (vocali, vocali+5, putchar (toupper(lettera)));
  	
		if (risultato2 != vocali+5)
		{
			system("cls");
			cout << "La lettera inserita e' una vocale, Hai inserito: "<< colore::yellow << *risultato2 << colore::reset << endl;
		}
 		else
		{
			system("cls");
			cout << "La lettera inserita e' una consonante"<<endl;
		}
	}
 	else
	{
		system("cls");
		cout << "Non hai inserito una lettera!"<<endl;
	}	
	
}


void conIf(char lettera)
{
	if(putchar (toupper(lettera)) == 'A' ||putchar (toupper(lettera)) == 'E' 
		|| putchar (toupper(lettera)) == 'I' || putchar (toupper(lettera)) == 'O' 
		|| putchar (toupper(lettera)) == 'U')
	{
		system("cls");
		cout << "La lettera inserita e' una vocale'"<<endl;	
	}
	else
	{
		system("cls");
		cout << "La lettera inserita e' una consonante"<<endl;
	}
	
	
}

void menu()
{
	
	int scelta = 0;
	char lettera;
	
	
	
	cout << "Menu'" << endl;
	cout << colore::green << "1." << colore::reset << " Con IF." << endl;
	cout << colore::green << "2." << colore::reset << " Con Array." << endl;
	cout << colore::green << "99." << colore::reset << " Esci dal programma." << endl;
	cout << endl;
	cout << "Scelta: " << colore::green;
	cin >> scelta;
	cout << colore::reset;
	
	
	system("cls");
	
	
	
	
	switch(scelta)
	{
		case 1:
			
			cout << "immetere la lettera: " << colore::green;
			cin>> lettera;
			cout << colore::reset;
			
			conIf(lettera);

			Sleep(5000);
			system("cls");
			menu();
		break;	
			
		case 2:
			
			cout << "immetere la lettera: " << colore::green;
			cin>> lettera;
			cout << colore::reset;
			
			conArray(lettera);

			Sleep(5000);
  			system("cls");
			menu();	
		break;
			
		case 99:	
			system("cls");
			exit();
		break;
			
	}
}
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
	system("cls");
}


int main() {
	
	
	intro();
	menu();
	
	
	return 0;
}
