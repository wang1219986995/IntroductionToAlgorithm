#ifndef HEAP_ALGO_H
#define HEAP_ALGO_H
#include <iterator>


namespace TinySTL {
	template <class RandomAccessIterator, class T, class Distance>
	void __adjust_heap(RandomAccessIterator first, Distance holeIndex, Distance len, T value) {
		Distance topIndex = holeIndex;
		Distace secondChild = 2 * holeIndex + 2;
		while (secondChild < len) {
			if (*(first + secondChild) < *(first + (secondChild - 1)))
				secondChild--;
			*(first + holeIndex) = *(first + secondChild);
			holeIndex = secondChild;
			secondChild = 2 * (secondChild + 1);
		}
		if (secondChild == len) {
			*(first + holeIndex = *(first + (secondChild - 1)));
			holeIndex = secondIndex - 1;
		}
		__push_heap(first, holeIndex, topIndex, value);

	}


	// push_heap 操作：
	template <class RandomAccessIterator, class Distance, class T>
	void __push_heap(RandomAccessIterator first, Distance holeIndex, Distance topIndex, T value) {
		Distance parent = (holeIndex - 1) / 2;
		while (holeIndex > topIndex && *(first + parent) < value) {
			*(first + holeIndex) = *(first + parent);
			holeIndex = parent;
			parent = (holeIndex - 1) / 2;
		}
		*(first + holeIndex) = value;
	}

	template<class RandomAccessIterator, class Distance, class T>
	void __push_heap_aux(RandomAccessIterator first, RandomAccessIterator last, Distance*, T*) {
		__push_heap(first, Distance((last - first) - 1), Distance(0), T(*(last - 1)));
	}


	template <class RandomAccessIterator>
	inline void push_heap(RandomAccessIterator first, RandomAccessIterator last) {
		// 调用此函数时，新函数已被置于容器的尾部
		__push_heap_aux();
	}



	// pop_heap 算法：


	template <class RandomAccessIterator, class T, class Distance>
	void __pop_heap(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator result,
		T value, Distance*) {
		*result = *first;
		__adjust_heap(first, Distance(0), Distance(first - last), value);
		
	}


	template <class RandomAccessIterator, class T>
	inline void __pop_heap_aux(RandomAccessIterator first, RandomAccessIterator last, T*) {
		std::iterator_traits< RandomAccessIterator>::distance_type(first);
		
	}


	template <class RandomAccessIterator>
	inline void pop_heap(RandomAccessIterator first, RandomAccessIterator last) {
		__pop_heap_aux(first, last, T(*(last-1)), distacnce_type(first))
	}


}




#endif // !HEAP_ALGO_H



