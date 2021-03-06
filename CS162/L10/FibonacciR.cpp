/*********************************************************************

** Program Filename: FibonacciR.cpp

** Author: Pedro Torres-Picon

** Date: 12/05/2016

** Description: Lab 10 - This is the implementation file for a FibonacciR
class, which executes a recursive function to calculate fibonacci
numbers. This file the source code for all the functions in the class.

** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

*********************************************************************/

#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR() {
}

FibonacciR::FibonacciR(const unsigned long long &n):n_(&n){
}

FibonacciR::~FibonacciR() {
}

unsigned long long FibonacciR::Fibonacci(const unsigned long long &n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	return Fibonacci(n-1) + Fibonacci(n-2);
}

void FibonacciR::PrintFibonacci(){
	unsigned long long FibonaciNum=Fibonacci(*n_);
	std::cout << *n_ << "th fibonaci number: "<< FibonaciNum << std::endl;
}
