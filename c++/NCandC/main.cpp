#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include <algorithm>
#include "colori.hpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class Player {
	// Private section
		string _nome;
		int _punti = 0;
		int _vittorie = 0;
		string _parole;
	public:
	
		
		
		void setNome(){
			cin>>_nome;
		}
		
		void setPunti(){
			cin>>_punti;
		}
		
		void setVittorie(){

			cin>>_vittorie;
		}
		
		void setParole(){
			cin>> _parole;
		}
		
		void getNome(){
			cout << _nome;
		}
		
		void getPunti(){
			cout << _punti;
		}
		
		void getVittorie(){
			cout << _vittorie;
		}
		
		void getAll()
		{
		cout << colore::on_white << "[##########################################]" << colore::reset << endl;
		cout << endl;
		transform(_nome.begin(), _nome.end(), _nome.begin(), ::toupper);										//Trasforma la stringa in uppercase
		cout << "	Giocatore: " << colore::green << _nome << colore::reset << endl;
		cout << "#------------------------------------------#" << endl;
		cout << "	Punti: " << colore::red << _punti << colore::reset << endl;
		cout << "	Vittorie: " << colore::cyan << _vittorie << colore::reset << endl;
		cout << "#------------------------------------------#" << endl;
		cout << endl;
		}
		// Public Declarations
	protected:
		// Protected Declarations
};


void game(){
	
}


int main() {
	int numPla;
	
	
	cout << "quanti giocatori: ";
	cin >> numPla;
	
	Player* newPlayer = new Player[numPla];
	
	for(int i = 0; i < numPla; i++){
		cout << "Nome player ["<< i <<"]: ";
		newPlayer[i].setNome();
	}
	system("cls");
	

	
	
	
	system("cls");
	for(int i = 0; i < numPla; i++)
	{
		newPlayer[i].getAll();
	}
	
	return 0;
}
