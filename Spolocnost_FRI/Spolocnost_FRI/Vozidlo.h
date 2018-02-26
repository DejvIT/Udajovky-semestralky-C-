#pragma once
#include <cstring>
#include <sstream>
#include <iostream>
#include <ctime>

#include "structures\list\array_list.h"

#include "Paleta.h"

using namespace structures;

class Vozidlo
{
public:
	Vozidlo(const int pNosnost, const string pSPZ, Datum *pDatum);
	
	Vozidlo(Vozidlo &other);

	Vozidlo();
	
	~Vozidlo();

	int getPocetPaliet();

	int getOpotrebovanie();

	bool isNaOdpis();

	int getNosnost();

	string getSPZ();

	Datum* getDatumEvidencie();

	bool operator==(Vozidlo &other);

	bool operator!=(Vozidlo &other);

	Vozidlo& operator=(Vozidlo &other);

	bool isNovsieVozidloAko(Vozidlo &other);

	void pridajPaletuDoVozidla(Paleta *other);

	void odstranPaletuZVozidla(Paleta *other);

	string toString();

	void setNalozenaVaha(int pVaha);

	int getNalozenaVaha();

	Paleta* getPaleta(int index);

	ArrayList<Paleta*> getZoznamPaliet();

	void pridajOpotrebenie(int opotrebenie);

private:
	int aNosnost;
	int aOpotrebovanie;
	string aSPZ;
	Datum *aDatum;
	ArrayList<Paleta*> *aZoznamPaliet;
	int aNalozenaVaha;
};

