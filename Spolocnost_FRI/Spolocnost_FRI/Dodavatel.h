#pragma once
#include "paleta.h"
#include "Vozidlo.h"



class Dodavatel
{
public:
	Dodavatel(string pNazov, string pUlica);

	~Dodavatel();

	string getNazov();

	string getUlica();

	string toString();

	void nalozDoKamionu(Paleta &paleta);

	string poslatObjednavkuSpolocnosti(Datum &datum);

	Datum* getDatumObjednavky();

	Vozidlo* getKamion();

	void posliKamionDomov();

	void pridajNeprevziatuPaletu();

	int getPocetNeprevziatychPaliet();

	bool getPrijataObjednavka();

	void setPrijataObjednavka();

private:
	string aNazov;
	string aUlica;
	bool aVyslanyKamion;
	Vozidlo *aKamion;
	Datum *aDatumObjednavky;
	int aNeprevziatePalety;
	bool aPrijataObjednavka;
};

