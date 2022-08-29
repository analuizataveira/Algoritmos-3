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

//função para pesquisar um elemento específico na árvore binária
treenodeptr tPesq(treenodeptr p, int x){
	if (p == NULL) // elemento nãoo encontrado returna NULL;
	return NULL;
		
	else
		if (x == p->info) // elemento encontrado na raiz	
		return p;
	
	else 
		if(x < p->info) //procura na subárvore esquerda
			return tPesq(p->esq,x);
	
    else 
		return tPesq(p->dir,x);	//pesquisa na subárvore direita
	
}

	
int main(){
	treenodeptr arvore = NULL; //ponteiro para raiz da arvore 
	treenodeptr p = NULL; //ponteiro que será feito a pesquisa do elemento
	int i; //variavel auxiliar
	int N; //numero de nós a serem inseridos
	int no; //elementos a serem inseridos na arvore 
	int X; //elemento a ser procurado
	
	//entrando com o número de nós a serem inseridos na arvore
	cin>> N;
	
	//criando arvore
	for(i=0;i<=N;i++){
		cin>> no;
		tInsere(arvore,no);	
		
	}
	
	//pesquisando elemento X na arvore
	cin >> X;
	p=tPesq(arvore,X);
	
	//saída de dados
	if(p==NULL) //não foi encontrado o nó
		cout << "Elemento nao encontrado" << endl;
	
	else //foi encontrado
		cout<< p->info << endl;

	return 0;	

}