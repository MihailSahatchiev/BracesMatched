// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<stack>
#include<string>
#include <memory>
using namespace std;

bool CheckIfMatch(char first, char second)
{
	if (first == '(' && second == ')')
	{
		return true;
	}
	else if (first == '{' && second == '}')
	{
		return true;
	}
	else if (first == '[' && second == ']')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckIfBraketsMatch(string expre)
{
	stack<char>  Brackets;
	for (int i = 0; i < expre.length(); i++)
	{
		if (expre[i] == '(' || expre[i] == '{' || expre[i] == '[')
		{
			Brackets.push(expre[i]);
		}
		else if (expre[i] == ')' || expre[i] == '}' || expre[i] == ']')
		{
			if (Brackets.empty() || !CheckIfMatch(Brackets.top(), expre[i]))
			{
				return false;
			}
			else
			{
				Brackets.pop();
			}
		}
	}
	if (Brackets.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string input[15];
	int lines;
	//max lines, max yes nos
	string result[15];
	cout << "Lines :  ";
	cin >> lines;
	int j = 0;
	while (lines != 0)
	{
		cout << "Expressions: ";
		cin >> input[j];
		lines--;
		j++;
	}

	for (int i = 0; i < j; i++)
	{
		string expression = input[i];
		if (CheckIfBraketsMatch(expression))
		{
			result[i] = "YES\n";
		}
		else
		{
			result[i] = "NO\n";
		}
	}
	int k = 0;
	while (k < j)
	{
		cout << result[k];
		k++;
	}
}
//This is the failed try to make it work with pointers,
//Lost my way with them.. :(

//bool CheckIfMatch(char first, char second)
//{
//	if (first == '(' && second == ')')
//	{
//		return true;
//	}
//	else if (first == '{' && second == '}')
//	{
//		return true;
//	}
//	else if (first == '[' && second == ']')
//	{
//		return true;
//	}
//	else
//	{
//	    return false;
//	}
//}
//
//string CheckIfBraketsMatch(string input[], int lines)
//{
//	string result[15];
//	for (int j = 0; j < lines; j++)
//	{
//		string expre = input[j];
//		stack<char>  Brackets;
//		for (int i = 0; i < expre.length(); i++)
//		{
//			if (expre[i] == '(' || expre[i] == '{' || expre[i] == '[')
//			{
//				Brackets.push(expre[i]);
//			}
//			else if (expre[i] == ')' || expre[i] == '}' || expre[i] == ']')
//			{
//				if (Brackets.empty() || !CheckIfMatch(Brackets.top(), expre[i]))
//				{
//					return false;
//				}
//				else
//				{
//					Brackets.pop();
//				}
//			}
//		}
//		if (Brackets.empty())
//		{
//			result[j] = "YES\n";
//		}
//		else
//		{
//			result[j] = "NO\n";
//		}
//	}
//	string *pointer;
//	pointer = result;
//	return *pointer;
//}
//
//int main()
//{
//	string input[15];
//	int lines;
//	//max lines, max yes nos
//	
//	cout << "Lines :  ";
//	cin >> lines;
//	int j = 0;
//	while (lines != 0)
//	{		
//		cout << "Expressions: ";
//		cin >> input[j];
//		lines--;
//		j++;
//	}
//	string *result;
//	result = &CheckIfBraketsMatch(input, j);
//	for (int k = 0; k < sizeof(result); k++)
//	{		
//		cout << *(&result + k) << endl;
//	}
//}

