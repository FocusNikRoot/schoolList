/***************************
*                          *
*    Дата: 09.12.2021г.    *
*       Куликов А.М.       *
* Название:                *
*     Работа с файлами     *
*                          *
***************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct school {

	string name;
	string surname;
	int endYear;
	int schoolNumer;
	int math;
	int phys;
	int russ;
};

int main() {

	ifstream input("in.txt");

	system("chcp 1251");

	string str;
	school schoolList[200];
	int rowCount = 0, schoolCount = 0;
	int indexRow, schoolNumber, math = 0, phys = 0, russ = 0;

	while (getline(input, str)) {

		++rowCount;
	}
	input.close();

	input.open("in.txt");

	while (!input.eof()) {

		for (indexRow = 0; indexRow < rowCount; ++indexRow) {

			input >> schoolList[indexRow].schoolNumer;
			input >> schoolList[indexRow].surname;
			input >> schoolList[indexRow].name;
			input >> schoolList[indexRow].endYear;
			input >> schoolList[indexRow].math;
			input >> schoolList[indexRow].phys;
			input >> schoolList[indexRow].russ;

			cout << schoolList[indexRow].schoolNumer
				 << " " << schoolList[indexRow].surname
				 << " " << schoolList[indexRow].name 
				 << " " << schoolList[indexRow].endYear
				 << " " << schoolList[indexRow].math 
				 << " " << schoolList[indexRow].phys
				 << " " << schoolList[indexRow].russ
				 << endl;
		}
	}
	
	cout << "Введите номер школы: ";
	cin >> schoolNumber;

	for (indexRow = 0; indexRow < rowCount; ++indexRow) {

		if (schoolList[indexRow].schoolNumer == schoolNumber) {

			cout << schoolList[indexRow].schoolNumer
				 << " " << schoolList[indexRow].surname
				 << " " << schoolList[indexRow].name
				 << " " << schoolList[indexRow].endYear
				 << " " << schoolList[indexRow].math
				 << " " << schoolList[indexRow].phys
				 << " " << schoolList[indexRow].russ
				 << endl;

			++schoolCount;
			math += schoolList[indexRow].math;
			phys += schoolList[indexRow].phys;
			russ += schoolList[indexRow].russ;
		}
	}

	cout << "\n-------------------------------\nОбщий балл школы №" << schoolNumber
		 << ":\nМатематика: " << math
		 << "\nФизика: " << phys
		 << "\nРусский язык: " << russ
		 << "\nСредний балл: "
		 << "\nМатематика: " << math / schoolCount
		 << "\nФизика: " << phys / schoolCount
		 << "\nРусский язык: " << russ / schoolCount;
}