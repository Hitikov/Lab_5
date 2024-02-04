#include <iostream>
#include <clocale>

using namespace std;

// Нахождение минимального элемента
int min_value(int m[100][100], int n)
{
	int mv = m[0][0];
	for (int i = 0; i < n; ++i) {
		if (m[i][i] < mv) {
			mv = m[i][i];
		}
	}
	return mv;
}

// Нахождение количества элементов удовледворяющих условию 
int value_count(int m[100][100], int n, int min)
{
	int ct = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] > min) {
				++ct;
			}
		}
	}
	return ct;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, mode;
	int mtr[100][100];

	// Указание длины катета массива в диапазоне от 1 до 50
	cout << "Введите размерность двумерного массива: ";
	do {
		cin >> n;
		if ((n > 50) || (n < 1)) {
			cout << "Не корректная размерность, повторите ввод: ";
		}
	} while ((n > 50) || (n < 1));
	cout << endl;

	// Создание массива
	cout << "Укажите режим создания массива: 1. ручной / 2. автоматический: ";
	do {
		cin >> mode;
		if ((mode != 1) && (mode != 2)) {
			cout << "Не корректное указание режима, повторите ввод: ";
		}
	} while ((mode != 1) && (mode != 2));
	cout << endl;

	switch (mode)
	{
	case 1:
		cout << "Вводите элементы массива: " << endl;
		for (int i = 0; i < n; ++i) {
			cout << "След. строка: ";
			for (int j = 0; j < n; ++j) {
				cin >> mtr[i][j];
			}
		}
		cout << endl;
		break;
	case 2:
		srand(time(0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				mtr[i][j] = rand() % 100;
			}
		}
		break;
	default:
		break;
	}

	// Вывод массива
	cout << "Полученный массив:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mtr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Количество элементов удовлетворяющих условию: " << value_count(mtr, n, min_value(mtr, n));

	return 0;
}