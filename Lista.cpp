#include<iostream>
#include"Lista.h"
#include<fstream>
#include<iomanip>
using namespace std;

Lista::Lista()
{
//	cout<<"constr fara param Lista"<<endl;
	next=NULL;
}

Lista::Lista(Team t, class Lista* n)
{
//	cout<<"constr cu param Lista"<<endl;
	elem=t;
	next=n;
}

Lista& Lista::operator=(const Lista& t)
{

//	cout<<"Operator egal Lista"<<endl;
	elem=t.elem;
	next=t.next;

	return *this;
}


Lista::Lista(const Lista &t)
{
//	cout<<"Constr de copiere Lista"<<endl;

	*this=t;
}


void Lista::creeazalista(Lista *&head, int &n, fstream &f)
{
	
	f>>n;
	Team aux;
	f>>aux;
	Lista *apel;
	head=new Lista;
	head->elem=aux;
	head->next=NULL;
	for(int i=1; i<n; i++)
	{
		f>>aux;
		apel->adaugahead(head, aux);
	}
}

void Lista::adaugahead(Lista *&head, Team aux)
{
	Lista *w;
	w=new Lista;
	w->elem=aux;
	w->next=head;
	head=w;
}

void Lista::afiseazalista(ostream & dev)
{
	Lista *p;
	p=this;
	while(p!=NULL)
	{
		dev<<p->elem;
		p=p->next;
		dev<<endl;
	}

}

void Lista::afiseazalista_puncte(ostream &dev)
{
	Lista *p;

	p=this;
	while(p!=NULL)
	{
		string size="                                  -  ";
		size.erase(0, p->elem.getnumeteam().length());
		dev<<left<<p->elem<<size;
		dev<<fixed<<setprecision(2);
		dev<<right<<(double)p->elem.getmedie();

		p=p->next;
		dev<<endl;
	}

}

int Lista::minim()
{
	Lista *p;
	p=this;
	int min=p->elem.get_puncte_team();
	p=p->next;
	while(p!=NULL)
	{
		if(min>(p->elem.get_puncte_team()))
		{
			min=p->elem.get_puncte_team();
		}
		p=p->next;
	}
	return min;
}


void Lista::elimin(Lista *& head, int min)
{
	Lista *p, *q;
	p=head;
	q=p->next;
	if(min==p->elem.get_puncte_team())
	{
		head=q;
		delete p;
	}
	else
	{
		while(q!=NULL)
		{
			if(min==q->elem.get_puncte_team())
			{
				p->next=q->next;
				delete q;
				return;
			}
			p=q;
			q=p->next;
		}
	}
}

Team Lista::getelem()
{
	return elem;
}

Lista* Lista::getnext()
{
	return next;
}

void Lista::setelem(Team t)
{
	elem=t;
}

void Lista::setnext(Lista *n)
{
	next=n;
}

void Lista::adaugapuncte()
{
	Lista *p;
	p=this;
	while(p!=NULL)
	{
		p->elem.pluspct_team();
		p=p->next;
	}
}

void Lista::sterge()
{
	Lista *p, *q;
	p=this;
	q=p;
	while(q!=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
}

void Lista::salveaza(Lista *&last8)
{
	Lista *win;
	win=this;
	Lista *p, *q;
	
	p=new Lista;
	p->elem=win->elem;
	p->next=NULL;
	last8=p;
	
	win=win->next;
	while(win!=NULL)
	{
		q=new Lista;
		q->elem=win->elem;
        p->next=q;
        p=q;
        win=win->next;
	}
}

void Lista::dezordoneaza(Lista *&last8)
{
	Lista *p, *q;
	p=last8;
	
	while(p!=NULL)
	{
		q=p;
		while(q!=NULL)
		{
			if(p->elem.getmedie()<q->elem.getmedie())
			{
				Team aux;
				aux=p->elem;
				p->elem=q->elem;
				q->elem=aux;
			}
			else if(p->elem.getmedie()==q->elem.getmedie())
			{
				if(p->elem.getnumeteam() < q->elem.getnumeteam())
				{
					Team aux;
					aux=p->elem;
					p->elem=q->elem;
					q->elem=aux;
				}
			}
			q=q->next;
		}
		p=p->next;
	}
	
	
	
}
