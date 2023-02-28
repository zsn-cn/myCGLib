#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class myVector
{
public:

	//无参构造
	myVector();

	//有参构造
	myVector(double x, double y, double z);

	//拷贝构造
	myVector(myVector& vec);

	//等号构造
	myVector& operator=(myVector& vec);

	//向量加法
	myVector& operator+(myVector& vec);
	myVector& operator+(int num);
	myVector& operator+(float num);
	myVector& operator+(double num);

	//向量减法
	myVector& operator-(myVector& vec);
	myVector& operator-(int num);
	myVector& operator-(float num);
	myVector& operator-(double num);

	//向量点积
	double vecDot(myVector& vec);

	//向量叉积
	myVector& vecCross(myVector& vec);

	//向量大小
	double size();

	//析构
	~myVector();

	//以行向量形式输出向量
	friend ostream& operator<<(ostream& cout, myVector& vec);

	//向量归一化
	friend myVector& norm(myVector& vec);

	//向量数乘
	myVector& operator*(int num);
	myVector& operator*(float num);
	myVector& operator*(double num);

	//重载[]
	double operator[](int index);

	//向量投影操作
	myVector& projectionVec(myVector& vec);
	

public:

	//向量的三维坐标
	double _x;
	double _y;
	double _z;

	//临时用向量指针
	myVector* myVecPtr = nullptr;

private:


};

ostream& operator<<(ostream& cout, myVector& vec);

myVector& norm(myVector& vec);