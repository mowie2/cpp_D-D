#pragma once
template<typename T>
class MyList
{
public:
	MyList()  
	{
		length = 0;
	}

	~MyList() 
	{
		delete[] list;
	}

	void AddItem(T &element) {
		T *buffer = new T[length + 1];
		memcpy(buffer, list, length);
		delete[] list;
		length++;
		list = buffer;
		list[length-1] = element;
	}

	T const GetItem(int index) {
		if (index < length && index >= 0) {
			return list[index];
		}
		return T();
	}

private:
	int length;
	T* list;
};

