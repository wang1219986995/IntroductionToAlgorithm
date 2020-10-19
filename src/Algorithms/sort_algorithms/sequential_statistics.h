#ifndef SEQUENTIALSTATISTICS_H
#define SEQUENTIALSTATISTICS_H
#include <vector>

// 第9章  中位数和顺序统计量
namespace IntroductionToAlgorihtms {
	namespace SortAlgotithms {
		class Sequential {
		public:
			std::vector<int> nums;

			int randomized_select_recursion(int bit);
			int randomized_select_recursion_aux(int begin, int end,int bit);
			int partition_random(int p, int r);

			int randomized_select_iteration(int bit);
			int randomized_select_iteration_aux(int begin, int end, int bit);
		};

		int Sequential::randomized_select_recursion(int bit) {
			int res = randomized_select_recursion_aux(0, nums.size()-1,bit);
			return res;
		}

		int Sequential::randomized_select_recursion_aux(int begin, int end,int bit) {
			if (begin == end)  return nums[begin];
			int q = partition_random(begin, end);
			int k = q - begin + 1;
			if (k == bit)  return nums[q];
			else if (bit < k)	randomized_select_recursion_aux(begin, q - 1,bit);
			else randomized_select_recursion_aux(q + 1, end, bit-k);
		}

		int Sequential::partition_random(int p, int r) {
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

		int Sequential::randomized_select_iteration(int bit) {
			int res = randomized_select_iteration_aux(0, nums.size()-1, bit);
			return res;
		}

		int Sequential::randomized_select_iteration_aux(int begin, int end, int bit) {
			while (true) {
				if (begin == end)  return nums[begin];
				int q = partition_random(begin, end);
				int k = q - begin + 1;
				if (k == bit)  return nums[q];
				else if (bit < k)  end = q - 1;
				else {
					begin = q + 1;
					bit -= k;
				}
			}
			//return nums[begin];
		}

	}
}



#endif // !SEQUENTIALSTATISTICS_H
