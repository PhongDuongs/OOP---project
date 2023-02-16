#pragma once
#include "Stack.h"
#include <sstream>
#include <vector>
#include<string.h>
using namespace std;
class TrungTo
{
public:
	TrungTo();
	~TrungTo();
	void InputM(string, vector <string>&);
	int DoUuTien(string);
	bool KiemTraToanTu(string);
	string CongThuc(string, string, string);
	float VectorM(vector<string>);
	float Xuat(string);
	int CheckError(string& x, string Input);
	void XoaKhoangTrang(string&);
	int TimKhoangTrang(string);
	string FunctionOfMath(string&);
	string result(string, string);
};