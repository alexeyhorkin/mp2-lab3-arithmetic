// реализация пользовательского приложения
#include <string>
#include "iostream"
#include "arithmetic.h"

using namespace std;
int main()
{
	int q = 0;
	string a; int res; Lexem *LexemPtr;
	int k = 0;
	while (k == 0) {
		cout << "Write your string" << endl;
		cin >> a;
		k = ChekString(a);
	}
	Arifmetic A(a);
	A.GetArrLexOne();
	A.PrintArrLex();
	A.GetArrLexTwo();
	A.PrintArrLex2();
	while (q != 2)
	{
		A.Lala();
		A.Calculete();
		cout << "If you want to change the variables, press 1, else 2" << endl;
		cin >> q;
	}


  return 0;
}
//проверка на корректность строки
// создание массива лексем 
// преобразование массива лексем с помощью двух стеков в отсортированный массив лексем без ( ) 
// Этап вычисления - сбор данных о переменных , вычисление, представить возможность ввода других переменных
//вывод результата
