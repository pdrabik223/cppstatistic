// cppstatistic.cpp: definiuje punkt wejścia dla aplikacji.
//
#include "ctx.h"
#include "cppstatistic.h"
#include <time.h>
#include <chrono>
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
	srand(time(NULL));
	std::cout << "Hello CMake." << std::endl;
	std::vector<int> *vec;
	Myarray<int> *my;
	ctx<int, double> push("create_and_push");

	

	for (int i = 0; i < 1000; i++) {
	
		
		
		my = new Myarray<int>(30);

		vec = new std::vector<int>;
		std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
		for (int j = 0; j < i; j++) {
			my->push(0);
		}
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

		
		start = std::chrono::steady_clock::now();

		for (int j = 0; j < i; j++) {
			vec->push_back(0);
		}
		
		end = std::chrono::steady_clock::now();




		delete[] my;
		delete[] vec;

		

	}


	return 0;
}
