#include "Paleta.h"



Paleta::Paleta(int pRegion, int pHmotnost, Datum *pDatum, bool pPrvaTrieda, string pMenoDodavatela)
{
	aRegion = pRegion;
	aHmotnost = pHmotnost;
	aDatumDorucenia = pDatum;	//ak sa jedná o zásielku 1.triedy
	aDatumNaskladnenia = NULL;	//Paleta nebola naskladnená.
	aPrvaTrieda = pPrvaTrieda;
	aMenoDodavatela = pMenoDodavatela;
}

Paleta::Paleta(Paleta &other) {
	if (this != &other) {
		aRegion = other.aRegion;
		aHmotnost = other.aHmotnost;
		aDatumDorucenia = other.aDatumDorucenia;
		aDatumNaskladnenia = other.aDatumNaskladnenia;
		aPrvaTrieda = other.aPrvaTrieda;
		aMenoDodavatela = other.aMenoDodavatela;
	}
}

Paleta::Paleta() {
	aRegion = 1;
	aHmotnost = 1;
	aDatumDorucenia = NULL;
	aDatumNaskladnenia = NULL;
	aPrvaTrieda = false;
	aMenoDodavatela = "NEZNAME";
}

Paleta::~Paleta()
{
	delete aDatumDorucenia;
	aDatumDorucenia = nullptr;
	delete aDatumNaskladnenia;
	aDatumNaskladnenia = nullptr;

}

Datum Paleta::getDatum() {
	return *aDatumDorucenia;
}

bool Paleta::isPrvaTrieda() {
	return aPrvaTrieda;
}

int Paleta::getHmotnostPalety() {
	return aHmotnost;
}

bool Paleta::operator==(Paleta &other) {
	return ((aRegion == other.aRegion) && (aHmotnost == other.aHmotnost)
		&& (aDatumDorucenia == other.aDatumDorucenia) && (aPrvaTrieda == other.aPrvaTrieda));
}

bool Paleta::operator!=(Paleta &other) {
	return ((aRegion == other.aRegion) || (aHmotnost == other.aHmotnost)
		|| (aDatumDorucenia == other.aDatumDorucenia) || (aPrvaTrieda == other.aPrvaTrieda));
}

Paleta& Paleta::operator=(Paleta &other) {
	if (this != &other) {
		aRegion = other.aRegion;
		aHmotnost = other.aHmotnost;
		aDatumDorucenia = other.aDatumDorucenia;
		aPrvaTrieda = other.aPrvaTrieda;
	}
	return *this;
}

int Paleta::getCisloRegionu() {
	return aRegion;
}

void Paleta::setDatumNaskladnenia(Datum *datum) {
	aDatumNaskladnenia = datum;
}

Datum* Paleta::getDatumNaskladnenia() {
	return aDatumNaskladnenia;
}

string Paleta::toString() {
	string dorucenie = "lubovolne";

	if (aPrvaTrieda) {
		dorucenie = aDatumDorucenia->getDateToString();
	}

	return ("Datum naskladnenia: " + aDatumNaskladnenia->getDateToString() 
		+ ", Datum dorucenia: " + dorucenie 
		+ ", Hmotnost: " + to_string(aHmotnost) + "kg, Dodavatel: " + aMenoDodavatela + "\n");
}