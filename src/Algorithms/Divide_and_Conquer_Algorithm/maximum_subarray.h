#ifndef DIVIDEANDCONQUER_H
#define DIVIDEANDCONQUER_H
#include <vector>
#include <iostream>
using namespace std;


class MaxSubarry {
public:
	std::vector<int> nums;
private:
	int first;
	int last;

public:
	MaxSubarry(std::vector<int>& n) : nums(n), first(0), last(nums.size() - 1) {};
	void set(int x, int y) { first = x; last = y; }
	int find_maximum_subarray_Recursion(int low, int high);
	int find_maximum_subarray_Violence(int low, int high);
	int find_maximum_subarry_RecursionAndViolence(int low, int high, int k);
	int find_maximum_subarry_Lineary(int low, int high);



private:
	int find_max_crossing_subarray(int low, int mid, int high);

};

int MaxSubarry::find_maximum_subarray_Recursion(int low, int high) {
	if (high == low)	return nums[low];
	auto mid = low + (high - low) / 2;
	int sum_left = this->find_maximum_subarray_Recursion(low, mid);
	int sum_right = this->find_maximum_subarray_Recursion(mid + 1, high);
	int sum_mid = find_max_crossing_subarray(low, mid, high);

	if (sum_left >= sum_right && sum_left >= sum_mid)	return sum_left;
	else if (sum_right >= sum_left && sum_right >= sum_mid)	return sum_right;
	else    return sum_mid;
}

int MaxSubarry::find_max_crossing_subarray(int low, int mid, int high) {
	int left_sum = INT_MIN, sum = 0;
	int left_index = mid;
	for (int i = mid; i >= low; --i) {
		sum = sum + nums[i];
		if (sum > left_sum) {
			left_sum = sum;
			left_index = i;
		}
	}

	sum = 0;
	int right_sum = INT_MIN;
	int right_index = mid;
	for (int j = mid + 1; j <= high; ++j) {
		sum += nums[j];
		if (sum > right_sum) {
			right_sum = sum;
			right_index = j;
		}
	}
	return left_sum + right_sum;
}


//  习题4.1-2  最大子数组的暴力解法：
int MaxSubarry::find_maximum_subarray_Violence(int low, int high) {
	int sum = INT_MIN;
	int temp_sum = 0;
	int left_index = 0, right_index = 0;
	for (int i = low; i <= high; ++i) {
		for (int j = i; j <= high; ++j) {
			temp_sum += nums[j];
			if (temp_sum > sum)
				sum = temp_sum;
				left_index = i;
				right_index = j;
		}
		temp_sum = 0;
	}
	return sum;
}


int MaxSubarry::find_maximum_subarry_RecursionAndViolence(int low, int high, int k) {
	int sum = INT_MIN;
	if (high - low <= k) {
		int temp_sum = 0;
		int left_index = 0, right_index = 0;
		for (int i = low; i <= high; ++i) {
			for (int j = i; j <= high; ++j) {
				temp_sum += nums[j];
				if (temp_sum > sum)
					sum = temp_sum;
				left_index = i;
				right_index = j;
			}
			temp_sum = 0;
		}
		return sum;
	}
	else {
		auto mid = low + (high - low) / 2;
		int sum_left = this->find_maximum_subarray_Recursion(low, mid);
		int sum_right = this->find_maximum_subarray_Recursion(mid + 1, high);
		int sum_mid = find_max_crossing_subarray(low, mid, high);

		if (sum_left >= sum_right && sum_left >= sum_mid)	return sum_left;
		else if (sum_right >= sum_left && sum_right >= sum_mid)	return sum_right;
		else    return sum_mid;
	}


}

int MaxSubarry::find_maximum_subarry_Lineary(int low, int high)
{
	int max_sum = INT_MIN;
	int sum = 0;
	int current_Low = 0, current_High = 0;
	int result_Low = 0, result_High = 0;
	for (int i = low; i <= high; ++i) {
		current_High = i;
		if (sum > 0)
			sum += nums[i];
		else {
			current_Low = i;
			sum = nums[i];
		}

		if (sum > max_sum) {
			max_sum = sum;
			result_Low = current_Low;
			result_High = current_High;
		}
	}
	return max_sum;
}










#endif // !DIVIDEANDCONQUER_H
