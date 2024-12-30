#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>

class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	//기본 생성자
	SimpleVector() : currentSize(0), currentCapacity(10) { data = new T[currentCapacity]; }

	//크기 지정 생성자
	SimpleVector(int inCapacity) : currentSize(0), currentCapacity(inCapacity) { data = new T[currentCapacity]; }

	//복사 생성자
	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}

	//소멸자
	~SimpleVector() {
		if(data) delete[] data;
	}

	//현재 배열의 마지막 원소 추가
	void push_back(const T& inValue) {
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);
		}

		data[currentSize++] = inValue;
	}

	//현재 배열의 마지막 원소 제거
	void pop_back() {
		if (currentSize > 0)
		{
			currentSize--;
		}
	}

	//현재 원소 개수 반환
	int size() const {
		return currentSize;
	}

	//현재 배열 크기 반환
	int capacity() const {
		return currentCapacity;
	}

	//정렬
	void sortData() {
		sort(data, data + currentSize);
	}

	//배열 크기 재할당
	void resize(int newCapacity) {
		if (newCapacity > currentCapacity)
		{
			T* newData = new T[newCapacity];
			for (int i = 0; i < currentSize; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			currentCapacity = newCapacity;
		}
	}

	//출력
	void print()
	{
		cout << "[";
		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i];
			if (i != currentSize - 1) cout << ", ";
		}
		cout << "]" << endl;
	}
};
