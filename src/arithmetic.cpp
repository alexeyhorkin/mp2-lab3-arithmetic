// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"



Lexem& Lexem::operator = (const Lexem&b) {
	if (this != &b)
	{
		OPER = b.OPER;
		VAR = b.VAR;
		priority = b.priority;
		type = b.type;
		LStr = b.LStr;
	}
	return *this;
}

string DellProbel(const string a) {
	string b("\0");
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != ' ')
			b.push_back(a[i]);
	}
	return b;

}

bool determinatevar(char s) // если английский символ, то вернёт true;
{
	int k = s;
	if (((k > 64) && (k < 91)) || ((k > 96) && (k < 123))) // ((k >= 'a')&(k <= 'z')) || ((k > 'A')&(k < 'B')) // isalpha(k) 
		return true;
	else return false;
}
bool determinatechar(char s) //если char это цифра, то вернём true;
{
	int k = s;
	if ((k>47) && (k<58)) // (k > '0') && (k <= '9') // isdigit(k) 
		return true;
	else return false;
}

bool determinateoperand(char s) //если char это  *+/-, то вернём true;
{
	int k = s;
	if ((!determinatechar(s)) && (!determinatevar(s)) && (s != ')') && (s != '(') && (s!='.'))
		return true;
	else return false;
}

bool determinateopetator(char s) //если char это () *+/-, то вернём true;
{
	int k = s;
	if ((!determinatechar(s)) && (!determinatevar(s)))
		return true;
	else return false;
}
int getcase(char b)
{
	if (b == '(')
		return 0;
	else if (b == ')')
		return -1;
	else if (b == '+')
		return 1;
	else if (b == '-')
		return 2;
	else if (b == '*')
		return 3;
	else if (b == '/')
		return 4;
	else if (determinatechar(b))
		return 5;
	else if (determinatevar(b))
		return 6;
}


void Arifmetic::GetArrLexOne()
{
	SimplyLexem = new Lexem[lengthStr];
	int i = 0;
	int q = 0;
	int v = 0;
	while (i < lengthStr)
	{
		switch (getcase(Str[i]))
		{
		case 0:
		{
			SimplyLexem[q].setype(0);
			SimplyLexem[q].setpriority(0);
			SimplyLexem[q++].setLStr("("); i += 1; v += 1; break; }
		case -1:
		{
		SimplyLexem[q].setype(-1);
		SimplyLexem[q].setpriority(-1);
		SimplyLexem[q++].setLStr(")"); i += 1; v += 1; break; }
		case 1:
		{ 
		SimplyLexem[q].setype(1);
		SimplyLexem[q].setpriority(1);
		SimplyLexem[q++].setLStr("+"); i += 1; break; }
		case 2:
		{
			if (((i == 0)&(getcase(Str[i + 1]) == 5)) || ((i!=0)&&(getcase(Str[i - 1]) == 0)&&(getcase(Str[i + 1]) == 5))) //если первый сивол - а после него число
			{
				int k = 1;
				while ((determinatechar(Str[i + 1])) || (Str[i + 1] == '.'))
				{
					k += 1;
					i++;
				}
				char * c = new char[k];
				strncpy(c, &Str[i + 1 - k], k);
				c[k] = '\0';
				string b(c);
				i += 1;
				SimplyLexem[q].setVAR(atof(c));
				SimplyLexem[q].setype(5);
				SimplyLexem[q].setpriority(3);
				SimplyLexem[q++].setLStr(b); break;

			}
			else if (((i == 0)&(getcase(Str[i + 1]) == 6)) || ((getcase(Str[i - 1]) == 0)&(getcase(Str[i + 1]) == 6))) // усли первый символ - а после него char
			{
				int k = 1;
				while (determinatevar(Str[i + 1]))
				{
					k += 1;
					i++;
				}
				char * c = new char[k];
				strncpy(c, &Str[i + 1 - k], k);
				c[k] = '\0';
				string b(c);
				i += 1;
				SimplyLexem[q].setVAR(atof(c));
				SimplyLexem[q].setype(6);
				SimplyLexem[q].setpriority(3);
				SimplyLexem[q++].setLStr(b); break;

			}
			else {
				string b = "-";
				SimplyLexem[q].setype(2);
				SimplyLexem[q].setpriority(1);
				SimplyLexem[q++].setLStr(b); i += 1; break;
			}}
		case 3:
		{ string b = "*";
		SimplyLexem[q].setype(3);
		SimplyLexem[q].setpriority(2);
		SimplyLexem[q++].setLStr(b); i += 1; break; }
		case 4:
		{ string b = "/";
		SimplyLexem[q].setype(4);
		SimplyLexem[q].setpriority(2);
		SimplyLexem[q++].setLStr(b); i += 1; break; }
		case 5: {
			int k = 0;
			while ((determinatechar(Str[i])) || (Str[i] == '.'))
			{
				k += 1;
				i++;
			}
			char * c = new char[k];
			strncpy(c, &Str[i - k], k);
			c[k] = '\0';
			string b(c);

			SimplyLexem[q].setVAR(atof(c));
			SimplyLexem[q].setype(5);
			SimplyLexem[q].setpriority(3);
			SimplyLexem[q++].setLStr(b); break; }
		case 6:
		{
			int k = 0;
			while (determinatevar(Str[i]))
			{
				k += 1;
				i++;
			}
			char * c = new char[k];
			strncpy(c, &Str[i - k], k);
			c[k] = '\0';
			string b(c);
			SimplyLexem[q].setype(6);
			SimplyLexem[q].setpriority(3);
			SimplyLexem[q++].setLStr(b); break; }
		default:
			break;
			break;
		}
	}
	q1 = q;
	v1 = v;
}


