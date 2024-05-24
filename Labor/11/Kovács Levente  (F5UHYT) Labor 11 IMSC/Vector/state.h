﻿#pragma once
#include <ostream>

template <class LABEL_TYPE>
class State
{
	LABEL_TYPE label; // Egy címke, amit az állapothoz társítunk. A példában a LABEL_TYPE string.
	bool accepting;	  // Elfogadó állapot-e vagy sem.
public:
	// TODO: Ide jön egy konstruktor
	State(const LABEL_TYPE &label, bool accepting = false) : label(label), accepting(accepting) {}
	State() {}

	// Diagnosztikai kiírást biztosító shift operátor
	template <class U>
	friend std::ostream &operator<<(std::ostream &os, const State<U> &state);

	// Elfogadó-e az állapot.
	bool isAccepting() const
	{
		// 1. Visszaadjuk, hogy elfogadó-e az állapot.
		return accepting;
	}

	bool operator==(const State<LABEL_TYPE> &other) const
	{
		// 1. Megegyezik a két objektum, ha minden tagváltozójuk megegyezik
		return label == other.label && accepting == other.accepting;
	}

	// Megjegyzés: most megelégszünk az alapértelmezett operator=-vel
	// (ami egyébként kell a Vector dinamikus adatkezelése miatt).
};

template <class U>
std::ostream &operator<<(std::ostream &os, const State<U> &state)
{
	// 1. A label os-be shiftelése
	os << state.label;

	// 2. Visszatérés
	return os;
}