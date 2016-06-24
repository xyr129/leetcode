#pragma once

//���ܣ�����һ�������һ�����֣��ҳ���������ӽ������������ֵ����������±�
//������[2, 7, 11, 15]  sum = 9,
//      Because nums[0] + nums[1] = 2 + 7 = 9,
//      return[0, 1]

//��0��size-1Ϊ��ʼ�߽磬���ұ߽��Ӧ������֮��Ϊ��ǰ��
//��ǰ�ʹ��ڸ���ֵ�������ұ߽磬С���������߽�

class Solution1
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		if (nums.empty())
		{
			return vector<int>(-1, -1);
		}

		bool  flag = false;
		int left = 0;
		int right = 0;
		int size = nums.size();

		while (left < size)
		{
			right = left + 1;
			while (right < size)
			{
				int sum = nums[left] + nums[right];
				if (sum != target)
				{
					right++;
				}
				else
				{
					flag = true;
					break;
				}
			}

			if (flag == true)
			{
				break;
			}
			left++;
		}

		vector<int> ret;
		ret.push_back(left);
		ret.push_back(right);
		return ret;
	}
};

void TestTwoSum()
{
	int target = 9;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	Solution1 s;

	vector<int> ret = s.twoSum(nums, target);
	vector<int>::iterator it = ret.begin();
	while (it != ret.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

