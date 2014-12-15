#define _CRT_SECURE_NO_DEPRECATE
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>


//Function Prototypes
double PrecisionVersusBase( double ); //returns precision
void ComputeEpsilon( double );

int main( )
{
	double Precision = 0.0;
	double EpsilonVar = 0.0;
	Precision = PrecisionVersusBase( 1.0 );
	printf( "%.50f", Precision );

	ComputeEpsilon ( 1.0 );

	//getch();
	return 0;
}
// This funtion computes precision for a given
// reference value.
double PrecisionVersusBase( double Base )
{
	double Precision = Base;

	//Loops until Precision is negligible
	while ( Base + Precision > Base )
		Precision /= 2.0;

	Precision *= 2.0;				//Multiply by two to become accurate

	return Precision;
}


//This function compues the Epsilon values from 1.0 to 1e-30.
//Then it outputs the base, epsilon and range to a CSV for graphing in Matlab.
void ComputeEpsilon( double base )
{
	FILE *fout;

	double Precision = 0.00;
	double Epsilon = 0.00;
	double Ratio = 0.00;

	double Exponent = pow( 10.0, -30.0 );
	fout = fopen( "Output.csv", "w" );
	
	//This calls the ComputeEpsilon function, calculates the ration, and then updates the base until it reaches 1e-30
	while ( base >= Exponent )
	{
		Epsilon = PrecisionVersusBase( base );
		Ratio = Epsilon / base;
		printf( "\n\nBase: %.60lf \nEpsilon: %.68lf\nratio: %.50lf", base, Epsilon, Ratio );
		
		fprintf( fout, "%.60lf, %.60lf, %.60lf\n", base, Epsilon, Ratio );
		base /= 10;
	}
	fclose( fout );
}
