#include "Vector.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	myVector vec1;
	myVector vec2(3, 4, 5);
	myVector vec3(vec2);
	myVector vec4 = vec3;

	cout << fixed << setprecision(2);
	cout << "vec2的大小为: " << vec2.size() << endl;
	cout << "vec2归一化后: " << norm(vec2) << endl;

	vec3 = vec3 + 1;
	cout << "vec3" << vec3 << endl;
	vec3 = vec3 + 2.0f;
	cout << "vec3" << vec3 << endl;
	vec3 = vec3 + 3.0;

	vec4 = vec4 - 1;
	cout << "vec4" << vec4 << endl;
	vec4 = vec4 - 2.0f;
	cout << "vec4" << vec4 << endl;
	vec4 = vec4 - 3.0;

	cout << "vec3 dot vec4 = " << vec3.vecDot(vec4) << endl;

	cout << "vec3 cross vec4 = " << vec3.vecCross(vec4) << endl;


	cout << "vec1" << vec1 << endl;
	cout << "vec2" << vec2 << endl;
	cout << "vec3" << vec3 << endl;
	cout << "vec4" << vec4 << endl;

	cout << "vec1[0] = " << vec1[0] << endl;
	cout << "vec1[1] = " << vec1[1] << endl;
	cout << "vec1[2] = " << vec1[2] << endl;
	cout << "vec2[0] = " << vec2[0] << endl;
	cout << "vec2[1] = " << vec2[1] << endl;
	cout << "vec2[2] = " << vec2[2] << endl;
}