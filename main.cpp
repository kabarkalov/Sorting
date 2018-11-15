#include <stdio.h>
#include <stdlib.h>

void CountSort(int* mas, int size, int *counter, int max)
{
	int i, j, k;
	for (i = 0; i <= max; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[mas[i]]++;

	k = 0;
	for (int i = 0; i <= max; i++)
		for (int j = 0; j<counter[i];j++)
			mas[k++] = i;
}

void QuickSort(int *mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	while (f<l)
	{
		while (mas[f]<mid) f++;
		while (mas[l]>mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} 
	if (first<l) QuickSort(mas, first, l);
	if (f<last) QuickSort(mas, f, last);
}


void Merge(int *B, int*  C, int Start, int Middle, int End)
{

	int i, j, k;
	i = Start;
	j = Middle + 1;
	k = Start;
	while ((i <= Middle) && (j <= End)) 
	{
		if (B[i] <= B[j])
		{
			C[k] = B[i];
			i++; k++;
		}
		else
		{
			C[k] = B[j];
			j++; k++;
		}
	}
	if (i > Middle)
		while (j <= End)
		{
			C[k] = B[j];
			j++; k++;
		}
	if (j > End)
		while (i <= Middle)
		{

			C[k] = B[i];
			i++; k++;
		}
	for (i = Start; i <= End; i++)
		B[i] = C[i];
}

void MergeSort(int* B, int* C, int Start, int End)
{
	int Middle;

	if (Start == End) return;
	Middle = (Start + End) / 2;
	MergeSort(B, C, Start, Middle);
	MergeSort(B, C, Middle + 1, End);
	Merge(B, C, Start, Middle, End);
}

void main()
{
	int size = 20;
	int MaxElem = 100;
	int *mas = (int*)malloc(size*sizeof(int));
	int *buffer=(int*)malloc(size*sizeof(int));
	int *counter=(int*)malloc((MaxElem+1)*sizeof(int));


	for (int i = 0; i < size; i++)
	{
		mas[i] = size - i;
		printf("%i ", mas[i]);
	}
	printf("\n");

//	QuickSort(mas, 0, size - 1);
	MergeSort(mas,buffer, 0, size - 1);
//	CountSort(mas,size, counter, MaxElem);


	for (int i = 0; i < size; i++)
	{
		printf("%i ", mas[i]);
	}
	printf("\n");

	free(mas);
	free(buffer);
	free(counter);

}