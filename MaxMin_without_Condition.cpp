//Q1. Write a C Program to find the Maximum and minimum of two numbers without using any loop or condition.
#include<iostream>
using namespace std;

int main() {

	int a = 10;
	int b = 20;

	cout << abs( (a+b) - (a-b) ) / 2;
	cout << abs( (a+b) + (a-b) ) / 2;

	return 0;
}
