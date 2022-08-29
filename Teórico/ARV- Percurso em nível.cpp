#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

// struct para criar um nó em uma árvore binária
struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};

typedef treenode *treenodeptr;

// função para inserir um elemento em uma árvore de busca binária
void tInsere(treenodeptr &p, int x)
{
    // insere na raiz
    if (p == NULL)
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }

    // insere na subarvore esq
    else if (x < p->info)
        tInsere(p->esq, x);

    // insere na subarvore direita
    else
        tInsere(p->dir, x);
}

//realiza um percurso em nivel na arvore
void emNivel(treenodeptr t){
	
	treenodeptr n;
	list <treenodeptr> q;
	
	if(t != NULL){
		
		q.push_back(t);
		
		while(!q.empty()){
			
			n = *q.begin();
			q.pop_front();
			
			if(n->esq != NULL)
				q.push_back(n->esq);
			
			if(n->dir != NULL)
				q.push_back(n->dir);
			
			cout << n->info << " ";
		}
		cout << endl;
	}
}

//funcao pra destruir a arvore
void tDestruir(treenodeptr &arvore){
	
	if(arvore != NULL){
		
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	
	arvore = NULL;
}


int main()
{
    treenodeptr arvore = NULL; //ponteiro para a raiz da árvore
    int N; //numero de nós inseridos na arvore
	
	//entrada de dados
    cin >> N;
    
    //criando árvore
    while (N != -1)
    {
        tInsere(arvore, N);
        cin >> N;
    }

	emNivel(arvore);
	
	tDestruir(arvore);
    
    return 0;
    
    
}