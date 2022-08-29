#include <iostream>

using namespace std;

struct dados{ //struct para armazenar notas
	
	int nota1; //variavel para armazenar o valor de uma nota
	int nota2; //variavel para armazenar o valor de uma nota
	int nota3; //variavel para armazenar o valor de uma nota
	int nota4; //variavel para armazenar o valor de uma nota
	float media; //variavel para armazenar o valor da média
	
};

int main()
{
    dados *notas = NULL; //ponteiro
    int i; //variável auxiliar
    
    
    //alocando memoria
    notas = new dados;
    
	//entrando com o valor das notas que sera armazenado
	cin >> notas->nota1;
	cin >> notas->nota2;
	cin >> notas->nota3;
	cin >> notas->nota4;
		
 	notas->media = 1.0*(notas->nota1 + notas->nota2 + notas->nota3 + notas->nota4)/4;
    
     //sáida de dados
    cout << notas->media;
    

    //liberando memoria
	delete [] notas;
	
    return 0;
}