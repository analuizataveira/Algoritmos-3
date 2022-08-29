#include <iostream>
using namespace std;

// struct com as informacoes de um no da arvore
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;

// funcao que insere elementos na arvore
void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}

	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);

	else             // insere na subarvore direita
		tInsere(p->dir, x);
}

// funcao que realiza o percurso pre-ordem
void preOrdem (treenodeptr arvore, int x, int &cont, bool &encontrou)
{
	if (arvore != NULL)
	{
		if(arvore->info != x && !encontrou)
			cont++;

		if(arvore->info == x)
		{
			cont++;
			encontrou = true;
		}

		preOrdem(arvore->esq, x, cont, encontrou);
		preOrdem(arvore->dir, x, cont, encontrou);
	}
}

// funcao que realiza o percurso em ordem
void emOrdem (treenodeptr arvore, int x, int &cont, bool &encontrou)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq, x, cont, encontrou);

		if(arvore->info != x && !encontrou)
			cont++;

		if(arvore->info == x)
		{
			cont++;
			encontrou = true;
		}

		emOrdem(arvore->dir, x, cont, encontrou);
	}
}

// funcao que realiza o percurso pos-ordem
void posOrdem (treenodeptr arvore, int x, int &cont, bool &encontrou)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq, x, cont, encontrou);
		posOrdem(arvore->dir, x, cont, encontrou);

		if(arvore->info != x && !encontrou)
			cont++;

		if(arvore->info == x)
		{
			cont++;
			encontrou = true;
		}
	}
}

// funcao para destruir a arvore
void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a raiz da arvore
	int x; // variavel auxiliar para inserir dados e receber informacao do chocolate
	int pre = 0, em = 0, pos = 0; // variaveis auxiliares para definir o melhor caminho
	bool preb = false, emb = false, posb = false; // variaveis auxiliares para definir o melhor caminho

	// inserindo elementos na arvore ate que a entrada seja 0
	cin >> x;

	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	// leitura do local onde esta o chocolate
	cin >> x;

	// percurso pre-ordem
	preOrdem(arvore, x, pre, preb);

	// percurso em ordem
	emOrdem(arvore, x, em, emb);

	// percurso pos-ordem
	posOrdem(arvore, x, pos, posb);

	// saidas; melhor caminho possivel para o chocolate
	if(pre <= em)
		if(pre <= pos)
			cout << "Pre" << endl;

		else
			cout << "Pos" << endl;

	else if(em <= pos)
		cout << "Em" << endl;

	else
		cout << "Pos" << endl;
	
	// destruindo a arvore
	tDestruir(arvore);

	return 0;
}