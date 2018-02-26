#pragma once

#include <cstring>		// použitie std::string
#include <sstream>		//použitie std::to_string
#include <iostream>		//použitie std::cout, std::cin
#include <cstdio>

#include "structures\list\array_list.h"

using namespace std;	//kvôli includnutým structures z AUS sa bije std::string napr. s std::Array 
using namespace structures;

class OkresVRoku
{
public:
	OkresVRoku(int rok);
	~OkresVRoku();
	int getRok();
	void setPocetZP(int data);
	int getPocetZP();
	void setPocetAsolventov(int data);
	int getPocetAbsolventov();
	void setPocetMladistvych(int data);
	int getPocetMladistvych();
	void setPocetDlhodobych(int data);
	int getPocetDlhodobych();
	void setMieraEvidovanejNezamestnanostiAtIndex(int index, double data);
	double getMieraEvidovanejNezamestnanostiAtIndex(int index);
	void setEkonomickyAktivneObvAtIndex(int index, int data);
	int getEkonomickyAktivneObvAtIndex(int index);
	void setDisponibilnyPocUchadzacovAtIndex(int index, int data);
	int getDisponibilnyPocUchadzacovAtIndex(int index);
	string vypisUchadzacov();

private:
	int rok_;
	int pocetZP_;
	int pocetAbsolventov_;
	int pocetMladistvych_;
	int pocetDlhodobych_;

	ArrayList<double> *mieraEvidovanejNezamestnanosti_;		//0 - Spolu, 1 - Muzi, 2 - Zeny
	ArrayList<int> *ekonomickyAktivneObyvatelstvo_;			//0 - Spolu, 1 - Muzi, 2 - Zeny
	ArrayList<int> *disponibilnyPocetUchadzacov_;			//0 - Spolu, 1 - Muzi, 2 - Zeny
};

