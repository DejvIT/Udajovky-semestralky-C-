#include "OkresVRoku.h"



OkresVRoku::OkresVRoku(int rok)
{
	rok_ = rok;

	rok_ = -1;
	pocetZP_ = -1;
	pocetAbsolventov_ = -1;
	pocetMladistvych_ = -1;
	pocetDlhodobych_ = -1;

	mieraEvidovanejNezamestnanosti_ = new ArrayList<double>();
	ekonomickyAktivneObyvatelstvo_ = new ArrayList<int>();
	disponibilnyPocetUchadzacov_ = new ArrayList<int>();

	for (int i = 0; i < 3; i++)
	{
		mieraEvidovanejNezamestnanosti_->add(-1.0);
		ekonomickyAktivneObyvatelstvo_->add(-1);
		disponibilnyPocetUchadzacov_->add(-1);
	}
}


OkresVRoku::~OkresVRoku()
{
	delete mieraEvidovanejNezamestnanosti_;
	mieraEvidovanejNezamestnanosti_ = nullptr;

	delete ekonomickyAktivneObyvatelstvo_;
	ekonomickyAktivneObyvatelstvo_ = nullptr;

	delete disponibilnyPocetUchadzacov_;
	disponibilnyPocetUchadzacov_ = nullptr;
}

int OkresVRoku::getRok() {
	return rok_;
}

void OkresVRoku::setPocetZP(int data) {
	pocetZP_ = data;
}

int OkresVRoku::getPocetZP() {
	return pocetZP_;
}

void OkresVRoku::setPocetAsolventov(int data) {
	pocetAbsolventov_ = data;
}

int OkresVRoku::getPocetAbsolventov() {
	return pocetAbsolventov_;
}

void OkresVRoku::setPocetMladistvych(int data) {
	pocetMladistvych_ = data;
}

int OkresVRoku::getPocetMladistvych() {
	return pocetMladistvych_;
}

void OkresVRoku::setPocetDlhodobych(int data) {
	pocetDlhodobych_ = data;
}

int OkresVRoku::getPocetDlhodobych() {
	return pocetDlhodobych_;
}

void OkresVRoku::setMieraEvidovanejNezamestnanostiAtIndex(int index, double data) {
	(*mieraEvidovanejNezamestnanosti_)[index] = data;
}

double OkresVRoku::getMieraEvidovanejNezamestnanostiAtIndex(int index) {
	return (*mieraEvidovanejNezamestnanosti_)[index];
}

void OkresVRoku::setEkonomickyAktivneObvAtIndex(int index, int data) {
	(*ekonomickyAktivneObyvatelstvo_)[index] = data;
}

int OkresVRoku::getEkonomickyAktivneObvAtIndex(int index) {
	return (*ekonomickyAktivneObyvatelstvo_)[index];
}

void OkresVRoku::setDisponibilnyPocUchadzacovAtIndex(int index, int data) {
	(*disponibilnyPocetUchadzacov_)[index] = data;
}

int OkresVRoku::getDisponibilnyPocUchadzacovAtIndex(int index) {
	return (*disponibilnyPocetUchadzacov_)[index];
}

string OkresVRoku::vypisUchadzacov() {
	return "\nPocet uchadzacov o zamestnanie - ZP: " + to_string(getPocetZP())
		+ "\nPocet uchadzacov o zamestnanie - Absolventi: " + to_string(getPocetAbsolventov())
		+ "\nPocet uchadzacov o zamestnanie - Mladistvi: " + to_string(getPocetMladistvych())
		+ "\nPocet uchadzacov o zamestnanie - Dlhodobo ev.: " + to_string(getPocetDlhodobych())
		+ "\n";
}