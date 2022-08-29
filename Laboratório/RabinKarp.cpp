#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q, int &last, int &qtd)
{
    int h;     // valor utilizado para calculo de hash
    int p = 0; // padrao convertido para inteiro
    int t = 0; // texto convertido para inteiro
    for (int i = 0; i < tamP; i++)
    {
        p = (d * p + (P[i] - '0')) % q; // converte o padrao
        t = (d * t + (T[i] - '0')) % q; // converte o texto para o primeiro valor (t0)
    }
    h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash
    for (int i = 0; i <= tamT - tamP; i++)
    {
        if (p == t) // Se encontrei um valor de hash valido
        {
            // Verifico se ha diferencas
            int j;
            for (j = 0; j < tamP; j++)
            {
                if (P[j] != T[i + j])
                {
                    break;
                }
            }
            if (j == tamP)
            {
                last = i;
                qtd++;
            }
        }
        if (i < tamT - tamP) // se ainda nao cheguei no final
        {
            t = (d * (t - (T[i] - '0') * h) + (T[i + tamP] - '0')) % q; // atualizo o ti para ti+1
            if (t < 0)
                t += q;
        }
    }
}
int main()
{
    char texto[100];
    char padrao[100];
    int n;
    int m;
    int lastOccurrence = 0;
    int qtd = 0;
    int q = 13;
    int d = 10;
    
    //entrada de dados
    cin >> n >> m;
    cin >> texto;
    cin >> padrao;
    
    
    rabin_karp(texto, padrao, n, m, d, q, lastOccurrence, qtd);
    if (qtd == 0)
        cout << "0 ocorrencia(s)" << endl;
    else
        cout << "Ultima ocorrencia: " << lastOccurrence << endl
             << qtd << " ocorrencia(s)" << endl;
    return 0;
}