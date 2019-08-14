#pragma once

struct Karty 
{
	int cisloKarty;
	char * const barva;
	int hodnota;
	char * const nazev;
}

Balicek[32] =
{
	{ 0, "Zaludy", 7, "7" },
	{ 1, "Zaludy", 8, "8" },
	{ 2, "Zaludy", 9, "9" },
	{ 3, "Zaludy", 10, "10" },
	{ 4, "Zaludy", 1, "Spodek" },
	{ 5, "Zaludy", 1, "Svrsek" },
	{ 6, "Zaludy", 2, "Kral" },
	{ 7, "Zaludy", 11, "Eso" },

	{ 8, "Kule", 7, "7" },
	{ 9, "Kule", 8, "8" },
	{ 10, "Kule", 9, "9" },
	{ 11, "Kule", 10, "10" },
	{ 12, "Kule", 1, "Spodek" },
	{ 13, "Kule", 1, "Svrsek" },
	{ 14, "Kule", 2, "Kral" },
	{ 15, "Kule", 11, "Eso" },

	{ 16, "Srdce", 7, "7" },
	{ 17, "Srdce", 8, "8" },
	{ 18, "Srdce", 9, "9" },
	{ 19, "Srdce", 10, "10" },
	{ 20, "Srdce", 1, "Spodek" },
	{ 21, "Srdce", 1, "Svrsek" },
	{ 22, "Srdce", 2, "Kral" },
	{ 23, "Srdce", 11, "Eso" },

	{ 24, "Listy", 7, "7" },
	{ 25, "Listy", 8, "8" },
	{ 26, "Listy", 9, "9" },
	{ 27, "Listy", 10, "10" },
	{ 28, "Listy", 1, "Spodek" },
	{ 29, "Listy", 1, "Svrsek" },
	{ 30, "Listy", 2, "Kral" },
	{ 31, "Listy", 11, "Eso" }
};