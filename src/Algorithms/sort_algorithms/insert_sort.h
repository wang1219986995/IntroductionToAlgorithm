#ifndef INSERTSORTE_H
#define INSERTSORTE_H

namespace IntroductionToAlgorihtms {
	namespace SortAlgotithms {

		//…˝–Ú≈≈¡–
		template<typename Iterator, typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>> 
		void insert_sort(const Iterator begin, const Iterator end, CompareType compare = CompareType()) {
			auto size = std::distance(begin, end);
			if (size <= 1)  return;
			auto current = begin;
			while (++current != end) {
				auto key = *current;
				auto small_next = current;
				while (small_next != begin && compare(key, *(small_next - 1))) {
					*small_next = *(small_next - 1);
					--small_next;
				}
				*small_next = key;
			}
		}

		//Ωµ–Ú≈≈¡–
		template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
		void insert_sort_reverse(const Iterator begin, const Iterator end, CompareType compare = CompareType()) {
			auto size = std::distance(begin, end);
			if (size <= 1)  return;
			auto current = begin;
			while (++current != end) {
				auto key = *current;
				auto small_next = current;
				while (small_next != begin && compare(*(small_next - 1),key)) {
					*small_next = *(small_next - 1);
					--small_next;
				}
				*small_next = key;
			}
		}





	}
}



#endif // !INSERTSORTE_H
