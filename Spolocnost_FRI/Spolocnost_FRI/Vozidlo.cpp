#include "Vozidlo.h"



Vozidlo::Vozidlo(const int pNosnost, const string pSPZ, Datum *pDatum)
{
	aNosnost = pNosnost;
	aOpotrebovanie = 0;	//nove vozidlo
	aSPZ = pSPZ;
	aDatum = pDatum;	//dátum evidencie vozidla
	aZoznamPaliet = new ArrayList<Paleta*>;
	aNalozenaVaha = 0;	//vozidlo je prázdne
}

Vozidlo::Vozidlo(Vozidlo &other) {
	if (this != &other) {
		aNosnost = other.aNosnost;
		aOpotrebovanie = other.aOpotrebovanie;
		aSPZ = other.aSPZ;
		aDatum = other.aDatum;
		aZoznamPaliet = other.aZoznamPaliet;
		aNalozenaVaha = other.aNalozenaVaha;
	}
}

Vozidlo::Vozidlo() {

	aNosnost = 100000;
	aOpotrebovanie = 0;
	aSPZ = "Kamion";
	aDatum = new Datum();
	aZoznamPaliet = new ArrayList<Paleta*>;
	aNalozenaVaha = 0;
}

Vozidlo::~Vozidlo()
{
	for each (Paleta *var in *aZoznamPaliet)
	{
		delete var;
	}
	delete aZoznamPaliet;
	aZoznamPaliet = nullptr;
	//delete aDatum;	//jediný pointer, ostatné atributy sú primitívnym typom takže ich nedeletujeme
	aDatum = nullptr;
}

int Vozidlo::getPocetPaliet() {
	return aZoznamPaliet->size();
}

int Vozidlo::getOpotrebovanie() {
	return aOpotrebovanie;
}

bool Vozidlo::isNaOdpis() {
	if (aOpotrebovanie >= 100) {	//ak attribút opotrebovaia Vozidla prekroèí hodnotu 99 tak sa v triede Firma vozidlo vopchá do ArrayListu na vyradenie
		return true;
	}
	return false;
}

int Vozidlo::getNosnost() {
	return aNosnost;
}

std::string Vozidlo::getSPZ() {
	return aSPZ;
}

Datum* Vozidlo::getDatumEvidencie() {
	return aDatum;
}

bool Vozidlo::operator==(Vozidlo &other) {
	return ((aNosnost == other.aNosnost) && (aOpotrebovanie == other.aOpotrebovanie)
		&& (aSPZ == other.aSPZ) && (aDatum = other.aDatum));
}

bool Vozidlo::operator!=(Vozidlo &other) {
	return ((aNosnost == other.aNosnost) || (aOpotrebovanie == other.aOpotrebovanie)
		|| (aSPZ == other.aSPZ) || (aDatum = other.aDatum));
}

Vozidlo& Vozidlo::operator=(Vozidlo &other) {
	if (this != &other) {
		aNosnost = other.aNosnost;
		aOpotrebovanie = other.aOpotrebovanie;
		aSPZ = other.aSPZ;
		aDatum = other.aDatum;
	}
	return *this;
}

bool Vozidlo::isNovsieVozidloAko(Vozidlo &other) {
	return (getDatumEvidencie()->operator>(*other.getDatumEvidencie()));
}

void Vozidlo::pridajPaletuDoVozidla(Paleta *other) {
	if (other->getHmotnostPalety() <= (getNosnost() - getNalozenaVaha())) {
		aZoznamPaliet->add(other);
		setNalozenaVaha(other->getHmotnostPalety());
	}
}

void Vozidlo::odstranPaletuZVozidla(Paleta *other) {
	aZoznamPaliet->tryRemove(other);
	setNalozenaVaha(-(other->getHmotnostPalety()));
}

string Vozidlo::toString() {
	return ("SPZ: " + aSPZ + ", nosnost: " + std::to_string(aNosnost)
		+ ", opotrebenie: " + std::to_string(aOpotrebovanie)
		+ ", datum evidencie: " + aDatum->getDateToString());
}

void Vozidlo::setNalozenaVaha(int pVaha) {
	aNalozenaVaha += pVaha;
}

int Vozidlo::getNalozenaVaha() {
	return aNalozenaVaha;
}

Paleta* Vozidlo::getPaleta(int index) {
	return (*aZoznamPaliet)[index];
}

ArrayList<Paleta*> Vozidlo::getZoznamPaliet() {
	return *aZoznamPaliet;
}

void Vozidlo::pridajOpotrebenie(int opotrebenie) {
	aOpotrebovanie += opotrebenie;
}
