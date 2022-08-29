#include <iostream>
#include <iomanip>

using namespace std;

// informações a serem armazenadas de cada aluno
struct notas
{
  int nota1;
  int nota2;
  int nota3;
  int nota4;
  double media;
};

int main()
{

  notas *aluno; // ponteiro criado para armazenar as informações das notas
  int n;        // tamanho do vetor dinamico
  int i;        // variavel auxiliar
  double mediafinal = 0;

  // determinando tamamanho do vetor dinamico
  cin >> n;
  aluno = new notas[n];

  // entrada de dados
  for (i = 0; i < n; i++)
  {
    cin >> aluno[i].nota1 >> aluno[i].nota2 >> aluno[i].nota3 >> aluno[i].nota4;
  }

  // calculando media de cada aluno
  for (i = 0; i < n; i++)
  {
    aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3 + aluno[i].nota4)/4.0;
    mediafinal += aluno[i].media;
  }

  //saída de dados
  cout << fixed << setprecision(2);
  cout << mediafinal / n << endl;
  
  
  delete [] aluno;
}