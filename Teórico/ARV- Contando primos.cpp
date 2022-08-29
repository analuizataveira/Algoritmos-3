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

//função adpatada para ordenar um vetor numeros
void contaEmOrdem (treenodeptr arvore, int numeros[], int &i)
{
	if(arvore!=NULL){
		contaEmOrdem(arvore->esq,numeros,i);
		numeros[i]=arvore->info;
		i++;
		contaEmOrdem(arvore->dir, numeros, i);
	}
	
}

//função para calcular o número de primos
int contaPrimos(treenodeptr arvore)
{	   	
  int numeros[100]; //vetor ordenado
  int primos=0; //numero de elementos primos
  int x=0; //variavel auxiliar para contar o numero de elementos primos
  int i = 1; //variável de controle
  int j; // variavel de controle
  int n; // numero de elementos do vetor
 
  //função para ordenar o vetor
  contaEmOrdem(arvore, numeros, i);
  n = i - 1; 

	for (i = 1; i <= n; i++)
	{
		x = 0;
		for (j = 1; j <= numeros[i]; j++)
		{
			if (numeros[i] % j == 0)
				x++;
		}
		if (x == 2)
			primos++;
	}
	
	return primos;
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


int main()
{
    treenodeptr arvore = NULL; //ponteiro para a raiz da árvore
    int N; //numero de nós inseridos na arvore
	int p; //variavel para ser atribuido numero de elementos primos
	
	//entrada de dados
    cin >> N;
    
    //criando árvore
    while (N != -1)
    {
        tInsere(arvore, N);
        cin >> N;
    }

	p= contaPrimos(arvore); 
    cout << p << " numeros primos" << endl;
	tDestruir(arvore);
    return 0;
}