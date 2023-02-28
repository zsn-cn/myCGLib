#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class myVector
{
public:

	//�޲ι���
	myVector();

	//�вι���
	myVector(double x, double y, double z);

	//��������
	myVector(myVector& vec);

	//�ȺŹ���
	myVector& operator=(myVector& vec);

	//�����ӷ�
	myVector& operator+(myVector& vec);
	myVector& operator+(int num);
	myVector& operator+(float num);
	myVector& operator+(double num);

	//��������
	myVector& operator-(myVector& vec);
	myVector& operator-(int num);
	myVector& operator-(float num);
	myVector& operator-(double num);

	//�������
	double vecDot(myVector& vec);

	//�������
	myVector& vecCross(myVector& vec);

	//������С
	double size();

	//����
	~myVector();

	//����������ʽ�������
	friend ostream& operator<<(ostream& cout, myVector& vec);

	//������һ��
	friend myVector& norm(myVector& vec);

private:

	//��������ά����
	double _x;
	double _y;
	double _z;

	//��ʱ������ָ��
	myVector* myVecPtr;

private:


};

ostream& operator<<(ostream& cout, myVector& vec);

myVector& norm(myVector& vec);