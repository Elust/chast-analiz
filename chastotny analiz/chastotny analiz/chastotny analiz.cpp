#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
// izmenenia
using namespace std;
//povtor
int main()
{
	int o = 0;
	cout << "changes";
	cout << "povtorniye izmenenia";
	ifstream f;
	f.open("C:\\1\\1.txt");    //открытие файла.


	string tmp, res;

	while (getline(f, tmp))     // пока не достигнут конец файла класть очередную строку в переменную (tmp)    //построчное сохранение в переменной res.
	{
		res += tmp;            // ресультат сохраняет каждую строку.
		res += '\n';           // ресультат сохраняет перенос по окончанию строки.
	}
	// Сейчас текст записан в стринг res!

///////////////////////////////////////////////


	int num = res.length();         //Длина нашего текста.(длина строки res)
	int *arr = new int[num];        //Динамический массив arr.


	int z = 0;  // счетчик количества одного и того же символа в тексте.

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {           //Записываем в массив arr для каждого символа количество его появлений в тексте.

			if (res[i] == res[j]) {
				z++;
			}
		}
		arr[i] = z;
		z = 0;
	}

	char *konres = new char[num];  // создаём новый массив, в который мы будем записывать результат.

   //////////////////////////// ...........................................................................................

	string polosa = " etoainshrdlcumvfgypbvkxjqz";

	for (int m = 0; m < 29; m++) {  //цикл букв


		int max = 0;  //счётчик для индекса.
		int maxsize = arr[0];         //изначально maxsize равно первому числу в arr.

		for (int i = 1; i < num; i++) {                          // maxsize - максимально большое число в arr!!! 
			if (arr[i] > maxsize) {
				maxsize = arr[i];       //если последующие числа больше нэнешнего maxsize, то они становяться maxsize.
				max = i;                                           //его индекс!!!
			}
		}


		char ch = res[max];          //присвоение ch максимального символа.!!

		//...........................
		if (ch == '.') {
			for (int i = 0; i < num; i++) {
				if (res[i] == ch) {
					konres[i] = '.';
					arr[i] = 0;
				}
			}
			o = o + 1;  // После этого на 1 назад в цикле.
			continue;   //Идём на следующий шаг цикла.
		}

		if (ch == ',') {
			for (int i = 0; i < num; i++) {
				if (res[i] == ch) {
					konres[i] = ',';
					arr[i] = 0;
				}
			}
			o = o + 1;  // После этого на 1 назад в цикле.
			continue;   //Идём на следующий шаг цикла.
		}


		//...........................//

		for (int i = 0; i < num; i++) {
			if (res[i] == ch) {          //если элемент равен ch (максимальному символу), то    //ЗАМЕНА.
				konres[i] = polosa[m - o];    //этот символ заменяем на нужный символ.
				arr[i] = 0;            //и заменяем число в arr на 0.
			}
		}
	} //конец цикла

	konres[num - 1] = ' ';

	/////////////////////////////

	cout << konres << endl;    // Вывод дешифрованного варианта.

	//ofstream h;
	//h.open("C:\\1\\2.txt");    //открытие файла.

	//h << konres;

	getch();

	return 0;
}


