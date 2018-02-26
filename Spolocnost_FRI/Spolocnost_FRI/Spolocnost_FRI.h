#pragma once
#include "CentralnySklad.h"
#include "Dodavatel.h"

class Spolocnost_FRI
{
public:
	Spolocnost_FRI(Datum *datum, CentralnySklad *centralnySklad);

	~Spolocnost_FRI();

	Datum* getAktualnyDatum();

	void pridajDodavatela(Dodavatel *pDodavatel);

	string vypisDodavatelov();

	void prijatObjednavky();

	Dodavatel* getDodavatelaObjednavky();

	void vykladajPodlaRegionov(Dodavatel *dodavatel);

	bool isRegion(int pCisloRegionu);

	void pridajDen();

	int getMaxNosnostVozidla();

	Dodavatel* getSmutnehoDodavatela();

private:
	LinkedList<Dodavatel*> *aZoznamDodavatelov;
	Datum *aDnesnyDatum;
	CentralnySklad *aCentralnySklad;
};