void Arifmetic::GetArrLexTwo() {
	PolishLexem = new Lexem[q1 - v1];
	Stack<Lexem> One(q1 - v1);
	int i = 0;
	int q = 0;
	while (i < q1)
	{
		switch (SimplyLexem[i].getype())
		{
		case 0: {
			One.push(SimplyLexem[i]);
			i++;
			break;
		}
		case -1:
		{
			while (One.Check().getype() != 0)
				PolishLexem[q++] = One.pop();
			One.pop(); // извлекли скомбу
			i++;
			break;
		}

		case 1:
		{
			if (One.IsEmpty())
			{
				One.push(SimplyLexem[i]);
				i++;
				break;
			}
			else
				if (1 > One.Check().getpriority())
				{
					One.push(SimplyLexem[i]);
					i++;
					break;
				}
				else {
					int flag = 0;
					while ((!One.IsEmpty()) && (flag == 0))
					{
						if (One.Check().getpriority() > 1)
							PolishLexem[q++] = One.pop();
						else flag = 1;
					}
					One.push(SimplyLexem[i]);
					i++; break;
				}
		}
		case 2:
		{
			if (One.IsEmpty())
			{
				One.push(SimplyLexem[i]);
				i++;
				break;
			}
			else
				if (1 > One.Check().getpriority())
				{
					One.push(SimplyLexem[i]);
					i++;
					break;
				}
				else {
					int flag = 0;
					while ((!One.IsEmpty())&(flag == 0))
					{
						if (One.Check().getpriority() > 1)
							PolishLexem[q++] = One.pop();
						else flag = 1;
					}
					One.push(SimplyLexem[i]);
					i++; break;
				}}
		case 3:
		{
			One.push(SimplyLexem[i]);
			i++;
			break;
		}
		case 4:
		{
			One.push(SimplyLexem[i]);
			i++;
			break;
		}
		case 5:
		{
			PolishLexem[q++] = SimplyLexem[i++];
			break;
		}
		case 6:
		{
			PolishLexem[q++] = SimplyLexem[i++];
			break;
		}
		default:
			break;
		}
	}
	if (!One.IsEmpty()) //если не пустой
	{
		while (!One.IsEmpty())
		{
			PolishLexem[q++] = One.pop();
		}
	}

}

void Arifmetic::Lala()
{
	int i = 0;
	while (i < q1 - v1)
	{
		if (PolishLexem[i].getype() == 6)
		{
			int t = 0;
			for (int j = 0; j < i; j++)
			{
				if ((PolishLexem[j].getype() == 6) && (PolishLexem[i].getLStr() == PolishLexem[j].getLStr()))
				{
					double k = PolishLexem[j].getVAR();
					PolishLexem[i].setVAR(k);
					t = 1;
					break;
				}
			}
			if (t == 0)
			{
				cout << "Please, enter ";
				if (PolishLexem[i].getLStr()[0] == '-')
				{
					for (int j = 1; j < PolishLexem[i].getLStr().length(); j++)
						cout << PolishLexem[i].getLStr()[j];
					cout << endl;
					int k;
					cin >> k;
					PolishLexem[i].setVAR(-k);
				}
				else
				{
					cout << PolishLexem[i].getLStr() << endl;
					int k;
					cin >> k;
					PolishLexem[i].setVAR(k);
				}
			}

		}
		i++;
	}
}

double Arifmetic::Calculete() {
	int z = q1 - v1, i = 0;
	Stack <double> Two(z);
	while (i<z)
	{
		if ((PolishLexem[i].getype() == 5) || (PolishLexem[i].getype() == 6))
			Two.push(PolishLexem[i].getVAR());
		else if (PolishLexem[i].getype() == 1)
		{
			double a = Two.pop();
			double b = Two.pop();
			Two.push(b + a);
		}
		else if (PolishLexem[i].getype() == 2)
		{
			double a = Two.pop();
			double b = Two.pop();
			Two.push(b - a);
		}
		else if (PolishLexem[i].getype() == 3)
		{
			double a = Two.pop();
			double b = Two.pop();
			Two.push(b*a);
		}
		else if (PolishLexem[i].getype() == 4)
		{
			double a = Two.pop();
			double b = Two.pop();
			Two.push(b / a);
		}
		i++;
	}
	cout << " Answer = " << Two.Check() << endl;

	return Two.pop();
}

