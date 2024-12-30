#include "SimpleVector.h"
#include <string>
#include <ctime>
#include <random>

int main() {
	srand((unsigned int)time(NULL));

	SimpleVector<int> SV_int;
	SimpleVector<string> SV_str(20);

	//������ �׽�Ʈ
	cout << "�⺻ ������ currentCapacity : " << SV_int.capacity() << endl;
	cout << "ũ�� ���� ������ currentCapacity : " << SV_str.capacity() << endl;


	//push_back �׽�Ʈ
	for (int i = 0; i < 14; i++)
	{
		SV_int.push_back(rand() % 30);
		cout << "push_back(" << i << ") : currentSize = " << SV_int.size() << " | currentCapacity = " << SV_int.capacity() << endl;
	}

	SV_int.print();

	//���� ������ �׽�Ʈ
	SimpleVector<int> SV_intClone(SV_int);
	cout << "���� ������ currentCapacity : " << SV_intClone.capacity() << endl;
	SV_intClone.print();

	//pop_back �׽�Ʈ
	for (int i = 0; i < 4; i++)
	{
		SV_int.pop_back();
		cout << "pop_back() : currentSize = " << SV_int.size() << " | currentCapacity = " << SV_int.capacity() << endl;
	}

	SV_int.print();

	//sort �׽�Ʈ
	SV_int.sortData();
	SV_int.print();
	
	//resize �׽�Ʈ
	SV_int.resize(30);
	cout << "resize(30) : currentSize = " << SV_int.size() << " | currentCapacity = " << SV_int.capacity() << endl;

	return 0;
}