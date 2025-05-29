///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

/**
 * @brief Verschlüsselt ein Wort mithilfe einer Look-up-Tabelle.
 *
 * @param schluessel Die Look-up-Tabelle mit Klartext- und Geheimzeichen.
 * @param wort Das zu verschlüsselnde Wort.
 * @return Das verschlüsselte Wort.
 */


string verschluesseln(char schluessel[2][26], string wort)
{
	string geheim = ""; // leere String

	for (int i = 0; i < wort.length(); i++){

		char buchstabe = wort[i];
		for(int j = 0; j<26; j++){

			if(schluessel[0][j] == buchstabe){ //Buchstabe (wie zB A) wird im Alphabet untersucht, dann
				geheim += schluessel[1][j];		//Wort aus der geheimtext (im Geheimtext == Q) gewählt
				break;
			}
		}

	}


	return geheim;
}

string entschluesseln(char schluessel[2][26], string wort)	//umkehr aufgabe von verschlusseln funktion
{
	string klar = ""; // leere String

	for(int i = 0; i < wort.length(); i++){

		char buchstabe = wort[i];
		for(int j = 0; j < 26; j++){

			if(schluessel[1][j] == buchstabe){

				klar += schluessel[0][j];
				break;
			}
		}
	}

	return klar;
}

int main()
{
	char schluessel[2][26]; //UNSERE TABELLE

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string geheimtext = "QWERTYUIOPASDFGHJKLZXCVBNM";


	for(int i = 0; i<26; i++){

		schluessel[0][i] = alphabet[i];
		schluessel[1][i] = geheimtext[i];
	}


	string eingabe; //eingabe == wort
		cout << "Geben Sie ein Wort in GROSSBUCHSTABEN ein: ";
		cin >> eingabe;

		string verschluesselt = verschluesseln(schluessel, eingabe);
		cout << "Verschluesselt: " << verschluesselt << endl;

		string entschluesselt = entschluesseln(schluessel, verschluesselt);
		cout << "Entschluesselt: " << entschluesselt << endl;


	return 0;
}
