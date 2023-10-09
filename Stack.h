#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<assert.h>

#define MaxSize 100

template<class T>
class Stack
{
private:
	T *elements;                    //���ջ��Ԫ��
	int top;                        //ջ��ָ��
	int Max;                        //������ɸ���
	void overflowProcess();         //�������
public:
	Stack(int sz = 50);             //���캯��
	~Stack(){ delete[]elements; }   //��������
	void Push(const T&x);           //ѹջ
	bool Pop(T&x);                  //��ջ
	bool getTop(T&x)                //���ջ��Ԫ��
	{
		if (IsEmpty()) return false;
		x = elements[top];
		return true;
	}
	bool IsEmpty()const             //�Ƿ�Ϊ��
	{
		return (top == -1) ? true : false;
	}
	bool IsFull() const             //�Ƿ���
	{
		return (top == Max - 1) ? true : false;
	}
	int getSize() const             //ջ��Ԫ��
	{
		return top + 1;
	}
	void MakeEmpty(){ top = -1; }   //���ջ
	//����<<
	//friend ostream& operator<< (ostream&os, Stack<T> &s);
};
//*******************************************���캯��
template<class T>
Stack<T>::Stack(int sz) :top(-1), Max(sz)
{
	elements = new T[Max];
	assert(elements != nullptr);
	//*********************��()����Ϊ�٣���������
}
//*******************************************�������
template<class T>
void Stack<T>::overflowProcess()
{
	//*************************��100��
	T *newArray = new T[Max + MaxSize];
	assert(newArray != nullptr);
	for (int i = 0; i <= top; i++)
		newArray[i] = elements[i];
	Max = Max + MaxSize;
	delete[]elements;
	elements = newArray;
}
//*******************************************ѹջ
template<class T>
void Stack<T>::Push(const T&x)
{
	if (IsFull() == true)
		overflowProcess();
	elements[++top] = x;
}
//********************************************��ջ
template<class T>
bool Stack<T>::Pop(T &x)
{
	if (IsEmpty() == true)
		return false;
	x = elements[top--];
	return true;
}
//******************************************����<<
/*template<class T>
ostream& operator<< (ostream&os, Stack<T> &s)
{
	os << "top=" << s.top << endl;
	for (int i = 0; i < s.top; i++)
	{
		os << i << ":" << s.elements[i] << endl;
	}
	return os;
}*/

#endif