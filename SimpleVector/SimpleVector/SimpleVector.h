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
	//�⺻ ������
	SimpleVector() : currentSize(0), currentCapacity(10) { data = new T[currentCapacity]; }

	//ũ�� ���� ������
	SimpleVector(int inCapacity) : currentSize(0), currentCapacity(inCapacity) { data = new T[currentCapacity]; }

	//���� ������
	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}

	//�Ҹ���
	~SimpleVector() {
		if(data) delete[] data;
	}

	//���� �迭�� ������ ���� �߰�
	void push_back(const T& inValue) {
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);
		}

		data[currentSize++] = inValue;
	}

	//���� �迭�� ������ ���� ����
	void pop_back() {
		if (currentSize > 0)
		{
			currentSize--;
		}
	}

	//���� ���� ���� ��ȯ
	int size() const {
		return currentSize;
	}

	//���� �迭 ũ�� ��ȯ
	int capacity() const {
		return currentCapacity;
	}

	//����
	void sortData() {
		sort(data, data + currentSize);
	}

	//�迭 ũ�� ���Ҵ�
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

	//���
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
