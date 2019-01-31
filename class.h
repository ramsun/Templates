/*
Ramamurthy Sundar
class.h

Definition of stockType and stockListType classes.

The stockType class is a representation of a stock, which holds both
string and double information.  It not only holds the name of the stock,
but also various information such as the prices, number of shares, and the
percentage gain/loss.  There are also functions to view the stock information
in terminal and a text file and calculate the percentage gain. 

The stockListType class is mostly just a vector that can hold any number of
stocks.  It can perform a basic push operation, be sorted, and create a 
financial report of the stock information;
*/

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

//declaration of stockType class
class stockType {
private:
	std::string symbol;
	double openPrice, closePrice, highPrice, lowPrice, prevPrice, percentGain, numOfShares;

public:
	stockType();
	void set(std::ifstream &infile);
	void print_to_txt(std::ofstream &outfile);
	void print_to_terminal();
	void calc_percentageGain();
	bool operator<(const stockType &rhs) const; //overload the less than operator
};

//definition of stockListType class
template <typename T>
class stockListType {
private:
	std::vector<T> vec;

public:
	stockListType() {};
	void push(const stockType &stock);
	void class_sort();
	void finacial_report(std::ofstream &outfile);
};

