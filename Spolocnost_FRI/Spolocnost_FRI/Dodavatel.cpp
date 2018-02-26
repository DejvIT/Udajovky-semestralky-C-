#include "Dodavatel.h"



Dodavatel::Dodavatel(string pNazov, string pUlica)
{
	aNazov = pNazov;
	aUlica = pUlica;
	aVyslanyKamion = false;
	aKamion = new Vozidlo();
	aDatumObjednavky = NULL;
	aNeprevziatePalety = 0;
	aPrijataObjednavka = false;
}


Dodavatel::~Dodavatel()
{
	//delete aDatumObjednavky;
	aDatumObjednavky = nullptr;
	delete aKamion;
	aKamion = nullptr;
}

string Dodavatel::getNazov() {
	return aNazov;
}

string Dodavatel::getUlica() {
	return aUlica;
}

string Dodavatel::toString() {
	return "nazov: " + aNazov + ", ulica: " + aUlica;
}

void Dodavatel::nalozDoKamionu(Paleta &paleta) {
	if (!aVyslanyKamion) {
		aKamion->pridajPaletuDoVozidla(&paleta);
	}
}

string Dodavatel::poslatObjednavkuSpolocnosti(Datum &datum) {
	string objednavka = "";
	if (!aVyslanyKamion) {
		objednavka = aKamion->toString();
		aVyslanyKamion = true;
		aDatumObjednavky = &datum;
	}
	return objednavka;
}

Datum* Dodavatel::getDatumObjednavky() {
	return aDatumObjednavky;
}

Vozidlo* Dodavatel::getKamion() {
	return aKamion;
}

void Dodavatel::posliKamionDomov() {
	aVyslanyKamion = false;
	setPrijataObjednavka();
}

void Dodavatel::pridajNeprevziatuPaletu() {
	aNeprevziatePalety += 1;
}

int Dodavatel::getPocetNeprevziatychPaliet() {
	return aNeprevziatePalety;
}

bool Dodavatel::getPrijataObjednavka() {
	return aPrijataObjednavka;
}

void Dodavatel::setPrijataObjednavka() {
	aPrijataObjednavka = !aPrijataObjednavka;
}