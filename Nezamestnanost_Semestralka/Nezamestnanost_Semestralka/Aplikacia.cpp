#include "Aplikacia.h"



Aplikacia::Aplikacia()
{
	sortedOkresy_ = new SortedSequenceTable<string, Okres*>();
	sortedKraje_ = new SortedSequenceTable<string, Kraj*>();

	sortedKraje_->insert("Bratislavsky kraj", new Kraj("Bratislavsky kraj"));
	sortedKraje_->insert("Trnavsky kraj", new Kraj("Trnavsky kraj"));
	sortedKraje_->insert("Trenciansky kraj", new Kraj("Trenciansky kraj"));
	sortedKraje_->insert("Nitriansky kraj", new Kraj("Nitriansky kraj"));
	sortedKraje_->insert("Zilinsky kraj", new Kraj("Zilinsky kraj"));
	sortedKraje_->insert("Banskobystricky kraj", new Kraj("Banskobystricky kraj"));
	sortedKraje_->insert("Presovsky kraj", new Kraj("Presovsky kraj"));
	sortedKraje_->insert("Kosicky kraj", new Kraj("Kosicky kraj"));
}


Aplikacia::~Aplikacia()
{
	for each (auto okres in *sortedOkresy_)
	{
		delete okres->accessData();
	}
	delete sortedOkresy_;
	sortedOkresy_ = nullptr;

	for each (auto kraj in *sortedKraje_)
	{
		delete kraj->accessData();
	}
	delete sortedKraje_;
	sortedKraje_ = nullptr;
}

