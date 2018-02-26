#include "Spolocnost_FRI.h"



Spolocnost_FRI::Spolocnost_FRI(Datum *datum, CentralnySklad *centralnySklad)
{
	aZoznamDodavatelov = new LinkedList<Dodavatel*>;
	aDnesnyDatum = datum;
	aCentralnySklad = centralnySklad;
	aCentralnySklad->setAktualnyDatum(datum);
}


Spolocnost_FRI::~Spolocnost_FRI()
{
	delete aCentralnySklad;
	aCentralnySklad = nullptr;
	for each (Dodavatel *var in *aZoznamDodavatelov)
	{
		delete var;
	}
	delete aZoznamDodavatelov;
	aZoznamDodavatelov = nullptr;
	//delete aDnesnyDatum;
	aDnesnyDatum = nullptr;
}

Datum* Spolocnost_FRI::getAktualnyDatum() {
	return aDnesnyDatum;
}

void Spolocnost_FRI::pridajDodavatela(Dodavatel *pDodavatel) {
	if (aZoznamDodavatelov->size() == 0) {
		aZoznamDodavatelov->add(pDodavatel);
	}

	for (int i = 0; i < static_cast<int>(aZoznamDodavatelov->size()); i++)
	{
		if ((pDodavatel->getNazov()) < ((*aZoznamDodavatelov)[i]->getNazov())) {
			aZoznamDodavatelov->insert(pDodavatel, i);
			break;
		}
	}
}

string Spolocnost_FRI::vypisDodavatelov() {
	string vypis = "";
	for (int i = 0; i < static_cast<int>(aZoznamDodavatelov->size()); i++)
	{
		vypis += (to_string(i + 1) + ".) " + (*aZoznamDodavatelov)[i]->toString() + "\n");
	}
	return vypis;
}

void Spolocnost_FRI::prijatObjednavky() {
	for (int i = 0; i < static_cast<int>(aZoznamDodavatelov->size()); i++)
	{
		if (getAktualnyDatum() == (*aZoznamDodavatelov)[i]->getDatumObjednavky())
		{
			(*aZoznamDodavatelov)[i]->setPrijataObjednavka();
		}
	}
}

Dodavatel* Spolocnost_FRI::getDodavatelaObjednavky() {
	for (int i = 0; i < static_cast<int>(aZoznamDodavatelov->size()); i++)
	{
		if ((*aZoznamDodavatelov)[i]->getPrijataObjednavka()) {
			return (*aZoznamDodavatelov)[i];
		}
	}
	return NULL;
}

void Spolocnost_FRI::vykladajPodlaRegionov(Dodavatel *dodavatel) {
	for (int i = 0; i < dodavatel->getKamion()->getPocetPaliet(); i++)
	{
		if ((isRegion((dodavatel->getKamion()->getPaleta(i)->getCisloRegionu())))
			&& ((dodavatel->getKamion()->getPaleta(i)->getDatum() > *getAktualnyDatum())
			|| (dodavatel->getKamion()->getPaleta(i)->getDatum() == *getAktualnyDatum())))
		{
			if ((dodavatel->getKamion()->getPaleta(i)->getHmotnostPalety()) > (getMaxNosnostVozidla())) 
			{
				dodavatel->pridajNeprevziatuPaletu();
			}
			else 
			{
				dodavatel->getKamion()->getPaleta(i)->setDatumNaskladnenia(getAktualnyDatum());
				aCentralnySklad->getRegionPodlaCisla(dodavatel->getKamion()->getPaleta(i)->getCisloRegionu())->pridajPaletuDoZoznamu(dodavatel->getKamion()->getPaleta(i));
			}
		}
		else {
			dodavatel->pridajNeprevziatuPaletu();
		}
	}
	
	for (int i = dodavatel->getKamion()->getPocetPaliet(); i > 0; i--)
	{
		dodavatel->getKamion()->odstranPaletuZVozidla(dodavatel->getKamion()->getPaleta(i - 1));
		cout << "Odstranil som paletu z kamionu" << endl;
	}
	dodavatel->posliKamionDomov();
}

bool Spolocnost_FRI::isRegion(int pCisloRegionu) {
	for (int i = 0; i < aCentralnySklad->getPocetRegionov(); i++)
	{
		if (aCentralnySklad->getRegion(i)->getCisloRegionu() == pCisloRegionu) {

			cout << "Region existuje do pièi!" << endl;
			return true;
		}
	}
	cout << "Region neexistuje kurva!" << endl;
	return false;
}

void Spolocnost_FRI::pridajDen() {
	aDnesnyDatum->setDalsiDen();
	aCentralnySklad->pridajDenVSklade();
}

int Spolocnost_FRI::getMaxNosnostVozidla() {
	int maxNosnost = 0;

	for (int i = 0; i < (aCentralnySklad)->getVozovyPark().size(); i++)
	{
		if (maxNosnost < (*aCentralnySklad).getVozidloZoZoznamu(i)->getNosnost()) {
			maxNosnost = (*aCentralnySklad).getVozidloZoZoznamu(i)->getNosnost();
		}
	}

	return maxNosnost;
}

Dodavatel* Spolocnost_FRI::getSmutnehoDodavatela() {
	int indexDodavatela, pocetPaliet = 0;

	for (int i = 0; i < aZoznamDodavatelov->size(); i++)
	{
		if (pocetPaliet < (*aZoznamDodavatelov)[i]->getPocetNeprevziatychPaliet()) {
			pocetPaliet = (*aZoznamDodavatelov)[i]->getPocetNeprevziatychPaliet();
			indexDodavatela = i;
		}
	}

	return (*aZoznamDodavatelov)[indexDodavatela];
}