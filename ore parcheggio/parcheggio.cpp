#include <iostream>
#include "windows.h"
#include <math.h>


using namespace std;



const float primaOra = 1.50, pro = 1.20, pg = 8;
	
	

 
float uscitaCasa(float ouc,float muc,float oac,float mac)
{
	float minuti;
	
	minuti = (((oac * 60) + mac) - ((ouc * 60) + muc)) *-1;
	
	return minuti;
	 
		
}


 
float permanenza(float minuti)
{
	float ore = 0;
	while (minuti >= 60)
	{
		ore += 1;
		minuti -= 60;
	};
	return ore;
}




float calcoloCosto(float ora)
{
	float costo;
	
	if(ora >8)
	{
		costo = pg;
	}
	else
	{
		costo = primaOra;
		ora -= 1;
	}
	while (ora >= 0)
	{
		costo += pro;
		ora -= 1; 
	}
	return costo;
	
}
int main() 
{
	float pOre;
	float uCasa;
	float oArrivo,mArrivo,oUscita,mUscita;
	float uscitaO, uscitaM, arrivoO, arrivoM;
	float Pparcheggio, oParcheggio;
	float cost;


 	
	cout<<"inserire l'orario di uscita da casa: ";
	cin>>uscitaO;

	cout<<"inserire i minuti di uscita da casa: ";
	cin>>uscitaM;

	cout<<"inserire l'ora di arrivo nel parcheggio: ";
	cin>>oArrivo;
	
	cout<<"inserire i minuti di arrivo nel parcheggio: ";
	cin>>mArrivo;
	
	cout<<"inserire l'ora di uscita al parcheggio: ";
	cin>>oUscita;
	
	cout<<"inserire i minuti di uscita dal parcheggio: ";
	cin>>mUscita;
	
	cout<<"inserire l'orario di arrivo a casa: ";
	cin>>arrivoO;

	cout<<"inserire i minuti di arrivo a casa: ";
	cin>>arrivoM;

	
	uCasa = uscitaCasa(arrivoO,arrivoM,uscitaO, uscitaM);
	
	Pparcheggio = uscitaCasa(oUscita,mUscita,oArrivo,mArrivo);
	
	pOre = permanenza(uCasa);
	
	oParcheggio = permanenza(Pparcheggio);
	
	cost = calcoloCosto(oParcheggio);
	

	cout<<"hai impiegato: "<<uCasa<<" minuti"<<endl;
	cout<<"hai impiegato: "<<pOre<<" ore"<<endl;
	cout<<"sei rimasto al parcheggio:"<<Pparcheggio<<" minuti"<<endl;
	cout<<"sei rimasto al parcheggio: "<<oParcheggio<<" ore"<<endl;
	cout<<"il costo e' di: "<<cost<<" euro"<<endl;
	
 	system("pause");	
}
