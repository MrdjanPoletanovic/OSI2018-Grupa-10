#include "signUp.h"

void signUp()
{
    string korisnickoIme = "", lozinka = "";
    bool controlIme, controlLozinka;

    cout << "*** Molim unesite korisnicko ime koristeci alfanumericke znakove i simbole tacka (.) ili donja crta (_)";
    cout << std::endl << "*** Molim unesite sigurnu lozinku koristeci alfanumericke znakove." << std::endl;

    do
    {
        controlIme = true;
        controlLozinka = true;

        cin.sync();
        cout << "\nMolim unesite korisnicko ime: ";
        cin >> korisnickoIme;

        for (int j = 0; j < (int)korisnickoIme.length(); j++)
            if (!(isalpha(korisnickoIme.at(j)) || isdigit(korisnickoIme.at(j)) || korisnickoIme.at(j) == '_' || korisnickoIme.at(j) == '.'))
                controlIme = false;

        cin.sync();
        cout << "Molim unesite lozinku: ";
        cin >> lozinka;

        for (int j = 0; j < (int)lozinka.length(); j++)
            if (!(isalpha(lozinka.at(j)) || isdigit(lozinka.at(j))))
                controlLozinka = false;

        cout << std::endl;

        if (!controlIme)
            cout << "Unijeli ste ime u pogresnom formatu.\n";

        if (!controlLozinka)
            cout << "Unijeli ste lozinku u pogresnom formatu.\n";
    }
    while (!controlIme || !controlLozinka);

    std::ifstream datotekaSaNalozima;
    datotekaSaNalozima.open("nalozi.csv");

    string compareUsername, demPassword;
    bool control = true;

    if (datotekaSaNalozima.is_open())
        while(!datotekaSaNalozima.eof())
        {
            getline(datotekaSaNalozima, compareUsername, ',');
            getline(datotekaSaNalozima, demPassword);

            if (!korisnickoIme.compare(compareUsername))
            {
                cout << "\nKorisnicko ime vec postoji.\n";
                control  = false;
                break;
            }
        }

    datotekaSaNalozima.close();

    std::ofstream datotekaSaNalozimaUpis;
    datotekaSaNalozimaUpis.open("nalozi.csv", std::ios::app);

    if (control)
        datotekaSaNalozimaUpis << korisnickoIme << ',' << lozinka << '\n';

    datotekaSaNalozimaUpis.close();

    return;
}

