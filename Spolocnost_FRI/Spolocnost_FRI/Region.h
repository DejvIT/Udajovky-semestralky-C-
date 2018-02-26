#pragma once
#include "Paleta.h"
#include "structures\list\array_list.h"

using namespace structures;

class Region
{
public:
	Region(int pCisloRegionu);

	~Region();

	void pridajPaletuDoZoznamu(Paleta *other);

	void vyhodPaletuZoZoznamu(Paleta *other);

	int getCisloRegionu();

	int getPocetPalietNaDorucenie();

	Paleta* getPaletaAtIndex(int index);

	ArrayList<Paleta*> getZoznamPaliet();

private:
	int aCisloRegionu;
	ArrayList<Paleta*> *aZoznamPalietNaDorucenie;
};

