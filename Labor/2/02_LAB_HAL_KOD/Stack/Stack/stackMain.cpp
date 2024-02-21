﻿#include <stdio.h>  /* printf-nek */
#include <stdlib.h> /* Memóriakezelésnek */

struct Stack
{
	int elements; // tárolt elemek száma
	char* pData;
};
/* Általános megállapodások.
1. Ha a Stack üres, a pData nullptr, az elements 0.
2. Az pData mutat az elemek tömbjére, dinamikus memóriafoglalással.
3. Az elements jelzi az stackben lévo aktuális elemek számát.
4. A függvények karbantartják a dinamikus memóriaterületet
5. A Stack használata elott a meg kell hívni a void stack_init(struct Stack* s)-et.
6. A Stack használata után meg kell hívni a void stack_cleanUp(struct Stack* s)-t.
7. A függvények visszatérése hiba esetén nem nulla
*/

int stack_init(struct Stack* s)
{
	/* Mivel alapértelmezésben a Stack két változójának értékei véletlenszámok,
	inicializálni kell oket. Üres stackkel indulunk.
	*/

	// 1. Az s->elements beállítása

	// 2. Az s->pData beállítása

	return 0;
}

/*
// 4. FELADAT: függvénynév túlterhelés
// inicializálja az "s" nevű Stacket az "other" nevű Stack elemeivel
int stack_init(Stack& s, const Stack& other)
{
	// 1. Az s.elements beállítása az other.elements felhasználásával

	// 2. Az s.pData beállítása az other.pData felhasználásával

	// 3. Ha sikertelen a helyfoglalás, az s.elements=0, és visszatérünk -1-gyel

	// 4. Az s stack feltöltése az other stack tartalmával

	return 0;
}
*/

void stack_cleanUp(struct Stack* s)
{
	/* Mivel dinamikus adatterülete foglalunk le, a Stack használata után
	fel kell szabadítani ezeket*/

	// 1. Az s->elements beállítása


	// 2. Az s->pData felszabadítása


	// 3. Az s->pData értékének beállítása

}

int stack_push(struct Stack* s, char newElement)
{
	/* Itt új elemet fuzünk az s->pData végére. Ehhez lefoglalunk
	eggyel nagyobb méretu helyet egy ideiglenes mutatóval, majd
	átmásoljuk bele a s->pData eddigi tartalmát, hozzáfuzzük az
	új elemet, és felszabadítjuk az eredeti s->pData területét.
	Utána s->pDatat átirányítjuk az ideiglenes pointer által
	mutatott területre.
	*/

	// Az ideiglenes mutató
	char *ptrTemp;
	// Ciklusváltozó a másoláshoz
	int i;

	// 1. Eggyel nagyobb helyet foglalunk az ideiglenes pointer (ptrTemp) segítségével


	// 2. Ha nem sikerült a helyfoglalás, -1-gyel térünk vissza

	// 3. Egy for ciklussal átmásoljuk az s->pData tartalmát a ptrTemp által mutatott
	// területre.




	// 4. Az újonan foglalt terület végére rakjuk az új elemet (newElement)

	// 5. Ha mutatott valahova elozoleg a pData, felszabadítjuk 


	// 6. Átállítjuk az s->pData pointert az újonnan lefoglalt területre (ptrTemp)

	// 7. Beállítjuk az elemszám (s->elements) új értékét

	return 0;
}

int stack_pop(struct Stack* s)
{
	/* Ha nem üres a Stack, kivesszük az utolsóként berakott elemet
	a tömb végérol. Lefoglalunk eggyel kisebb tárhelyet, átmásoljuk
	az adatokat, felszabadítjuk az eredetit. Ha kiürül a Stack,
	a megállapodásnak megfeleloen állítjuk be az s truktúra adattagjait.*/

	// Az ideiglenes mutató és a visszatérési érték
	char *ptrTemp, value;
	// Ciklusváltozó a másoláshoz
	int i;

	// 1. Ha a Stack üres -1-gyel visszatérünk


	// 2. A value értéke az utolsóként betett elem, a tömb vége

	// 3. Az s->elements értékét beállítjuk az új szituációnak megfeleloen


	if (s->elements) // 4a. Ha a tömb ezzel nem lesz üres
	{
		// 4a1. Az ideiglenes pointer segítségével az új méretnek megfelelo
		// helyet foglalunk


		// 4a2. Ha nem sikerült a helyfoglalás, -1-gyel térünk vissza


		// 4a3. Átmásoljuk az ideiglenes területre a stackben maradt adatokat



		// 4a4. Felszabadítjuk a régi memóriaterületet (s->pData)

		// 4a5. Átállítjuk az s->pData pointert az újonnan lefoglalt területre (ptrTemp)

	}
	else // 4b. Ha a tömb ezzel üres lett
	{
		// 4b1. Felszabadítjuk az eddigi elemet

		// 4b2. Beállítjuk az s->pData értékét (az elements már be lett állítva) 

	}

	// 5. Visszatérünk a kivett elemmel (value)

}

int stack_isEmpty(struct Stack* s)
{
	/* Ha üres a Stack, nem nullával térünk vissza, egyébként igen. */

}

int main(void)
{
	struct Stack s;
	char i;

	printf("Initializing stack...\n");
	stack_init(&s);

	for (i = 'A'; i <= 'Z'; i++)
	{
		// printf("push: %c\n",i);
		// Itt nézzük a s.pData változót debuggerbol, lépjünk bele a függvénybe
		stack_push(&s, i);
	}

	/// 4. FELADAT: teszt a stack_init túlterheléséhez
	
	/// 4. FELADAT vége
	
	while (!stack_isEmpty(&s))
	{
		// Itt nézzük a s.pData változót debuggerbol, lépjünk bele a függvénybe
		printf("pop: %c\n", (char)stack_pop(&s));
	}

	// Üres stackbol kivétel: hiba (-1)
	printf("pop: %d\n", stack_pop(&s));

	printf("Cleaning up stack...\n");
	stack_cleanUp(&s);
	return 0;
}
