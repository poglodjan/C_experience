// .h
using namespace std;
#include <string.h>
#include <iostream>
#include <iomanip>
#include <exception>

// ********************* Przedmiot *********************
class Przedmiot
{
protected:
    string nazwa;
    string opis;
public:
    Przedmiot(string _nazwa, string _opis);
    virtual ~Przedmiot(){};
    virtual void info(ostream&) const;
    friend ostream& operator<<(ostream&, const Przedmiot&);
};

class SymbolWiary : public Przedmiot
{
public:
	SymbolWiary(string nazwa, string opis);
	bool uzyj() const;
	void info(ostream&) const;
};

class Bron : public Przedmiot
{
protected:
	int obrazenia;
public:
	Bron(string nazwa, string opis, int obrazenia);
	virtual int atak_bronia() const;
	void info(ostream&) const;
};

// ********************* Zaklecia *********************
class Zaklecie
{
protected:
    string nazwa;
    int poziom_trudnosci;
public:
    Zaklecie(string nazwa, int poziom_trudnosci);
    virtual int wypowiedz_zaklecie() = 0;
    int jaki_poziom_trudnosci() const {return poziom_trudnosci;}
    void info(ostream&) const;
    friend ostream& operator<<(ostream&, const Zaklecie&);
};

class ZaklecieOfensywne : public Zaklecie
{
protected:
    int obrazenia;
public:
    ZaklecieOfensywne(string nazwa, int poziom_trudnosci, int dmg);
    int wypowiedz_zaklecie() override;
};

class ZaklecieDefensywne : public Zaklecie
{
protected:
    int odzyskane_punkty_zycia;
public:
    ZaklecieDefensywne(string nazwa,int poziom_trudnosci, int hp);
    int wypowiedz_zaklecie() override;
};

// ********************* Postacie *********************
class Kaplan
{
	static const int wielkosc_ekwipunku = 4;
	static const int ilosc_zaklec = 4;
	string imie;
	int punktyZycia = 30;
	int zrecznosc = 5;
	int sila = 5;
	int madrosc = 5;

	int sila_ataku;
	int poziom_ochrony;
	int ile_zaklec = 0;

	Bron* bron_w_rece;
	SymbolWiary* symbol_w_rece;

	Zaklecie* znane_zaklecia[ilosc_zaklec];

	Przedmiot* ekwipunek[wielkosc_ekwipunku];
	void modlitwa();
public:
	
	Kaplan(string imie);
	virtual ~Kaplan();
	void przygotuj_postac();
	int wykonaj_atak(int poziom_ochrony_przeciwnika);
	void przyjmij_atak(int obrazenia);

	int znajdz_zaklecie_ofensywne() const;
	int znajdz_zaklecie_defensywne() const;

	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	friend ostream& operator<<(ostream&, const Kaplan&);
};

class Skorpion
{	
protected:
	int punktyZycia = 15;
	int sila_ataku = 2;
	int poziom_ochrony = 2;

public:
	virtual ~Skorpion() {};
	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const = 0;
	void przyjmij_atak(int obrazenia);

	virtual void info(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Skorpion&);
};

class SkorpionOlbrzymi : public Skorpion
{
public:
	int wykonaj_atak(int poziom_ochrony_przeciwnika) const override;
	int atak_ostrym_odnozem() const;

	void info(ostream&) const override;
};

class JadowitySkorpionOlbrzymi : public SkorpionOlbrzymi
{
	static int ktory_atak;
public:
	JadowitySkorpionOlbrzymi();

	int wykonaj_atak(int poziom_ochrony_przeciwnika) const override;
	int atak_jadowitym_kolcem() const;

	void info(ostream&) const override;

};
