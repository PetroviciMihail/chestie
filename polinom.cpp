#include<stdio.h>
#include<malloc.h>

void citire_polinom(int* grad, float** coef)
{
	int i;
	printf("gradul polinomului este: ");
	scanf("%d", &*grad); //se poate pune grad direct
	*coef = (float*)malloc((*grad + 1) * sizeof(float));

	for (i = *grad; i >=0 ; i--)
	{
		printf("coeficientul lui x^%d este:",i);
		scanf("%f", &(*coef)[i]);
	}
}
float functie(int grad, float* coef, float x)
{   
	int i;
	float rez=0, f=x;
	rez = *coef;
	for (i = 1; i <= grad; i++)
	{
		rez = rez + coef[i] * f;
		f = f * x;
	}
	return rez;
}
float radacina(int grad, float* coef, float a, float b, int nr_iteratii, float epsilon)
{
	float mij;
	if (0 == functie(grad, coef, a))
		return a;
	if (functie(grad, coef, b) == 0)
		return b;

	while (nr_iteratii > 0)
	{
		mij = (a + b) / 2;
		if (functie(grad, coef, mij) == 0)
			return mij;
		if (functie(grad, coef, mij) * functie(grad, coef, a) < 0)
			b = mij;
		else a = mij;

		if (b - a <= epsilon)
			return a;
		nr_iteratii--;

	}

}
void main()
{
	int n, i;
	float  *v,a,b;
	citire_polinom(&n, &v);

	printf("limita din stanga a intervalului este:");
	scanf("%f", &a);
	printf("limita din dreapta a intervalului este:");
	scanf("%f", &b);

	if (functie(n, v, a) * functie(n, v, b) > 0)
		printf("polinomul nu are radacina in intervalui[%.1f,%.1f] sau sunt mai multe radacini", a, b);
	else printf("radacina este: %.1f", radacina(n, v, a, b, 1000, 0.00001));
	free(v);
}