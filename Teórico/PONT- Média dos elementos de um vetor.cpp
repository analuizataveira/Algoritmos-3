#include <iostream>
using namespace std;

int main()
{	
	int N; // tamanho do vetor
	int *p; //ponteiro para apontar a posição correta do vetor 
	int *v = NULL; // vetor 
	int i; // variável de controle
	double numerador=0; //elemento para calcular media dos elementos
	
	
	// entrando com o tamanho do vetor
	cin >> N;
	
	//criando vetor dinamico de tamanho N
	v = new int[N];
	p = v;
	
	//preenchendo o vetor de N posições
	for(i = 0; i < N; i++)
	cin >> v[i];
	
	//calculando media dos elementos
	for(i = 0; i < N; i++){
	numerador+= *p; 
	p++;
	}
	
	//saida de dados
	cout << 1.0*numerador/N << endl;
	
	// deletando a memória alocada pelo vetor
	delete [] v;
	
	return 0;
}