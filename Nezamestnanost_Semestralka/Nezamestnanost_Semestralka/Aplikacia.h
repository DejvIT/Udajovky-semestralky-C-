#pragma once

#include "Okres.h"
#include "Kraj.h"
#include "structures\table\sorted_sequence_table.h"
#include "structures\priority_queue\heap.h"
#include <fstream>


class Aplikacia
{
public:
	Aplikacia();
	~Aplikacia();
	void nacitajOkresy();
	string vypisPocetUchadzacovOZamestnanieOkresuVRokoch(string nazovOkresu, int rokOd, int rokDo);
	string vypisZoradeneOkresyPodlaParametrov(string typZoradenia, int typPriority, int rok);
	string maxPriemernyPocetEkonomickyAktivnehoObyvatelstva(int rokOd, int rokDo);
	string minPriemernyPocetEkonomickyAktivnehoObyvatelstva(int rokOd, int rokDo);
	string maxPoklesMieryEvidovanejNezamestnanosti(int rokOd, int rokDo, int index);
	string najPomer_DispPocUchAndPocAbsolventov(int rokOd, int rokDo);
	string vypisStatistikyKrajuONezamestnanosti(string nazovKraju, int rokOd, int rokDo);
	string vypisZoradeneKrajePodlaParametrov(string typZoradenia, int typPriority, int rok);
	int sucetDisponibilnehoPoctuUchadzacovVKraji(string nazovKraja, int rok);
	int sucetEkonomickyAktivnehoObvyvatelstvaVKraji(string nazovKraja, int rok);
	string maxPriemernyPocetAktivnychPreKraj(int rokOd, int rokDo);
	string minPriemernyPocetAktivnychPreKraj(int rokOd, int rokDo);
	string maxPoklesMieryEvidovanejNezamestnanostiPreKraj(int rokOd, int rokDo, int index);
	string najPomer_DispPocUchAndPocAbsolventovPreKraj(int rokOd, int rokDo);

private:
	SortedSequenceTable<string, Okres*> *sortedOkresy_;
	SortedSequenceTable<string, Kraj*> *sortedKraje_;
};

