#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//��ȡ�ַ����е����ֲ�ת��Ϊdouble���ʹ洢��double*ָ����
void str2double(string& str, double* doublePtr);

int main()
{
	/*
		��ҵ1
	*/
	ifstream fin;
	ofstream fout;
	fin.open("test.txt", ios::in);
	fout.open("out.txt", ios::out);

	fout << fixed << setprecision(2);

	if (!fin.is_open())
	{
		cout << "open file failed." << endl;
	}
	else
	{
		string str, strData1, strData2;
		myVector vec1, vec2, vecRes;
		double vecNum[3] = { 0 }, douRes = 0, douNum = 0;
		while (fin >> str)
		{
			if (str == "�������")
			{
				fin >> strData1 >> strData2;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}
				str2double(strData2, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec2[i] = vecNum[i];
				}

				vecRes = vec1 + vec2;

				fout << "�������" << endl <<  vec1 << "\t" << vec2 << "\t" << vecRes << endl;
			}
			else if (str == "�������")
			{
				fin >> strData1 >> strData2;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}
				str2double(strData2, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec2[i] = vecNum[i];
				}

				vecRes = vec1 - vec2;

				fout << "�������" << endl << vec1 << "\t" << vec2 << "\t" << vecRes << endl;
			}
			else if (str == "��������")
			{
				fin >> strData1 >> strData2;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}

				douNum = stod(strData2, 0);

				vecRes = vec1 * douNum;

				fout << "��������" << endl << vec1 << "\t" << douNum << "\t" << vecRes << endl;
			}
			else if (str == "�������")
			{
				fin >> strData1 >> strData2;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}
				str2double(strData2, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec2[i] = vecNum[i];
				}

				douRes = vec1.vecDot(vec2);

				fout << "�������" << endl << vec1 << "\t" << vec2 << "\t" << douRes << endl;
			}
			else if (str == "�������")
			{
				fin >> strData1 >> strData2;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}
				str2double(strData2, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec2[i] = vecNum[i];
				}

				vecRes = vec1.vecCross(vec2);

				fout << "�������" << endl << vec1 << "\t" << vec2 << "\t" << vecRes << endl;
			}
			else if (str == "������׼��")
			{
				fin >> strData1;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}

				vecRes = norm(vec1);

				fout << "������׼��" << endl << vec1 << "\t" << vecRes << endl;
			}
			else if (str == "������ģ")
			{
				fin >> strData1;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}

				douRes = vec1.size();

				fout << "������ģ" << endl << vec1 << "\t" << douRes << endl;
			}
			else if (str == "����ͶӰ")
			{
				fin >> strData1 >> strData2;

				str2double(strData1, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec1[i] = vecNum[i];
				}
				str2double(strData2, vecNum);
				for (int i = 0; i < 3; i++)
				{
					vec2[i] = vecNum[i];
				}

				vecRes = vec1.vecProj(vec2);

				fout << "����ͶӰ" << endl << vec1 << "\t" << vec2 << "\t" << vecRes << endl;
			}
		}

		fin.close();
		fout.close();
	}
	/*
		��ҵ1
	*/
}

void str2double(string& str, double* doublePtr)
{
	size_t pos1, pos2;
	string subStr;
	pos1 = str.find(',', 0);
	subStr = str.substr(0, pos1);
	doublePtr[0] = stod(subStr, 0);
	pos2 = str.find(',', pos1 + (size_t)1);
	subStr = str.substr(pos1 + (size_t)1, pos2 - pos1 - (size_t)1);
	doublePtr[1] = stod(subStr, 0);
	subStr = str.substr(pos2 + (size_t)1, str.size() - pos2 - (size_t)1);
	doublePtr[2] = stod(subStr, 0);
}