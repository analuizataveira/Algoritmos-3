#include <iostream>
using namespace std;

int main()
{
	int N; // tamanho do vetor
	int *p; //ponteiro para apontar a posição correta do vetor 
	int *v = NULL; // vetor 
	int i; // variável de controle
	int pares=0; //variavel para contar os elementos pares positivos do vetor
	
	// entrando com o tamanho do vetor
	cin >> N;
	
	//criando vetor dinamico de tamanho N
	v = new int[N];
	p = v; //ponteiro aponta pro vetor v
	
	//preenchendo o vetor de N posições
	for(i = 0; i < N; i++)
	cin >> v[i];
	
	//calculando elementos pares positivos do vetor
    for(i=0;i<N;i++){
    	
		if (*p > 0 && *p%2 ==0){
		pares++;
		}
		
    	p++;
	}	

	//saida de dados
	cout << pares << endl;
	
	// deletando a memória alocada pelo vetor
	delete [] v;
	
	return 0;
}
