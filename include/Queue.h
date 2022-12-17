#pragma once


const size_t MAX_QUEUE_SIZE = 100000000;

template <typename T>
class TQueue
{
protected:

	T* pMem;
	size_t size;
	size_t end;
	size_t start;
	size_t count;

	const static size_t unzero = ~0;

public:

	TQueue(size_t _size = 1);
	TQueue(const TQueue& q);
	TQueue(TQueue&& q);
	~TQueue();

	bool IsEmpty();
	bool IsFull();

	void Free();

	size_t GetSize();

	void Push(const T& e);
	T Top();
	void Pop();
	T TopPop();

	TQueue& operator=(const TQueue& q);

};

template<typename T>
inline TQueue<T>::TQueue(size_t _size) : end(0), start(0), pMem(nullptr), count(0)
{
	if ((_size < 1) && (_size > MAX_QUEUE_SIZE))
		throw "Queue size error";

	size = _size;

	pMem = new T[size];
}

template<typename T>
inline TQueue<T>::TQueue(const TQueue<T>& q)
{
	if (q.pMem == nullptr)
	{
		size = 0;

		pMem = nullptr;

		Free();
	}
	else
	{
		size = q.size;

		end = q.end;

		start = q.start;

		count = q.count;

		pMem = new T[size];

		size_t j = end;

		for (size_t i = 0; i < count; i++)
		{
			pMem[j] = q.pMem[j];

			j--;

			if (j == unzero)
				j = size - 1;
		}
	}
}

template<typename T>
inline TQueue<T>::TQueue(TQueue<T>&& q) 
{
	size = q.size;
	
	pMem = q.pMem;
	
	count = q.count;
	
	start = q.start;
	
	end = q.end;
	
	q.size = 0;

	q.pMem = nullptr;

	q.count = 0;

	q.start = 0;

	q.end = 0;
}

template<typename T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
	if (this == &q)
		return *this;

	if (size != q.size)
	{
		T* tmp = new T[q.size];

		delete[] pMem;

		size = q.size;

		pMem = tmp;
	}
	end = q.end;

	start = q.start;

	count = q.count;

	if (!(q.IsEmpty()))
	{
		size_t j = end;

		for (size_t i = 0; i < count; i++)
		{
			pMem[j] = q.pMem[j];

			j--;

			if (j == unzero)
				j = size - 1;
		}
	}
	return *this;
}


template<typename T>
inline TQueue<T>::~TQueue()
{
	delete[] pMem;

	size = 0;

	Free();
}

template<typename T>
inline bool TQueue<T>::IsEmpty()
{
	return (count == 0);
}

template<typename T>
inline bool TQueue<T>::IsFull() 
{
	return (count == size);
}

template<typename T>
inline void TQueue<T>::Free()
{
	end = 0;

	start = 0;

	count = 0;
}

template<typename T>
inline size_t TQueue<T>::GetSize()
{
	return size;
}

template<typename T>
inline void TQueue<T>::Push(const T& e)
{
	if (IsFull())
		throw "Queue is full error";

	pMem[start] = e;

	start++;

	start = (start < size) ? start : 0;

	count++;
}

template<typename T>
inline T TQueue<T>::Top() 
{
	if (IsEmpty())
		throw "Queue is empty";

	return pMem[end];
}

template<typename T>
inline void TQueue<T>::Pop()
{
	if (IsEmpty())
		throw "Queue is empty";

	end++;

	end = (end < size) ? end : 0;

	count--;
}

template<typename T>
inline T TQueue<T>::TopPop()
{
	T tmp = Top();

	Pop();

	return tmp;
}
