#pragma once

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>

using namespace std;

class Location
{
	friend istream& operator >> (istream&, Location&);

public:

	Location(); //constructor

	// call the private function
	bool callPrivate(Location ad);

	// customer or manager can view all the tour view all the tour
    void viewAllTour();

	// encasulation for Tour_name
	void setTourName(string name);
    string getTourName();

	// encasulation for Tour_date
    void setTourDate(string date);
    string getTourDate();

	// encasulation for Tour_time
    void setTourTime(string timeTour);
    string getTourTime();

	// encasulation for Tour_price
    void setTourPrice(double price);
    double getTourPrice();

	~Location();// destructor

	private:
		bool addMoreTour(Location ad); // private function
    	string t_name; // tour name
    	string t_date; // tour date
    	string t_time;// tour time
    	double t_price;;// tour price
};

#endif


