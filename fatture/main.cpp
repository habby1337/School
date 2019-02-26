#include<iostream>
#include<windows.h>
#include "colori.hpp"

using namespace std;


int anno(int data_anno){
	int year=0;
	year=(data_anno*365);
	return year;
}

int mese(int giorni_mese,int data_anno){
	
    int giorni=0, plus=0;
    
    switch(giorni_mese){
    	case 1:
    		giorni=0;
    	break;
    	case 2:
    		giorni=31;
    	break;
    	case 3:
		    if(data_anno%4==0) plus++;
    		giorni=59+plus;
    	break;
    	case 4:
    		if(data_anno%4==0) plus++;
    		giorni=89+plus;
    	break;
    	case 5:
    		if(data_anno%4==0) plus++;
    		giorni=119+plus;
    	break;
    	case 6:
    		if(data_anno%4==0) plus++;
    		giorni=150+plus;
    	break;
    	case 7:
    		if(data_anno%4==0) plus++;
    		giorni=180+plus;
    	break;
    	case 8:
    		if(data_anno%4==0) plus++;
    		giorni=211+plus;
    	break;
    	case 9:
    		if(data_anno%4==0) plus++;
    		giorni=242+plus;
    	break;
    	case 10:
    		if(data_anno%4==0) plus++;
    		giorni=272+plus;
    	break;
    	case 11:
    		if(data_anno%4==0) plus++;
    		giorni=304+plus;
    	break;
    	case 12:
    		if(data_anno%4==0)
			 plus++;
    		giorni=334+plus;
    	break;	
	}
	
	return giorni;
}

int diff(int data_giorni1, int data_mese1,int data_a1,int data_giorni2,int data_mese2,int data_a2){
	
    int giorni1=0, giorni2=0, giornif=0, ok1=data_a1;
    
    data_mese1=mese(data_mese1,data_a1);
    
    if(data_a1%4==0)
	{
    	
   		if(data_a1<data_a2)
		{
    		data_a1=anno(data_a1);
    		data_a1=data_a1-1;
		}
	}
    data_mese2=mese(data_mese2,data_a2);
    
    if(data_a1==ok1)
    
    data_a1=anno(data_a1);
    data_a2=anno(data_a2);
    
    giorni1=data_giorni1+data_mese1+data_a1;
    giorni2=data_giorni2+data_mese2+data_a2;
    giornif=giorni2-giorni1;
    
    return giornif;
}

int over(string domanda, int limite, string reply, int minimo)
{
	
	int x;

	cout << colore::cyan << "[QUESTION]: " << colore::reset << domanda<< colore::magenta;
	cin>>x;
	cout << colore::reset << "\n";
		
	while(limite<x || minimo>x){
		cout<<reply;
		cin>>x;
	}
	
	return x;
}

void intro(){
	cout << endl << endl << endl;
	cout << "			     Benvenuto " << colore::cyan << "Utente" << colore::reset << ".			" << endl;
	cout << "			Calcolare le fatture....			" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl
	 << endl << endl << endl << endl << endl << endl << endl << endl << endl
	  << endl << endl << endl;
	system("PAUSE");
	system("cls");
}

int main(){
	
	intro();
	
	int cont=0, i = 0;
	
    int gg_inz_f, mm_inz_f, gg_fine_f, mm_fine_f, differnza_f, aa_inz_f, aa_fine_f;
    
    cout<<"Quante fatture vuoi inserire: " << colore::red;
    cin>>cont;
    cout << colore::reset << "\n";
    
    
    while(cont!=0){
    	cont--;
    	i++;
    	
    	gg_inz_f=over("inserire il giorno della fattura: ",31,"la data inserita non e' essere giusta. Ne inserisca un'altra: ",1);
    	
    	mm_inz_f=over("inserire il mese della fattura: ",12,"la data inserita non e' essere giusta. Ne inserisca un'altra: ",1);
    		
    	cout << colore::cyan << "[QUESTION]: " << colore::reset << "inserire l'anno della fattura: "<< colore::magenta;
	    cin>>aa_inz_f;
	    cout << colore::reset;
	    cout << "\n";
   	 	gg_fine_f=over("inserire il giorno della scadenza fattura: ",31,"la data inserita non puo' essere giusta. inserisca un'altra: ",1);
    	
    	mm_fine_f=over("inserire il mese della scadenza fattura: ",12,"la data inserita non puo' essere giusta. inserisca un'altra: ",1);
    
    	cout << colore::cyan << "[QUESTION]: " << colore::reset << "inserire l'anno della scadenza fattura: "<< colore::magenta;
    	cin>>aa_fine_f;
		cout << colore::reset;
		
   		system("cls");

		differnza_f=diff(gg_inz_f,mm_inz_f,aa_inz_f,gg_fine_f,mm_fine_f,aa_fine_f);


		if(differnza_f <= 20)
		{
			cout<<"la fattura numero "<< colore::green <<i<< colore::reset << " scade tra: "<< colore::red <<differnza_f<< colore::reset <<" giorni"<<endl;
	
		}
		else if(differnza_f <= 50)
		{
			cout<<"la fattura numero "<< colore::green <<i<< colore::reset << " scade tra: "<< colore::yellow <<differnza_f<< colore::reset <<" giorni"<<endl;
	
		}
		else if(differnza_f < 100)
		{
			cout<<"la fattura numero "<< colore::green <<i<< colore::reset << " scade tra: "<< colore::green <<differnza_f<< colore::reset <<" giorni"<<endl;
	
 		}
		else
		{
			cout<<"la fattura numero "<< colore::green <<i<< colore::reset << " scade tra: "<< colore::green <<differnza_f<< colore::reset <<" giorni"<<endl;
		}
    	cout << endl;
    	
	}
    system("PAUSE");
	return 0;
}
 
