#include "CentralnySklad.h"



CentralnySklad::CentralnySklad()
{
	aVozovyPark = new ArrayList<Vozidlo*>;
	aVyradeneVozidla = new LinkedList<Vozidlo*>;
	aZoznamRegionov = new ArrayList<Region*>;
	aNeprevziatePalety = new LinkedList<Paleta*>;
	aNezrealizovanePrveTriedy = new LinkedList<Paleta*>;
	aDnesnyDatum = NULL;
}


CentralnySklad::~CentralnySklad()
{
	for each (Paleta *var in *aNezrealizovanePrveTriedy)
	{
		delete var;
	}
	delete aNezrealizovanePrveTriedy;
	aNezrealizovanePrveTriedy = nullptr;

	for each (Paleta *var in *aNeprevziatePalety)
	{
		delete var;
	}
	delete aNeprevziatePalety;
	aNeprevziatePalety = nullptr;

	for each (Region *var in *aZoznamRegionov)
	{
		delete var;
	}
	delete aZoznamRegionov;
	aZoznamRegionov = nullptr;

	znicVyradeneVozidla();
	delete aVyradeneVozidla;
	aVyradeneVozidla = nullptr;

	for each (Vozidlo *var in *aVozovyPark)
	{
		delete var;
	}
	delete aVozovyPark;
	aVozovyPark = nullptr;

	delete aDnesnyDatum;
	aDnesnyDatum = nullptr;
}

void CentralnySklad::pridajVozidloDoFirmy(Vozidlo *pVozidlo) {
	aVozovyPark->add(pVozidlo);
}

void CentralnySklad::kontrolaVozidla(Vozidlo *pVozidlo) {
	if (pVozidlo->getOpotrebovanie() > 90) {
		aVyradeneVozidla->add(pVozidlo);
		aVozovyPark->tryRemove(pVozidlo);
	}
}

string CentralnySklad::vypisVozidlaPodlaDatumu() {
	string vypis = "";
	for (int i = 0; i < static_cast<int>(aVozovyPark->size()); i++)
	{
		vypis += (to_string(i + 1) + ".) " +(*aVozovyPark)[i]->toString() + "\n");
	}
	return vypis;
}

void CentralnySklad::pridajRegionDoZoznamu(Region *region) {
	aZoznamRegionov->add(region);
}

Region* CentralnySklad::getRegion(int index) {
	return (*aZoznamRegionov)[index];
}

Region* CentralnySklad::getRegionPodlaCisla(int cisloRegionu) {
	for (int i = 0; i < aZoznamRegionov->size(); i++)
	{
		if ((*aZoznamRegionov)[i]->getCisloRegionu() == cisloRegionu) {
			return (*aZoznamRegionov)[i];
		}
	}
	return NULL;
}

int CentralnySklad::getPocetRegionov() {
	return aZoznamRegionov->size();
}

Vozidlo* CentralnySklad::getVozidloZoZoznamu(int index) {
	return (*aVozovyPark)[index];
}

Paleta* CentralnySklad::getPaletaPrvejTriedy(int indexRegionu) {
	for (int i = 0; i < (*aZoznamRegionov)[indexRegionu]->getPocetPalietNaDorucenie(); i++)
	{
		if ((*aZoznamRegionov)[indexRegionu]->getPaletaAtIndex(i)->isPrvaTrieda()
			&& ((*aZoznamRegionov)[indexRegionu]->getPaletaAtIndex(i)->getDatum() == *getDnesnyDatum())) {
			return (*aZoznamRegionov)[indexRegionu]->getPaletaAtIndex(i);
		}
	}
	return NULL;
}

Vozidlo* CentralnySklad::getPrioritneVozidlo() {
	int indexNajvhodnejsieho = 0;

	for (int i = 0; i < aVozovyPark->size(); i++)
	{
		if ((*aVozovyPark)[i]->getOpotrebovanie() == 0) {
			return (*aVozovyPark)[i];
		}

		if ((*aVozovyPark)[indexNajvhodnejsieho]->getOpotrebovanie() > (*aVozovyPark)[i]->getOpotrebovanie()) {
			indexNajvhodnejsieho = i;
		}
	}

	return (*aVozovyPark)[indexNajvhodnejsieho];
}

