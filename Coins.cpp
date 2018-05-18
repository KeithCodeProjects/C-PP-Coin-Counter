/*Keith Hicks
*CSE 153
* Final Part 1 (Program option 2)
* This program sorts differnt types of U.S. coins based on diameter and weight of each type of coin and a +-2% acceptable wear tolerance
* for each type of coin. It calculates and displays the acceptable high and low tolerances for diameter and weight for each type of 
* coin.  It then opens a text file containing diameters and weights of each coin, reads the data and determines if it is a 
* valid coin and what type of coin it is.  It counts the number of each type of coin contained in the file and also calculates the total
* value of each type of coins outputing the results.  It also outputs the number of invalid coins contained in the file that do not
* have acceptable diameters and weights to be classified as any one of the types of coins.  
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <fstream>


using namespace std;

//Declare constants for base diameter, weight, and value of each type of coin.
const double PENNYD = 19.05;
const double PENNYW = 2.5;
const double NICKELD = 21.21;
const double NICKELW = 5.0;
const double DIMED = 17.91;
const double DIMEW = 2.268;
const double QUARTERD = 24.26;
const double QUARTERW = 5.670;
const double TOLERANCE = 0.02;

const double PENNYVALUE = 0.01;
const double NICKELVALUE = 0.05;
const double DIMEVALUE = 0.10;
const double QUARTERVALUE = 0.25;

bool isValid(double coinDiameter, double coinWeight, double lowDiameter, double highDiameter, double lowWeight, double highWeight);
double acceptableHighDiameter(double coinDiameter);
double acceptableLowDiameter(double coinDiameter);
double acceptableHighWeight(double coinWeight);
double acceptableLowWeight(double coinWeight);



int main(int argc, char *argv[])
{
	//Declare variables to hold high/low tolerance values for weight and diameter for each type of coin. 
	double pennyLowDiameter;
	double pennyHighDiameter;
	double pennyLowWeight;
	double pennyHighWeight;

	double nickelLowDiameter;
	double nickelHighDiameter;
	double nickelLowWeight;
	double nickelHighWeight;

	double dimeLowDiameter;
	double dimeHighDiameter;
	double dimeLowWeight;
	double dimeHighWeight;

	double quarterLowDiameter;
	double quarterHighDiameter;
	double quarterLowWeight;
	double quarterHighWeight;

	//Declare variables to hold counts of each typ of coin.
	int pennyCount = 0;
	int nickelCount = 0;
	int dimeCount = 0;
	int quarterCount = 0;
	int invalidCount = 0;

	//Declare variables to hold total value/worth of each type of coin.
	double pennyWorth = 0;
	double nickelWorth = 0;
	double dimeWorth = 0;
	double quarterWorth = 0;

	//Calculate acceptable high and low tolerances for diameter and weight of a penny using functions.
	pennyLowDiameter = acceptableLowDiameter(PENNYD);
	pennyHighDiameter = acceptableHighDiameter(PENNYD);
	pennyLowWeight = acceptableLowWeight(PENNYW);
	pennyHighWeight = acceptableHighWeight(PENNYW);

	//Calculate acceptable high and low tolerances for diameter and weight of a nickel using functions.
	nickelLowDiameter = acceptableLowDiameter(NICKELD);
	nickelHighDiameter = acceptableHighDiameter(NICKELD);
	nickelLowWeight = acceptableLowWeight(NICKELW);
	nickelHighWeight = acceptableHighWeight(NICKELW);

	//Calculate acceptable high and low tolerances for diameter and weight of a dime using functions.
	dimeLowDiameter = acceptableLowDiameter(DIMED);
	dimeHighDiameter = acceptableHighDiameter(DIMED);
	dimeLowWeight = acceptableLowWeight(DIMEW);
	dimeHighWeight = acceptableHighWeight(DIMEW);

	//Calculate acceptable high and low tolerances for diameter and weight of a quarter using functions.
	quarterLowDiameter = acceptableLowDiameter(QUARTERD);;
	quarterHighDiameter = acceptableHighDiameter(QUARTERD);
	quarterLowWeight = acceptableLowWeight(QUARTERW);
	quarterHighWeight = acceptableHighWeight(QUARTERW);

	//Output calculated diameter and weight tolerances for each type of coin.
	cout << "Acceptable width of a penny is from " << pennyLowDiameter << " to " << pennyHighDiameter << endl;
	cout << "Acceptable weight of a penny is from " << pennyLowWeight << " to " << pennyHighWeight << endl;
	cout << endl;

	cout << "Acceptable width of a nickel is from " << nickelLowDiameter << " to " << nickelHighDiameter << endl;
	cout << "Acceptable weight of a nickel is from " << nickelLowWeight << " to " << nickelHighWeight << endl;
	cout << endl;

	cout << "Acceptable width of a dime is from " << dimeLowDiameter << " to " << dimeHighDiameter << endl;
	cout << "Acceptable weight of a dime is from " << dimeLowWeight << " to " << dimeHighWeight << endl;
	cout << endl;

	cout << "Acceptable width of a quarter is from " << quarterLowDiameter << " to " << quarterHighDiameter << endl;
	cout << "Acceptable weight of a quarter is from " << quarterLowWeight << " to " << quarterHighWeight << endl;
	cout << endl;

	//Declare variables to hold weight and diameter data as it is read from the data file.
	double diameter;
	double weight;

	//Create ifstream object that opens and reads data file.
	ifstream infile("coinstest.txt", ios::in);

	//Check to see if file was opened, if not displays error message.
	if (!infile.is_open())
		cout << "Could not open file" << endl;

	//Read each diameter and weight in the file, comparing each to determine if coin is valid and the type of coin based on diameter and weight.
	while (infile >> diameter && infile >> weight)
	{
		if (isValid(diameter, weight, pennyLowDiameter, pennyHighDiameter, pennyLowWeight, pennyHighWeight))
		{
			pennyCount++;
		}
		else if (isValid(diameter, weight, nickelLowDiameter, nickelHighDiameter, nickelLowWeight, nickelHighWeight))
		{
			nickelCount++;
		}
		else if (isValid(diameter, weight, dimeLowDiameter, dimeHighDiameter, dimeLowWeight, dimeHighWeight))
		{
			dimeCount++;
		}
		else if (isValid(diameter, weight, quarterLowDiameter, quarterHighDiameter, quarterLowWeight, quarterHighWeight))
		{
			quarterCount++;
		}
		else
		{
			invalidCount++;
		}

	}

	infile.close();

	//Calculate total worth/value of each type of coin counted.
	pennyWorth = pennyCount * PENNYVALUE;
	nickelWorth = nickelCount * NICKELVALUE;
	dimeWorth = dimeCount * DIMEVALUE;
	quarterWorth = quarterCount * QUARTERVALUE;

	//Output number and worth of each type of coin and number of invalid coins.
	cout << "Number of pennies counted: " << pennyCount << " Worth: " << pennyWorth << endl;
	cout << endl;
	cout << "Number of nickels counted: " << nickelCount << " Worth: " << nickelWorth << endl;
	cout << endl;
	cout << "Number of dimes counted: " << dimeCount << " Worth: " << dimeWorth << endl;
	cout << endl;
	cout << "Number of quarters counted: " << quarterCount << " Worth: " << quarterWorth << endl;
	cout << endl;
	cout << "Number of invalid coins counted: " << invalidCount << endl;

	cin.get();

	return 0;
}

//Function determines if a coin is valid or not and type of coin based on the coins base weight and diameter and if it is within acceptable 
//diameter and weight tolerances.  It takes the coins base diameter and weight and acceptable high and low tolerances for 
//weight and diameter as arguments.  
bool isValid(double coinDiameter, double coinWeight, double lowDiameter, double highDiameter, double lowWeight, double highWeight)
{
	if (coinDiameter >= lowDiameter && coinDiameter <= highDiameter)
	{
		if (coinWeight >= lowWeight && coinWeight <= highWeight)
		{
			return true;
		}
			
	}
	else
	{
		return false;
	}
	return true;
}

//Function determines acceptable high tolerance for a coins diameter.  Takes coins base diameter as argument.
double acceptableHighDiameter(double coinDiameter)
{
	double result = coinDiameter + (coinDiameter * TOLERANCE);

    return result;

}

//Function determines acceptable low tolerance for a coins diameter.  Takes coins base diameter as argument.
double acceptableLowDiameter(double coinDiameter)
{
	double result = coinDiameter - (coinDiameter * TOLERANCE);

	return result;

}

//Function determines acceptable high tolerance for a coins weight.  Takes coins base weight as argument.
double acceptableHighWeight(double coinWeight)
{
	double result = coinWeight + (coinWeight * TOLERANCE);

	return result;

}

//Function determines acceptable low tolerance for a coins weight.  Takes coins base weight as argument.
double acceptableLowWeight(double coinWeight)
{
	double result = coinWeight - (coinWeight * TOLERANCE);

	return result;

}
