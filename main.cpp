/*
Ramamurthy Sundar
main.cpp

This is the driver for machine problem 5.  It showcases the use of templates and how
they can be used to create custom classes than can store information of multiple types.

In this program, a class will be able to store stock information given in a text file.
It will then calculate the percentage gain of the stock, create a vector of the stocks, 
and finally create a financial report of the stocks outputed to a text file.
*/

#include "class.h"

int main() {
	
	//open file streams
	std::ifstream infile;
	std::ofstream outfile;
	std::string infile_name = "text.txt";
	std::string outfile_name = "Output.txt";
	infile.open(infile_name.c_str());
	outfile.open(outfile_name.c_str());

	//declare stocks
	stockType stock1;
	stockType stock2;
	stockType stock3;
	stockType stock4;
	stockType stock5;

	//set stocks from text file
	stock1.set(infile);
	stock2.set(infile);
	stock3.set(infile);
	stock4.set(infile);
	stock5.set(infile);

	//calculate the percent gain of each stock
	stock1.calc_percentageGain();
	stock2.calc_percentageGain();
	stock3.calc_percentageGain();
	stock4.calc_percentageGain();
	stock5.calc_percentageGain();

	//create stock type container
	stockListType<stockType> stocks;
	stocks.push(stock1);
	stocks.push(stock2);
	stocks.push(stock3);
	stocks.push(stock4);
	stocks.push(stock5);
	stocks.class_sort(); //sort the class vector

	//post a financial report to the output file
	stocks.finacial_report(outfile);

	//close file streams and exit program
	infile.close();
	outfile.close();
	return 0;
}
