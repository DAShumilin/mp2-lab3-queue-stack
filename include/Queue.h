#pragma once

#define Const 2

template <typename T>

class Queue {

private:

	T* dataQ;
	size_t itPush = 0;
	size_t itPop = 0;
	size_t sizeQR = 0;
	size_t sizeQI = 0;

	void resize(size_t newSize) {
		T* dataV_copy = new T[Const * newSize];

		for (size_t i = 0; i < newSize; ++i) {
			dataV_copy[i] = this->dataQ[i];
		}

		size_t tmp_itPush = this->sizeQR;
		size_t tmp_itPop = this->itPop;

		delete[] this->dataQ;
		this->dataQ = dataV_copy;
		this->sizeQI = Const * newSize;
		this->sizeQR = newSize;
		this->itPush = tmp_itPush;
		this->itPop = tmp_itPop;
	};

public:

	Queue() : sizeQI(5) {
		this->dataQ = new T[5];
		for (size_t i = 0; i < sizeQI; ++i) {
			this->dataQ[i] = 0;
		}
	};

	~Queue() {
		delete[] this->dataQ;
	};

	void pushQ(T k) {
		if ((itPush == itPop && sizeQR == 0) || (itPush != itPop && itPush < sizeQI)) {
			dataQ[itPush] = k;
			++itPush;
			++sizeQR;
		}
		else if (itPush == sizeQI && itPop != 0 && sizeQR != sizeQI) {
			itPush = 0;
			dataQ[itPush] = k;
			++itPush;
			++sizeQR;
		}
		else {
			resize(sizeQR);
			dataQ[itPush] = k;
			++itPush;
			++sizeQR;
		}
	};

	void popQ() {
		if (sizeQR == 0) {
			throw "Error";
		}
		dataQ[itPop] = 0;
		++itPop;
		--sizeQR;
	}

	bool emptyQ() {
		return !sizeQR;
	};

	size_t sizeQ() {
		return sizeQR;
	};

	T topQ() {
		if (sizeQR < 1) {
			throw "Error";
		}
		return dataQ[itPop];
	};
};