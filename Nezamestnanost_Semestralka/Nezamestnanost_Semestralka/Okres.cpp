#include "Okres.h"



Okres::Okres(string nazov)
{
	nazovOkresu_ = nazov;
	okresyVRoku_ = new ArrayList<OkresVRoku*>();
}


Okres::~Okres()
{
	for each (auto okres in *okresyVRoku_)
	{
		delete okres;
	}
	delete okresyVRoku_;
	okresyVRoku_ = nullptr;
}


string Okres::getNazovOkresu() {
	return nazovOkresu_;
}

void Okres::pridajOkresVRokuDoZoznamu(int rok) {
	okresyVRoku_->add(new OkresVRoku(rok));
}

ArrayList<OkresVRoku*>* Okres::getOkresyVRoku() {
	return okresyVRoku_;
}

string Okres::vypisUchadzacovOZamestnanie(int rokOd, int rokDo) {
	string vypis = "\nNazov: " + getNazovOkresu() + "\n======================================";

	for (int i = (rokOd - 2001); i <= (rokDo - 2001); i++)
	{
		vypis += (*okresyVRoku_)[i]->vypisUchadzacov();
	}

	return vypis;
}