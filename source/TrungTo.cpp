#include"pch.h"
#include "Math.h"
#include"TrungTO.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TrungTo::TrungTo()
{
}

TrungTo::~TrungTo()
{
}

int TrungTo::DoUuTien(string ToanTu)
{
	if (
		ToanTu == "z" ||
		ToanTu == "x" ||
		ToanTu == "c" ||
		ToanTu == "v" ||
		ToanTu == "b" ||
		ToanTu == "n" ||
		ToanTu == "e" ||
		ToanTu == "d" ||
		ToanTu == "s" ||
		ToanTu == "a")
	{
		return 3;
	}
	else if (ToanTu == "*" ||
		ToanTu == "/" ||
		ToanTu == "%" ||
		ToanTu == "^"
		)
		return 2;
	else if (ToanTu == "+" || ToanTu == "-")
		return 1;
	else if (ToanTu == "(")
		return 0;

	return -1;
}

bool TrungTo::KiemTraToanTu(string ToanTu)
{
	if (ToanTu == "*" ||
		ToanTu == "/" ||
		ToanTu == "%" ||
		ToanTu == "+" ||
		ToanTu == "-" ||
		ToanTu == "^" ||
		ToanTu == "z" ||
		ToanTu == "x" ||
		ToanTu == "c" ||
		ToanTu == "v" ||
		ToanTu == "b" ||
		ToanTu == "n" ||
		ToanTu == "e" ||
		ToanTu == "," ||
		ToanTu == "a" ||
		ToanTu == "s" ||
		ToanTu == "d"
		)
		return true;
	else
		return false;
}

string TrungTo::CongThuc(string ToanHang1, string ToanTu, string ToanHang2)// Do mình khai báo là string là dạng chuỗi, ta muốn tính toán ta phải đổi sang dạng số, câu lệnh atof() sử dụng cho việc này
{//atof(const char *str) nhưng mà a là std::string vì vậy ta sẽ dùng c_str để chuyển thành dạng const char *
	double Tinh = 0;

	if (ToanTu == "^")
	{
		Tinh = double(pow(atof(ToanHang2.c_str()), atof(ToanHang1.c_str())));
	}
	if (ToanTu == "%")
		Tinh = int(atof(ToanHang2.c_str())) % int(atof(ToanHang1.c_str()));
	if (ToanTu == "*")
		Tinh = atof(ToanHang1.c_str()) * atof(ToanHang2.c_str());
	else if (ToanTu == "/")
		Tinh = double(atof(ToanHang2.c_str()) / atof(ToanHang1.c_str()));
	else if (ToanTu == "+")
		Tinh = double(atof(ToanHang2.c_str()) + atof(ToanHang1.c_str()));
	else if (ToanTu == "-")
		Tinh = double(atof(ToanHang2.c_str()) - atof(ToanHang1.c_str()));
	else if (ToanTu == "z") //z:sin
		Tinh = double(sin(atof(ToanHang1.c_str())));
	else if (ToanTu == "x") //x:cos
		Tinh = double(cos(atof(ToanHang1.c_str())));
	else if (ToanTu == "c") //c:tan
		Tinh = double(tan(atof(ToanHang1.c_str())));
	else if (ToanTu == "v") //v:sqrt
		Tinh = double(sqrt(atof(ToanHang1.c_str())));
	else if (ToanTu == "b") //b:cbrt
		Tinh = double(cbrt(atof(ToanHang1.c_str())));
	else if (ToanTu == "n") //n:abs
		Tinh = double(abs(atof(ToanHang1.c_str())));
	else if (ToanTu == "e") //m:exp
		Tinh = double(exp(atof(ToanHang1.c_str())));
	else if (ToanTu == "d") //,:log
		Tinh = double(log(atof(ToanHang1.c_str())));
	else if (ToanTu == "a") //a:max
		Tinh = double(max(atof(ToanHang2.c_str()), atof(ToanHang1.c_str())));
	else if (ToanTu == "s") //s:min
		Tinh = double(min(atof(ToanHang2.c_str()), atof(ToanHang1.c_str())));

	string str = to_string(Tinh);/*Khi tính toán xong chuyển sang string*/
	return str;
}

