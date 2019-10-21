# parserPESEL

parserPESEL is a simply script for validating PESEL numbers. <br /> <br />
PESEL (Polish Powszechny Elektroniczny System Ewidencji Ludności, Universal Electronic System for Registration of the Population) is the national identification number used in Poland since 1979. It always has 11 digits, identifies just one person and cannot be changed to another one (except some specific situations such as gender reassignment). <br />
The PESEL was the system designed by the communist government (during PRL) to trace personal information about every citizen. It is a direct offshoot from the previous system, MAGISTER (an acronym spelling out the word 'Master', like a master's degree), which was designed to trace and record data about everyone with a university degree. <br />
For more information please visit [Wikipedia](https://en.wikipedia.org/wiki/PESEL)

## Technology

This paresr is based on three modules: <br />
**skrypt.bat** - file launch management	**[BATCH]** <br />
**parserPESEL.exe** - the algorithm checks the correctness of the PESEL number **[C++]** <br />
**skrypt_parser.py** - creates reports **[Python]** <br />

## Getting Started

* To run the program, you need download last [release](https://github.com/dawbit/parserPESEL/releases) archive. The archive can be unziped anywhere on the disk.
* If you are a developer, clone repository and open it in preferred IDE for C++ and Python language.

## Installing

You need Windows operating system and Python 3.x shell to run .py, .bat and .exe files. You can download latest Python version for Windows [here](https://www.python.org/downloads/).

## Running the program

1 - Save the PESEL number in the **inX.txt** file in the **in** folder, where X is the next file number from 1 to n, n is a number of last file. <br />
For example: <br />

| file    	| content      	|
|---------	|--------------	|
| in1.txt 	| 98080424546  	|
| in2.txt 	| 00262843599  	|
| in3.txt 	| 92101997561  	|
| in4.txt 	| 65020300071  	|
| in5.txt 	| 99224427472  	|
| in6.txt 	| 970000123737 	|
| in7.txt 	| 20010100000  	|
| in8.txt 	| 221199126176 	|
| ...     	| ...          	|
<br />

2 - Run **skrypt.bat** <br />
3 - Wait until the **outX.txt** files are generated in the **out** folder, and until an HTML report is created and opened in your default web browser. <br />
If the pesel is correct, the output file will provide information about the date of birth and gender. Otherwise, information will be printed that the PESEL is incorrect.

## Built With

**[Dev-C++](https://sourceforge.net/projects/orwelldevcpp/)** - C++ IDE. <br />
**[TDM-GCC MinGW](https://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/)** - C++ Compiler. <br />
**[Notepad++](https://notepad-plus-plus.org/)** - for batch file. <br />
**[Python](https://www.python.org/downloads/)** - for Python shell. <br />
**[PyCharm](https://www.jetbrains.com/pycharm/)** - Python IDE. <br />

## Author

**dawbit** - **[GitHub Profile](https://github.com/dawbit)**

## License

The project is entirely free to use as it is an university project. 
