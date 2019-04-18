#include "pesel.h"

pesel::pesel()
{
    //ctor
}

pesel::~pesel()
{
    //dtor
}

//https://pl.wikipedia.org/wiki/PESEL

int pesel::getBirthYear(){
	/*Numeryczny zapis daty urodzenia przedstawiony jest w następującym porządku: dwie ostatnie cyfry roku, miesiąc i dzień. 
	Dla odróżnienia poszczególnych stuleci przyjęto następującą metodę kodowania:

    dla osób urodzonych w latach 1900 do 1999 – miesiąc zapisywany jest w sposób naturalny, tzn. dwucyfrowo od 01 do 12
    dla osób urodzonych w innych latach niż 1900–1999 dodawane są do numeru miesiąca następujące wielkości:
        dla lat 1800–1899 – 80
        dla lat 2000–2099 – 20
        dla lat 2100–2199 – 40
        dla lat 2200–2299 – 60.*/
		
    int year;
    int month;

    year = 10 * PESEL[0];
    year += PESEL[1];
    month = 10 * PESEL[2];
    month += PESEL[3];

    if (month > 80 && month < 93){
        year += 1800;
    }
    else
        if (month > 0 && month < 13){
            year += 1900;
        }
    else
        if (month > 20 && month < 33){
            year += 2000;
        }
    else
        if (month > 40 && month < 53){
            year += 2100;
        }
    else
        if (month > 60 && month < 73){
            year += 2200;
        }
    return year;
}

int pesel::getBirthMonth(){
    int month;
    month = 10 * PESEL[2];
    month += PESEL[3];

    if (month > 80 && month < 93){
        month -= 80;
    }
    else
        if (month > 20 && month < 33){
            month -= 20;
        }
    else
        if (month > 40 && month < 53){
            month -= 40;
        }
    else
        if (month > 60 && month < 73){
            month -= 60;
        }
    return month;
}

int pesel::getBirthDay(){
    int day;

    day = 10 * PESEL[4];
    day += PESEL[5];

    return day;
}

const char* pesel::getSex(){
	/*Informacja o płci osoby, której zestaw informacji jest identyfikowany, zawarta jest na 10. (przedostatniej) pozycji numeru PESEL.

    cyfry 0, 2, 4, 6, 8 – oznaczają płeć żeńską
    cyfry 1, 3, 5, 7, 9 – oznaczają płeć męską

	Po zmianie płci przydzielany jest nowy numer PESEL*/
	
    if (valid){
        if (PESEL[9] % 2 == 1) {
            return "Mezczyzna";
        }
    else{
        return "Kobieta";
    }
	}
	else{
		return "-";
	}
}

int pesel::checkSum(){
	/*Jedenasta cyfra jest cyfrą kontrolną, służącą do wychwytywania przekłamań numeru. Jest ona generowana na podstawie pierwszych dziesięciu cyfr. 
	Aby sprawdzić czy dany numer PESEL jest prawidłowy, należy, zakładając, że litery a-j to kolejne cyfry numeru od lewej, obliczyć wyrażenie:
	9×a + 7×b + 3×c + 1×d + 9×e + 7×f + 3×g + 1×h + 9×i + 7×j
	Jeżeli ostatnia cyfra otrzymanego wyniku nie jest równa cyfrze kontrolnej, to znaczy, że numer zawiera błąd*/
	
    int sum = 9 * PESEL[0] +
    7 * PESEL[1] +
    3 * PESEL[2] +
    1 * PESEL[3] +
    9 * PESEL[4] +
    7 * PESEL[5] +
    3 * PESEL[6] +
    1 * PESEL[7] +
    9 * PESEL[8] +
    7 * PESEL[9];
    sum  = sum % 10;

    if (sum == PESEL[10]) return 1;
    else  return 0;
}

int pesel::checkMonth(){
    int month = getBirthMonth();

    if (month > 0 && month < 13){
        return 1;
    }
    else{
        return 0;
    }
}

int pesel::checkDay(){
    int year = getBirthYear();
    int month = getBirthMonth();
    int day = getBirthDay();
    if ((day > 0 && day < 32) &&
        (month == 1 || month == 3 || month == 5 ||
        month == 7 || month == 8 || month == 10 ||
        month == 12)) {
        return 1;
    }
    else
        if ((day > 0 && day < 31) &&
            (month == 4 || month == 6 || month == 9 ||
            month == 11)) {
            return 1;
        }
    else
        if ((day > 0 && day < 30 && leapYear(year)) || // warunk co do roku przestępnego
            (day > 0 && day < 29 && !leapYear(year))) {
            return 1;
        }
    else{
        return 0;
    }
}

int pesel::leapYear(int year){
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

void pesel::PeselValidator(char *PESELNumber){
    int i;

    if (strlen(PESELNumber) != 11){
        valid = 0;
    }
    else{
        for (i = 0; i < 11; i++){
            PESEL[i] = PESELNumber[i] - 48;		//char to int, wg. tablicy ASCII aby tego dokonoać odejmujemy 48
        }
    if (checkSum() && checkMonth() && checkDay()){
        valid = 1;
    }
    else{
        valid = 0;
    }
	}
}
