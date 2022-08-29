#include <iostream>
using namespace std;

int main()
{
	int N; // tamanho do vetor
	int *p; //ponteiro para apontar a posição correta do vetor 
	int *v = NULL; // vetor 
	int i; // variável de controle
	int maior=0; //variavel para calcular o maior elemento do vetor
	
	// entrando com o tamanho do vetor
	cin >> N;
	
	//criando vetor dinamico de tamanho N
	v = new int[N];
	p = v;
	
	//preenchendo o vetor de N posições
	for(i = 0; i < N; i++)
	cin >> v[i];
	
	//calculando o maior elemento do vetor
	maior=*p;
    for(i=0;i<N;i++){
    	
   	   if(*p>maior){
  	 	maior = *p;
		}
		
		p++;
	}	

	//saida de dados
	cout << maior << endl;
	
	// deletando a memória alocada pelo vetor
	delete [] v;
	
	return 0;
}
