#pragma once

//功能：逆波兰表达式
//例如：  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//        ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

//将操作数压栈，碰到操作符取栈顶两个操作数计算，再将结果压栈
//如果操作数是表达式，计算其结果压栈

class _Solution 
{
public:
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> _rnp;
		int result = 0;
		vector<string>::iterator it = tokens.begin();
		while (it != tokens.end())
		{
			int first = 0;
			int second = 0;
			if (*it == "+" || *it == "-" || *it == "*" || *it == "/")
			{
				if (!_rnp.empty())
				{
					second = _rnp.top();
				}
				_rnp.pop();
				if (!_rnp.empty())
				{
					first = _rnp.top();
				}
				_rnp.pop();

				char tmp = *((*it).c_str());
				switch (tmp)
				{
				case '+':
					result = first + second;
					break;
				case '-':
					result = first - second;
					break;
				case '*':
					result = first * second;
					break;
				case '/':
					result = first / second;
					break;
				default:
					break;
				}
				_rnp.push(result);
				it++;
				continue;
			}

			int ret = atoi((char*)(*it).c_str());
			_rnp.push(ret);
			result = ret;
			it++;
		}
		return result;
	}
};

void TestRPN()
{
	vector<string> tokens;
	char* input[5] = { "4", "13", "5", "/", "+" };
	char* input1[5] = { "2", "1", "+", "3", "*" };

	for (int i = 0; i < 5; i++)
	{
		//tokens.push_back(input[i]);
		tokens.push_back(input1[i]);
	}

	/*char* input2[1] = { "18" };
	tokens.push_back(input2[0]);*/

	_Solution s;
	cout << s.evalRPN(tokens) << endl;
}