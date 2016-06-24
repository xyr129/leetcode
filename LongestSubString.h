#pragma once

//功能：给定一个字符串，找出最长的没有重复字符子串的长度
//举例："abcabcbb" 的最长无重复子串是 "abc", 长度为 3。
//      "bbbbb" 的最长无重复子串是 "b",长度为 1。
//      "pwwkew" 的最长无重复子串是 "wke",长度为 3。

//指针first指向字符串第一个字符，second向后走，字符不重复则最长长度加1
//碰到出现过的字符first向后走一步，second从first后一位置开始重复遍历，此次长度记为当前长度
//当前长度若大于最长长度则更新最长长度

class __Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		const char *str = s.c_str();
		if (NULL == str)
		{
			return 0;
		}

		int maxLen = 0;
		const char* first = str;
		
		while (*first)
		{
			int length = 1;
			int times[256];
			memset(times, 0, sizeof(int)* 256);
			times[*first]++;
			const char* second = first+1;
			while (*second)
			{
				times[*second]++;
				if (times[*second] > 1)
				{
					break;
				}

				length++;
				second++;
			}

			if (length > maxLen)
			{
				maxLen = length;
			}

			first++;
		}
		return maxLen;
	}
};

void TestLongestSubString()
{
	char* str1 = "abcabcbb";
	char* str2 = "bbbbb";
	char* str3 = "pwwkew";

	__Solution s;

	cout << str1 << "->" << s.lengthOfLongestSubstring(str1) << endl;
	cout << str2 << "->" << s.lengthOfLongestSubstring(str2) << endl;
	cout << str3 << "->" << s.lengthOfLongestSubstring(str3) << endl;
}