#include <iostream>
#include"Node.h"
#include<string>
using namespace std;

void structureaza(Lista *&, int &);
void makearbore(Arbore *& ,Lista *&);
void makeAVL(Node *& ,Lista *&);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	fstream c(argv[1], ios::in);
 	if(!c)
 	{
		cout<<"Eroare la deschidere c.in!"<<endl;
	}
	fstream d(argv[2], ios::in);
 	if(!d)
 	{
		cout<<"Eroare la deschidere d.in!"<<endl;
	}
	fstream r(argv[3], ios::out);
 	if(!r)
 	{
		cout<<"Eroare la deschidere r.out!"<<endl;
	}

	Lista *head;
	int n;
	Lista *apel;
	Coada *meci;
	Coada *apl;
	Lista *last8;
	Arbore *root, *apell;
	root=NULL;
	Node *nod, *last;
	nod=NULL;			// Variabilele apel,apl,apell,last sunt variabile ajutatoare pentru apelarea
						//functiilor membre claselor folosite pentru a putea transmite calea prin *&



	int task[5];
	for (int i = 0; i < 5; i++)
	{
		c>> task[i];
	}

	for (int i = 0; i < 5; i++) {
		switch (i) {
			case 0: {
				if (task[0] == 1)
				{
						apel->creeazalista(head, n, d);  //construieste lista initiala
						if(task[1]==0)					//conditie pentru c.in: 1 0 0 0 0
						head->afiseazalista(r);
				}
				break;

			}
			case 1: {
				if (task[1] == 1)
				{
						structureaza(head, n);  //structureaza in asa fel incat sa ramana 2^k echipe
						head->afiseazalista(r);
				}
				break;

			}
			case 2: {
				if (task[2] == 1)
				{
						apl->makecoada(meci, head, n);
						head->sterge();// stergere lista creata la punctul 1
						apl->joaca(meci, n, last8, r); //jucarea rundelor, la fiecare iteratie coada va fi stearsa si refacuta
						apl->sterg(meci); //stergere coada
				}
				break;
			}
			case 3: {
				if (task[3] == 1)
				{
						makearbore(root, last8);
						r<<endl;
						r<<"TOP 8 TEAMS:"<<endl;
						apell->inorder(root, r);
						apell->delet(root); //stergere arbore
				}
				break;
			}
			case 4: {
				if (task[4] == 1)
				{
					apel->dezordoneaza(last8);
					makeAVL(nod, last8);
					r<<endl<<"THE LEVEL 2 TEAMS ARE:"<<endl;
						last->printGivenLevel(nod, 3, r);

						last->delet(nod);//stergere arbore
						last8->sterge();//stergere lista cu ultimele 8 echipe
				}
				break;
			}
			default: {
				cout << "Error! " << endl;
				break;
			}
		}

	}
	r.close();
	c.close();
	d.close();
	return 0;
}
