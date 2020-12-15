// pavlovskaya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Для хранения данных о ноутбуках описать структуру вида, описанного в варианте
10.
Написать функцию, которая читает данные о ноутбуках из файла note.txt (см.
с. 158) в структуру приведенного вида. Написать функцию, которая записывает
содержимое структуры в конец бинарного файла. Структура бинарного файла:
первые два байта (целое) — число записей в файле; далее записи в формате
структуры NOTEBOOK.
Написать программу, в которой на основе разработанных функций осуществляется
запись в двоичный файл данных только о тех ноутбуках, максимальный объем
ОЗУ которых не менее 40 Мбайт, отсортированных по объему.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct NOTEBOOK {
	struct disp__res { // разрешающая способность дисплея
		int х; // по горизонтали
		int у; // по вертикали
	}disp;
	int o; //оперативная память
	int f; // частота регенерации
	float d; // размер диагонали дисплея
	int price; // цена
	char model[21]; // наименование

	//void printf()
	//{

	//	cout << model << '\t';
	//	cout << disp.х << '\t';
	//	cout << disp.у << '\t';
	//	cout << f << '\t';
	//	cout << d << '\t';
	//	cout << price << '\t';
	//	cout << o << '\t';
	//
	//}
	void printf()
	{
		ofstream note_file("notes");
		note_file<< model << '\t';
		note_file << disp.х << '\t';
		note_file << disp.у << '\t';
		note_file << f << '\t';
		note_file << d << '\t';
		note_file << price << '\t';
		note_file << o << '\t';
		note_file.close();
	}
};

void newNotes(NOTEBOOK  notes[4]);

void printf(NOTEBOOK  notes[4], int i);

void sortBubble(NOTEBOOK  notes[4]);

void savetoBinar(NOTEBOOK  notes[4]);

void printfNote(NOTEBOOK  notes[4]);

void readfromBinar(NOTEBOOK  notes[4]);

int main()
{
	NOTEBOOK notes[4];
	newNotes(notes);
	for (int i = 0; i < 4; i++) {
		notes[i].printf();
	}
	printfNote(notes);
	sortBubble(notes);
	printfNote(notes);
	cout << endl;
	savetoBinar(notes);
	readfromBinar(notes);
	printfNote(notes);
	return 0;

}

void readfromBinar(NOTEBOOK  notes[4])
{
	ifstream note_file("notes");
	int num;
	note_file.read((char*)&num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		note_file.read((char*)&notes[i], sizeof(NOTEBOOK));
	}
	note_file.close()

}

void printfNote(NOTEBOOK  notes[4])
{
	for (int i = 0; i < 4; i++)
	{
		notes[i].printf();
		cout << endl;

	}
}

void savetoBinar(NOTEBOOK  notes[4])
{
	int num = 4;
	ofstream note_file("notes");
	note_file.write((char*)&num, sizeof(int));
	for (int i = 0; i < 4; i++)
	{
		note_file.write((char*)&notes[i], sizeof(NOTEBOOK));
	}
}

void sortBubble(NOTEBOOK  notes[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i - 1; j++)
		{
			/*if (notes[i].o >= 40)*/ {
				if (notes[j].o > notes[j + 1].o)
				{
					NOTEBOOK temp = notes[j];
					notes[j] = notes[j + 1];
					notes[j + 1] = temp;
					cout << endl;
				}
			}
		}
	}
}



void newNotes(NOTEBOOK  notes[4])
{
	strcpy_s(notes[0].model, "Acer Note Light");
	notes[0].disp.х = 1024;
	notes[0].disp.у = 768;
	notes[0].f = 100;
	notes[0].d = 10.4;
	notes[0].price = 2699;
	notes[0].o = 40;

	strcpy_s(notes[1].model, "ASW ND5123T");
	notes[1].disp.х = 1024;
	notes[1].disp.у = 768;
	notes[1].f = 133;
	notes[1].d = 12.1;
	notes[1].price = 3489;
	notes[1].o = 32;

	strcpy_s(notes[2].model, "ARMNote TS80CD");
	notes[2].disp.х = 1024;
	notes[2].disp.у = 768;
	notes[2].f = 133;
	notes[2].d = 11.3;
	notes[2].price = 3699;
	notes[2].o = 64;

	strcpy_s(notes[3].model, "AST Ascent1a P50");
	notes[3].disp.х = 800;
	notes[3].disp.у = 600;
	notes[3].f = 133;
	notes[3].d = 11.3;
	notes[3].price = 4499;
	notes[3].o = 40;

}
