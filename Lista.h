#include<iostream>
#include"team.h"
using namespace std;

class Lista
{ 
	Team elem; 
	class  Lista* next; 
	
	public:
		Lista();
		Lista(Team , class Lista* );
		Lista& operator=(const Lista&);
		Lista(const Lista &);
		
		void creeazalista(Lista *&, int &, fstream &);
		void afiseazalista(ostream &);
		void adaugahead(Lista *&, Team);
		void afiseazalista_puncte(ostream &);
		void elimina(Lista *&, Lista *&);
		int minim(); // calculeaza punctjul minim pe intreaga lisita
		void elimin(Lista *&, int);//elimina echipa cu punctaj minim
		
		Team getelem();
		Lista* getnext();
		void setelem(Team );
		void setnext(Lista *);
		void adaugapuncte();
		void sterge();
		void salveaza(Lista *&);//copiaza lista
		void dezordoneaza(Lista *&); //sorteaza lista descrescator
}; 

