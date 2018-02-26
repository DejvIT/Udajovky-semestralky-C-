#include "structures\heap_monitor.h"
#include "Aplikacia.h"

int main() {
	initHeapMonitor();

	Aplikacia *appka = new Aplikacia();
	bool koniec = false;
	int prikaz;
	
	appka->nacitajOkresy();

	while (!koniec)
	{
		system("pause");
		cout << "\nSpracovanie statistik nezamestnanosti." << endl;
		cout << "======================================" << endl;
		cout << "0. Koniec" << endl;													
		cout << "1. Vypis statistiky okresu v zadanom rozpati rokov." << endl;	
		cout << "2. Zoradenie okresov v danom roku na zaklade danych parametrov." << endl;
		cout << "3. Vyhladanie okresov, ktore mali v danom rozpati rokov dosiahnute parametre." << endl;
		cout << "4. Vyhladanie kraju a vypis jeho statistik pre zadane rozpatie rokov." << endl;
		cout << "5. Zoradenie krajov v danom roku na zaklade danych parametrov." << endl;
		cout << "6. Vyhladanie kraju, ktory mal v danom obdobi prislusne udaje." << endl;

		cout << "----------------------------------------------------------------------------\nZadajte cislo prikazu:" << ends;
		cin >> prikaz;

		switch (prikaz)
		{
		case 0:
			koniec = true;
			break;
		case 1:
		{
			string nazovOkresu;
			int rokOd, rokDo;
			cout << "Zadajte nazov okresu:" << ends;
			cin.ignore();
			getline(cin, nazovOkresu);
			cout << "Zadajte rozpatie rokov OD:" << ends;
			cin >> rokOd;
			cout << "Zadajte rozpatie rokov DO:" << ends;
			cin >> rokDo;

			try
			{
				cout << appka->vypisPocetUchadzacovOZamestnanieOkresuVRokoch(nazovOkresu, rokOd, rokDo) << endl;
			}
			catch (exception& e)
			{
				cout << "Zadany Okres sa nenasiel! " << e.what() << endl;
			}
		}
		break;
		case 2:
		{
			string typZoradenia;
			int typPriority, rok;
			cout << "Zadajte typ zoradenia(zostupne/vzostupne):" << ends;
			cin.ignore();
			getline(cin, typZoradenia);
			cout << "Zadajte prioritu zoradenia(1-podla miery, 2-podla disponibilneho poctu:" << ends;
			cin >> typPriority;
			cout << "Zadajte rok:" << ends;
			cin >> rok;

			try
			{
				cout << appka->vypisZoradeneOkresyPodlaParametrov(typZoradenia, typPriority, rok) << endl;
			}
			catch (exception& e)
			{
				cout << "Errorik hopa ho! " << e.what() << endl;
			}
		}
		break;
		case 3:
		{
			int rokOd, rokDo;
			cout << "Zadajte od akeho roku:" << ends;
			cin >> rokOd;
			cout << "Zadajte do akeho roku:" << ends;
			cin >> rokDo;

			try
			{
				cout << appka->maxPriemernyPocetEkonomickyAktivnehoObyvatelstva(rokOd, rokDo) << endl;
				cout << appka->minPriemernyPocetEkonomickyAktivnehoObyvatelstva(rokOd, rokDo) << endl;
				cout << appka->maxPoklesMieryEvidovanejNezamestnanosti(rokOd, rokDo, 1) << endl;		//Muzi
				cout << appka->maxPoklesMieryEvidovanejNezamestnanosti(rokOd, rokDo, 2) << endl;		//Zeny
				cout << appka->najPomer_DispPocUchAndPocAbsolventov(rokOd, rokDo) << endl;
			}
			catch (exception& e)
			{
				cout << "Zadane roky su nespravne! " << e.what() << endl;
			}
		}
		break;
		case 4:
		{
			string nazovKraju;
			int rokOd, rokDo;

			cout << "Zadajte nazov kraju:" << ends;
			cin.ignore();
			getline(cin, nazovKraju);
			cout << "Zadajte rozpatie rokov OD:" << ends;
			cin >> rokOd;
			cout << "Zadajte rozpatie rokov DO:" << ends;
			cin >> rokDo;

			try
			{
				cout << appka->vypisStatistikyKrajuONezamestnanosti(nazovKraju, rokOd, rokDo) << endl;
			}
			catch (exception& e)
			{
				cout << "Zadany Kraj neexistuje! " << e.what() << endl;
			}
		}
			break;
		case 5:
		{
			string typZoradenia;
			int typPriority, rok;
			cout << "Zadajte typ zoradenia(zostupne/vzostupne):" << ends;
			cin.ignore();
			getline(cin, typZoradenia);
			cout << "Zadajte prioritu zoradenia(1-podla miery, 2-podla disponibilneho poctu:" << ends;
			cin >> typPriority;
			cout << "Zadajte rok:" << ends;
			cin >> rok;

			try
			{
				cout << appka->vypisZoradeneKrajePodlaParametrov(typZoradenia, typPriority, rok) << endl;
			}
			catch (exception& e)
			{
				cout << "Errorik hopa ho! " << e.what() << endl;
			}
		}
			break;
		case 6:
		{
			int rokOd, rokDo;
			cout << "Zadajte od akeho roku:" << ends;
			cin >> rokOd;
			cout << "Zadajte do akeho roku:" << ends;
			cin >> rokDo;

			try
			{
				cout << appka->maxPriemernyPocetAktivnychPreKraj(rokOd, rokDo) << endl;
				cout << appka->minPriemernyPocetAktivnychPreKraj(rokOd, rokDo) << endl;
				cout << appka->maxPoklesMieryEvidovanejNezamestnanostiPreKraj(rokOd, rokDo, 1) << endl;	//MUZI
				cout << appka->maxPoklesMieryEvidovanejNezamestnanostiPreKraj(rokOd, rokDo, 2) << endl;	//ZENY
				cout << appka->najPomer_DispPocUchAndPocAbsolventovPreKraj(rokOd, rokDo) << endl;
			}
			catch (exception& e)
			{
				cout << "Zadane roky su nespravne! " << e.what() << endl;
			}
		}
			break;
		
		default:
			cout << "Neznamy prikaz!\n" << endl;
			break;
		}
	}


	delete appka;
	appka = nullptr;
	return 0;
}