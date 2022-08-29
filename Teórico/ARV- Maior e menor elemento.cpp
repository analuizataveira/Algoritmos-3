#include <iostream>
#include <climits>
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

// função preOrdem adpatada para que seja possivel calcular os maiores e menores elementos
void MaMePreOrdem(treenodeptr arvore, int &maior, int &menor)
{
    if (arvore != NULL)
    {
        if (arvore->info > maior)
            maior = arvore->info;

        if (arvore->info < menor)
            menor = arvore->info;
        
        MaMePreOrdem(arvore->esq, maior, menor);
        MaMePreOrdem(arvore->dir, maior, menor);
    }
}

int main()
{
    treenodeptr arvore = NULL; //ponteiro para a raiz da árvore
    int maior = -999999; //variaveis passadas por referencia
    int menor = 99999; //variaveis passadas por referencia
    int N; //numero de nós inseridos na arvore

	//entrada de dados
    cin >> N;
    
    //criando árvore
    while (N != -1)
    {
        tInsere(arvore, N);
        cin >> N;
    }

    MaMePreOrdem(arvore,maior,menor);

    cout << menor << " e " << maior << endl;

    return 0;
}