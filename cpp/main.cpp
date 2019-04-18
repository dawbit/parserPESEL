#include "pesel.h"

int main(){
    pesel Pesel;

    char PESEL[12] = "";	// prawid³owy numer PESEL ma dok³adnie 11 cyfr, wystarczy ¿e jest d³u¿szy o 1 cyfra ¿eby by³ nieprawid³owy
    int i;

	/*rozwi¹zanie problemu za:
	https://stackoverflow.com/questions/26475540/c-having-problems-with-a-simple-example-of-findfirstfile */

    string DATA_DIR = "out/out*.*"; // wyszukaj tylko pliki out*.* w folderze out; mo¿e byæ out/out*.txt, bo tekstowy
    string lastFile = ""; // tworzenie stringu, rownie dobrze moze byc samo string lastFile;

    HANDLE hFind; // uchwyt
    WIN32_FIND_DATAA data; // https://docs.microsoft.com/en-us/windows/desktop/api/minwinbase/ns-minwinbase-_win32_find_dataa

    hFind = FindFirstFileA(DATA_DIR.c_str(), &data); // https://docs.microsoft.com/en-us/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea

    if(hFind != INVALID_HANDLE_VALUE){
        while(FindNextFile(hFind, &data)); // czytanie kazdego pliku, ostatni zostanie zapisany w data
        lastFile = data.cFileName; // lastFile to nazwa pliku
        FindClose(hFind); // zamknij handler
    }

	if(lastFile.length()){ // jesli to nie jest pusty string, czyli jesli istnieje juz jakis out
		lastFile = lastFile.substr(3, lastFile.length() - 4 - 3); // 4 = ".txt"; 3 = "out"
		 i = atoi(lastFile.c_str()) + 1; // string -> char[] -> int
	}
	else // jesli jednak zaden out nie istnieje
		i = 1; // to zacznij od pierwszego

		cout << lastFile;

    do{
		stringstream ss; // z <sstream>, int to string
		ss << i; // z <sstream>, int to string

		//---OTWIERANIE PLIKU WEJSCIOWEGO---//
        string filenameInput = "in/in" + ss.str(); // inX.txt, gdzie X to kolejny iterator
		filenameInput += ".txt"; // inX.txt, gdzie X to kolejny iterator

		ifstream fileInput;
		fileInput.open(filenameInput.c_str(), ios::in);

		//---WARUNEK STOPU---//
		if(!fileInput.is_open()){ // je¿eli plik nie istnieje to zakoñcz
            return 0;
		}

		//---CZYTANIE Z PLIKU---//
        fileInput>>PESEL;
        fileInput.close();

        Pesel.PeselValidator(PESEL); // funkcja uruchamiaj¹ca walidator -> pesel.cpp

		//---TWORZENIE DANYCH WYJŒCIOWYCH---//
        string filenameOutput = "out/out" + ss.str();
		filenameOutput += ".txt";
		ofstream fileOutput;
		fileOutput.open(filenameOutput.c_str(), ios::out);


        if (Pesel.valid == 1) {
            fileOutput<<"Numer PESEL jest prawidlowy\n";
            fileOutput<<"Rok urodzenia: "<<Pesel.getBirthYear()<<"\n";
            fileOutput<<"Miesiac urodzenia: "<<Pesel.getBirthMonth()<<"\n";
            fileOutput<<"Dzien urodzenia: "<<Pesel.getBirthDay()<<"\n";
            fileOutput<<"Plec: "<<Pesel.getSex()<<"\n";
        }
        else  {
            fileOutput<<"Numer PESEL jest nieprawidlowy\n";
        }
        i++; // zwiêksza iterator, outX.txt
    }while(true);

    return 0;
}
