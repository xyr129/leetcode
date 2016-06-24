#pragma once

//���ܣ�����һ���ַ������ҳ����û���ظ��ַ��Ӵ��ĳ���
//������"abcabcbb" ������ظ��Ӵ��� "abc", ����Ϊ 3��
//      "bbbbb" ������ظ��Ӵ��� "b",����Ϊ 1��
//      "pwwkew" ������ظ��Ӵ��� "wke",����Ϊ 3��

//ָ��firstָ���ַ�����һ���ַ���second����ߣ��ַ����ظ�������ȼ�1
//�������ֹ����ַ�first�����һ����second��first��һλ�ÿ�ʼ�ظ��������˴γ��ȼ�Ϊ��ǰ����
//��ǰ�������������������������

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