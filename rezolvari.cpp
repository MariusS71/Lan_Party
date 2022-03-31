#include <iostream>
#include"Node.h"
#include<string>
#include<fstream>
using namespace std;		
		
void structureaza(Lista *&head, int &n)
{
	int i=1;
	while(i<=n)
	{
		i=i*2;
	}
	i=i/2;  //i va fi nr de echipe care trebuie sa ramana in lista
	Lista *apel;
	while(i!=n) //eliminarea echipelor pana la i
	{
		apel->elimin(head, head->minim());
		n--;
	}
}

void makearbore(Arbore *&root, Lista *&last8) // arbore BST
{
	Lista *p;
	p=last8;
	Arbore *apel;
	while(p!=NULL)
	{
		root=apel->insert(root, p->getelem());
		p=p->getnext();
	}
}

void makeAVL(Node *& root,Lista *&last8)
{
	Lista *p;
	p=last8;
	Node *apel;
	
	while(p!=NULL)
	{

		root=apel->insert(root, p->getelem());

		p=p->getnext();
	}
}




