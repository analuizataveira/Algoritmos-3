#include <iostream>
#include <iomanip>

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
	else if (x < p->info)
		tInsere(p->esq,x);
	else
		tInsere(p->dir,x);
}	

//função preOrdem adaptada para calcular a soma dos elementos da árvore e o número de elementos
void MediapreOrdem(treenodeptr arvore, float &soma, float &q)
{
  if (arvore != NULL)
  {
    MediapreOrdem(arvore->esq, soma, q);
    MediapreOrdem(arvore->dir, soma, q);
    soma += arvore->info; //soma dos elementos
    q++; //quantidade de elementos
  }
  
}

int main(){
	
	treenodeptr arvore = NULL; //ponteiro para raiz da arvore 
	int N; //numero de nós a serem inseridos
	float soma=0; //variavel passada por referencia
	float q=0; //variavel passada por referncia
	float media=0; //variavel para calcular a media dos elementos
	
	//entrando com o número de nós a serem inseridos na arvore
	cin>> N;
	
	//criando arvore
	while(N!=-1){
	tInsere(arvore,N);	
	cin >> N;	
	}
	
	MediapreOrdem(arvore,soma,q);
	media= soma/q*1.00;
		
	cout << fixed << setprecision(2);	
    cout << "Media: " << media << endl;
	
	
	return 0;
	}