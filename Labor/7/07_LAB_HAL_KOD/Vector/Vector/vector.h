#pragma once
#include <iostream>

namespace Sorters {
	bool ascend(const int&, const int&);
	bool descend(const int&, const int&);
}

// Egy dinamikus t�mb oszt�ly
class Vector
{
	// A t�mb m�rete
	unsigned elementNum;

	// A t�mb maxim�lis m�rete; alap�rtelmezetten 20
	unsigned maxElementsNum;

	// A dinamikus adatokra mutat� pointer
	int *pData;
	
	// Diagnosztikai c�l� glob�lis kiirat�oper�tor
	
	// T�mbfelt�lt�s oper�tor t�lterhel�ssel
	friend std::istream& operator>>(std::istream&, Vector&);
public:
	// Konstruktorok, destruktor
	Vector(unsigned=20);
	Vector(const Vector&);
	~Vector();

	// Visszat�r a t�mb m�ret�vel.
	unsigned size() const;

	// Visszat�r a t�mb maxim�lis m�ret�vel.
	unsigned getMaxElementsNum() const;

	// T�rli a t�mb�t.
	void clear();
	
	// T�rli a megadott index� elemet. A 0 �s size()-1 k�z�tti indexek �rv�nyesek.
	bool erase(unsigned);

	// Visszat�r a megadott index� elemmel, amely m�dos�that� is egyben.
	// A 0 �s size()-1 k�z�tti indexek �rv�nyesek.
	int& at(unsigned);

	// Visszat�r a megadott index� elemmel, amely csak olvashat�.
	// A 0 �s size()-1 k�z�tti indexek �rv�nyesek. Az int t�pus eset�n nem kellene
	// const referencia (mert olcs� m�velet a be�p�tett t�pus�
	// v�ltoz�k m�sol�sa), de saj�t t�pus eset�n igen.
	const int& at(unsigned) const;

	// Besz�r egy elemet a megadott index� helyre.
	// Ha az index nagyobb, mint a t�mb m�rete, megn�veli a t�mb m�ret�t,
	// �s a sz�ks�ges �j helyeket null�kkal t�lti fel.
	bool insert(unsigned, int);

	void sort(bool(*)(const int&, const int&) = Sorters::ascend);

	// operator=
	Vector& operator=(const Vector&);

	// K�t operator[]. Az at() tagf�ggv�ny operator form�ban is.
	int& operator[](unsigned);
	const int& operator[](unsigned) const;

	// Minden elem megszorz�sa a jobb oldali operandussal.
	void operator*=(unsigned);

	// A jobb oldali operandus hozz�ad�sa minden elemhez.
	void operator+=(unsigned);
};

// Diagnosztikai c�l� kiirat�s
std::ostream& operator<<(std::ostream&, const Vector&);

// T�mbfelt�lt�s oper�tor t�lterhel�ssel
std::istream& operator>>(std::istream&, Vector&);