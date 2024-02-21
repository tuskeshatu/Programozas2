#include <stdio.h>

void swapUsingPointers(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapUsingReferences(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int& getLocalVariable() { // referenci�t lok�lis v�ltoz�ra SOSE ADJATOK VISSZA! => while(--pontok);
	int a = 10;
	int& b = a;
	return b; // warning: returning address of local variable or temporary: a
			  // ezen a ponton az 'a' lok�lis v�ltoz� m�r felszabadult a call stack framen
}

int main(int argv, char*argc[]) {
	// 1. p�lda
	printf("1. pelda\n");
	int x;
	int& y = x;
	printf("\tx=%d; y=%d\n", x, y);

	// 2. p�lda
	printf("2. pelda\n");
	int u = 10;
	int v = 20;
	printf("\tu=%d; v=%d\n", u, v);
	swapUsingPointers(&u, &v);
	printf("\tu=%d; v=%d\n", u, v);

	// 3. p�lda
	printf("3. pelda\n");
	int i = 40;
	int j = 50;
	printf("\ti=%d; j=%d\n", i, j);
	swapUsingReferences(i, j);
	printf("\ti=%d; j=%d\n", i, j);

	// 4. p�lda
	printf("4. pelda\n");
	// - a localref olyan ter�letre mutat, ami ugyan m�g tartalmazza a 10-es �rt�ket, de m�r nem ez a program kezeli
	// - teh�t mem�riaszem�tre mutat: nem b�zhatunk abban, hogy ha b�rmikor kiolvassuk, mindig 10-et kapunk
	int& localref = getLocalVariable();
	printf("\tlocalref=%d\n", localref);
	localref = 44;
	printf("\tlocalref=%d\n", localref);
	printf("\tlocalref=%d\n", localref);
	printf("\tlocalref=%d\n", localref);

	// 5. p�lda
	printf("5. pelda\n");
	int k = 100;
	int& l = k;
	int& m = l;
	int& n = m = 200;
	printf("\tk=%d; l=%d; m=%d; n=%d\n", k, l, m, n);

	// 6. p�lda
	printf("6. pelda\n");
	int* o = new int;
	*o = 700;
	int& p = *o;
	printf("\to=%d; p=%d\n", *o, p);

	delete o; // dinamikusan foglalt ter�letet fel kell szabad�tani, k�l�nben => while(--pontok); // :(

	return 0;
}