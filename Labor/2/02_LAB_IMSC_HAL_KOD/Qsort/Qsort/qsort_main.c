#include <stdio.h>	// printf(), scanf(), scanf_s() (csak Microsoft standard C library!)
#include <stdlib.h>	// Memóriakezeléshez
#include <string.h>	// Valamiért a memcpy() nem volt definiálva a stdlib.h-ban
#include <time.h>	// Teszteléshez random feltöltéshez seed generáláshoz

#define ARRAY_MAX 5

// Az összehasonlító függvény:
// a tömb két elemét hasonlítja össze.
// Ezt nekünk kell megírnunk, hiszen bármilyen típusú
// tömböt átadhatunk volna a qsortnak, és
// ő nem tud a típusról.
// Miért void pointerek a paraméterei?
int compare(const void *a, const void *b)
{
	// 1. FELADAT - ide kell egy break point (töréspont)
	double *da = (double *)a, *db = (double *)b;

	// Visszatérés: <0, ha a a<b; 0, ha a=b;	>0, ha a>b.
	if (*da < *db)
		return -1;
	else if (*da == *db)
		return 0;
	else
		return 1;
}

// 5. FELADAT: qsort paraméterlistájával megegyező függvény, amely rendező algoritmust valósít meg

// Swap fgv az elemcseréhez

int swap(void *a, void *b, size_t elem_size)
{
	void *temp = malloc(elem_size);

	memcpy(temp, a, elem_size);
	memcpy(a, b, elem_size);
	memcpy(b, temp, elem_size);

	free(temp);
}

// Optimalizált Bubble sort algoritmus

void myBubbleSort(void *base, size_t arr_size, size_t elem_size, int (*compar)(const void *, const void *))
{
	for (size_t i = arr_size; i > 1;)
	{
		size_t sorted_num;
		size_t swap_cnt = 0;

		for (size_t j = 1; j < i; j++)
		{
			if (compare(base + (j - 1) * elem_size, base + j * elem_size) > 0)
			{
				swap(base + (j - 1) * elem_size, base + j * elem_size, elem_size);
				sorted_num = j;
				swap_cnt++;
			}
		}
		i = sorted_num;
		if (swap_cnt == 0)
			return;
	}
}

int main()
{
	// 2. FELADAT: tömbméret bekérés a felhasználótól. Használj dinamikus memóriakezelést!

	// Méret bekérése

	size_t arr_size;

	printf("\nEnter array size: ");
	scanf("%llu", &arr_size);

	// Memóriakezelés

	double *array = malloc(arr_size * sizeof(double));

	if (array == NULL)
		return -1;

	// double d[ARRAY_MAX];
	// int i;

	// 4. FELADAT: biztonságos szövegbevitel. Tipp: scanf_s
	// miért kell scanf_s: ha olyan területre írunk, amit nem foglaltunk le (akár csak kis részben is) => segmentation fault hiba
	// hacker/óvatlan felhasználó leállíthatja a programunk: buffer overflow attack
	// Warning kikapcsolás: C/C++ -> Preprocessor -> Preprocessor definitions: _CRT_SECURE_NO_WARNINGS

	//	for (size_t i = 0; i < arr_size; i++)
	//	{
	//		printf("Enter a number:");
	//
	//		// scanf_s használatával buffer overflow elkerülhető (csak Microsoft C library!!!)
	//
	//		if (scanf_s("%lf", &array[i]) != 1)
	//		{
	//			free(array);
	//			return -1;
	//		}
	//	}

	// 3. FELADAT: scanf háromféleképpen

	// 1.:

	//	for (size_t i = 0; i < arr_size; i++)
	//	{
	//		printf("Enter a number:");
	//
	//		// Sima tömbindexelés
	//
	//		scanf("%lf", &array[i]);
	//	}

	//	// 2.:
	//
	//	for (size_t i = 0; i < arr_size; i++)
	//	{
	//		printf("Enter a number:");
	//
	//		// Címképzés a tömb i. eleméből
	//
	//		scanf("%lf", &(array[i]));
	//	}
	//
	//	// 3.:
	//
	//	double *elemptr = array;
	//
	//	for (size_t i = 0; i < arr_size; i++)
	//	{
	//		printf("Enter a number:");
	//
	//		// Pointeraritmetika
	//
	//		scanf("%lf", elemptr + i);
	//	}

	// Teszteléshez random feltöltött tömb 0-255ig számokkal

	srand(time(NULL));

	for (size_t i = 0; i < arr_size; i++)
	{
		array[i] = rand() % 256;
	}

	// Második ugyanolyan tömb összehasonlításra

	double *array2 = malloc(arr_size * sizeof(double));

	if (array == NULL)
		return -1;

	memcpy(array2, array, arr_size * sizeof(double));

	// qsort és myBubbleSort futtatása

	printf("\nSorting with built in qsort...\n");

	qsort(array, arr_size, sizeof(double), compare);

	printf("Done built in qsort\n");

	printf("Sorting with myBubbleSort...\n");

	myBubbleSort(array2, arr_size, sizeof(double), compare);

	printf("Done myBubbleSort\n\n");

	printf("Do you want to print sorted array? (y/n)\n");

	getchar();

	if (getchar() == 'y')
	{
		for (size_t i = 0; i < arr_size; i++)
		{
			printf("%lf ", array2[i]);
		}
	}

	// 2. FELADAT: a korábban lefoglalt dinamikus területet ne felejtsd el felszabadítani!

	free(array);
	free(array2);

	return 0;
}