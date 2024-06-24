#pragma once
#include <iostream>

using namespace std;

class Container
{
private:
	int* data;
	size_t Size;
public:
	Container(size_t new_size = 0, bool pointer = 0) 
	{
		data = new int[new_size];
		Size = new_size;
		if (pointer != 0) 
		{
			for (int i = 0; i < Size; i++)
			{
				cout << "Input element number: " << i + 1 << "  ";
				cin >> data[i];
			}
		}
		else{
			for (int i = 0; i < Size; i++)
			{
				data[i] = 0;
			}
		}
	}
	Container(int other[], size_t length)
	{ 
		Size = length;
		data = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			data[i] = other[i];
		}
	}
	Container(Container& other) 
	{
		data = new int[other.Size];
		Size = other.Size;
		for (int i = 0; i < Size; i++) { data[i] = other.data[i]; }
	}
	void Print();
	void Add(int element);
	bool Contains(int element);
	void ReSize(int new_size);
	void Remove(int element);
	Container Merge(Container& other);
	Container Difference(Container& other) {
		Container result(*this);

		for (size_t i = 0; i < other.Size; ++i) {
			result.Remove(other.data[i]);
		}

		return result;
	}
	Container Intersection(Container& other) {
		Container result;

		for (size_t i = 0; i < Size; ++i) {
			if (other.Contains(data[i])) {
				result.Add(data[i]);
			}
		}

		return result;
	}
	~Container() { delete[] data; }
};

