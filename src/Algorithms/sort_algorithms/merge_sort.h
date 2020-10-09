#ifndef MERGESORTE_H
#define MERGESORTE_H
#include <vector>

namespace IntroductionToAlgorihtms {
	namespace SortAlgotithms {

		//升序排列
		template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>> 
		void merge(const Iterator begin, const Iterator mid,const Iterator end, CompareType compare = CompareType()) {
			typedef typename std::iterator_traits<Iterator>::value_type T;
			int n1 = std::distance(begin, mid);
			int n2 = std::distance(mid, end);
			std::vector<T> result(n1 + n2);
			auto current = result.begin();
			auto left_current = begin;
			auto right_current = mid;
			while (left_current != mid && right_current != end) {
				if (compare(*left_current, *right_current)    *current++ = *left_current++;//左侧较小
				else                                          *current++ = *right_current++;//左侧较小
			}
			if (left_current == mid && right_current != end) { std::copy(right_current, end, current); }
			if (right_current == end && left_current != mid) { std::copy(left_current, mid, current); }
			std::copy(result.begin(), result.end(), begin);
		}


		template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>> 
		void merge_sort(const Iterator begin, const Iterator end, CompareType compare = CompareType()) {
			auto size = std::distance(begin, end);
			if (size > 1) {
				Iterator mid = begin + size / 2;
				merge_sort(begin, mid,compare);
				merge_sort(mid, end,compare);
				merge(begin, mid, end,compare);
			}
		}




	}
}



#endif // !MERGESORTE_H
