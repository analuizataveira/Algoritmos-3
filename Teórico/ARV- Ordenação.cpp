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
	
	//insere na raiz
	if (p == NULL)
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	
	}
	
	//insere na subarvore esq
	else if (x < p->info)
		tInsere(p->esq,x);
	
	//insere na subarvore direita
	else
		tInsere(p->dir,x);
}	

//função adpatada para varrer os elementos em ordem decrescente
void OrdemDec(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		OrdemDec(arvore->dir); //os elementos da arvore direita são maiores que a raiz
		cout << arvore->info << " ";
		OrdemDec(arvore->esq); //os elementos da arvore esquerda sao menores que o da raiz
	}
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a raiz da arvore
	int N; //numero de elementos a serem inseridos na arvore
	
	 
	//entrando com o número de nós a serem inseridos na arvore
	cin>> N;
	
	//criando arvore
	while(N!=-1){
		
	tInsere(arvore,N);	
	cin >> N;	
	
	}
	
	OrdemDec(arvore);
	
	return 0;
}