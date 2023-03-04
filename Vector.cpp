#include "Vector.h"

myVector::myVector()
{
	this->_x = 0.;
	this->_y = 0.;
	this->_z = 0.;
}

myVector::myVector(double x, double y, double z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

myVector::myVector(myVector& vec)
{
	this->_x = vec._x;
	this->_y = vec._y;
	this->_z = vec._z;
}

myVector& myVector::operator=(myVector& vec)
{
	this->_x = vec._x;
	this->_y = vec._y;
	this->_z = vec._z;
	return *this;
}

myVector& myVector::operator+(myVector& vec)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x + vec._x;
	(*(this->myVecPtr))._y = this->_y + vec._y;
	(*(this->myVecPtr))._z = this->_z + vec._z;
	return *(this->myVecPtr);
}

myVector& myVector::operator+(int num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x + (double)num;
	(*(this->myVecPtr))._y = this->_y + (double)num;
	(*(this->myVecPtr))._z = this->_z + (double)num;
	return *(this->myVecPtr);
}

myVector& myVector::operator+(float num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x + (double)num;
	(*(this->myVecPtr))._y = this->_y + (double)num;
	(*(this->myVecPtr))._z = this->_z + (double)num;
	return *(this->myVecPtr);
}

myVector& myVector::operator+(double num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x + num;
	(*(this->myVecPtr))._y = this->_y + num;
	(*(this->myVecPtr))._z = this->_z + num;
	return *(this->myVecPtr);
}

myVector& myVector::operator-(myVector& vec)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x - vec._x;
	(*(this->myVecPtr))._y = this->_y - vec._y;
	(*(this->myVecPtr))._z = this->_z - vec._z;
	return *(this->myVecPtr);
}

myVector& myVector::operator-(int num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x - (double)num;
	(*(this->myVecPtr))._y = this->_y - (double)num;
	(*(this->myVecPtr))._z = this->_z - (double)num;
	return *(this->myVecPtr);
}

myVector& myVector::operator-(float num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x - (double)num;
	(*(this->myVecPtr))._y = this->_y - (double)num;
	(*(this->myVecPtr))._z = this->_z - (double)num;
	return *(this->myVecPtr);
}

myVector& myVector::operator-(double num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x - num;
	(*(this->myVecPtr))._y = this->_y - num;
	(*(this->myVecPtr))._z = this->_z - num;
	return *(this->myVecPtr);
}

double myVector::vecDot(myVector& vec)
{
	double res;
	res = this->_x * vec._x + this->_y * vec._y + this->_z * vec._z;
	return res;
}

myVector& myVector::vecCross(myVector& vec)
{
	myVector newVec(this->_y * vec._z - this->_z * vec._y,
					this->_z * vec._x - this->_x * vec._z,
					this->_x * vec._y - this->_y * vec._x);
	
	this->myVecPtr = new myVector;

	(*(this->myVecPtr))._x = newVec._x;
	(*(this->myVecPtr))._y = newVec._y;
	(*(this->myVecPtr))._z = newVec._z;

	return *(this->myVecPtr);
}

double myVector::size()
{
	double res = sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z);
	return res;
}

myVector::~myVector()
{
	if (this->myVecPtr != nullptr)
	{
		delete this->myVecPtr;
		this->myVecPtr = nullptr;
	}
}

myVector& myVector::operator*(int num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x * (double)num;
	(*(this->myVecPtr))._y = this->_y * (double)num;
	(*(this->myVecPtr))._z = this->_z * (double)num;
	return *(this->myVecPtr);
}

myVector& myVector::operator*(float num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x * (double)num;
	(*(this->myVecPtr))._y = this->_y * (double)num;
	(*(this->myVecPtr))._z = this->_z * (double)num;
	return *(this->myVecPtr);
}

myVector& myVector::operator*(double num)
{
	this->myVecPtr = new myVector;
	(*(this->myVecPtr))._x = this->_x * num;
	(*(this->myVecPtr))._y = this->_y * num;
	(*(this->myVecPtr))._z = this->_z * num;
	return *(this->myVecPtr);
}

double& myVector::operator[](int index)
{
	if (index == 0)
	{
		return this->_x;
	}
	else if (index == 1)
	{
		return this->_y;
	}
	else if (index == 2)
	{
		return this->_z;
	}
	else
	{
		cout << "the index is out of range." << endl;
		return this->_x;
	}
}

myVector& myVector::vecProj(myVector& vec)
{
	this->myVecPtr = new myVector;

	myVector newVec(vec * (this->vecDot(vec) / vec.vecDot(vec)));

	(*(this->myVecPtr))._x = newVec._x;
	(*(this->myVecPtr))._y = newVec._y;
	(*(this->myVecPtr))._z = newVec._z;

	return *(this->myVecPtr);
}

ostream& operator<<(ostream& cout, myVector& vec)
{
	cout /*<< "("*/ << vec._x << ", " << vec._y << ", " << vec._z /*<< ")"*/;
	return cout;
}

myVector& norm(myVector& vec)
{
	vec.myVecPtr = new myVector;

	myVector newVec(vec._x / vec.size(), vec._y / vec.size(), vec._z / vec.size());

	(*(vec.myVecPtr))._x = newVec._x;
	(*(vec.myVecPtr))._y = newVec._y;
	(*(vec.myVecPtr))._z = newVec._z;

	return *(vec.myVecPtr);
}
