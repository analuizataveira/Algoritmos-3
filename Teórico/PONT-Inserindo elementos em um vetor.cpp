#include <iostream>
using namespace std;

int main()
{	
	int N; // tamanho do vetor
	int *p; //ponteiro para apontar a posição correta do vetor e inserir o elemento
	int *v = NULL; // vetor 
	int i; // variável de controle
	
	// entrando com o tamanho do vetor
	cin >> N;
	
	//criando vetor dinamico de tamanho N
	v = new int[N];
	p = v;
	
	//preenchendo o vetor de N posições
	for(i = 0; i < N; i++)
	cin >> v[i];
	
	
	// mostrando o vetor
	for(i = 0; i < N; i++){
	cout << *p << " ";
	p++;
	}
	
	// deletando a memória alocada pelo vetor
	delete [] v;
	
	return 0;
}