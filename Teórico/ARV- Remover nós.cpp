#include <iostream>
#include <iomanip>

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



//funcao para destruir a arvore para limpar a memoria caso necessário
void tDestruir(treenodeptr &arvore)
{
	if(arvore != NULL)
	{

		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}


//função auxiliar para o tremove que encontra o meonr elemento do lado direito da arvore
treenodeptr tMenor(treenodeptr &raiz){
    
	treenodeptr t;
    
    t = raiz;
    
    //encontrou o menor valor
    if(t->esq == NULL){
		
		raiz = raiz->dir;
		return t;
	}
    
    //continua a busca na subarvore esquerda
    else 
    	return tMenor(raiz->esq);
}

//função auxiliar para tremove que encontra o maior elemento do lado direito da arvore
treenodeptr tMaior(treenodeptr &raiz){
    
	treenodeptr t;
    
    t = raiz;
    
    //encontrou o menor valor
    if(t->dir == NULL){
		
		raiz = raiz->dir;
		return t;
	}
    
    //continua a busca na subarvore esquerda
    else 
    	return tMaior(raiz->dir);
}

//funcao para remoção de nós
int tRemove(treenodeptr &raiz, int x){
	
	treenodeptr p;
	
	//arvore ja esta vazia
	if(raiz == NULL)
		return 1;
	
	if(x == raiz->info){
		
		p = raiz;
		
		//a raiz nao tem filho esquerdo
		if(raiz->esq == NULL)
			raiz = raiz->dir;
		
		//a raiz nao tem filho direito
		else if(raiz->dir == NULL)
			raiz = raiz->esq;
		
		//a raiz tem ambos os filhos
		else{
			
			p = tMenor(raiz ->dir);
			raiz->info = p->info;
		}
		
		delete p;
		return 0;
	}
	
	else if(x < raiz->info)
		return tRemove(raiz->esq, x);
	
	else 
		return tRemove(raiz->dir, x);
}

//funcao emOrdem para retornar os valores de forma crescente
void emOrdem(treenodeptr arvore)
{
	if(arvore != NULL){
        
		emOrdem(arvore->esq); //os valores da esquerda sao os menores
        cout << arvore->info << " ";
        emOrdem(arvore->dir); //os valores da direita sao os maiores
    }
}


int main()
{
    treenodeptr arvore = NULL; //ponteiro para a raiz da árvore
    int N; //numero de nós inseridos na arvore
	int x; //valor a ser removido da árvore
	int Rm; //variavel auxiliar
	
	//entrada de dados
    cin >> N;
    
    //criando árvore
    while (N != 0)
    {
        tInsere(arvore, N);
        cin >> N;
    }

	//entrando com o nó a ser removido
	cin >> x;
   
    
    Rm= tRemove(arvore, x);
    while(Rm != 1){
		Rm= tRemove(arvore, x);
	}
    
    emOrdem(arvore);
	
	tDestruir(arvore);
    
    return 0;
    
    
}