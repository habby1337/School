#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <tgmath.h>
#include <cmath>
#include "colori.hpp"


using namespace std;

class Student
{
	string classe;
	float tot, totf, totm, numm, numf;
	float pm, pf;

public:

#pragma region Get Function 

	void getClasse()
	{
		cin >> classe;
	}
	void getnumf()
	{
		cin >> numf;
	}
	void getnumm()
	{
		cin >> numm;
	}
	int getTot()
	{
		tot = numm + numf;

		return tot;
	}
	float getPM()
	{
		pm = numm / tot * 100;

		return pm;
	}
	float getPF()
	{
		pf = numf / tot * 100;

		return pf;
	}
#pragma endregion

#pragma region DispleyInfo Text setup

	void displayInfo()
	{
		cout << colore::on_white << "[##########################################]" << colore::reset << endl;
		cout << endl;
		transform(classe.begin(), classe.end(), classe.begin(), ::toupper);											//Trasforma la stringa in uppercase
		cout << "	Classe: " << colore::green << classe << colore::reset << endl;
		cout << "#------------------------------------------#" << endl;
		cout << "	Alunni totali: " << colore::red << tot << colore::reset << endl;
		cout << "	Percentuale maschi: " << colore::cyan << floor(pm + 0.5) << "%" << colore::reset << endl;
		cout << "	Percentuale femmine: " << colore::cyan << floor(pf + 0.5) << "%" << colore::reset << endl;
		cout << "#------------------------------------------#" << endl;
		cout << endl;
	}

#pragma endregion

};

#pragma region Output Text type select

void ctext(int select)
{
	/*
	*	INFO = 1
	*	ATTENZIONE = 2
	*	ERRORE = 3
	*	DOMANDA = 4
	*	
	*/

	switch(select)
	{
	case 1:
		cout << colore::green << "[INFO]" << colore::reset << ": ";
		break;
	case 2:
		cout << colore::yellow << "[ATTENZIONE]" << colore::reset << ": ";
		break;
	case 3:
		cout << colore::red << "[ERRORE]" << colore::reset << ": ";
		break;
	case 4:
		cout << colore::cyan << "[DOMANDA]" << colore::reset << ": ";
		break;
	default:
		cout << colore::cyan << "[$3%�\"3!%]" << colore::reset << ": ";
		break;
	}
}

#pragma endregion

int main()
{
	
	int n = 1, cont = 0;

	ctext(4);
	cout << "Quante classi vuoi inserire: " << colore::yellow;
	cin >> n;
	cout << colore::reset;
	cont = n;

	Student* st = new Student[n]; 

	system("cls");

#pragma region Get input

	for(int i = 0; i < n; i++)
	{
		ctext(1);
		cout << "Numero classi da inserire: " << colore::red << cont-- << ". " << colore::yellow << "[Contando questa]" << colore::reset << endl;
		cout << "-------" << endl;
		cout << "Classe: " << colore::cyan << i + 1 << colore::reset << endl;
		cout << "-------" << endl;

		ctext(4);
		cout << "Nome classe: " << colore::yellow;
		st[i].getClasse();
		cout << colore::reset << endl;

		ctext(4);
		cout << "Numero femmine: " << colore::yellow;
		st[i].getnumf();
		cout << colore::reset << endl;

		ctext(4);
		cout << "Numero maschi: " << colore::yellow;
		st[i].getnumm();
		cout << colore::reset << endl;

		st[i].getTot();
		st[i].getPM();
		st[i].getPF();

		system("cls");

	}

#pragma endregion


	system("pause");

	system("cls");

	for(int i = 0; i < n; i++)
	{
		st[i].displayInfo();
	}

	system("pause");

	return 0;
}
