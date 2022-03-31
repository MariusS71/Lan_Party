#include<iostream>
#include"Coada.h"
#include<fstream>
#include<iomanip>
using namespace std;

Coada::Coada()
{
//	cout<<"constr fara param Coada"<<endl;
	next=NULL;
}

Coada::Coada(Team n1, Team n2, Coada* t)
{
//	cout<<"constr cu param Coada"<<endl;
	elem1=n1;
	elem2=n2;
	next=t;
}

Coada& Coada::operator=(const Coada& t)
{

//	cout<<"Operator egal Coada"<<endl;
	elem1=t.elem1;
	elem2=t.elem2;
	next=t.next;

	return *this;
}


Coada::Coada(const Coada &t)
{
//	cout<<"Constr de copiere Coada"<<endl;

	*this=t;
}

void Coada::makecoada(Coada *&meci, Lista *head, int n)
{
	Coada *c1;
	Lista *p;
	p=head;
	c1=new Coada;
	c1->elem1=p->getelem();
	p=p->getnext();
	c1->elem2=p->getelem();
	p=p->getnext();
	c1->next=NULL;
	Coada *c2;
	meci=c1;
	
	for(int i=1; i<n/2; i++)
	{
		c2=new Coada;
		c2->elem1=p->getelem();
		p=p->getnext();
		c2->elem2=p->getelem();
		p=p->getnext();
        c2->next=NULL;
        c1->next=c2;
        c1=c2;
	}
}

void Coada::afisarecoada(ostream & dev)
{
	Coada *p;
	p=this;
	while(p!=NULL)
	{
		string size="                                 -                                 ";
		size=size.substr(0, size.length()-p->elem2.getnumeteam().length());
		size.erase(0, p->elem1.getnumeteam().length());
		
		dev<<p->elem1<<size<<p->elem2<<endl;

		p=p->next;
	}
}


void Coada::joaca(Coada *& meci, int &n, Lista *&last8, ostream & f)
{	
	
	int i=0;
	f<<endl;
	while(n!=1) //se repeta ciclul pana ramane o singura echipa
	{
		i++;
		f<<"--- ROUND NO:"<<i<<endl;
		meci->afisarecoada(f);

		Lista *win, *lose;//capatul listelor pt win si lose
		
		stive(meci, win, lose);//apel de creeare a stivelor
		
				
		//adaugare punte pentru wineri 
		win->adaugapuncte();
		
		//afisare  Liste lose win
		f<<endl;
		f<<"WINNERS OF ROUND NO:"<<i<<endl;
		win->afiseazalista_puncte(f);
		if(n!=2)
		f<<endl;
		

		n=n/2;
		
		//salvarea ultimelor 8 echipe
		if(n==8)
		{
			win->salveaza(last8);
		}
		
		//extragerea elementelor din lista win inapoi in coada
		Coada *apel;
		if(n!=1)
		apel->makecoada(meci, win, n);
		
		//stergere liste win si lose
		win->sterge();
		lose->sterge();		
	}
	
}

void Coada::stive(Coada *&meci, Lista *&win, Lista*&lose)
{
	Lista *w, *l;
	Coada *p=meci;
		//Primele elemente din win si lose(care vor fi de fapt ultimele, introducerea in liste facandu se la inceput)
		if(p->elem1.get_puncte_team()>p->elem2.get_puncte_team())
		{
			w=new Lista;
			w->setelem(p->elem1);
			w->setnext(NULL);
			win=w;
			
			l=new Lista;
			l->setelem(p->elem2);
			l->setnext(NULL);
			lose=l;
		}		
		else if(p->elem1.get_puncte_team()<=p->elem2.get_puncte_team())
		{
			w=new Lista;
			w->setelem(p->elem2);
			w->setnext(NULL);
			win=w;
			
			l=new Lista;
			l->setelem(p->elem1);
			l->setnext(NULL);
			lose=l;
		}/*
		else if(p->elem1.get_puncte_team()==p->elem2.get_puncte_team())
		{
			if(p->elem1.getnumeteam() < p->elem2.getnumeteam())
			{
				w=new Lista;
				w->setelem(p->elem1);
				w->setnext(NULL);
				win=w;
				
				l=new Lista;
				l->setelem(p->elem2);
				l->setnext(NULL);
				lose=l;
			}
			else
			{
				w=new Lista;
				w->setelem(p->elem2);
				w->setnext(NULL);
				win=w;
				
				l=new Lista;
				l->setelem(p->elem1);
				l->setnext(NULL);
				lose=l;
			}
		}*/
		meci=p->next;
		delete p;

		//urmatoarele elemente pentru win lose
		while(meci!=NULL)
		{
			p=meci;
			if(p->elem1.get_puncte_team()>p->elem2.get_puncte_team())
			{
				w=new Lista;
				w->setelem(p->elem1);
				w->setnext(win);
				win=w;
				
				l=new Lista;
				l->setelem(p->elem2);
				l->setnext(lose);
				lose=l;
			}		
			else if(p->elem1.get_puncte_team()<=p->elem2.get_puncte_team())
			{
				w=new Lista;
				w->setelem(p->elem2);
				w->setnext(win);
				win=w;
				
				l=new Lista;
				l->setelem(p->elem1);
				l->setnext(lose);
				lose=l;
			}/*
			else if(p->elem1.get_puncte_team()==p->elem2.get_puncte_team())
			{
				if(p->elem1.getnumeteam() < p->elem2.getnumeteam())
				{
					w=new Lista;
					w->setelem(p->elem1);
					w->setnext(win);
					win=w;
					
					l=new Lista;
					l->setelem(p->elem2);
					l->setnext(lose);
					lose=l;
				}
				else
				{
					w=new Lista;
					w->setelem(p->elem2);
					w->setnext(win);
					win=w;
					
					l=new Lista;
					l->setelem(p->elem1);
					l->setnext(lose);
					lose=l;
				}
			}*/
			meci=p->next;
			delete p;
		}
}

void Coada::sterg(Coada *&meci)
{
	Coada *p, *q;
	p=meci;
	q=p;
	while(q!=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
}
