using namespace std;
#include <string.h>
#include <iostream>
#include <iomanip>
#include <exception>
#include "test.cpp"


// ****************** Przedmioty ******************
Przedmiot::Przedmiot(string nazwa, string opis) : nazwa(nazwa), opis(opis) {}

void Przedmiot::info(ostream& out) const
{
	out << nazwa << " (" << opis << ") ";
}
ostream& operator<<(ostream& out, const Przedmiot& p)
{
	p.info(out);
	out << endl;
	return out;
}

// bron
Bron::Bron(string nazwa, string opis, int obrazenia) : Przedmiot(nazwa, opis), obrazenia(obrazenia) {}
int Bron::atak_bronia() const {return obrazenia;}

void Bron::info(ostream& out) const {
	Przedmiot::info(out);
	out << "Obrazenia: " << obrazenia;
}

// symbol wiary
SymbolWiary::SymbolWiary(string nazwa, string opis) : Przedmiot(nazwa, opis) {}

bool SymbolWiary::uzyj() const {
	cout << "Symbol wiary rozswietla wszystko dookola - Bostwo slucha - Czas na modlitwe!\n";
	return true;
}
void SymbolWiary::info(ostream& out) const {
	Przedmiot::info(out);
}

// ****************** Zaklecia ******************
Zaklecie::Zaklecie(string nazwa,  int poziom_trudnosci) : nazwa(nazwa), poziom_trudnosci(poziom_trudnosci) {}
void Zaklecie::info(ostream& out) const
{
	out << nazwa << " (poziom " << poziom_trudnosci << ") ";
}
ostream& operator<<(ostream& out, const Zaklecie& p)
{
	p.info(out);
	out << endl;
	return out;
}

// ZaklecieOfensywne
ZaklecieOfensywne::ZaklecieOfensywne(string nazwa, int poziom_trudnosci, int dmg) : Zaklecie(nazwa, poziom_trudnosci), obrazenia(dmg) {}
int ZaklecieOfensywne::wypowiedz_zaklecie() {
	return obrazenia;
}

// ZaklecieDefensywne
ZaklecieDefensywne::ZaklecieDefensywne(string nazwa, int poziom_trudnosci, int hp) : Zaklecie(nazwa, poziom_trudnosci), odzyskane_punkty_zycia(hp) {}
int ZaklecieDefensywne::wypowiedz_zaklecie() {
	return odzyskane_punkty_zycia;
}


// ****************** Postacie ******************
// skorpion

int JadowitySkorpionOlbrzymi::ktory_atak = 0;

void Skorpion::przyjmij_atak(int obrazenia){punktyZycia -= obrazenia;}
ostream& operator<<(ostream& out, const Skorpion& p)
{
	p.info(out);
	return out;
}

// Klasa SkorpionOlbrzymi
int SkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const {
	if (sila_ataku > poziom_ochrony_przeciwnika)
		return atak_ostrym_odnozem();
	return 0;
}
int SkorpionOlbrzymi::atak_ostrym_odnozem() const {
	return 2;
}
void SkorpionOlbrzymi::info(ostream& out) const {
	out << "Skorpion Olbrzymi - poziom ochrony: " << poziom_ochrony << 
    " punkty zycia: " << punktyZycia << "\n";
}

// Klasa JadowitySkorpionOlbrzymi
JadowitySkorpionOlbrzymi::JadowitySkorpionOlbrzymi() {
	sila_ataku *= 2;
	punktyZycia *= 2;
	poziom_ochrony *= 2;
}
int JadowitySkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const {
	++ktory_atak;
	if (ktory_atak % 2 == 0)
		return atak_jadowitym_kolcem();
	else if (sila_ataku > poziom_ochrony_przeciwnika)
		return atak_ostrym_odnozem();

	return 0;
}
int JadowitySkorpionOlbrzymi::atak_jadowitym_kolcem() const {
	return 4 * atak_ostrym_odnozem();
}
void JadowitySkorpionOlbrzymi::info(ostream& out) const {
	out << "Jadowity ";
	SkorpionOlbrzymi::info(out);
}

