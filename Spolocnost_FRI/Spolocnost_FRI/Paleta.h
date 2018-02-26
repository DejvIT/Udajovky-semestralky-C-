#pragma once
#include "Datum.h"

class Paleta
{
public:
	Paleta(int pRegion, int pHmotnost, Datum *pDatum, bool prvaTrieda, string pMenoDodavatela);

	Paleta(Paleta &pPaleta);

	Paleta();

	~Paleta();

	Datum getDatum();

	bool isPrvaTrieda();

	int getHmotnostPalety();

	bool operator==(Paleta &other);

	bool operator!=(Paleta &other);

	Paleta& operator=(Paleta &other);

	int getCisloRegionu();

	void setDatumNaskladnenia(Datum *datum);

	Datum* getDatumNaskladnenia();

	string toString();

private:
	int aRegion;
	int aHmotnost;
	Datum *aDatumDorucenia;
	Datum *aDatumNaskladnenia;
	bool aPrvaTrieda;
	string aMenoDodavatela;
};

