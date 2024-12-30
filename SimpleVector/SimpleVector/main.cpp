#include "SimpleVector.h"
#include <string>
#include <ctime>
#include <random>

int main() {
	srand((unsigned int)time(NULL));

	SimpleVector<int> SV_int;
	SimpleVector<string> SV_str(20);

	//생성자 테스트
	cout << "기본 생성자 currentCapacity : " << SV_int.capacity() << endl;
	cout << "크기 지정 생성자 currentCapacity : " << SV_str.capacity() << endl;


	//push_back 테스트
	for (int i = 0; i < 14; i++)
	{
		SV_int.push_back(rand() % 30);
		cout << "push_back(" << i << ") : currentSize = " << SV_int.size() << " | currentCapacity = " << SV_int.capacity() << endl;
	}

	SV_int.print();

	//복사 생성자 테스트
	SimpleVector<int> SV_intClone(SV_int);
	cout << "복사 생성자 currentCapacity : " << SV_intClone.capacity() << endl;
	SV_intClone.print();

	//pop_back 테스트
	for (int i = 0; i < 4; i++)
	{
		SV_int.pop_back();
		cout << "pop_back() : currentSize = " << SV_int.size() << " | currentCapacity = " << SV_int.capacity() << endl;
	}

	SV_int.print();

	//sort 테스트
	SV_int.sortData();
	SV_int.print();
	
	//resize 테스트
	SV_int.resize(30);
	cout << "resize(30) : currentSize = " << SV_int.size() << " | currentCapacity = " << SV_int.capacity() << endl;

	return 0;
}