void Aplikacia::nacitajOkresy() {
	string riadok;
	ifstream subor1("subory/miera_evidovanej_nezamestnanosti.txt");

	//nacitanie miery evidovanej nezamestnanosti
	if (subor1.is_open())
	{
		while (getline(subor1, riadok))
		{
			string delimiter = ";";

			size_t poz;
			string nazov;

			poz = riadok.find(delimiter);
			nazov = riadok.substr(0, poz);
			riadok.erase(0, poz + delimiter.length());

			Okres *okres = new Okres(nazov);
			sortedOkresy_->insert(okres->getNazovOkresu(), okres);

			int rok = 2001;
			for (int i = 0; i < 16; i++)
			{
				okres->pridajOkresVRokuDoZoznamu(rok + i);

				for (int j = 0; j < 3; j++)
				{
					double miera;
					poz = riadok.find(delimiter);
					miera = stod(riadok.substr(0, poz).c_str());
					riadok.erase(0, poz + delimiter.length());

					(*okres->getOkresyVRoku())[i]->setMieraEvidovanejNezamestnanostiAtIndex(j, miera);
				}
			}

			getline(subor1, riadok);
			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					int pocetAktivnych;
					poz = riadok.find(delimiter);
					pocetAktivnych = stoi(riadok.substr(0, poz).c_str());
					riadok.erase(0, poz + delimiter.length());

					(*okres->getOkresyVRoku())[i]->setEkonomickyAktivneObvAtIndex(j, pocetAktivnych);
				}
			}

			getline(subor1, riadok);

			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					int pocetDisponibilnych;
					poz = riadok.find(delimiter);
					pocetDisponibilnych = stoi(riadok.substr(0, poz).c_str());
					riadok.erase(0, poz + delimiter.length());

					(*okres->getOkresyVRoku())[i]->setDisponibilnyPocUchadzacovAtIndex(j, pocetDisponibilnych);
				}
			}

		}
		subor1.close();
		cout << "miera_evidovanej_nezamestnanosti.txt loaded!" << endl;
	}
	else {
		cout << "miera_evidovanej_nezamestnanosti.txt failed!" << endl;
	}


	ifstream subor2("subory/uchadzaci_o_zamestnanie.txt");

	//nacitanie uchadzacov o zamestnanie
	if (subor2.is_open()) {
		int poradie = 1;

		while (getline(subor2, riadok))
		{
			string delimiter = ";";

			size_t poz;
			string nazov;

			poz = riadok.find(delimiter);
			nazov = riadok.substr(0, poz);
			riadok.erase(0, poz + delimiter.length());

			Okres *okres = (*sortedOkresy_)[nazov];

			for (int i = 0; i < 16; i++)
			{
				int uchadzaci, absolventi, mladistvi, dlhodobi;

				poz = riadok.find(delimiter);
				uchadzaci = stoi(riadok.substr(0, poz).c_str());
				riadok.erase(0, poz + delimiter.length());

				poz = riadok.find(delimiter);
				absolventi = stoi(riadok.substr(0, poz).c_str());
				riadok.erase(0, poz + delimiter.length());

				poz = riadok.find(delimiter);
				mladistvi = stoi(riadok.substr(0, poz).c_str());
				riadok.erase(0, poz + delimiter.length());

				poz = riadok.find(delimiter);
				dlhodobi = stoi(riadok.substr(0, poz).c_str());
				riadok.erase(0, poz + delimiter.length());

				(*okres->getOkresyVRoku())[i]->setPocetZP(uchadzaci);
				(*okres->getOkresyVRoku())[i]->setPocetAsolventov(absolventi);
				(*okres->getOkresyVRoku())[i]->setPocetMladistvych(mladistvi);
				(*okres->getOkresyVRoku())[i]->setPocetDlhodobych(dlhodobi);
			}

			//Zaradenie daneho okresu k prislusnemu Kraju v zoznameKrajov_
			if (poradie <= 8) {
				(*sortedKraje_)["Bratislavsky kraj"]->pridajOkresDoKraju(nazov);
			}
			else if (poradie <= 15) {
				(*sortedKraje_)["Trnavsky kraj"]->pridajOkresDoKraju(nazov);
			}
			else if (poradie <= 24) {
				(*sortedKraje_)["Trenciansky kraj"]->pridajOkresDoKraju(nazov);
			}
			else if (poradie <= 31) {
				(*sortedKraje_)["Nitriansky kraj"]->pridajOkresDoKraju(nazov);
			}
			else if (poradie <= 42) {
				(*sortedKraje_)["Zilinsky kraj"]->pridajOkresDoKraju(nazov);
			}
			else if (poradie <= 55) {
				(*sortedKraje_)["Banskobystricky kraj"]->pridajOkresDoKraju(nazov);
			}
			else if (poradie <= 68) {
				(*sortedKraje_)["Presovsky kraj"]->pridajOkresDoKraju(nazov);
			}
			else {
				(*sortedKraje_)["Kosicky kraj"]->pridajOkresDoKraju(nazov);
			}
			poradie++;
		}
		subor2.close();
		cout << "uchadzaci_o_zamestnanie.txt loaded!" << endl;
		cout << "Kraje inicializovane!" << endl;
	}
	else {
		cout << "uchadzaci_o_zamestnanie.txt failed!" << endl;
	}
}

string Aplikacia::vypisPocetUchadzacovOZamestnanieOkresuVRokoch(string nazovOkresu, int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;

	return (*sortedOkresy_)[nazovOkresu]->vypisUchadzacovOZamestnanie(rokOd, rokDo);
}

