#pragma once

#include <stdio.h>
#include <string>
using namespace std;
class NODE //Một node trong danh sách liên kết đơn được cấu thành từ hai thành phần là dữ liệu và phần kết nối(Next).
{
public:
	string Data;
	NODE* pNext;
};
/*Lý do sử dụng Danh sách liên kết đơn thay vì mảng.
-Danh sách liên kết có kích thước động, có thể mở rộng hay thu hẹp rất dễ ràng.
-Việc chèn hay xóa một phần tử trong danh sách liên kết là rất dễ dàng, ta chỉ cần thay đổi vị trí trỏ của các con trỏ thay vì phải dịch toàn bộ phần dữ liệu còn lại.*/
typedef NODE Node;
/*Phù hợp cho việc khai báo stack và sử dụng nó sẽ dễ dàng hơn so với các cấu trúc dữ liệu còn lại*/
class Stack
{
private:
	Node* pHead;

public:
	Stack();
	~Stack();
	int IsEmpty();
	Node* CreateNode(string str);
	void Push(string str);
	int Pop(string& str);
	Node* Top();
};