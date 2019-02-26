#include <iostream>
#include <vector>

using namespace std;




float n, decimale;
int segno = 0, intero = 0, cont = 0;
vector <int> vetInt;
vector <int> vetFloat;

void intToBin()
{
	vetInt.clear();	
	
	int a = intero;
	int b = 0;
	
	do
	{
		a = a/2;
		b = a%2;
		
		vetInt.push_back(b);
	
		cont++;
	}while(a > 0);
	
	if(intero % 2 == 0)
	{
		vetInt.insert(vetInt.begin(), 0);
	}
	else
	{
		vetInt.insert(vetInt.begin(), 1);
	}
	
	cout << "Output of begin and end: "; 
    for (auto i = vetInt.rbegin(); i != vetInt.rend(); ++i) 
        cout << *i << " "; 	
	
}

void floatToBin()
{
	float a = decimale;
	
	do
	{
		a = a*2;
		
		if(a > 1)
		{
			vetFloat.push_back(1);
			a -= 1;
		}
		else
		{
			vetFloat.push_back(0);
		}
		cont++;
	}while(cont != 23);
	
	cout << "Output of begin and end: "; 
    for (auto i = vetFloat.begin(); i != vetFloat.end(); ++i) 
        cout << *i << " "; 
	
}

01010
void cat()
{
		cout << "Output of begin and end: "; 
    for (auto i = vetInt.rbegin(); i != vetInt.rend(); ++i) 
        cout << *i << " ";
        if(vetInt.at(i) == 0)
		{
			vetInt.erase(i)
			
		}
        
        
        
	
}
//10000010101010,101010101010101
//10				15

int main()
{
	

	
	vector <string> vet;
	
	
	cout << "numero: ";
	cin>> n;
	
	intero = n;
	
	decimale = n-intero;
	
	
	if(n < 0)
	{
		segno = 1;
	}
	else 
	{
		segno = 0;
	}
	
	cout << "Decimale: " << decimale;
	cout << "\nIntero: " << intero;
	cout << "\nN: " << n;
	cout << "\nSegno: " << segno;
	cout << "\nVet.";
	 intToBin();
	 
	cout << "\nFLoat: ";
	floatToBin();
	
	cout << "\nCat:";
	cat();
	
	
	

}

