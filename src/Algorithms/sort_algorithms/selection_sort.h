#ifndef SELECTIONSORTE_H
#define SELECTIONSORTE_H

namespace IntroductionToAlgorihtms {
	namespace SortAlgotithms {

		template<typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
		void selection_sort(const Iterator begin, const Iterator end, CompareType compare = CompareType()) {
			auto size = std::distance(begin, end);
			if (size <= 1)  return;
			auto i = begin;
			while ( i != end) {
				auto j = i;
				auto key = j;
				while (j != end) {
					if (compare(*j, *key)) {
						key = j;
					}
					j++;
				}
				auto temp = *i;
				*i = *key;
				*key = temp;
				i++;
			}
		}



	}
}



#endif // !SELECTIONSORTE_H
