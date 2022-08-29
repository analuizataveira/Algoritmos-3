#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

int main()
{
	int n;
	ponto P1, P2, P3;
	float area;

	cout << fixed << setprecision(2);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> P1.x >> P1.y;
		cin >> P2.x >> P2.y;
		cin >> P3.x >> P3.y;

		area = area_triangulo(P1, P2, P3);
		
		
		if(area == 0)
			cout << "Nao formam triangulo" << endl;
		else
			cout << area << endl;
	}

	return 0;
}