string Aplikacia::vypisZoradeneOkresyPodlaParametrov(string typZoradenia, int typPriority, int rok) {
	if (typPriority < 1) typPriority = 1;
	if (typPriority > 2) typPriority = 2;
	if (rok < 2001) rok = 2001;
	if (rok > 2016) rok = 2016;

	Heap<Okres*> *halda = new Heap<Okres*>();

	if (typZoradenia.compare("zostupne") == 0) {		//zoradenie (9,8,7,6,5,...)
		//zaporna priorita
		if (typPriority == 1) {					//zoradenie podla miery evidovanej nezamestnanosti
			for each (auto okres in *sortedOkresy_)
			{
				halda->push(static_cast<int>(-100 * (*okres->accessData()->getOkresyVRoku())[rok - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(0)), okres->accessData());
			}
		}
		else									//zoradenia podla disponibilneho poctu uchadzacov o zamestnanie
		{
			for each (auto okres in *sortedOkresy_)
			{
				halda->push(static_cast<int>(-(*okres->accessData()->getOkresyVRoku())[rok - 2001]->getDisponibilnyPocUchadzacovAtIndex(0)), okres->accessData());
			}
		}
	}
	else										//zoradenie (1,2,3,4,5,...)
	{	//kladna priorita
		if (typPriority == 1) {					//zoradenie podla miery evidovanej nezamestnanosti
			for each (auto okres in *sortedOkresy_)
			{
				halda->push(static_cast<int>(100 * (*okres->accessData()->getOkresyVRoku())[rok - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(0)), okres->accessData());
			}
		}
		else									//zoradenia podla disponibilneho poctu uchadzacov o zamestnanie
		{
			for each (auto okres in *sortedOkresy_)
			{
				halda->push(static_cast<int>((*okres->accessData()->getOkresyVRoku())[rok - 2001]->getDisponibilnyPocUchadzacovAtIndex(0)), okres->accessData());
			}
		}
	}

	string vypis = "Vypis pre rok " + to_string(rok) + ".";

	int poradie = 1;
	while (!halda->isEmpty())
	{
		Okres *okres = halda->pop();
		vypis += "\n\n" + to_string(poradie) + ".) " + "Nazov: " + okres->getNazovOkresu() + " v roku " + to_string(rok)
			+ "\nMiera evidovanej nezamestnanosti = " + to_string((*okres->getOkresyVRoku())[rok - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(0)) + "%"
			+ "\nDisponibilny pocet uchadzacov o zamestnanie = " + to_string((*okres->getOkresyVRoku())[rok - 2001]->getDisponibilnyPocUchadzacovAtIndex(0));
	
		poradie++;
	}

	delete halda;
	return vypis;
}

string Aplikacia::maxPriemernyPocetEkonomickyAktivnehoObyvatelstva(int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double max = 0.0;
	string nazovOkresu;

	for each (auto okres in *sortedOkresy_)
	{
		double priemer = 0.0;
		
		for (int i = (rokOd - 2001); i <= (rokDo - 2001); i++)
		{
			priemer += static_cast<double>((*okres->accessData()->getOkresyVRoku())[i]->getEkonomickyAktivneObvAtIndex(0));
		}
		priemer = priemer / (rokDo - rokOd + 1);

		if (max < priemer)
		{
			max = priemer;
			nazovOkresu = okres->accessData()->getNazovOkresu();
		}
	}

	return "\nNazov: " + nazovOkresu + ", Obdobie: " + to_string(rokOd) + "-" + to_string(rokDo)
		+ "\nNajvacsi priemerny pocet ekonomicky aktivneho obyvatelstva = " + to_string(max);
}

string Aplikacia::minPriemernyPocetEkonomickyAktivnehoObyvatelstva(int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double min = DBL_MAX / 2;
	string nazovOkresu;

	for each (auto okres in *sortedOkresy_)
	{
		double priemer = 0.0;

		for (int i = (rokOd - 2001); i <= (rokDo - 2001); i++)
		{
			priemer += static_cast<double>((*okres->accessData()->getOkresyVRoku())[i]->getEkonomickyAktivneObvAtIndex(0));
		}
		priemer = priemer / (rokDo - rokOd + 1);

		if (min > priemer)
		{
			min = priemer;
			nazovOkresu = okres->accessData()->getNazovOkresu();
		}
	}

	return "\nNazov: " + nazovOkresu + ", Obdobie: " + to_string(rokOd) + "-" + to_string(rokDo)
		+ "\nNajmensi priemerny pocet ekonomicky aktivneho obyvatelstva = " + to_string(min);
}

string Aplikacia::maxPoklesMieryEvidovanejNezamestnanosti(int rokOd, int rokDo, int index) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double max = 0.0;
	string nazovOkresu;

	for each (auto okres in *sortedOkresy_)
	{
		double rozdiel = (*okres->accessData()->getOkresyVRoku())[rokOd - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(index)
			- (*okres->accessData()->getOkresyVRoku())[rokDo - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(index);

		if (max < rozdiel)
		{
			max = rozdiel;
			nazovOkresu = okres->accessData()->getNazovOkresu();
		}
	}

	string pohlavie;
	if (index == 1)
	{
		pohlavie = "Muzi";
	}
	else {
		pohlavie = "Zeny";
	}

	return "\nNazov: " + nazovOkresu + ", Obdobie: " + to_string(rokOd) + "-" + to_string(rokDo)
		+ "\nNajvacsi pokles miery evidovanej nezamestnanosti - " + pohlavie + " = " + to_string(max);
}

string Aplikacia::najPomer_DispPocUchAndPocAbsolventov(int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double max = 0.0;
	string nazovOkresu;

	for each (auto okres in *sortedOkresy_)
	{
		double priemer = 0.0;

		for (int i = (rokOd - 2001); i <= (rokDo - 2001); i++)
		{
			priemer += static_cast<double>((*okres->accessData()->getOkresyVRoku())[i]->getDisponibilnyPocUchadzacovAtIndex(0))
				/ static_cast<double>((*okres->accessData()->getOkresyVRoku())[i]->getPocetAbsolventov());
		}

		priemer = priemer / (rokDo - rokOd + 1);

		if (max < priemer) {
			max = priemer;
			nazovOkresu = okres->accessData()->getNazovOkresu();
		}
	}

	return "\nNazov: " + nazovOkresu + ", Obdobie: " + to_string(rokOd) + "-" + to_string(rokDo)
		+ "\nNajlepsi pomer medzi disponibilnym poctom uchadzacov a absolventov = " + to_string(max);
}

string Aplikacia::vypisStatistikyKrajuONezamestnanosti(string nazovKraju, int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	int sumZP = 0;
	int sumAbsolventov = 0;
	int sumMladych = 0;
	int sumDlhodobych = 0;

	for (int j = 0; j < (*sortedKraje_)[nazovKraju]->getPocetOkresov(); j++)
	{
		string nazovOkresu = (*sortedKraje_)[nazovKraju]->getNazovOkresuAtIndex(j);

		for (int indexVRoku = (rokOd - 2001); indexVRoku <= (rokDo - 2001); indexVRoku++)
		{
			sumZP += (*(*sortedOkresy_)[nazovOkresu]->getOkresyVRoku())[indexVRoku]->getPocetZP();
			sumAbsolventov += (*(*sortedOkresy_)[nazovOkresu]->getOkresyVRoku())[indexVRoku]->getPocetAbsolventov();
			sumMladych += (*(*sortedOkresy_)[nazovOkresu]->getOkresyVRoku())[indexVRoku]->getPocetMladistvych();
			sumDlhodobych += (*(*sortedOkresy_)[nazovOkresu]->getOkresyVRoku())[indexVRoku]->getPocetDlhodobych();
		}
	}
		
	return "\nNazov: " + nazovKraju + ", Obdobie: " + to_string(rokOd) + " - " + to_string(rokDo)
		+ "\nSucet zdravotne postihnutych uchadzacov = " + to_string(sumZP)
		+ "\nSucet uchadzacov o zamestnanie - Absolventov = " + to_string(sumAbsolventov)
		+ "\nSucet mladistvych uchadzacov o zamestnanie = " + to_string(sumMladych)
		+ "\nSucet dlhodobo evidovanych uchadzacov o zamestnanie = " + to_string(sumDlhodobych);
}

string Aplikacia::vypisZoradeneKrajePodlaParametrov(string typZoradenia, int typPriority, int rok) {
	if (typPriority < 1) typPriority = 1;
	if (typPriority > 2) typPriority = 2;
	if (rok < 2001) rok = 2001;
	if (rok > 2016) rok = 2016;

	Heap<Kraj*> *halda = new Heap<Kraj*>();

	if (typZoradenia.compare("zostupne") == 0) {		//zoradenie (9,8,7,6,5,...)
		//zaporna priorita
		if (typPriority == 1) {							//zoradenie podla miery evidovanej nezamestnanosti
			for each (auto kraj in *sortedKraje_)
			{
				halda->push(static_cast<int>(-1000000 * (static_cast<double>(sucetDisponibilnehoPoctuUchadzacovVKraji(kraj->getKey(), rok)) / static_cast<double>(sucetEkonomickyAktivnehoObvyvatelstvaVKraji(kraj->getKey(), rok)))), kraj->accessData());
			}
		}
		else											//zoradenia podla disponibilneho poctu uchadzacov o zamestnanie
		{
			for each (auto kraj in *sortedKraje_)
			{
				halda->push(-(sucetDisponibilnehoPoctuUchadzacovVKraji(kraj->getKey(), rok)), kraj->accessData());
			}
		}
	}
	else												//zoradenie (1,2,3,4,5,...)
	{	//kladna priorita
		if (typPriority == 1) {							//zoradenie podla miery evidovanej nezamestnanosti
			for each (auto kraj in *sortedKraje_)
			{
				halda->push(static_cast<int>(1000000 * (static_cast<double>(sucetDisponibilnehoPoctuUchadzacovVKraji(kraj->getKey(), rok)) / static_cast<double>(sucetEkonomickyAktivnehoObvyvatelstvaVKraji(kraj->getKey(), rok)))), kraj->accessData());
			}
		}
		else											//zoradenia podla disponibilneho poctu uchadzacov o zamestnanie
		{
			for each (auto kraj in *sortedKraje_)
			{
				halda->push(sucetDisponibilnehoPoctuUchadzacovVKraji(kraj->getKey(), rok), kraj->accessData());
			}
		}
	}

	string vypis = "Vypis pre rok " + to_string(rok) + ".";

	int poradie = 1;
	
	while (!halda->isEmpty())
	{
		Kraj *kraj = halda->pop();
		vypis += "\n\n" + to_string(poradie) + ".) " + "Nazov: " + kraj->getNazovKraju() + " v roku " + to_string(rok)
			+ "\nMiera evidovanej nezamestnanosti = " + to_string(100 * (static_cast<double>(sucetDisponibilnehoPoctuUchadzacovVKraji(kraj->getNazovKraju(), rok)) / static_cast<double>(sucetEkonomickyAktivnehoObvyvatelstvaVKraji(kraj->getNazovKraju(), rok)))) + "%"
			+ "\nDisponibilny pocet uchadzacov o zamestnanie = " + to_string(sucetDisponibilnehoPoctuUchadzacovVKraji(kraj->getNazovKraju(), rok));

		poradie++;
	}

	delete halda;
	return vypis;
}

int Aplikacia::sucetDisponibilnehoPoctuUchadzacovVKraji(string nazovKraja, int rok) {
	int sum = 0;

	for (int i = 0; i < (*sortedKraje_)[nazovKraja]->getPocetOkresov(); i++)
	{
		sum += (*(*sortedOkresy_)[(*sortedKraje_)[nazovKraja]->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[rok - 2001]->getDisponibilnyPocUchadzacovAtIndex(0);
	}

	return sum;
}

int Aplikacia::sucetEkonomickyAktivnehoObvyvatelstvaVKraji(string nazovKraja, int rok) {
	int sum = 0;

	for (int i = 0; i < (*sortedKraje_)[nazovKraja]->getPocetOkresov(); i++)
	{
		sum += (*(*sortedOkresy_)[(*sortedKraje_)[nazovKraja]->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[rok - 2001]->getEkonomickyAktivneObvAtIndex(0);
	}

	return sum;
}

string Aplikacia::maxPriemernyPocetAktivnychPreKraj(int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double max = 0.0;
	string nazovKraja;

	for each (auto kraj in *sortedKraje_)
	{
		double priemer = 0.0;

		for (int i = 0; i < kraj->accessData()->getPocetOkresov(); i++)
		{
			double priemerOkresu = 0.0;

			for (int j = (rokOd - 2001); j <= (rokDo - 2001); j++)
			{
				priemerOkresu += (*(*sortedOkresy_)[kraj->accessData()->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[j]->getEkonomickyAktivneObvAtIndex(0);
			}
			priemer += priemerOkresu / (rokDo - rokOd + 1);
		}
		priemer = priemer / kraj->accessData()->getPocetOkresov();

		if (max < priemer)
		{
			max = priemer;
			nazovKraja = kraj->getKey();
		}
	}

	return "\nNazov: " + nazovKraja + ", Obdobie: " + to_string(rokOd) + " - " + to_string(rokDo)
		+ "\nNajvacsi priemerny pocet ekonomicky aktivneho obyvatlstva = " + to_string(max);
}

string Aplikacia::minPriemernyPocetAktivnychPreKraj(int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double min = DBL_MAX / 2;
	string nazovKraja;

	for each (auto kraj in *sortedKraje_)
	{
		double priemer = 0.0;

		for (int i = 0; i < kraj->accessData()->getPocetOkresov(); i++)
		{
			double priemerOkresu = 0.0;
			for (int j = (rokOd - 2001); j <= (rokDo - 2001); j++)
			{
				priemerOkresu += (*(*sortedOkresy_)[kraj->accessData()->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[j]->getEkonomickyAktivneObvAtIndex(0);
			}
			priemer += priemerOkresu / (rokDo - rokOd + 1);
		}
		priemer = priemer / kraj->accessData()->getPocetOkresov();

		if (min > priemer)
		{
			min = priemer;
			nazovKraja = kraj->getKey();
		}
	}

	return "\nNazov: " + nazovKraja + ", Obdobie: " + to_string(rokOd) + " - " + to_string(rokDo)
		+ "\nNajmensi priemerny pocet ekonomicky aktivneho obyvatlstva = " + to_string(min);
}

string Aplikacia::maxPoklesMieryEvidovanejNezamestnanostiPreKraj(int rokOd, int rokDo, int index) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double max = 0.0;
	string nazovKraja;

	for each (auto kraj in *sortedKraje_)
	{
		double priemer = 0.0;

		for (int i = 0; i < kraj->accessData()->getPocetOkresov(); i++)
		{
			priemer += (*(*sortedOkresy_)[kraj->accessData()->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[rokOd - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(index)
				- (*(*sortedOkresy_)[kraj->accessData()->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[rokDo - 2001]->getMieraEvidovanejNezamestnanostiAtIndex(index);
		}

		if (max < priemer)
		{
			max = priemer;
			nazovKraja = kraj->getKey();
		}
	}

	string pohlavie;
	if (index == 1)
	{
		pohlavie = "Muzi";
	}
	else {
		pohlavie = "Zeny";
	}

	return "\nNazov: " + nazovKraja + ", Obdobie: " + to_string(rokOd) + "-" + to_string(rokDo)
		+ "\nNajvacsi pokles miery evidovanej nezamestnanosti - " + pohlavie + " = " + to_string(max);
}

string Aplikacia::najPomer_DispPocUchAndPocAbsolventovPreKraj(int rokOd, int rokDo) {
	if (rokOd < 2001) rokOd = 2001;
	if (rokDo > 2016) rokDo = 2016;
	double max = 0.0;
	string nazovKraja;

	for each (auto kraj in *sortedKraje_)
	{
		double priemer = 0.0;

		for (int i = 0; i < kraj->accessData()->getPocetOkresov(); i++)
		{
			double priemerOkresu = 0.0;

			for (int j = (rokOd - 2001); j <= (rokDo - 2001); j++)
			{
				priemerOkresu += static_cast<double>((*(*sortedOkresy_)[kraj->accessData()->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[j]->getDisponibilnyPocUchadzacovAtIndex(0))
					/ static_cast<double>((*(*sortedOkresy_)[kraj->accessData()->getNazovOkresuAtIndex(i)]->getOkresyVRoku())[j]->getPocetAbsolventov());
			}

			priemer += priemerOkresu / (rokDo - rokOd + 1);
		}

		priemer = priemer / kraj->accessData()->getPocetOkresov();

		if (max < priemer) {
			max = priemer;
			nazovKraja = kraj->getKey();
		}
	}

	return "\nNazov: " + nazovKraja + ", Obdobie: " + to_string(rokOd) + "-" + to_string(rokDo)
		+ "\nNajlepsi pomer medzi disponibilnym poctom uchadzacov a absolventov = " + to_string(max);
}