float TrungTo::VectorM(vector<string> Chuoi)
{
	double Ketqua = 0;
	string str = "";
	Stack* ToanHang = new Stack();
	Stack* ToanTu = new Stack();


	for (int i = 0; i < Chuoi.size(); i++)
	{
		if (Chuoi[i] == "(")
			ToanTu->Push(Chuoi[i]);

		if (KiemTraToanTu(Chuoi[i]) == true)
		{
			string ToanHang1 = "";
			string ToanTu1 = "";
			string ToanHang2 = "";
			while (ToanTu->IsEmpty() == 0 && (DoUuTien(Chuoi[i]) <= DoUuTien(ToanTu->Top()->Data)))
			{
				ToanHang->Pop(ToanHang1);
				ToanTu->Pop(ToanTu1);
				ToanHang->Pop(ToanHang2);
				ToanHang->Push(this->CongThuc(ToanHang1, ToanTu1, ToanHang2));
			}
			ToanTu->Push(Chuoi[i]);
		}
		if (Chuoi[i] == ")")
		{
			string ToanHang1 = "";
			string ToanTu1 = "";
			string ToanHang2 = "";
			while (ToanTu->Top()->Data != "(")
			{
				ToanHang->Pop(ToanHang1);
				ToanTu->Pop(ToanTu1);
				ToanHang->Pop(ToanHang2);
				ToanHang->Push(this->CongThuc(ToanHang1, ToanTu1, ToanHang2));
			}
			string Drop = "";
			ToanTu->Pop(Drop);
		}

		if (KiemTraToanTu(Chuoi[i]) == false && Chuoi[i] != "(" && Chuoi[i] != ")" ||
			(Chuoi[i] == "z") ||
			(Chuoi[i] == "x") ||
			(Chuoi[i] == "c") ||
			(Chuoi[i] == "v") ||
			(Chuoi[i] == "b") ||
			(Chuoi[i] == "n") ||
			(Chuoi[i] == "e") ||
			(Chuoi[i] == "d")
			)
			ToanHang->Push(Chuoi[i]);
	}



	while (ToanTu->IsEmpty() == 0)
	{
		string ToanHang1 = "";
		string ToanTu1 = "";
		string ToanHang2 = "";
		ToanHang->Pop(ToanHang1);
		ToanTu->Pop(ToanTu1);
		ToanHang->Pop(ToanHang2);
		ToanHang->Push(this->CongThuc(ToanHang1, ToanTu1, ToanHang2));
	}

	ToanHang->Pop(str);
	Ketqua = atof(str.c_str());
	return Ketqua;
}

string TrungTo::result(string String, string subString)
{
	string h = "";
	int r = String.find(subString);
	for (int i = r; i <= String.length(); i++)
	{
		if (String[i] == '(')
		{
			break;
		}
		h.push_back(String[i]);
	}
	return h;
}


string TrungTo::FunctionOfMath(string& INPUT) //5+2-4*sin(4)-tan(5) x=5+2-4*z(4)-c(5)
{
	for (int i = 0; i < INPUT.length(); i++)
	{
		if (result(INPUT, "sin") == "sin")  //1 Sin
		{
			INPUT.replace(INPUT.find("sin"), 3, "z");
		}

		if (result(INPUT, "cos") == "cos")//2 Cos
		{
			INPUT.replace(INPUT.find("cos"), 3, "x");
		}

		if (result(INPUT, "tan") == "tan") //3 Tan
		{
			INPUT.replace(INPUT.find("tan"), 3, "c");
		}

		if (result(INPUT, "sqrt") == "sqrt") //4 sqrt
		{
			INPUT.replace(INPUT.find("sqrt"), 4, "v");
		}

		if (result(INPUT, "cbrt") == "cbrt") //5 cbrt
		{
			INPUT.replace(INPUT.find("cbrt"), 4, "b");
		}

		if (result(INPUT, "abs") == "abs") //6 abs
		{
			INPUT.replace(INPUT.find("abs"), 3, "n");
		}

		if (result(INPUT, "exp") == "exp") //7 exp
		{
			INPUT.replace(INPUT.find("exp"), 3, "e");
		}

		if (result(INPUT, "log") == "log") //8 log
		{
			INPUT.replace(INPUT.find("log"), 3, "d");
		}

		if (result(INPUT, "max") == "max") //9 max
		{
			INPUT.replace(INPUT.find("max"), 3, "a");
		}
		if (result(INPUT, "min") == "min") //10 min
		{
			INPUT.replace(INPUT.find("min"), 3, "s");
		}
		if (result(INPUT, "pow") == "pow") //11 pow
		{
			INPUT.replace(INPUT.find("pow"), 3, "^");
		}
		if (result(INPUT, "mod") == "mod") //12 mod
		{
			INPUT.replace(INPUT.find("mod"), 3, "%");
		}
	}
	return INPUT;

}

