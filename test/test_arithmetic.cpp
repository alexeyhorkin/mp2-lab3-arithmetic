// ����� ��� ���������� �������������� ���������
#include <cstring>
#include <string>
#include <gtest.h>
#include "arithmetic.h"
class ParameterizedString : public ::testing::TestWithParam<string>
{
protected:
	string bf1;

public:
	ParameterizedString() : bf1(GetParam())
	{		
	}

	~ParameterizedString() {}
};


TEST_P(ParameterizedString, can_determinate_eror)
{
	EXPECT_EQ(0, ChekString(bf1));
}

string test_values[] = { "2--", "2++","1+3*()", "(4.4-3)*((6-5)", "(1-arr*)", "(/2+1)" , "()"};

INSTANTIATE_TEST_CASE_P(Instantiation2,
	ParameterizedString,
	::testing::ValuesIn(test_values));

class ParameterizedString2 : public ParameterizedString
{};

TEST_P(ParameterizedString2, can_determinate_eror)
{
	EXPECT_EQ(1, ChekString(bf1));
}

string test_values2[] = { "2-1" };

INSTANTIATE_TEST_CASE_P(Instantiation3,
	ParameterizedString2,
	::testing::ValuesIn(test_values2));

struct T
{
	string s;
	bool isCorrect;
	double val;

	T(string mys = "", bool f = true, double v = 0.0)
	{
		s = mys;
		isCorrect = f;
		val = v;
	}
};

class ParameterizedString3 : public ::testing::TestWithParam<T>
{
protected:
	T testcase;
public:
	ParameterizedString3() : testcase(GetParam())
	{}

	~ParameterizedString3() {}
};

TEST_P(ParameterizedString3, can_determinate_eror_from_string)
{
	EXPECT_EQ(GetParam().isCorrect, ChekString(GetParam().s));
}

TEST_P(ParameterizedString3, can_calc)
{
	Arifmetic a(GetParam().s);
	a.GetArrLexOne();
	a.GetArrLexTwo();
	EXPECT_EQ(GetParam().val, a.Calculete());
}

T myarray[2] = {T("3-2", true, 1), T("2*3", true, 6) };

INSTANTIATE_TEST_CASE_P(Instantiation4,
	ParameterizedString3,
	::testing::ValuesIn(myarray));