////////////////////////////// 
// kaplan
//////////////////////////////
void Kaplan::modlitwa() {
	if (symbol_w_rece != nullptr && symbol_w_rece->uzyj()) {
		ile_zaklec = madrosc;
	}
}
Kaplan::Kaplan(string imie) : imie(imie)
{
	sila_ataku = sila;
	poziom_ochrony = zrecznosc;
	bron_w_rece = nullptr;
	symbol_w_rece = nullptr;
	for (int i = 0; i < wielkosc_ekwipunku; i++)
		ekwipunek[i] = nullptr;
	ekwipunek[0] = new Bron("Miecz", "klasyczny miecz jednoreczny", 3);
	ekwipunek[1] = new SymbolWiary("Pierscien z granitem", "pierscien z symbolem zywiolu ziemi");
	ekwipunek[2] = new Bron("Sztylet", "sztylet krotki", 1);

	for (int i = 0; i < ilosc_zaklec; i++)
		znane_zaklecia[i] = nullptr;
	znane_zaklecia[0] = new ZaklecieOfensywne("Lodawa strzala", 2, 5);
	znane_zaklecia[1] = new ZaklecieDefensywne("Leczniczy dotyk", 1, 4);
	znane_zaklecia[2] = new ZaklecieOfensywne("Widmowe Ostrza", 1, 2);
	znane_zaklecia[3] = new ZaklecieOfensywne("Ognisty deszcz", 7, 10);
}
Kaplan::~Kaplan() {
	delete bron_w_rece;
	delete symbol_w_rece;

	for (int i = 0; i < ilosc_zaklec; ++i) 
		delete znane_zaklecia[i];

	for (int i = 0; i < wielkosc_ekwipunku; ++i)
		delete ekwipunek[i];
}
void Kaplan::przygotuj_postac() {
	for (int i = 0; i < wielkosc_ekwipunku; ++i) {
		bron_w_rece = dynamic_cast<Bron*>(ekwipunek[i]);  // dynia
		if (bron_w_rece != nullptr) {
			ekwipunek[i] = nullptr;
			break;
		}
	}

	for (int i = 0; i < wielkosc_ekwipunku; ++i) {
		symbol_w_rece = dynamic_cast<SymbolWiary*>(ekwipunek[i]);
		if (symbol_w_rece != nullptr) {
			ekwipunek[i] = nullptr;
			break;
		}
	}
	modlitwa();
}
int Kaplan::wykonaj_atak(int poziom_ochrony_przeciwnika) {
	if (punktyZycia < 15 && znajdz_zaklecie_defensywne() != -1) {
		punktyZycia += znane_zaklecia[znajdz_zaklecie_defensywne()]->wypowiedz_zaklecie();
		--ile_zaklec;

		return 0;
	}
	if (znajdz_zaklecie_ofensywne() != -1) {
		int i = znajdz_zaklecie_ofensywne();
		--ile_zaklec;
		
		return znane_zaklecia[i]->wypowiedz_zaklecie();
	}
	if (sila_ataku > poziom_ochrony_przeciwnika)
		return bron_w_rece->atak_bronia();

	return 0;
}
void Kaplan::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}
int Kaplan::znajdz_zaklecie_ofensywne() const {
	if (ile_zaklec == 0) return -1;

	for (int i = 0; i < ilosc_zaklec; ++i) {
		ZaklecieOfensywne* spell = dynamic_cast<ZaklecieOfensywne*>(znane_zaklecia[i]);
		if (spell != nullptr)
			return i;
	}

	return -1;
}
int Kaplan::znajdz_zaklecie_defensywne() const {
	if (ile_zaklec == 0) return -1;

	for (int i = 0; i < ilosc_zaklec; ++i) {
		ZaklecieDefensywne* spell = dynamic_cast<ZaklecieDefensywne*>(znane_zaklecia[i]);
		if (spell != nullptr)
			return i;
	}

	return -1;
}
ostream& operator<<(ostream& out, const Kaplan& p)
{
	out << p.imie << " - calkowita sila ataku: " << p.sila_ataku << " calkowity poziom ochrony: " << p.poziom_ochrony << " punkty zycia: " << p.punktyZycia << " liczba zaklec: " << p.ile_zaklec << endl;
	for (int i = 0; i < p.wielkosc_ekwipunku; i++)
	{
		if (p.ekwipunek[i])
			out << i+1 << ". " << *p.ekwipunek[i];
		else
			out << i+1 << ". " << "pusto" << endl;
	}
	return out;
}