void TrungTo::InputM(string Input, vector<string>& Chuoi)
{
	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] >= 'a' && Input[i] <= 'z' || (Input[i] == '(') || (Input[i] == ')') || (Input[i] == '*') || (Input[i] == '/') || (Input[i] == '+') || (Input[i] == '-') || (Input[i] == '%') || (Input[i] == '^'))
		{
			string temp(1, Input[i]); /*bỏ vào Chuỗi các toán tử với số lượng là 1*/
			Chuoi.push_back(temp);
		}

		else if (
			Input[i] >= '0' && Input[i] <= '9'
			)
		{
			if (i == Input.length() - 1)
			{
				Chuoi.push_back(Input.substr(i, 1));
				break;
			}
			else if (i < Input.length() - 1)
			{
				for (int j = i + 1; j < Input.length(); j++) /* xem đằng trước của i có phải là toán tử hay không*/
					if (
						Input[j] == ')' ||
						Input[j] == '*' ||
						Input[j] == '/' ||
						Input[j] == '+' ||
						Input[j] == '-' ||
						Input[j] == '%' ||
						Input[j] == '^'/*dấu , sử dụng cho các hàm 2 biến nhu pow, max, min*/
						)
					{
						Chuoi.push_back(Input.substr(i, j - i));/* cắt chuỗi */
						i = j - 1;
						break;
					}
			}
		}
	}
}

int TrungTo::TimKhoangTrang(string str)// tim khoang trang
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ' ')
			return i;
	return -1;
}

void TrungTo::XoaKhoangTrang(string& str) //xoa khoang trang
{
	int ViTri;
	while ((ViTri = TimKhoangTrang(str)) != -1)
		str.erase(ViTri, 1);
}
int TrungTo::CheckError(string& x, string Input)
{
	for (int j = 0; j < Input.length(); j++)
	{
		int i;
		for (i = 0; i < x.length(); i++)
		{
			int count = i + 1;
			if (x[i] == '-' && x[count] == '-')
			{
				x.replace(i, 1, "+");
				x.erase(i + 1, 1);
			}
			if ((x[i] == '*' ||
				x[i] == '/' ||
				x[i] == '%' ||
				x[i] == '+' ||
				x[i] == '-' ||
				x[i] == '^' ||
				x[i] == 'z' ||
				x[i] == 'x' ||
				x[i] == 'c' ||
				x[i] == 'v' ||
				x[i] == 'b' ||
				x[i] == 'n' ||
				x[i] == 'e' ||
				x[i] == ',' ||
				x[i] == 'a' ||
				x[i] == 's' ||
				x[i] == 'd') && i == x.length() - 1)
			{
				cout << "Nhap sai roi ";
				exit(0);
			}
		}
	}
}




float TrungTo::Xuat(string Input)
{
	TrungTo* trungto = new TrungTo();
	vector<string> Chuoi;
	string x;
	x = FunctionOfMath(Input);
	XoaKhoangTrang(x);
	CheckError(x, Input);
	InputM(x, Chuoi);
	return VectorM(Chuoi);
}

