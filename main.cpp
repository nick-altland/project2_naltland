/**
 * Nicholas Altland
 * CS124A
 *
 * Project 2
 * Main File
 */

#include "county_climate.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string filename = "../sampleData.csv";

    //Define the name of the file to be read in
    vector<Climate> climateData;

    // Create a default Climate constructor
    Climate clim;

    // Fill vector with information from data set
    clim = getDataFromFile(filename, climateData);

    // Get the dataset length
    int setLength = getDataSetLength(clim, climateData);

    // Get the first entry in the data set
    cout << "The first entry in the data set is: " << endl;
    dataLineInformation(clim, climateData, 0);



    return 0;

}


/**
    // Get the first entry in the data set
    cout << "The first entry in the data set is: " << endl;
    dataLineInformation(clim, climateData, 0);

    //Call the 2776th entry (should be the county Burlington is in)
    cout << "The 2776 entry in the data set is: " << endl;
    dataLineInformation(clim, climateData, 2775);

    //Call the 2776th entry (should be the county Burlington is in)
    cout << "The Final entry in the data set is: " << endl;
    dataLineInformation(clim, climateData, setLength-1);

    //What was the highest annual temperature?
    highestAnnualTemp(clim, climateData);

    // What was the lowest annual temp?
    lowestAnnualTemp(clim, climateData);

    //The number of times a season had the max warming temp
    maxWarmingFrequency(clim, climateData);

*/