#include "Vector.h"

#pragma once

template <typename T>

class Stack {

private:

	Vector<T> stack;

public:

	Stack() : stack(0) {};

	void pushS(T k) {
		this->stack.pushV(k);
	};

	size_t sizeS() {
		return this->stack.sizeV();
	};
	
	bool emptyS() {
		if (this->stack.sizeV() == 0) {
			return true;
		}
		return false;
	};

	T topS() {
		return this->stack.getV((stack.sizeV()) - 1);
	};

	void popS() {
		if (this->stack.sizeV() == 0) {
			throw "Error";
		}
		stack.eraseV((stack.sizeV()) - 1);
	};
};