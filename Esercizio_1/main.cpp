#include <iostream>
#include <windows.h>
#include <math.h>
#include <fstream>
#include <time.h>
#include "colori.hpp"




using namespace std;


class data {

	public:
		
	/*#######################*/
	/*VARIABILI*/
	int new_n = 0, old_n = 0, max_n = -999999, min_n = +999999, pari_n = 0, disp_n = 0;
	float somma = 0;
	float media = 0;
	int contatore = 0;
	bool valid = false; 
	
	
	
	
	
	/*#######################*/
	/*FUNZIONI*/
	
	int getSomma()
	{
		if(new_n != 0)
		{
	 		return somma += new_n; //Ritorna la somma
 		} 
	} 
	
	float getMedia()
	{ 
		if(new_n != 0)
		{	
			media = floorf(somma / contatore * 100) / 100; return media ;
				   /*^^^^*/
		} 		/*Da due cifre dopo il decimale*/
	}
	
	void getMinMax(){	
		if(new_n != 0 )
		{
			if(new_n > max_n)
			{ 
				max_n = new_n; 
			}
			else if(new_n < min_n)
			{
				min_n = new_n;
			}	
		}
	}
	
	void getSide(){
		if(new_n != 0)
		{
			if(new_n % 2)
			{ 
				disp_n++;
			}
			else
			{ 
				pari_n++; 
			}
		}	
	}

};

//Funzioni per prendere la data e ora corrente
string current_date(){
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[40];
    tstruct = *localtime(&now);
    //format: day DD-MM-YYYY
    strftime(buf, sizeof(buf), "%A %d/%m/%Y", &tstruct);
    return buf;
}

string current_time(){
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[40];
    tstruct = *localtime(&now);
    //format: HH:mm:ss
    strftime(buf, sizeof(buf), "%X", &tstruct);
    return buf;
}


int main() {
	
	
	
	data data; 
	int num_list[data.contatore]; // Array dinamico
	
	do
	{
		system("cls");
		cout << "Made with " << colore::on_red << "<3" << colore::reset << " by " << colore::on_green << "Fede.Tensi" << colore::reset << endl;
		cout << endl;
		cout << colore::on_yellow <<"Inserendo \"0\" il programma verra' terminato'"<< colore::reset<<endl;
		cout << endl;
		cout << endl;
		cout << "Somma: " << colore::cyan << data.getSomma() << colore::reset << endl;
		cout << "Media: " << colore::cyan << data.getMedia() << colore::reset << endl;
		cout << "Il nummero maggiore: " << colore::cyan << data.max_n << colore::reset << endl;
		cout << "Il nummero minore: " << colore::cyan << data.min_n << colore::reset << endl;
		cout << "Ultimo numero inserito: " << colore::cyan << data.old_n << colore::reset << endl;
		cout << "Numeri pari inseriti: " << colore::cyan << data.pari_n << colore::reset << endl;
		cout << "Numeri dispari inseriti: " << colore::cyan << data.disp_n << colore::reset << endl;
		
	
		do
		{
			data.valid = true; //Assumo che il cin sarà un integer.
	
			cout << endl;
			cout << "Numero: " << colore::magenta;
			cin >> data.new_n;
		
			
			
			//cin >> data.new_n;
			cout << colore::reset;
			
	
			if(cin.fail()) //cin.fail() cerca se la value dentro il cin è un tipo coretto (int), se no ritorna true,oppure falso.
			{
				cin.clear(); //Sistema lo stream.
				cin.ignore(); //Questo salta i rimasugli inseriti prima.
				system("cls");
				cout << colore::red << "[ERRORE] "<< colore::reset <<"Perfavore immetti solo i numeri." << endl;
				data.valid = false; //il cin non era un int quindi prova di nuovo
			}
			else
			{
				break;//Esce
			}
		}while(!data.valid);

		
		data.old_n = data.new_n; 
				
		
		data.getMinMax(); //Determina se il valore sia in max o il min
		
		data.getSide(); //Determina se pari o dispari

		
		
		num_list[data.contatore] = data.new_n; // Aggiunge il numero inserito alla posizione del contatore

		data.contatore++;
	}
	while(data.new_n != 0);
	
	
	/*Aggiungere la poss per salvare i file*/
	string save = "n";
	
	cout << "Vuoi salvare i dati? (y/N): ";
	cin.ignore();
	getline(cin, save);
	
	
	

	
	
	if(save == "y" || save == "Y")
	{

		ofstream buff_file;
		
		if(buff_file){
			buff_file.open ("Dati.txt");
  			buff_file << "Risultati operazioni del \n";
   			buff_file<<"Data => "<<current_date()<<"\n";
   			buff_file<<"Ora => "<<current_time()<<"\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "------------------------------------------------\n";
  			buff_file << "DATI:";
	  		buff_file << "\n";
  			buff_file << "Somma: " << data.somma << "\n";
  			buff_file << "Media: " << data.media << "\n";
  			buff_file << "Numero massimo: " << data.max_n << "\n";
  			buff_file << "Numero minimo: " << data.min_n << "\n";
  			buff_file << "Numeri pari inseriti: " << data.pari_n << "\n";
  			buff_file << "Numeri dispari inseriti: " << data.disp_n << "\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "------------------------------------------------\n";
  			buff_file << "Cronologia numeri inseriti: \n";
  			
			for(int i = 0; i < data.contatore; i++) 
			{
				buff_file <<  "Numero "<< i + 1 <<": " << num_list[i] << "\n";
			}
			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "\n";
  			buff_file << "############################\n";
  			buff_file << "Made with <3 by Fede.Tensi\n";
  			buff_file << "############################";
  			buff_file.close();
  			
  			cout << colore::green <<"[OK] "<< colore::reset << " Dati salvati..."<<endl;
		}
		else
		{
			cout << colore::red <<"[ERRORE] "<< colore::reset << " dati non sono stati salvati..." <<endl;
		}
	}
	else
	{
		cout << colore::green <<"[OK] "<< colore::reset << " I dati non verranno salvati..."<<endl;
	}
		Sleep(2000);
	
	
	
	for(int j = 3; j > 0; j--)
	{
		system("cls");
		
		cout<<endl;
		cout<<endl;
		cout<<endl;

		cout << colore::on_cyan <<"Il programma verra' terminato tra " << j << colore::reset << endl;
		Sleep(1000);
	}
	

	
	exit(1);
	
}
