#include "Datum.h"


Datum::Datum(int pDen, int pMesiac, int pRok)
{	
	if ((0 < pDen) && (pDen <= getPocetDniVMesiaci(pMesiac))) {
		den = pDen;
	} 
	else {
		den = 1;
	}

	if ((0 < pMesiac) && (pMesiac < 13)) {
		mesiac = pMesiac;
	} 
	else {
		mesiac = 1;
	}

	if ((1999 < pRok) && (pRok < 2101)) {
		rok = pRok;
	}
	else {
		rok = 2000;
	}
}

Datum::Datum(const Datum &other) {
	den = other.den;
	mesiac = other.mesiac;
	rok = other.rok;
}

Datum::Datum() {
	den = 1;
	mesiac = 1;
	rok = 2000;
}

Datum::~Datum()
{
}

int Datum::getAktualnyDen() {
	return den;
}

int Datum::getAktualnyMesiac() {
	return mesiac;
}

int Datum::getAktualnyRok() {
	return rok;
}

Datum* Datum::getAktualnyDatum() {
	return this;
}

string Datum::getDateToString() {
	string formatDen, formatMesiac;

	if (den < 10) {
		formatDen = "0" + std::to_string(den);
	}
	else {
		formatDen = std::to_string(den);
	}

	if (mesiac < 10) {
		formatMesiac = "0" + std::to_string(mesiac);
	}
	else {
		formatMesiac = std::to_string(mesiac);
	}

	return formatDen + "." + formatMesiac + "." + std::to_string(rok);
}

int Datum::getPocetDniVMesiaci(int pMesiac) {
	switch (pMesiac) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (jePriestupnymRokom(getAktualnyRok())) {
			return 29;
		}
		else {
			return 28;
		}
		break;
	default:
		return 31;
		break;
	}
}

bool Datum::jePriestupnymRokom(int pRok) {
	if (pRok % 400 == 0) return true;
	if (pRok % 100 == 0) return false;
	return pRok % 4 == 0;
}

void Datum::setDalsiDen() {
	if (den == 31 && mesiac == 12) {
		den = 1;
		mesiac = 1;
		rok++;
		return;
	}

	if (den == getPocetDniVMesiaci(mesiac)) {
		den = 1;
		mesiac++;
		return;
	}

	den++;
}

Datum& Datum::operator=(Datum &datum) {
	if (this != &datum) {
		den = datum.den;
		mesiac = datum.mesiac;
		rok = datum.rok;
	}
	return *this;
}

bool Datum::operator==(Datum &datum) {
	return ((den == datum.den) && (mesiac == datum.mesiac) && (rok == datum.rok));
}

bool Datum::operator!=(Datum &datum) {
	return ((den == datum.den) || (mesiac == datum.mesiac) || (rok == datum.rok));
}

bool Datum::operator>(Datum &datum) {
	if (rok > datum.rok) {
		return true;
	}
	else if (rok < datum.rok) {
		return false;
	}

	if (mesiac > datum.mesiac) {
		return true;
	}
	else if (mesiac < datum.mesiac) {
		return false;
	}

	return den > datum.den;
}

bool Datum::operator<(Datum &datum) {
	if (rok < datum.rok) {
		return true;
	}
	else if (rok > datum.rok) {
		return false;
	}

	if (mesiac < datum.mesiac) {
		return true;
	}
	else if (mesiac > datum.mesiac) {
		return false;
	}

	return den < datum.den;
}