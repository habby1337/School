#include<iostream>
#include<windows.h>
#include<vector>
#include <bits/stdc++.h> 
#include"colori.hpp"

using namespace std;

float n, decimale;
int segno = 0;
int intero = 0;
int cont = 0;
int caratt = 0;
int esponente;
vector <int> vetInt;
vector <int> vetFloat;
vector <int> vetCar;
void intToBin(){
	vetInt.clear();
	
	int a = intero;
	int b;
	do{
		a = a / 2;
		b = a % 2;
		vetInt.push_back(b);
		cont++;
	}while(a > 0);
	
	if(intero % 2 == 0){
		vetInt.insert(vetInt.begin(), 0);
	} else{
		vetInt.insert(vetInt.begin(), 1);
	}
	
	/*for(auto x = vetInt.rbegin(); x != vetInt.rend(); x++){
		cout<<*x;
	}
	cout<<endl;*/
	
}

int cat(){
	int car = 0;
	bool exit = false;
	int last = 0;
	int negcont = 0;
	
	
	if (intero > 0){
		do{
			last = vetInt.at(vetInt.back());
			if(last == 1){
				vetInt.pop_back();
				exit = true;
			}	else{
				vetInt.pop_back();
			}
		}while(exit = false);
		vetInt.pop_back();
		
		/*for(auto x = vetInt.rbegin(); x != vetInt.rend(); x++){
			cout<<*x;
		}
		cout<<endl;*/
		
		car = vetInt.size();
	} else {
		do{
			negcont--;
			last = vetFloat.at(vetFloat.front());
			if(last == 1){
				vetFloat.erase(vetFloat.begin());
				exit = true;
			}	else{
				vetFloat.erase(vetFloat.begin());
			}
		}while(exit = false);
		vetFloat.erase(vetFloat.begin());
		negcont--;
		negcont--;
		/*for(auto x = vetFloat.begin(); x != vetFloat.end(); x++){
			cout<<*x;
		}
		cout<<endl;*/
		
		car = negcont;
		
	}
	
	return car;
}

void floatToBin(){
	float a = decimale;
	
	do{
		a = a * 2;
		if(a >= 1){
			vetFloat.push_back(1);
			a -= 1;
		}	else{
			vetFloat.push_back(0);
		}
		cont++;
	}while(cont <= 23);
	
	/*for(auto x = vetFloat.begin(); x != vetFloat.end(); x++){
		cout<<*x;
	}
	cout<<endl;*/
}

void carToBin(){
	vetCar.clear();
	
	int a = caratt + 127;
	
	int b;
	do{
		a = a / 2;
		b = a % 2;
		vetCar.push_back(b);
	}while(a > 0 && vetCar.size() < 8);
	
	vetCar.pop_back();
	
	if(a % 2 == 0){
		vetCar.insert(vetCar.begin(), 0);
	} else{
		vetCar.insert(vetCar.begin(), 1);
	}
	
	if(vetCar.size() < 8){
		for(int h = vetCar.size(); h < 8; h++){
			vetCar.push_back(0);
		}
	}
	
	/*for(auto x = vetCar.rbegin(); x != vetCar.rend(); x++){
		cout<<*x;
	}
	
	cout<<endl;*/
	
}



int main(){
	while(true){
		system("cls");
		cout<<"Per uscire premi "<< colore::yellow << "CTRL+C"<< colore::reset<<endl;
		cout<<"Inserisci un numero: "<< colore::red;
		cin>>n;
		cout << colore::reset;
		
		if (n<0){
			segno = 1;
		}
		
		intero = n;
		
		decimale = n - intero;
		
		intToBin();
		floatToBin();
		
		caratt = cat();
		
		carToBin();
		
		if(vetInt.size() + vetFloat.size() < 23){
			for(int k = vetInt.size() + vetFloat.size(); k < 23; k++){
				vetFloat.push_back(0);
			}
		}
		
		cout<<endl;
		cout<<segno<< colore::cyan<<"|" << colore::reset;
		for(auto x = vetCar.rbegin(); x != vetCar.rend(); x++){
			cout<<*x;
		}
		cout<< colore::cyan<<"|" << colore::reset;
		for(auto x = vetInt.rbegin(); x != vetInt.rend(); x++){
			cout<<*x;
		}
		for(auto x = vetFloat.begin(); x != vetFloat.end(); x++){
			cout<<*x;
		}
		cout<<endl;
		system("pause");
	}
	
	return 0;
}
