#include "Region.h"



Region::Region(int pCisloRegionu)
{
	if ((0 < pCisloRegionu) && (pCisloRegionu < 100)) {
		aCisloRegionu = pCisloRegionu;
	}
	aZoznamPalietNaDorucenie = new ArrayList<Paleta*>;
}


Region::~Region()
{
	for each (Paleta *var in *aZoznamPalietNaDorucenie)
	{
		delete var;
	}
	delete aZoznamPalietNaDorucenie;
	aZoznamPalietNaDorucenie = nullptr;
}

void Region::pridajPaletuDoZoznamu(Paleta *other) {
	aZoznamPalietNaDorucenie->add(other);
}

void Region::vyhodPaletuZoZoznamu(Paleta *other) {
	aZoznamPalietNaDorucenie->tryRemove(other);
}

int Region::getCisloRegionu() {
	return aCisloRegionu;
}

int Region::getPocetPalietNaDorucenie() {
	return aZoznamPalietNaDorucenie->size();
}

Paleta* Region::getPaletaAtIndex(int index) {
	return (*aZoznamPalietNaDorucenie)[index];
}

ArrayList<Paleta*> Region::getZoznamPaliet() {
	return *aZoznamPalietNaDorucenie;
}
 