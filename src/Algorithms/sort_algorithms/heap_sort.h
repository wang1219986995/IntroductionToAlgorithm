#ifndef HEAPSORTE_H
#define HEAPSORTE_H
#include <vector>

namespace IntroductionToAlgorihtms {

	template <class T>
	struct less {
		bool operator() (const T& l, const T& r) { return l < r; }
	};

	template <class T>
	struct greater {
		bool operator() (const T& l, const T& r) { return l > r; }
	};


	template < class T, class Container = std::vector<T>, class Compare = less<typename Container::value_type> >
	class Heap {
	public:
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		Heap() :c() {};
		Heap(Container& ct, Compare& x) :c(ct), cmp(x) { make_heap(); }


	public:
		bool empty() { return c.empty(); }
		

		void push(const value_type& x);
		const_reference top() const { return c.front(); }
		void pop();
		void heap_sort();
		size_type size() const { return c.size(); }
	private:
		size_type parent(size_type i) { return (i - 1) / 2; };
		size_type leftChild(size_type i) { return 2 * (i + 1) - 1; }
		size_type rightChild(size_type i) { return 2 * (i + 1); }
		void make_heap() {
			for (size_type i = c.size() / 2 - 1; i >= 0; --i) {
				adjust_heap(i);
			}
		};
		void adjust_heap(size_type i );
		void adjust_heap(size_type i, size_type size);

	public:
		Container c;
		Compare cmp;
	};

	template < class T, class Container, class Compare >
	void Heap<T,Container,Compare>::adjust_heap(size_type i) {
		size_type cur = i;
		size_type cur = i;
		size_type l = leftChild(i);
		size_type r = rightChild(i);
		size_type index = i;
		if (l < c.size() && cmp(c[i], c[l]))  index = l;
		if (r < c.size() && cmp(c[index],c[r]))  index = r;
		while (index != cur) {
			std::swap(c[cur], c[index]);
			cur = index;
			l = leftChild(cur);
			r = rightChild(cur);
			if (l < c.size() && cmp(c[i], c[l]) )  index = l;
			if (r < c.size() && cmp(c[index], c[r]) )  index = r;
		}
	}



	template < class T, class Container, class Compare >
	void Heap<T, Container, Compare>::pop() {
		if (c.size() <= 1) {
			c.clear();
			return;
		}
		std::swap(c.front(), c.back());
		c.pop_back();
		adjust_heap(0);
	}


	template < class T, class Container, class Compare >
	void Heap<T, Container, Compare>::push(const value_type& x){
		c.push_back(x);
		size_type cur = c.size()-1;

		while (cur > 0 && cmp(c[parent(cur)], c[cur] ) ) {
			c[cur] = c[parent(cur)];
			cur = parent(cur);
		}
		c[cur] = x;
	}


	template < class T, class Container, class Compare >
	void Heap<T, Container, Compare>::adjust_heap(size_type i, size_type size) {
		size_type cur = i;
		size_type l = leftChild(i);
		size_type r = rightChild(i);
		size_type index = i;
		if (l <= size && cmp(c[i], c[l]) )  index = l;
		if (r <= size && cmp(c[index], c[r]) )  index = r;
		while (index != cur) {
			std::swap(c[cur], c[index]);
			cur = index;
			l = leftChild(cur);
			r = rightChild(cur);
			if (l <= size && cmp(c[i], c[l]))  index = l;
			if (r <= size && cmp(c[index], c[r]))  index = r;
		}
	}

	template < class T, class Container, class Compare >
	void Heap<T, Container, Compare>::heap_sort() {
		size_type size = c.size() - 1;
		for (int i = c.size() - 1; i > 0; --i) {
			std::swap(c[0], c[i]);
			adjust_heap(0, i-1);
		}
	}







	
}



#endif // !HEAPSORTE_H
