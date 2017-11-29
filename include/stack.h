
#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
using namespace std;

// ���������� � ���������� ���������� �����
template <class ValType> 
class Stack {
private:
	ValType * arr;
	int SizeMax;
	int topmember; //���������� ��������� � �����

public:
	Stack(int Size_Max=10);
		~Stack();
	Stack(const Stack& a);
	void push(const ValType a); // �������� ������� �� ������� �����
	ValType pop(); // ������� � ������� ����� � �������
	void dell();
	bool IsEmpty(); // ��������� ������ ��
	ValType Check(); //  ���������� ������� �������
	int CurrentSize(); // ���������� ��������� � �����
	void Clear();
};
//////////////////////////////////////////////////////////////

template <class ValType>
Stack <ValType> ::Stack(int Size_Max)
{
	SizeMax = Size_Max;
	topmember = -1;
	arr = new ValType[SizeMax];
}
///////////////////////////////////////////////////////////////
template <class ValType>
Stack <ValType> ::~Stack()
{
	delete[] arr;
}
///////////////////////////////////////////////////////////////
template <class ValType>
 Stack <ValType> :: Stack(const Stack& a)
{
	SizeMax = a.SizeMax;
	delete[] arr;
	arr = new ValType[SizeMax];
	for (int i = 0; i < topmember+1; i++)
		arr[i] = a.arr[i];
}
 /////////////////////////////////////////////////////////////
 template <class ValType>
 void Stack <ValType>::push(const ValType a)
 {
	 if (topmember + 1 < SizeMax)
		 arr[++topmember] = a;
	 else {
		 Stack <ValType> Copy(*this);
		 delete[] arr;
		 SizeMax= SizeMax*2;
		 arr = new  ValType[SizeMax];
		 for (int i = 0; i <= topmember; i++)
			 arr[i] = Copy.arr[i];
		 arr[++topmember] = a;
	 }
 }
 ////////////////////////////////////////////////////////////
 template <class ValType>
 void Stack <ValType>::dell() {

	 if (topmember != -1)
		 topmember -= 1;
	 else throw "lalala";
 }
 ////////////////////////////////////////////////////////////
 template <class ValType>
 ValType Stack <ValType>::pop()
 {
	 if(topmember!=-1)
	 return arr[topmember--];
	 else throw "lalala";
 }
 ////////////////////////////////////////////////////////////
 template <class ValType>
 bool  Stack <ValType>::IsEmpty()
 {
	 if (topmember == -1) return 1; else return 0;
 }
 ////////////////////////////////////////////////////////////
 template <class ValType>
 ValType  Stack <ValType>::Check()
 {
	 if(topmember!=-1)
	 return arr[topmember];
	 else throw "lalala";
 }
 ///////////////////////////////////////////////////////////
 template <class ValType>
 int  Stack <ValType>::CurrentSize()
 {
	 return topmember + 1;
 }
 ////////////////////////////////////////////////////////////
 template <class ValType>
 void  Stack <ValType>::Clear()
 {
	 topmember = -1;
 }
 ///////////////////////////////////////////////////////////

// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������
#endif;