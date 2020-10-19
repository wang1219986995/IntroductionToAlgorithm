#ifndef QUICKSORTE_H
#define QUICKSORTE_H
#include <vector>
#include <cstdlib>
namespace IntroductionToAlgorihtms {
	namespace SortAlgotithms {
		class QuickSort {
		public:
			std::vector<int> nums;
			void quick_sort();
			void quick_sort_aux(int begin, int end);
			int partition(int p,int r);

			void quick_sort_random();
			void quick_sort_aux_random(int begin, int end);
			int partition_random(int p, int r);

			//思考题7-1 hoare_sort 算法实现：
			void quick_hoare_sort();
			void quick_hoare_sort_aux(int begin, int end);
			int hoare_partition(int p, int r);



			//思考题 7-2 代码实现  P104；
			void quick_sort_();
			void quick_sort_aux_(int begin, int end);
			std::pair<int, int> partition_(int p, int r);


			//思考题 7-4 尾递归：
			void tail_recursive_quicksort(int begin, int end);

		};

		void QuickSort::quick_sort(){
			quick_sort_aux(0, nums.size()-1);
		}

		void QuickSort::quick_sort_aux(int begin, int end) {
			if (begin >= end)  return;
			int q = partition(begin, end);
			quick_sort_aux(begin, q-1);
			quick_sort_aux(q + 1, end);
		}

		int QuickSort::partition(int p, int r) {
			int x = nums[r];
			int cur = p - 1;
			for (int i = p; i < r; ++i) {
				if (nums[i] <= x) {
					cur += 1;
					std::swap(nums[cur], nums[i]);
				}
			}
			std::swap(nums[cur + 1], nums[r]);
			return cur + 1;
		}

		void QuickSort::quick_sort_random(){
			quick_sort_aux_random(0, nums.size() - 1);
		}

		void QuickSort::quick_sort_aux_random(int begin, int end){
			if (begin >= end)  return;
			int q = partition_random(begin, end);
			quick_sort_aux_random(begin, q - 1);
			quick_sort_aux_random(q + 1, end);
		}

		int QuickSort::partition_random(int p, int r){
			int ran = rand() % (r - p);
			ran += p;
			std::swap(nums[r], nums[ran]);
			int x = nums[r];
			int cur = p - 1;
			for (int i = p; i < r; ++i) {
				if (nums[i] <= x) {
					cur += 1;
					std::swap(nums[cur], nums[i]);
				}
			}
			std::swap(nums[cur + 1], nums[r]);
			return cur + 1;
		}


		void QuickSort::quick_sort_() {
			quick_sort_aux_(0, nums.size()-1);
		}
		void QuickSort::quick_sort_aux_(int begin, int end) {
			if (begin >= end)  return;
			std::pair<int, int> index = partition_(begin, end);
			quick_sort_aux_(begin, index.first - 1);
			quick_sort_aux_(index.second + 1, end);
			
		}

		std::pair<int,int> QuickSort::partition_(int p, int r) {
			int x = nums[r];
			int cur = p - 1;
			int count = 0;
			for (int i = p; i < r; ++i) {
				if (nums[i] < x) {
					cur += 1;
					int temp = nums[i];
					nums[i] = nums[cur + count];
					nums[cur + count] = nums[cur];
					nums[cur] = temp;
				}
				else if (nums[i] == x) {
					++count;
					swap(nums[i], nums[cur + count]);
				}
			}
			std::swap(nums[cur + count +1], nums[r]);
			return std::pair<int, int>(cur + 1, cur + count + 1);
		}

		void QuickSort::quick_hoare_sort() {
			quick_hoare_sort_aux(0, nums.size() - 1);
		}
		void QuickSort::quick_hoare_sort_aux(int begin, int end) {
			if (begin >= end)  return;
			int q = hoare_partition(begin, end);
			quick_hoare_sort_aux(0, q - 1);
			quick_hoare_sort_aux(q + 1, end);

		}
		int QuickSort::hoare_partition(int p, int r) {
			int x = nums[p];
			int i = p-1;
			int j = r+1;
			while (true) {
				while (nums[++i] < x && i <= r)  ;
				while (nums[--j] > x && j >= p)  ;
				if(i < j)  std::swap(nums[i], nums[j]);
				else return j;
			}
		}

		void QuickSort::tail_recursive_quicksort(int begin, int end) {
			while (begin < end) {
				int q = partition(begin, end);
				tail_recursive_quicksort(begin, q - 1);
				begin = q + 1;
			}
			

		}


	}
}



#endif // !QUICKSORTE_H
