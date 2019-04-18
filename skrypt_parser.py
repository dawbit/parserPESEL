#!/usr/bin/python
# -*- coding: utf-8 -*-
import os, sys
import time  # timestamp
import datetime  # timestamp
import webbrowser  # przegladarka
import os  # pliki
import shutil  # foldery

for file in os.listdir("backup"):  # wszystkie pliki w folderze backup
    if file.endswith(".html"):  # jesli plik jest rozszerzenia html
        lastBackup = file  # to przypisz go do zmiennej lastBackup, ostatni plik to ostatni backup
        backupExists = True  # ustaw flage, ze backup istnieje

try:  # sprawdz czy zmienna lastBackup istnieje
    lastBackup
except NameError:  # jesli nie
    backupExists = False  # ustaw flage, ze to bedzie pierwszy backup

outFiles = []  # pusta lista przechowujaca wszystkie indeksy

for file in os.listdir("out"):  # wszystkie pliki w folderze out
    if file.startswith("out") and file.endswith(".txt"):  # jesli plik jest o nazwie out*.txt
        outFiles.append(file)  # to dopisz go do listy
        lastOut = True  # ustaw flage, ze ostatni plik wyjscia istnieje

for i in range(len(outFiles)):  # dla wszystkich plikow out nadpisz nazwe indeksami
    outFiles[i] = int(outFiles[i][3:len(outFiles[i])-4])  # outx.txt - usuwamy 3 pierwsze i 4 ostatnie, rzutowanie int

if not len(outFiles):  # jesli lista plikow wyjsciowych jest pusta
    lastOut = False  # ustaw flage, ze zaden plik wyjsciowy nie istnieje

if lastOut:  # jesli plik wyjsciowy istnieje
    index = max(outFiles)  # to ustaw index jako maksymalny

ts = time.time()  # timestamp
st = datetime.datetime.fromtimestamp(ts).strftime("%Y-%m-%d_%H-%M-%S")  # konwersja timestampu na date

fileOut = open("backup/" + st + ".html", "a+")  # stworz nowy plik backup z data

if backupExists:  # jesli jakis backup istnieje
    fileTemp = open("backup/" + lastBackup).read()  # skopiuj zawartosc poprzedniego backupu do zmiennej tymczasowej
    shutil.copyfile("backup/" + lastBackup, "backup/" + st + ".html")  # skopiuj ostatni backup do nowego pliku
    while index:  # poki dzialamy na indeksach (od ostatniego indeksu wyjscia do 1)
        iTemp = "<tr id=" + str(index)  # string oznaczajacy wpis wiersza w HTML o podanym indeksie (np. dla out3 to 3)
        if iTemp in fileTemp:  # jesli znalazl
            indexTemp = fileTemp.index(iTemp) + 7  # pomin <tr id= i przejdz do liczby
            i = int(fileTemp[indexTemp:indexTemp + len(str(index))]) + 1  # index + 1, bo taki index juz mamy
            break
        index -= 1  # a jesli nie znalazl to zmniejsza index (czyli sprawdza out2, wedlug przykladu)
    del fileTemp  # zwolnij pamiec, tej zmiennej nie bedziemy juz uzywac
    del iTemp  # zwolnij pamiec, tej zmiennej nie bedziemy juz uzywac
    del indexTemp  # zwolnij pamiec, tej zmiennej nie bedziemy juz uzywac
    del index  # zwolnij pamiec, tej zmiennej nie bedziemy juz uzywac

else:  # jesli jednak backup nie istnieje
    fileOut.write("<html><head><meta charset='utf-8' />"
				  "<link rel='Stylesheet' href='../css/style.css'><script>var url = window.location.pathname; "
                  "var file = url.substring(url.lastIndexOf('/')+1);"
                  "filename = file.substr(0, file.length - 5);"
                  "document.title = 'Backup ' + filename;</script><meta charset='UTF-8'>"
                  "</head><body><h1>"
                  "<script>document.write(document.title)</script></h1>"
				  "<h2>Dawid Bitner IA</h2>"
				  "<h3>parser PESEL - jezyki skryptowe - projekt</h3>"
                  "<table>"
                  "<tr><th>Input</th><th>Output</th></tr>")  # to stworz nowy plik HTML
    i = 1  # i ustaw zmienna indeksu na 1

while True:
    try:  # sprawdz czy sie pliki otworza
        fileInput = open("in/in" + str(i) + ".txt", "r")
        fileOutput = open("out/out" + str(i) + ".txt", "r")
    except FileNotFoundError as e:  # warunek stopu, jesli pliki sie nie otworza to konczy program
        break

    fileOut.write("<tr id=" + str(i) + "><td style='width:10%; text-align:center'>" + fileInput.readline() + "</td><td>"
                  + fileOutput.read()+"</td></tr>")  # wpisz zawartosc plikow in i out do tabeli

    i += 1  # powieksz iterator
    fileInput.close()  # zamknij plik wejsciowy
    fileOutput.close()  # zamknij plik wyjsciowy

fileOut.close()  # jesli warunek stopu zostanie spelniony (wyjdzie z petli) to zamknij plik backup
webbrowser.open("file://" + os.path.realpath(fileOut.name))  # otworz przegladarke
