//Suppose a sorted array is rotated at some pivot unknown to you beforehand.

//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

//Find the minimum element.

//The array may contain duplicates.

#pragma once

int _findMin(vector<int>& nums, int left, int right)
{
	if (nums[left]<nums[right])
	{
		return nums[left];
	}
	if (left == right)
	{
		return nums[left];
	}
	if (left < right)
	{

		if (left == right - 1)
		{
			return nums[right];
		}

		int mid = left + (right - left) / 2;

		if (nums[left] < nums[mid])
		{
			return _findMin(nums, mid, right);
		}
		else if (nums[mid] == nums[right] || nums[left] == nums[mid])
		{
			int part1 = _findMin(nums, left, mid);
			int part2 = _findMin(nums, mid, right);
			return part1 < part2 ? part1 : part2;
		}
		else  //if (nums[mid] < nums[right])
		{
			return _findMin(nums, left, mid);
		}

	}
}

int findMin(vector<int>& nums) 
{
	if(!nums.empty())
	{
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		
		return _findMin(nums, left, right);
	}
	return -1;
}

void TestFindMin()
{
	vector<int> nums;
	/*nums.push_back(10);
	nums.push_back(1);
	nums.push_back(10);
	nums.push_back(10);
	nums.push_back(10);*/

	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(4);


	cout << findMin(nums) << endl;
}

