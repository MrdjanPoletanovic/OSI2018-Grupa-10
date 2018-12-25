// Definicija strukture i tipa za jedno pitanje.
typedef struct pitanja_odgovori
{
	int redniBrojPitanja;
	string pitanje;
	string odgovori[3];
	int tacanOdgovor;
} PITANJA;

// Funkcija za formatiran upis pitanja i odgovora u fajl "pitanja.csv".
void pisanjePitanjaCSV();


// Funkcija za ispis jednog pitanja sa ponudjenim odgovorima na izlaz.
void pisiPitanjeIOdgovore(PITANJA X, int Y);

// Funkcija koja vraca TRUE ako registruje pritisak na dugme i upisuje pritisnuto dugme na adresu karaktera 'prviKarakter' ili vraca FALSE ako dugme nije pritisnuto prije zavrsnog vremena.
bool pritisakNaDugme(DWORD zavrsnoVrijeme, char &prviKarakter);

// Funkcija koja se poziva u glavnom programu za izvrsavanje citavog modula
int kviz();