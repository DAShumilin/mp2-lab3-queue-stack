#pragma once

#define Const 2

template <typename T>

class Vector {

private:

	T* dataV;
	size_t size = 0;
	size_t capacity = 0;

public:

	Vector(size_t n) {
		this->dataV = new T[Const * n];
		for (size_t i = 0; i < n; ++i) {
			this->dataV[i] = 0;
		}
		this->capacity = Const * n;
		this->size = n;
	};

	~Vector() {
		delete[] this->dataV;
	};

	Vector(const Vector& v) {
		this->resize(v.size);
		for (size_t i = 0; i < this->size; ++i) {
			this->dataV[i] = v.dataV[i];
		}
	};

	Vector& operator=(const Vector& v) {
		if (this == &v) {
			return *this;
		}
		delete[] this->dataV;
		this->capacity = v.capacity;
		this->size = v.size;
		this->dataV = new T[this->capacity];
		for (size_t i = 0; i < this->size; ++i) {
			this->dataV[i] = v.dataV[i];
		}
	};

	void resize(size_t newSize) {
		size_t result = newSize > this->size ? this->size : newSize;
		if (newSize < this->capacity) {
			this->size = newSize;
		}
		else {
			T* dataV_copy = new T[Const * newSize];
			for (size_t i = 0; i < result; ++i) {
				dataV_copy[i] = this->dataV[i];
			}
			delete[] this->dataV;
			this->dataV = dataV_copy;
			this->capacity = Const * newSize;
			this->size = newSize;
		}
	};

	void pushV(T k) {
		if (this->size == this->capacity) {
			resize(this->size + 1);
			this->dataV[this->size - 1] = k;
		}
		else {
			this->dataV[this->size] = k;
			this->size++;
		}
	};

	T popV() {
		T tmp = this->dataV[this->size - 1];
		this->size--;

		return tmp;
	};

	void eraseV(T h) {
		for (size_t i = h; i < this->size; ++i) {
			this->dataV[i] = this->dataV[i + 1];
		}
		this->size--;
	};

	size_t sizeV() {
		return this->size;
	};

	T getV(size_t i) {
		return this->dataV[i];
	};
};