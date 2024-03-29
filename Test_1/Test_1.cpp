// Test_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));			

	int sel;
	vector<int> myVec;
	map<int, int> myMap;

	do {
		cout << endl << "### Menu ###" << endl;
		cout << "1) Заполнить vector" << endl;
		cout << "2) Заполнить map" << endl;
		cout << "3) Удалить случайное число элементов в vector" << endl;
		cout << "4) Удалить случайное число элементов в map" << endl;
		cout << "5) Синхронизировать элементы в vector и map" << endl;
		cout << "6) Выход" << endl;
		cout << "Ввод: "; cin >> sel; 
		cout << endl;

		switch (sel) {
			case 1: {
				int size;
				cout << "Введите количество элементов: "; cin >> size;

				FillVec(myVec, size);

				cout << "Заполненный vector:" << endl;
				copy(
					myVec.begin(),	
					myVec.end(), 
					ostream_iterator<int>(cout, "  ")
				);
				cout << endl;

				break;
			}
			case 2: {
				int size;
				cout << "Введите количество элементов: "; cin >> size;

				FillMap(myMap, size);

				cout << "Заполненный map:" << endl;
				for (auto it = myMap.begin(); it != myMap.end(); it++)
					cout << it->second << "  ";
				cout << endl;

				break;
			}
			case 3: {
				if (myVec.size() > 1) {
					cout << "Удалено  элементов: " << DelFromVec(myVec) << ". Vector:" << endl;
					copy(
						myVec.begin(),
						myVec.end(),
						ostream_iterator<int>(cout, "  ")
					);
					cout << endl;
				} 
				else
					cout << "В vector слишком мало элементов (< 2)!" << endl;

				break;
			}
			case 4: {
				if (myMap.size() > 1) {
					cout << "Удалено  элементов: " << DelFromMap(myMap) << ". Map:" << endl;
					for (auto it = myMap.begin(); it != myMap.end(); it++)
						cout << it->second << "  ";
					cout << endl;
				}
				else
					cout << "В map слишком мало элементов (< 2)!" << endl;

				break;
			}
			case 5: {
				if (myVec.size() > 0 && myMap.size() > 0) {
					Synch(myVec, myMap);

					cout << "Осталось элементов в vector: " << myVec.size() << ". Vector:"<< endl;
					copy(
						myVec.begin(),
						myVec.end(),
						ostream_iterator<int>(cout, "  ")
					);
					cout << endl;

					cout << "Осталось элементов в map: " << myMap.size() << ". Map: " << endl;
					for (auto it = myMap.begin(); it != myMap.end(); it++)
						cout << it->second << "  ";
					cout << endl;

				}
				else
					cout << "В одном из контейнеров отсутствуют элементы!" << endl;

				break;
			}
			case 6: { break; }
			default: {
				cout << "Введен неверный номер!" << endl;
				break;
			}
		} 

	} while (sel != 6);

    return 0;
}