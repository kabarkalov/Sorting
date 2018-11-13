#include <stdio.h>

void quicksort(int *mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //���������� �������� ��������
	do
	{
		while (mas[f]<mid) f++;
		while (mas[l]>mid) l--;
		if (f <= l) //������������ ���������
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f<l);
	if (first<l) quicksort(mas, first, l);
	if (f<last) quicksort(mas, f, last);
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
	const int size = 10;
	int mas[size] = { 9,8,7,6,5,4,23,2,1,5};
	int buffer[size];

	for (int i = 0; i < size; i++)
	{
		printf("%i ", mas[i]);
	}
	printf("\n");

//	quicksort(mas, 0, size - 1);
	MergeSort(mas,buffer, 0, size - 1);


	for (int i = 0; i < size; i++)
	{
		printf("%i ", mas[i]);
	}
	printf("\n");

}