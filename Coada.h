#include<iostream>
#include"Lista.h"
#include<fstream>
using namespace std;

class Coada
{ 
	Team elem1;
	Team elem2; 
	class Coada* next; 
	
	public:
		Coada();
		Coada(Team , Team, class Coada*);
		Coada& operator=(const Coada&);
		Coada(const Coada &);
		
		void makecoada(Coada *&,Lista *, int n);
		void afisarecoada(ostream &);
		void joaca(Coada *&, int &, Lista *&, ostream &);
		void stive(Coada *&, Lista *&, Lista*&);
		void sterg(Coada *&);

}; 
