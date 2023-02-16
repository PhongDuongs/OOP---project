#include "pch.h"
#include "Stack.h"


Stack::Stack()
{
	pHead = NULL;
}

int Stack::IsEmpty()
{

	if (pHead == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Stack::~Stack()/*Kiểm tra nếu mà trong danh sách liên kết vẫn còn dữ liệu ta sẽ xoá đi node đó*/
{
	while (IsEmpty() == 0)
	{
		Node* p = pHead;
		pHead = p->pNext;
		delete p;
	}
}



Node* Stack::CreateNode(string str)/*KHởi tạo 1 node mới mục đích để liên kết và push vào stack*/
{
	Node* p = new Node();
	p->Data = str;
	p->pNext = NULL;
	return p;
}

void Stack::Push(string str)
{
	Node* p = CreateNode(str);/*Ta khởi tạo một node p*/
	/*Nếu danh sách liên kết rỗng ta sẽ cho p là node đầu tiên với tên gọi là pHead*/
	if (IsEmpty() == 1)
	{
		pHead = p;
	}
	else
	{
		/*Nếu trong danh sách đã có node thì ta sẽ thêm vào đầu */
		p->pNext = pHead;
		pHead = p;
	}
}

int Stack::Pop(string& str)
{/*Xoá ở đầu*/
	if (IsEmpty())
	{
		/*ta kiểm tra xem danh sách đó có rỗng hay không, nếu rỗng, ta không cần xóa, trả về kết quả là 0. */
		return 0;
	}
	else
	{/*Nếu danh sách không rỗng, ta thực hiện lưu node head lại, sau đó gán head bằng next của node head, sau đó xóa node head đi.*/
		Node* p = pHead;
		str = p->Data;
		pHead = p->pNext;
		delete p;
	}
	return 1;
}

Node* Stack::Top()
{
	/*Trả về node head*/
	return pHead;
}
