#include <iostream>

#include "structures\vector\vector.h"
#include "structures\array\array.h"
#include "structures\list\array_list.h"
#include "structures\heap_monitor.h"

//testy
#include "Spolocnost_FRI.h"


using namespace structures;
using namespace std;

int main() {
	initHeapMonitor();

	Datum *miestnyDatum = new Datum(16, 3, 2017);
	Datum *porovnavac = new Datum(1, 1, 2020);
	//cout << (porovnavac) > (*miestnyDatum) << endl;
	CentralnySklad *centralnySklad = new CentralnySklad();
	Spolocnost_FRI *spolocnost = new Spolocnost_FRI(miestnyDatum, centralnySklad);
	Region *region1 = new Region(1);
	centralnySklad->pridajRegionDoZoznamu(region1);

	cout << "1.Pridanie vozidla do Firmy: " << endl;
	Vozidlo *vozidlo1 = new Vozidlo(850, "999XX", miestnyDatum);
	Vozidlo *vozidlo2 = new Vozidlo(780, "MRDKA", miestnyDatum);
	Vozidlo *vozidlo3 = new Vozidlo(1180, "159JO", miestnyDatum);
	centralnySklad->pridajVozidloDoFirmy(vozidlo1);
	centralnySklad->pridajVozidloDoFirmy(vozidlo2);
	centralnySklad->pridajVozidloDoFirmy(vozidlo3);

	cout << "\n2.Vypis vozidiel podla datumu:" << endl;
	cout << centralnySklad->vypisVozidlaPodlaDatumu() << endl;

	cout << "\n3.Pridanie dodavatelov:" << endl;
	Dodavatel *janko = new Dodavatel("Janko", "Jankova_8");
	Dodavatel *Bruzik = new Dodavatel("Bruzik", "Bruzikova_10");
	Dodavatel *Kundibad = new Dodavatel("Kundibad", "U lesa 3");
	spolocnost->pridajDodavatela(Kundibad);
	spolocnost->pridajDodavatela(janko);
	spolocnost->pridajDodavatela(Bruzik);

	cout << "\n4.Dodavateia abecedne: " << endl;
	cout << spolocnost->vypisDodavatelov() << endl;

	cout << "\n5.Ohlasenie Dodavatela s datumom prichodu objednavky: " << endl;
	Paleta *paleta1 = new Paleta(1, 200, miestnyDatum, true, "Janko");
	Paleta *paleta2 = new Paleta(1, 250, new Datum(1, 1, 2020), false, "Janko");
	Paleta *paleta3 = new Paleta(1, 1500, new Datum(1, 1, 2020), false, "Janko");
	janko->nalozDoKamionu(*paleta1);
	janko->nalozDoKamionu(*paleta2);
	janko->nalozDoKamionu(*paleta3);
	cout << janko->poslatObjednavkuSpolocnosti(*miestnyDatum) << endl;

	cout << "\n6.Vylozenie paliet do skladu podla regionov: " << endl;
	spolocnost->prijatObjednavky();
	spolocnost->vykladajPodlaRegionov(spolocnost->getDodavatelaObjednavky());
	centralnySklad->getRegion(0)->getPocetPalietNaDorucenie();


	cout << "Dealokacia pamate:" << endl;
	delete spolocnost;

	string character;
	cin >> character;
	return 0;
}