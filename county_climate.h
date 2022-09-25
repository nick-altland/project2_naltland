/**
 * Nicholas Altland
 * CS124A
 *
 * Project 2
 * Header file
 */

#ifndef PROJECT1_COUNTY_CLIMATE_H
#define PROJECT1_COUNTY_CLIMATE_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::cout , std::endl , std::ifstream , std::string, std::vector;

using namespace std;

// Create Climate
class Climate{

// private instance variables
private:

    int fips;   //Holds the fips value
    double fall, spring, summer, winter; //holds the seasonal temperature
    string maxWarm;     //holds the season with the max warming
    double annual;      //Holds the average temp change from the four seasons
    string cityName;    //County name where data was pulled
    string stateName;   //State name from where the data was pulled


    int dataLength = 0;     //Length of the data set
    double lowestTemp = 100;        //Lowest temp from the data set
    double highestTemp = -100;      //Highest temp from the data set
    int lowestTempIndex = 0;        //Location in the vector of the lowest temp
    int highestTempIndex = 0;       //Location in the vectore of the highest temp
    int fallTimes = 0;         //Number of times that fall is the highest temp
    int springTimes = 0;         //Number of times that spring is the highest temp
    int summerTimes = 0;         //Number of times that summer is the highest temp
    int winterTimes = 0;         //Number of times that winter is the highest temp

public:
    // Constructors, setting default values
    Climate(){
        fips = 1;
        fall = 2.0;
        spring = 3.0;
        summer = 4.0;
        winter = 5.0;
        maxWarm = "mud season";
        annual = 6.0;
        cityName = "burlington";
        stateName = "sleep deprived";

    }

    //Constructor, setting local values
    Climate(int fips, double fall, double spring, double summer, double winter, string maxWarm,
            double annual, string cityName, string stateName){

        this->fips = fips;
        this->fall = fall;
        this->spring = spring;
        this->summer = summer;
        this->winter = winter;
        this->maxWarm = maxWarm;
        this->annual = annual;
        this->cityName = cityName;
        this->stateName = stateName;

    }

    // GETTERS
    //GetFips: Returns the integer fips value
    int getFips() const {
        return fips;
    }
    //returns the integer fall value
    double getFall() const {
        return fall;
    }
    //Returns the double spring value
    double getSpring() const {
        return spring;
    }
    // Returns the double summer value
    double getSummer() const {
        return summer;
    }
    // Returns the double winter value
    double getWinter() const {
        return winter;
    }
    //Returns the string max warming season
    string getMax() const {
        return maxWarm;
    }
    // Returns the double annual value
    double getAnnual() const {
        return annual;
    }
    // Returns the string City Name, which stands for the county or origin
    string getName() const {
        return cityName;
    }
    // Returns the string State Name, which signifies the state of origin
    string getState() const {
        return stateName;
    }
    // Gets the length of the data set
    int getLength() const {
        return dataLength;
    }
    // Getter for the lowest mean temperature
    double getLowestTemp() const {
        return lowestTemp;
    }
    //Getter for highest mean temp
    double getHigestTemp() const {
        return highestTemp;
    }
    //Getter for Lowest mean temp index
    double getHighestTempIndex() const {
        return highestTempIndex;
    }
    //Getter for highest mean temp index
    double getLowestTempIndex() const {
        return lowestTempIndex;
    }
    //Getters the counts for the number of times a season appears in Max Temp Change
    int getFallCount(){return fallTimes;}
    int getSpringCount(){return springTimes;}
    int getSummerCount(){return summerTimes;}
    int getWinterCount(){return winterTimes;}

    //SETTERS
    // Sets the integer value of the FIPS number
    void setFips(int fips) {
        this->fips = fips;
    }
    // Sets the integer fall value
    void setFall(double fall) {
        this->fall = fall;
    }
    // Sets the double spring value
    void setSpring(double spring) {
        this->spring = spring;
    }
    // Sets the double summer value
    void setSummer(double summer) {
        this->summer = summer;
    }
    // Sets the double winter value
    void setWinter(double winter) {
        this->winter = winter;
    }
    // Sets the string max warming season
    void setMax(string max) {
        this->maxWarm = maxWarm;
    }
    // Sets the double annual value
    void setAnnual(double annual) {
        this->annual = annual;
    }
    // Sets the string City Name, which stands for the county or origin
    void setName(string cityName) {
        this->cityName = cityName;
    }
    // Sets the string State Name, which signifies the state of origin
    void setState(string setState) {
        this->stateName = stateName;
    }
    // Sets the length of the data set
    void setLength(int dataLength) {
        this-> dataLength = dataLength;
    }
    //Setter for highest mean temp index
    void setHighestTempIndex(double highestIndex){
        this-> highestTempIndex = highestIndex;
    }
    //Setter for lowest mean temp index
    void setLowestTempIndex(double lowestIndex){
        this-> lowestTempIndex = lowestIndex;
    }
    //Setter for highest mean temp
    void setHighestTemp(double highestTemp){
        this-> highestTemp = highestTemp;
    }
    //Write a setter for the lowest mean temp
    void setLowestTemp(double lowestTemp){
        this-> lowestTemp = lowestTemp;
    }
    //set the counts for the number of times a season appears in Max Temp Change
    void setFallCount(){this-> fallTimes++;}
    void setSpringCount(){this-> springTimes++;}
    void setSummerCount(){this-> summerTimes++;}
    void setWinterCount(){this-> winterTimes++;}


};

