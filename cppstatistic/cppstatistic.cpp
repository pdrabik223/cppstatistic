// cppstatistic.cpp: definiuje punkt wejścia dla aplikacji.
//
#include "ctx.h"
#include "cppstatistic.h"

template <class T>
class Myarray {
protected:
	T* data;
	unsigned size;
	unsigned MAX_SIZE;
	unsigned average_size;
public:
	Myarray() {
		average_size = 1;
		size = 0;
		MAX_SIZE = average_size;

		data = new T[average_size];

	}
	Myarray(unsigned average) {
		average_size = average;
		size = 0;
		MAX_SIZE = average_size;

		data = new T[average_size];
	}
	void push(T variable) {

		if (size >= MAX_SIZE) {
			T* temporary_data;
			memcpy(temporary_data, data, sizeof(T));
			MAX_SIZE += average_size;
			this->data = new T[MAX_SIZE];

			memcpy(data, temporary_data, sizeof(T));

			data[size] = variable;
			size++;
			delete[] temporary_data;

			return;
		}
		data[size] = variable;
		size++;
		return;

	}
	T& operator[](unsigned pos) { return data[pos]; }
	Myarray& operator=(const Myarray &other){
		if (*this == other) return *this;

		if (other.size < MAX_SIZE) {
			memcpy(other.data, data, sizeof(T));
			size = other.size;
			MAX_SIZE = other.MAX_SIZE;
			average_size = other.average_size;
			
		}
		else {
			data = new T[other.MAX_SIZE];
			memcpy(other.data, data, sizeof(T));
			size = other.size;
			MAX_SIZE = other.MAX_SIZE;
			average_size = other.average_size;
		}
			return *this;

	}
	~Myarray() { delete[] data; }

};
int main()
{
	std::cout << "Hello CMake." << std::endl;
	std::vector<int> vec;
	Myarray<int> my(30);

	vec.push_back(10);

	my.push(10);
	std::cout <<my[0];
	return 0;
}
