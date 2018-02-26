#pragma once
#include <cstring>		// pou�itie std::string
#include <sstream>		//pou�itie std::to_string
#include <iostream>		//pou�itie std::cout, std::cin
#include <cstdio>

using namespace std;	//kv�li includnut�m structures z AUS sa bije std::string napr. s std::Array 

/// <summary> D�tum. </summary>
class Datum
{
public:
	/// <summary> Kon�truktor vytvor� d�tum na z�klade vstupn�ch parametrov. </summary>
	/// <param name = "pDen"> De� v d�tume. </param>
	/// <param name = "pMesiac"> Mesiac v d�tume. </param>
	/// <param name = "pRok"> Rok v d�tume. </param>
	Datum(int pDen, int pMesiac, int pRok);
	
	/// <summary> Kop�rovaci kon�truktor. </summary>
	/// <param name = "other"> Zdrojovy d�tum. </param>
	Datum(const Datum &other);
	
	/// <summary> Defaultny kon�truktor. </summary>
	Datum();

	/// <summary> Destruktor. </summary>
	~Datum();

	/// <summary> Vyp�e aktu�lny de�. </summary>
	/// <returns> De�. </returns>
	int getAktualnyDen();

	/// <summary> Vyp�e aktu�lny mesiac. </summary>
	/// <returns> Mesiac v porad�. </returns>
	int getAktualnyMesiac();

	/// <summary> Vyp�e aktu�lny rok. </summary>
	/// <returns> Rok. </returns>
	int getAktualnyRok();

	/// <summary> Vr�ti adresou aktu�lny d�tum. </summary>
	/// <returns> Datum. </returns>
	Datum* getAktualnyDatum();

	/// <summary> Vyp�e d�tum. </summary>
	/// <returns> D�tum vo forme re�azca string. </returns>
	string getDateToString();

	/// <summary> Vr�ti po�et dn� v danom mesiaci. </summary>
	/// <param name = "pMesiac"> Mesiac, ktor�ho po�et dn� chceme vr�ti�. </param>
	/// <returns> Po�et dn�. </returns>
	int getPocetDniVMesiaci(int pMesiac);

	/// <summary> Zist� �i je rok prietupn�m. </summary>
	/// <returns> true = priestpn�, false = nepriestupn�. </returns>
	bool jePriestupnymRokom(int pRok);

	/// <summary> Prestav� d�tum na �al�� de�. </summary>
	void setDalsiDen();

	/// <summary> Vr�ti adresou priraden� d�tum. </summary>
	/// <param name = "pMesiac"> D�tum, z ktor�ho sa maj� prebra� vlastnosti. </param>
	/// <returns> Adresa, na ktorej sa tento d�tum nach�dza po priraden�. </returns>
	Datum& operator=(Datum &datum);

	/// <summary> Zist� rovnos� d�tumov. </summary>
	/// <param name = "pMesiac"> D�tum, ktor�ho vlastnosti s� porovn�van�. </param>
	/// <returns> true = rovnak�, false = r�zne (d�tumy). </returns>
	bool operator==(Datum &datum);

	/// <summary> Zist� nerovnos� d�tumov. </summary>
	/// <param name = "pMesiac"> D�tum, ktor�ho vlastnosti s� porovn�van�. </param>
	/// <returns> true = r�zne, false = rovnak� (d�tumy). </returns>
	bool operator!=(Datum &datum);

	/// <summary> Zist�, �i je d�tum nov�� ako porovn�vac� d�tum. </summary>
	/// <param name = "pMesiac"> D�tum, ktor�ho vlastnosti s� porovn�van�. </param>
	/// <returns> true = nov��, false = star�� (d�tumy). </returns>
	bool operator>(Datum &datum);

	/// <summary> Zist�, �i je d�tum star�� ako porovn�vac� d�tum. </summary>
	/// <param name = "pMesiac"> D�tum, ktor�ho vlastnosti s� porovn�van�. </param>
	/// <returns> true = star��, false = nov�� (d�tumy). </returns>
	bool operator<(Datum &datum);

private:
	/// <summary> De�. </summary>
	int den;
	/// <summary> Mesiac. </summary>
	int mesiac;
	/// <summary> Rok. </summary>
	int rok;
};

