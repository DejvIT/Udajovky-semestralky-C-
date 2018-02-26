#include "Kraj.h"



Kraj::Kraj(string nazovKraju)
{
	nazovKraju_ = nazovKraju;
	zoznamNazvovOkresov_ = new ArrayList<string*>();
}


Kraj::~Kraj()
{
	for each (auto var in *zoznamNazvovOkresov_)
	{
		delete var;
	}
	delete zoznamNazvovOkresov_;
	zoznamNazvovOkresov_ = nullptr;
}

string Kraj::getNazovKraju() {
	return nazovKraju_;
}

void Kraj::pridajOkresDoKraju(string nazovOkresu) {
	zoznamNazvovOkresov_->add(new string(nazovOkresu));
}

string Kraj::getNazovOkresuAtIndex(int index) {
	return *(*zoznamNazvovOkresov_)[index];
}

int Kraj::getPocetOkresov() {
	return zoznamNazvovOkresov_->size();
}
