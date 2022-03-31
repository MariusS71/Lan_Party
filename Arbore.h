#include <iostream>
#include"Coada.h"
#include<string>
using namespace std;

class Arbore
{
	Team elem;
	Arbore* left;
	Arbore* right;
	
	public:
	Arbore();
	Arbore(Team , class Arbore*, class Arbore*);
	
	Arbore* insert(Arbore *, Team);
	Arbore* getnewnode(Team);
	
	void inorder(Arbore *, ostream &);
	void delet(Arbore *&);

};
