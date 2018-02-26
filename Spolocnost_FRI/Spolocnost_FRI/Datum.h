#pragma once
#include <cstring>		// pouitie std::string
#include <sstream>		//pouitie std::to_string
#include <iostream>		//pouitie std::cout, std::cin
#include <cstdio>

using namespace std;	//kvôli includnutım structures z AUS sa bije std::string napr. s std::Array 

/// <summary> Dátum. </summary>
class Datum
{
public:
	/// <summary> Konštruktor vytvorí dátum na základe vstupnıch parametrov. </summary>
	/// <param name = "pDen"> Deò v dátume. </param>
	/// <param name = "pMesiac"> Mesiac v dátume. </param>
	/// <param name = "pRok"> Rok v dátume. </param>
	Datum(int pDen, int pMesiac, int pRok);
	
	/// <summary> Kopírovaci konštruktor. </summary>
	/// <param name = "other"> Zdrojovy dátum. </param>
	Datum(const Datum &other);
	
	/// <summary> Defaultny konštruktor. </summary>
	Datum();

	/// <summary> Destruktor. </summary>
	~Datum();

	/// <summary> Vypíše aktuálny deò. </summary>
	/// <returns> Deò. </returns>
	int getAktualnyDen();

	/// <summary> Vypíše aktuálny mesiac. </summary>
	/// <returns> Mesiac v poradí. </returns>
	int getAktualnyMesiac();

	/// <summary> Vypíše aktuálny rok. </summary>
	/// <returns> Rok. </returns>
	int getAktualnyRok();

	/// <summary> Vráti adresou aktuálny dátum. </summary>
	/// <returns> Datum. </returns>
	Datum* getAktualnyDatum();

	/// <summary> Vypíše dátum. </summary>
	/// <returns> Dátum vo forme reazca string. </returns>
	string getDateToString();

	/// <summary> Vráti poèet dní v danom mesiaci. </summary>
	/// <param name = "pMesiac"> Mesiac, ktorého poèet dní chceme vráti. </param>
	/// <returns> Poèet dní. </returns>
	int getPocetDniVMesiaci(int pMesiac);

	/// <summary> Zistí èi je rok prietupnım. </summary>
	/// <returns> true = priestpnı, false = nepriestupnı. </returns>
	bool jePriestupnymRokom(int pRok);

	/// <summary> Prestaví dátum na ïalší deò. </summary>
	void setDalsiDen();

	/// <summary> Vráti adresou priradenı dátum. </summary>
	/// <param name = "pMesiac"> Dátum, z ktorého sa majú prebra vlastnosti. </param>
	/// <returns> Adresa, na ktorej sa tento dátum nachádza po priradení. </returns>
	Datum& operator=(Datum &datum);

	/// <summary> Zistí rovnos dátumov. </summary>
	/// <param name = "pMesiac"> Dátum, ktorého vlastnosti sú porovnávané. </param>
	/// <returns> true = rovnaké, false = rôzne (dátumy). </returns>
	bool operator==(Datum &datum);

	/// <summary> Zistí nerovnos dátumov. </summary>
	/// <param name = "pMesiac"> Dátum, ktorého vlastnosti sú porovnávané. </param>
	/// <returns> true = rôzne, false = rovnaké (dátumy). </returns>
	bool operator!=(Datum &datum);

	/// <summary> Zistí, èi je dátum novší ako porovnávací dátum. </summary>
	/// <param name = "pMesiac"> Dátum, ktorého vlastnosti sú porovnávané. </param>
	/// <returns> true = novší, false = starší (dátumy). </returns>
	bool operator>(Datum &datum);

	/// <summary> Zistí, èi je dátum starší ako porovnávací dátum. </summary>
	/// <param name = "pMesiac"> Dátum, ktorého vlastnosti sú porovnávané. </param>
	/// <returns> true = starší, false = novší (dátumy). </returns>
	bool operator<(Datum &datum);

private:
	/// <summary> Deò. </summary>
	int den;
	/// <summary> Mesiac. </summary>
	int mesiac;
	/// <summary> Rok. </summary>
	int rok;
};

