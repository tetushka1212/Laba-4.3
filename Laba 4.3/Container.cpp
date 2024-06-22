#include "Container.h"

void Container::Print()
{
	cout << "Size of your container: " << Size << endl;
	for (int i = 0; i < Size; i++) 
	{
		cout << i + 1<<". element: " << data[i] << endl;
	}
}

void Container::Add(int element)
{
	cout << "-------"<<endl;
	if (Contains(element)) {
		ReSize(Size + 1);
		data[Size - 1] = element;
	}
}

bool Container::Contains(int element)
{
	for (int i = 0; i < Size; i++) {
		if (data[i] == element) {
			return true;
		}
	}
	;
}

void Container::ReSize(int new_size)
{
	int* newElements = new int[new_size];
	for (int i = 0; i < min(static_cast <int> (Size),new_size); i++) {
		newElements[i] = data[i];
	}
	delete[] data;
	data = newElements;
	Size = new_size;

}

void Container::Remove(int element)
{
	int index = -1;
	for (int i = 0; i < Size; i++) {
		if (data[i] == element) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int i = index; i < Size - 1; i++) {
			data[i] = data[i + 1];
		}
		ReSize(Size - 1);
	}

}

Container Container::Merge(Container& other)
{
	for (int i = 0; i < other.Size; i++) {
		this->Add(other.data[i]);
	}
	return
}
