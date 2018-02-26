#pragma once

#include "OkresVRoku.h"

class Okres
{
public:
	Okres(string name);
	~Okres();
	string getNazovOkresu();
	void pridajOkresVRokuDoZoznamu(int rok);
	ArrayList<OkresVRoku*>* getOkresyVRoku();
	string vypisUchadzacovOZamestnanie(int rokOd, int rokDo);

private:
	string nazovOkresu_;
	ArrayList<OkresVRoku*> *okresyVRoku_;
};

