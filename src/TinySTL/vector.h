#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <algorithm>
#include <iterator>
#include <algorithm>
#include <type_traits>

namespace TinySTL {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		// 成员变量定义：
	public:
		typedef T                               value_type;
		typedef value_type*                     pointer;
		typedef const value_type*               const_pointer;
		typedef value_type*                     iterator;
		typedef const value_type*               const_iterator;
		typedef reverse_iterator<T*>            reverse_iterator;
		typedef reverse_iterator<const T*>      const_reverse_iterator;
		typedef value_type&                     reference;
		typedef const value_type&               const_reference;
		typedef size_t                          size_type;
		typedef ptrdiff_t                       difference_type;
	protected:
		iterator start;
		iterator finish;
		iterator end_of_storage;
		typedef Alloc dataAllocator;



		void insert_aux(iterator position, const T& x);
		void deallocate() {
			if (start)  dataAllocator::deallocate(start, end_of_storage - start);
		}
		void fill_initialize(size_type n, const T& value) {
			start = allocate_and_fill(n, value);
			finish = start + n;
			end_of_storage = finish;
		}






		//成员函数相关定义：
	public:
		//构造与析构函数, 比较操作符：
		vector() : start(0), finish(0), end_of_storge(0) {};
		explicit vector(const size_type n) { fill_initialize(n, T()); }
		vector(const size_type n, const value_type& value) { fill_initialize(n, value); }
		vector(const int n, const value_type& value) { fill_initialize(n, value); }
		vector(const long n, const value_type& value) { fill_initialize(n, value); }
		template<class InputIterator>
		vector(InputIterator first, InputIterator last) :start(0), finish(0), end_of_storage(0) { range_initialize(first, last, iterator_category()); }
		vector(const vector& v);
		vector(vector&& v);
		vector& operator = (const vector& v);
		vector& operator = (vector&& v);
		~vector() {
			destory(start, finish);
			deallocate();
		}

		//比较操作：
		bool operator == (const vector& v) const;
		bool operator != (const vector& v) const;

	public:
		//迭代器相关：
		iterator begin() { return start; }
		const_iterator begin() const {  return start; }
		iterator end() { return finish; }
		const_iterator end() const { return finish; }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }


		//容量相关：
		size_type size() const { return size_type(end() - begin()); }
		size_type max_size() const { return size_type(-1) / sizeof(T); }
		size_type capacity() const { return size_type(end_of_storage - begin()); }
		bool empty() const { return bigin() == end(); }
		void reserve(size_type n);
		void shrink_to_fit();


		//访问元素相关：
		reference operator[] (size_type n) { return *(begin() + n); }
		const reference operator[] (size_type n) const { return *(begin() + n); }
		reference at(size_type n) { return (*this)[n]; }
		const_reference at(size_type n) const { return (*this)[n]; }
		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }
		reference back() { return *(end() - 1); }
		const_reference back() const { return *(end() - 1); }
		pointer data() noexcept;
		const_pointer data() const noexcept;
		

		//容器修改操作：
		void push_back(const T& x) {
			if (finish != end_of_storage) {
				construct(finish, x);
				++finish;
			}
			else
				insert_aux(end(), x);
		}
		void pop_back();
		void swap(vector<T, Alloc>& x) {
			std::swap(start, x.start);
			std::swap(finish, x.finish);
			std::swap(end_of_storage, x.end_of_storage);
		}
		iterator insert(iterator position, const T& x) {
			size_type n = position - begin();
			if (finish != end_of_storage && position == end()) {
				construct(finish, x);
				++finish;
			}
			else
				insert_aux(position, x);
			return begin() + n;
		}
		iterator insert(iterator position) { return insert(postiot, T()); }
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {
			range_insert(position, first, last, iterator_categoy(first));
		}
		void insert(iterator pos, size_type n, const T& x);
		void insert(iterator pos, int n, const T& x) { insert(pos, (size_type)n, x); }
		void insert(iterator pos, long n, const T& x) { insert(pos, (size_type)n, x); }
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void resize(size_type new_size, const T& x);
		void resize(size_type new_size);
		void clear();

		Alloc get_allocatr() { return dataAllocator; }




	private:
		void insert_aux(iterator position, const T& x);
		void deallocate();
		void fill_initialize(size_type n, const T& value)
		iterator allocate_and_fill(size_type n, const T& x);
		template <class ForwardIterator>
		iterator allocate_and_copy(size_type n, ForwardIterator first, ForwardIteratorlast);




	};

	//赋值构造函数
	template <class T, class Alloc>
	vector<T, Alloc>& vector<T, Alloc>::operator = (const vector<T, Alloc>& x) {
		if (&x != this);
		if(x.size() > capacity())
	}

	template <class T, class Alloc>
	vector<T, Alloc>& vector<T, Alloc>::vector(const vector<T, Alloc>& x) {
		start = allocate_and_copy(x.end() - x.begin(), x.begin(), x.end());
		finish = start + (x.end() - x.begin());
		end_of_startge = finish;
	}

	template <class T, class Alloc= std::allocator<T> >
	inline bool operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs.size() == rhs.size()) && equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc = std::allocator<T> >
	inline bool operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::insert_aux(iterator position, const T& x) {
		if (finish != end_of_storage) {
			construct(finish, *(finish - 1));
			++finish;
			T x_copy = x;
			copy_backward(position, finish - 2, finish - 1);
			*position = x_copy;
		}
		else {
			const size_tpe old_size = size();
			const size_type len = old_size != 0 ? 2 * old_size : 1;
			iterator new_start = dataAllocator::allocate(len);
			iterator = new_finish = new_start;
			try {
				new_finish = uninitialized_copy(start, position, new_start);
				construct(new_finish, x);
				++new_finish;
				new_finish = unitialized_copy(position, finish, new_finish);
			}
			catch (...) {
				destroy(new_start, new_finish);
				dataAllocator::deallocate(new_start, len);
			}
			destroy(begin(), end());
			deallocate();
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}
	}

	template<class T, Alloc>
	void vector<T, Alloc>::insert(iterator position, size_type n, const T& x) {
		if (n != 0) {
			if (size_type(end_of_storage - finish) >= n) {
				T x_copy = x;
				const size_type elems_after = finish - position;
				iterator old_finish = finish;
				if (elems_after > n) {
					unitialized_copy(finish - n, finish, finish);
					finish += n;
					copy_backward(position, odl_finish, finish);
					fill(position, position + n, x_copy);
				}
			}
			else {
				unitialized_fill_n(finish,n-elems_after)
			}
		}
	}


}




#endif // !_VECTOR_H_



