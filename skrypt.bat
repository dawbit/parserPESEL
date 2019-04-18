@echo off
IF NOT EXIST in mkdir in 
IF NOT EXIST out mkdir out
IF NOT EXIST backup mkdir backup
echo Trwa uruchamianie programu parserPESEL.exe
parserPESEL.exe
echo parserPESEL.exe zakonczyl prace
echo Trwa uruchamianie skrypt_parser.py
py -u skrypt_parser.py
echo skrypt_parser.py zakonczyl prace
echo otwieranie raportu
pause
