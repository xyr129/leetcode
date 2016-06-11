//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//For example,

/*Consider the following matrix :

[
	[1, 4, 7, 11, 15],
	[2, 5, 8, 12, 19],
	[3, 6, 9, 16, 22],
	[10, 13, 14, 17, 24],
	[18, 21, 23, 26, 30]
]
*/

#pragma once

bool searchMatrix(vector<vector<int>> &matrix,int target)
{
	if (!matrix.empty())
	{
		int rows = matrix.size();
		int cols = matrix[0].size();

		int rowIndex = 0;
		int colIndex = cols - 1;
		while (rowIndex < rows && colIndex >= 0)
		{
			if (target == matrix[rowIndex][colIndex])
			{
				return true;
			}
		
			if (target < matrix[rowIndex][colIndex])
			{
				--colIndex;
			}
			else
			{
				++rowIndex;
			}
		}
		return false;
	}
	return false;
}


void TestSearchMatrix()
{
	vector<vector<int>> matrix;
	vector<int> v0;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	matrix.push_back(v0);
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix[0].push_back(1);
	matrix[0].push_back(4);
	matrix[0].push_back(7);
	matrix[0].push_back(11);
	matrix[1].push_back(2);
	matrix[1].push_back(5);
	matrix[1].push_back(8);
	matrix[1].push_back(12);
	matrix[2].push_back(3);
	matrix[2].push_back(6);
	matrix[2].push_back(9);
	matrix[2].push_back(16);
	matrix[3].push_back(10);
	matrix[3].push_back(13);
	matrix[3].push_back(14);
	matrix[3].push_back(17);
	cout << searchMatrix(matrix, 6) << endl;
}
