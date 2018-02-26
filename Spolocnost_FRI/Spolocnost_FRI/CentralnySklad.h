#pragma once
#include "structures\list\array_list.h"
#include "structures\list\linked_list.h"
#include "Vozidlo.h"
#include "Region.h"

using namespace structures;

class CentralnySklad
{
public:
	CentralnySklad();

	~CentralnySklad();

	void pridajVozidloDoFirmy(Vozidlo *pVozidlo);

	void kontrolaVozidla(Vozidlo *pVozidlo);

	string vypisVozidlaPodlaDatumu();

	void pridajRegionDoZoznamu(Region *region);

	Region* getRegion(int index);

	Region* getRegionPodlaCisla(int cisloRegionu);

	int getPocetRegionov();

	Vozidlo* getVozidloZoZoznamu(int index);

	Paleta* getPaletaPrvejTriedy(int indeXregionu);

	Vozidlo* getPrioritneVozidlo();

	void nalozVozidla();

	void odvozZakaznikom();

	void znicVyradeneVozidla();

	Datum* getDnesnyDatum();

	void setAktualnyDatum(Datum *datum);

	void pridajDenVSklade();

	ArrayList<Vozidlo*> getVozovyPark();

	string paletyNaSkladeToString();

	void pridajNezrealizovanuPaletuPrvejTriedy(Paleta *paleta);

	string vypisNezrealizovanychPaliet(Datum *odKedy, Datum *doKedy);

private:
	ArrayList<Vozidlo*> *aVozovyPark;
	LinkedList<Vozidlo*> *aVyradeneVozidla;
	ArrayList<Region*> *aZoznamRegionov;
	LinkedList<Paleta*> *aNeprevziatePalety;
	LinkedList<Paleta*> *aNezrealizovanePrveTriedy;
	Datum *aDnesnyDatum;
};

