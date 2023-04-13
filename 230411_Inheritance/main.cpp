#include <iostream>
using namespace std;

class CParent {

public:
	int pVal;

public:
	CParent() {
		//cout << "Cparent Constructor" << endl;
	}
	~CParent() {
	//	cout << "cparent Destrictor" << endl;
	}


	virtual void Func() = 0;
	//virtual void Func() {
	//	cout << "Cparent Func" << endl;
	//}
};

class CChild : public CParent {

public:
	int cVal;

	CChild() {
	//	cout << "CChild Constructor" << endl;
	}
	~CChild() {
	//	cout << "CChild Destrictor" << endl;
	}

	void Func() {
		cout << "CChild Func" << endl;
	}
};

class CNewChild : public CParent
{
public:
	void Func() {
		cout << "CNewChild Func\n" << endl;
	}
};


void main() {
	//CParent* parent = new CParent();
	//printf("Parent Size: %d\n", sizeof(CParent));
	//printf("Parent->pVal: %p\n", &parent->pVal);

	//delete parent;

	CChild* child = new CChild();
	//printf("CChild Size: %d\n", sizeof(CChild));
	//printf("child->pVal: %p\n", &child->pVal);
	//printf("Child->cVal: %p\n", &child->cVal);

	//((CParent*)child)->Func();
	CParent* parent = child;
	parent->Func();
	//((CChild*)parent)->Func();

	CNewChild* newChild = new CNewChild();
	parent = newChild;


	// �̰�� ���Ǹ��� �Լ��� ������������
	//if(1<5) child->func();
	//else newChild ->func();
	// �������� �Ǵ� ���߾� �Լ��� ����� �Լ��� ����� �����ǵ� �θ���
	// �Լ��� ����� ����������.
	// void FuncVirtual(_child, _newchild)
	//{
	//if (1 < 5) parent = _child;
	//else parent = _newChild;
	//parent->Func();
	//}
	// null ��ü ã�ƺ���.
	delete newChild;
	delete child;




}