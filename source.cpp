// CPP program to count magic squares 
#include <bits/stdc++.h> 
using namespace std; 

const int R = 3; 
const int C = 4; 

// function to check is subgrid is Magic Square 
int magic(int a, int b, int c, int d, int e, 
				int f, int g, int h, int i) 
{ 
	set<int> s1 = { a, b, c, d, e, f, g, h, i }, 
			s2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 

	// Elements of grid must contain all numbers from 1 to 
	// 9, sum of all rows, columns and diagonals must be 
	// same, i.e., 15. 
	if (s1 == s2 && (a + b + c) == 15 && (d + e + f) == 15 && 
	(g + h + i) == 15 && (a + d + g) == 15 &&					 
	(b + e + h) == 15 && (c + f + i) == 15 && 
	(a + e + i) == 15 && (c + e + g) == 15) 
	return true; 
	return false;	 
} 

// Function to cound total Magic square subgrids 
int CountMagicSquare(int Grid[R][C]) 
{ 
	int ans = 0; 

	for (int i = 0; i < R - 2; i++) 
		for (int j = 0; j < C - 2; j++) { 

			// if condition true skip check 
			if (Grid[i + 1][j + 1] != 5) 
				continue; 

			// check for magic square subgrid 
			if (magic(Grid[i][j], Grid[i][j + 1], 
				Grid[i][j + 2], Grid[i + 1][j], 
				Grid[i + 1][j + 1], Grid[i + 1][j + 2], 
				Grid[i + 2][j], Grid[i + 2][j + 1], 
				Grid[i + 2][j + 2])) 

				ans += 1; 
		} 

	// return total magic square 
	return ans; 
} 

// Driver program 
int main() 
{ 
	int G[R][C] = { { 4, 3, 8, 4 }, 
					{ 9, 5, 1, 9 }, 
					{ 2, 7, 6, 2 } }; 

	// function call to print required answer 
	cout << CountMagicSquare(G); 

	return 0; 
} 
