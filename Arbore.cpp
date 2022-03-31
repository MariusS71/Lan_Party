#include <iostream>
#include"Arbore.h"
#include<string>
#include<iomanip>
using namespace std;

Arbore::Arbore()
{
	left=NULL;
	right=NULL;
}

Arbore::Arbore(Team t, Arbore* l, Arbore* r)
{
	elem=t;
	left=l;
	right=r;
}

Arbore* Arbore::insert(Arbore *root, Team data)
{
	Arbore *apel;
	if(root==NULL)
	{
		root=apel->getnewnode(data);
	}
	else if(data.getmedie() < root->elem.getmedie())
	{
		root->left=apel->insert(root->left, data);
	}
	else if(data.getmedie() > root->elem.getmedie())
	{
		root->right=apel->insert(root->right, data);
	}
	else if(data.getmedie() == root->elem.getmedie())
	{
		if(data.getnumeteam() < root->elem.getnumeteam())
		{
			root->left=apel->insert(root->left, data);
		}
		else
		{
			root->right=apel->insert(root->right, data);
		}
	}
	
	return root;
}

Arbore* Arbore::getnewnode(Team data)
{
	Arbore* newnode= new Arbore;
	newnode->elem=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}


void Arbore::inorder(Arbore *root, ostream & f) 
{
	if (root != NULL) 
	{
        inorder(root->right, f);
        
		string size="                                  -  ";
		size.erase(0, root->elem.getnumeteam().length());
		f<<root->elem<<size;
		
        f<<fixed<<setprecision(2);
        f<<std::right<<(root->elem.getmedie())<<endl; 
			   
        inorder(root->left, f);
    }
}


void Arbore::delet(Arbore*& root)
{
  if (root == NULL) { return; }

  delet(root->left);
  delet(root->right);

  delete root;
  root = NULL;
}
