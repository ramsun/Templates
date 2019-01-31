/*
Ramamurthy Sundar
Fall 2018

class.cpp

Implementations of the classes and functions defined in class.h.  See comments
bellow for explanations of function specifics.
*/

#include "class.h"

//custom constructor
stockType::stockType() : symbol(" "), openPrice(0), closePrice(0), highPrice(0), lowPrice(0), prevPrice(0), percentGain(0), numOfShares(0)
{}

//stream objects from text file into stockType class
void stockType::set(std::ifstream &infile) {
	infile >> symbol >> openPrice >> closePrice >> highPrice >> lowPrice >> prevPrice >> numOfShares;
}

//print the stock information in one line of text
void stockType::print_to_txt(std::ofstream &outfile) {
	outfile << symbol << " " << openPrice << " " << closePrice << " " << highPrice << " " << lowPrice
		<< "\t" << prevPrice << " " << numOfShares << "\t" << percentGain << "%" << "\n";
}

//prints the stock information into terminal
void stockType::print_to_terminal() {
	std::cout << "SYM" << " " << "OPEN" << " " << "CLOSE" << " " << "HIGH" << " " << "LOW"
		<< " " << "CLOSE" << " " << "SHARES" << " " << "G/L" << std::endl;
	std::cout<< symbol << " " << openPrice << " " << closePrice << " " << highPrice << " " << lowPrice
		<< " " << prevPrice << " " << numOfShares << " " << percentGain << "%" << std::endl;
	std::cout << std::endl;
}

//calculates and sets the percentage gain of stockType
void stockType::calc_percentageGain() {
	percentGain = ((closePrice - prevPrice) / (prevPrice)) * 100;
}

//overload the less than operator
bool stockType::operator<(const stockType & rhs) const {
	return symbol < rhs.symbol;
}

//pushs stockType class into a stockListType container class
template<typename T>
void stockListType<T>::push(const stockType &stock) {
	vec.push_back(stock);
}

//allows you to sort the vector using the std::sort function
//sort function uses the less than operator by default
template<typename T>
void stockListType<T>::class_sort() {
	std::sort(vec.begin(), vec.end());
}

//creates a financial report of the stock
template<typename T>
void stockListType<T>::finacial_report(std::ofstream &outfile) {
	outfile << "Financial Report" << "\n";
	outfile << "Today" << "\t" << "\t" << "\t" << "\t" << "Yesterday" <<"\t" << "Percent" << "\n";
	outfile << "SYM" << " " << "OPEN" << " " << "CLOSE" << " " << "HIGH" << " " << "LOW" <<"\t"
		<< "\t" << "CLOSE" << " " << "SHARES" << "\t" << "G/L" << "\n";
	
	//print out each stock in the stockList vector financial report style
	stockType tempstock;
	for (unsigned int i = 0; i < vec.size(); i++) {
		tempstock = vec.at(i);
		tempstock.print_to_txt(outfile);
	}
}

//potential types that will be used by stockListType.  Prevents linker errors
template class stockListType<stockType>;


