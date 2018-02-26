#pragma once

#include "structures\list\array_list.h"
#include <cstdio>

using namespace structures;
using namespace std;

class Kraj
{
public:
	Kraj(string nazovKraju);
	~Kraj();
	string getNazovKraju();
	void pridajOkresDoKraju(string nazovOkresu);
	string getNazovOkresuAtIndex(int index);
	int getPocetOkresov();

private:
	string nazovKraju_;
	ArrayList<string*> *zoznamNazvovOkresov_;
};

