// реализация пользовательского приложения
#include <string>
#include "iostream"
#include "arithmetic.h"

using namespace std;
int main()
{
	int q = 0;
	string b; string a; int res;
	int k = 0;
	while (k == 0) {
		cout << "Write your string" << endl;
		getline(cin, b);
	 a = DellProbel(b);
	 if (a != b)
		 cout << " String without probels" << endl << a << endl;
		k = ChekString(a);
	}
	Arifmetic A(a);
	A.GetArrLexOne();
	A.PrintArrLex();
	A.GetArrLexTwo();
	A.PrintArrLex2();
	while (q != 2)
	{
		q=A.Lala();
		A.Calculete();
		if (q != 2)
		{
			cout << "If you want to change the variables, press 1, else 2" << endl;
			cin >> q;
		}
	}
  return 0;
}
//проверка на корректность строки
// создание массива лексем 
// преобразование массива лексем с помощью двух стеков в отсортированный массив лексем без ( ) 
// Этап вычисления - сбор данных о переменных , вычисление, представить возможность ввода других переменных
//вывод результата
