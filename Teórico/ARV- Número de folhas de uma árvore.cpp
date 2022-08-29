#include <iostream>

using namespace std;

//struct para criar um nó em uma árvore binária
struct treenode{
	int info;
	treenode *esq;
	treenode *dir;
};

typedef treenode* treenodeptr;


//função para inserir um elemento em uma árvore de busca binária
void tInsere(treenodeptr &p, int x){
	if (p == NULL){
	p = new treenode;
	p->info = x;
	p->esq = NULL;
	p->dir = NULL;
	}
	else 
		if (x < p->info)
		tInsere(p->esq,x);
	else
		tInsere(p->dir,x);
}	

//função pre ordem adpatada para calcular o numero de folhas
void contapreOrdem (treenodeptr arvore, int &f)
{

	if (arvore != NULL)
	{	
		contapreOrdem(arvore->esq, f);
		contapreOrdem(arvore->dir, f);
			  
		//caso o nó esq e nó direito sejam nulos, ou seja, trata de uma folha	  		
		if((arvore->esq)==NULL && (arvore->dir)==NULL)
			f++; //soma-se 1 na variavel folha
	   	
	}
	
}

//função para contar o número de folhas 
int contaFolhas(treenodeptr arvore)
{
	int f = 0; //variavel passada por referencia
	contapreOrdem(arvore, f);
	return f;

}


int main()
{
	treenodeptr arvore = NULL;   //ponteiro para criação da árvore	
	int N=0; //elementos a serem inseridos na árvore
		
	//entrada de dados	
	cin>> N;
	
	//criando a árvore
	while(N!=-1)
	{
	   	tInsere(arvore,N);	
	   	cin>> N;
	
    }	
	  
	N= contaFolhas(arvore);
	
	//sáida de dados
	cout << N << endl;
	
	return 0;

}