void CentralnySklad::nalozVozidla() {
	for (int i = 0; i < aZoznamRegionov->size(); i++)
	{
		while (getPaletaPrvejTriedy(i) != NULL)
		{
			if (getPaletaPrvejTriedy(i)->getHmotnostPalety() > (getPrioritneVozidlo()->getNosnost() - getPrioritneVozidlo()->getNalozenaVaha())) {
				aNezrealizovanePrveTriedy->add(getPaletaPrvejTriedy(i));
				(*aZoznamRegionov)[i]->vyhodPaletuZoZoznamu(getPaletaPrvejTriedy(i));
				break;
			}

			getPrioritneVozidlo()->pridajPaletuDoVozidla(getPaletaPrvejTriedy(i));
			(*aZoznamRegionov)[i]->vyhodPaletuZoZoznamu(getPaletaPrvejTriedy(i));
		}
	}

	for (int i = 0; i < aZoznamRegionov->size(); i++)
	{
		for each (Paleta *paleta in (*aZoznamRegionov)[i]->getZoznamPaliet())
		{
			getPrioritneVozidlo()->pridajPaletuDoVozidla(paleta);
		}
	}
}

void CentralnySklad::odvozZakaznikom() {
	srand(time(0));
	int nahodneCislo, rozvazanyRegion;

	for (int i = 0; i < (*aVozovyPark)[i]->getPocetPaliet(); i++)
	{
		rozvazanyRegion = (*aVozovyPark)[i]->getPaleta(0)->getCisloRegionu();

		for each (Paleta *paleta in (*aVozovyPark)[i]->getZoznamPaliet())
		{
			nahodneCislo = (rand() % 20 + 1);
			if (nahodneCislo == 5) {
				aNeprevziatePalety->add(paleta);
			}
			(*aVozovyPark)[i]->odstranPaletuZVozidla(paleta);
		}
		(*aVozovyPark)[i]->pridajOpotrebenie(rozvazanyRegion);
		kontrolaVozidla((*aVozovyPark)[i]);
	}
}

void CentralnySklad::znicVyradeneVozidla() {
	for each (Vozidlo *var in *aVyradeneVozidla)
	{
		delete var;
	}
}

Datum* CentralnySklad::getDnesnyDatum() {
	return aDnesnyDatum;
}

void CentralnySklad::setAktualnyDatum(Datum *datum) {
	aDnesnyDatum = datum;
}

void CentralnySklad::pridajDenVSklade() {
	aDnesnyDatum->setDalsiDen();
}

ArrayList<Vozidlo*> CentralnySklad::getVozovyPark() {
	return *aVozovyPark;
}

string CentralnySklad::paletyNaSkladeToString() {
	string vypis = "";

	for (int i = 0; i < aZoznamRegionov->size(); i++)
	{
		vypis += to_string((*aZoznamRegionov)[i]->getCisloRegionu()) + ". Region:\n";

		for (int j = 0; j < (*aZoznamRegionov)[i]->getPocetPalietNaDorucenie(); j++)
		{
			vypis += to_string(j + 1) + ". Paleta: " 
				+ (*aZoznamRegionov)[i]->getPaletaAtIndex(j)->toString();
		}

		vypis += "\n";
	}

	return vypis;
}

void CentralnySklad::pridajNezrealizovanuPaletuPrvejTriedy(Paleta *paleta) {
	aNezrealizovanePrveTriedy->add(paleta);
}

string CentralnySklad::vypisNezrealizovanychPaliet(Datum *odKedy, Datum *doKedy) {
	string vypis = "";

	for (int i = 0; i < aNezrealizovanePrveTriedy->size(); i++)
	{
		if ((((*aNezrealizovanePrveTriedy)[i]->getDatum() > *odKedy) 
			|| ((*aNezrealizovanePrveTriedy)[i]->getDatum() == *odKedy))
				&& (((*aNezrealizovanePrveTriedy)[i]->getDatum() < *doKedy)
					|| ((*aNezrealizovanePrveTriedy)[i]->getDatum() == *doKedy))) {
			vypis += (*aNezrealizovanePrveTriedy)[i]->toString();
		}
	}

	return vypis;
}