//GLOBAL FUNCTION

// Create a vector of all the data from the file
Climate getDataFromFile(string fileName, vector<Climate>& climateData) {

    //Create a file string for the file to be read in
    ifstream inFile;
    inFile.open(fileName); //Open the file

    //If the file is valid and available
    string header; //Create a string representing the header of the file

    //Create Climate
    Climate climate;

    //Read in and print out the header line
    if (inFile){
        //Read in the header line
        getline(inFile, header);
    }
    //If the file is not valid/cannot be found, let user know and end the program
    else
    {
        cout << "Could not open file" << endl;
    }

    //Declare variables needed for the Climate object
    int fips = 0;
    int count = 0;
    double fall = 0.0, spring = 0.0, summer = 0.0, winter = 0.0;
    string maxWarm = "";
    double annual = 0.0;
    string cityName = "";
    string stateName = "";
    char comma; //Local variable, overwritten everytime a comma is encountered

    //While the file is in a good state and not at the end of the file
    while (inFile && inFile.peek() != EOF) {

        // Read in the FIPS value
        inFile >> fips;
        inFile >> comma;

        // Read in Fall
        inFile >> fall;
        inFile >> comma;

        // Read in Spring
        inFile >> spring;
        inFile >> comma;

        // Read in Summer
        inFile >> summer;
        inFile >> comma;

        // Read in Winter
        inFile >> winter;
        inFile >> comma;

        // Read in the max warming season
        getline(inFile, maxWarm, ',');

        // Read in Annual
        inFile >> annual;
        inFile >> comma;

        // Read in City Name, which stands for county
        getline(inFile, cityName, ',');

        //Read in State Name
        getline(inFile, stateName);

        //Store data into a Climate object and add to the vector
        climateData.push_back(Climate(fips, fall, spring, summer, winter, maxWarm, annual, cityName, stateName)); //increase vector size by one and add object to the end of it

        //Increase count by 1
        ++count;

        //compare highest temps
        // if the annual temp is more then the previous highest temp, set it as new value
        if (annual > climate.getHigestTemp()){
            climate.setHighestTemp(annual);
            climate.setHighestTempIndex(count);
        }

        //compare lowest temps
        // If annual temp is less then previous, set it as the new value
        if (annual < climate.getLowestTemp()){
            climate.setLowestTemp(annual);
            climate.setLowestTempIndex(count);
        }

        //record what season is in maxWarm
        //Run through each of the seaons, checking to see if the string values match
        if (maxWarm == "Fall"){climate.setFallCount();}
        else if (maxWarm == "Summer"){climate.setSummerCount();}
        else if (maxWarm == "Spring"){climate.setSpringCount();}
        else climate.setWinterCount();

    }

    // close the file
    inFile.close();

    // Return the climate object
    return climate;
}

// Get the length of the data set
int getDataSetLength(Climate clim, vector <Climate>& climateData){
    //Set the length
    clim.setLength(climateData.size());

    //Print out the length of the data
    cout << "There are " << clim.getLength() << " entries in the data set" << endl << endl;

    return climateData.size();
}

//A function that has the outline and formate to return a readible summery of the data
void dataLineInformation(Climate clim, vector <Climate>& climateData, int location){

    cout << right << setw(5) << "FIPS" << setw(11) << "Fall" << setw(11) << "Spring" << setw(11) << "Summer" << setw(11)
    << "Winter" << setw(11) << "MaxWarm" << setw(11) << "Annual" << setw(20) << "County Of Origin" << setw(20) << "State of Origin" << endl;
    cout << right << setw(5) << climateData[location].getFips();
    cout << setprecision(4) <<setw(11) << climateData[location].getFall();
    cout << setw(11) <<climateData[location].getSpring();
    cout << setw(11) <<climateData[location].getSummer();
    cout << setw(11) <<climateData[location].getWinter();
    cout << setw(11) <<climateData[location].getMax();
    cout << setw(11) <<climateData[location].getAnnual();
    cout << setw(20) <<climateData[location].getName();
    cout << setw(20) <<climateData[location].getState();
    cout << endl << endl;

}

// Print the highest annual temp in the data set
void highestAnnualTemp(Climate clim, vector <Climate>& climateData){
    cout << "The highest annual temperature was ";
    cout << clim.getHigestTemp() << ", from the following line:" << endl;
    dataLineInformation(clim, climateData, clim.getHighestTempIndex()-1);
}

// Prints the lowest Annual temp in the data set
void lowestAnnualTemp(Climate clim, vector <Climate>& climateData){
    cout << "The lowest annual temperature was ";
    cout << clim.getLowestTemp() << ", from the following line:" << endl;
    dataLineInformation(clim, climateData, clim.getLowestTempIndex()-1);
}

// Prints the number of times a season had the highest warming period for the county
void maxWarmingFrequency(Climate climate, vector <Climate>climateData){
    cout << "The number of times a season had the highest warming period:" << endl;
    cout << "     Fall: " << climate.getFallCount() << endl;
    cout << "   Summer: " << climate.getSummerCount() << endl;
    cout << "   Spring: " << climate.getSpringCount() << endl;
    cout << "   Winter: " << climate.getWinterCount() << endl << endl;

}

#endif //PROJECT1_COUNTY_CLIMATE_H