void Arifmetic::PrintArrLex() {
	for (int i = 0; i < q1; i++)
		cout << "Your Lexems " << SimplyLexem[i].getLStr() << endl;
}

void Arifmetic::PrintArrLex2() {
	for (int i = 0; i < q1 - v1; i++)
		cout << "Your PolishLexems " << PolishLexem[i].getLStr() << endl;
}






//////////////////////////////////////////////////////////////////////


bool finder(string b, int* k) // Проверка недопустимых символов;
{
	string a = ",&^$#@_;:!\='";
	for (int i = 0; i < b.length(); i++)
		for (int j = 0; j < a.length(); j++)
		{
			if (b[i] == a[j])
			{
				*k = i + 1;
				return false;
			}
		}
	return true;
}
int ChekString(const string a)
{
	int k = 0; // проверка количества скобок
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '(')
			k += 1;
		else if ((a[i] == ')') && (k != 0))
			k -= 1;
		else if ((a[i] == ')') && (k == 0))
		{
			cout << "ERROR pos " << i + 1 << endl;
			return 0;
		}

	}
	if (k != 0)
	{
		cout << "ERROR - number '(' != nember ')' " << endl;
		return 0;
	}
	k = 0;

	if (!finder(a, &k)) // проверка недопустимых символов
		cout << "ERROR pos " << k << endl;
	k = 0;
	// проверка  и () и )( и char( и )char и var_char и char_var и ). и .( и (. .)
	for (int i = 0; i < a.length() - 1; i++)
	{

		if (((a[i] == ')')&&(determinatechar(a[i + 1]))) || ((determinatechar(a[i]))&&(a[i + 1] == '(')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}
		if (((a[i] == ')')&&(a[i + 1] == '.')) || ((a[i] == '.')&(a[i + 1] == '(')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}
		if (((a[i] == '(')&(a[i + 1] == '.')) || ((a[i] == '.')&&(a[i + 1] == ')')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}
		if ((a[i] == '.')&&((a[i + 1] == ')') || (a[i + 1] == '(')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}
		if (((a[i] == '(')&&(a[i + 1] == ')')) || ((a[i] == ')')&&(a[i + 1] == '(')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}

		if ((determinatevar(a[i])&&(determinatechar(a[i + 1]))) || (determinatevar(a[i + 1])&(determinatechar(a[i]))) || (((a[i] == '.')&(determinatevar(a[i + 1])))))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}

	}
	// проверка последнего символа 
	k = a.length() - 1;
	if ((a[k] == '+') || (a[k] == '-') || (a[k] == '*') || (a[k] == '/'))
	{
		cout << "ERROR pos " << k + 1 << endl;
		return 0;
	}
	// проверка первого символа 

	if ((a[0] == '+') || (a[0] == '*') || (a[0] == '/'))
	{
		cout << "ERROR pos " << 1 << endl;
		return 0;
	}

	for (int i = 0; i < a.length(); i++) { // проверка .а или а.
		if ((a[i] == '.')&&(determinatevar(a[i + 1])))
		{
			cout << "ERROR pos " << i << endl;
			return 0;
		}
		else if ((a[i + 1] == '.')&&(determinatevar(a[i])))
		{
			cout << "ERROR pos " << i << endl;
			return 0;
		}
	}
	for (int i = 0; i < a.length(); i++) //два повторяющихся операторанда 
	{
		if ((determinateoperand(a[i]))&(determinateoperand(a[i + 1])))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}
	}
	for (int i = 0; i < a.length(); i++) //два повторяющихся операторанда 
	{
		if ((a[i] == '(')&&((a[i + 1] == '+') || (a[i + 1] == '*') || (a[i + 1] == '/')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}

		else if (((a[i + 1] == ')'))&&((a[i] == '+') || (a[i] == '*') || (a[i] == '/')))
		{
			cout << "ERROR pos " << i + 2 << endl;
			return 0;
		}
	}
	// определение  ошибки вида 12.12.13
	int u = 0;
	for (int i = 0; i < a.length(); i++) {
		while ((determinatechar(a[i])) || (a[i] == '.'))
		{
			if (a[i] == '.')
				u += 1;
			if ((determinateoperand(a[i + 1]))&(u <= 1))
				u = 0;
			else if ((determinateoperand(a[i + 1])) && (u > 1))
			{
				cout << "ERROR" << endl;
				return 0;
			}
			i++;
		}
	}
		cout << "all right" << endl;
		return 1;
	}







