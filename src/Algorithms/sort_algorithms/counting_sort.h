#ifndef COUNTINGSORTE_H
#define COUNTINGSORTE_H
#include <vector>
namespace IntroductionToAlgorihtms {
	namespace SortAlgotithms {


		//  默认计数向量为 0-100
		class CountingSort {
		public:
			std::vector<int> nums;
			void counting_sort();

			//习题8.2 - 4 算法实现：
			int count_of(int a, int b);
		};

		void CountingSort::counting_sort() {
			std::vector<int> count(101);
			for (int i = 0; i < nums.size(); ++i)	count[nums[i]]++;
			for (int i = 1; i < count.size(); ++i)	count[i] += count[i - 1];
			std::vector<int> res(nums.size());
			for (int i = nums.size() - 1; i >= 0; --i) {
				res[count[nums[i]]-1] = nums[i];
				--count[nums[i]];
			}
			nums = res;
		}

		int CountingSort::count_of(int a, int b) {
			std::vector<int> count(36);
			for (int i = 0; i < nums.size(); ++i)	count[nums[i]]++;
			for (int i = 1; i < count.size(); ++i)	count[i] += count[i - 1];
			for (auto i : count)  cout << i << " ";
			cout << endl;
			
			return count[b] - count[a-1];
		}





	}
}



#endif // !COUNTINGSORTE_H
