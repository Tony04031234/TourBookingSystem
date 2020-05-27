#include "location.h"

Location::Location()// constructor
{
}

// Set and Get t_name, t_date, t_time, t_price
void Location::setTourName(string name) {
    t_name = name;
}

string Location::getTourName(){
    return t_name;
}

void Location::setTourDate(string date) {
    t_date = date;
}

string Location::getTourDate(){
    return t_date;
}

void Location::setTourTime(string timeTour){
    t_time = timeTour;
}

string Location::getTourTime(){
    return t_time;
}

void Location::setTourPrice(double price){
    t_price = price;
}

double Location::getTourPrice(){
    return t_price;
}


bool Location::addMoreTour(Location ad)
{

	bool ok = false;

	// write to the location2.dat file
	ofstream addLocation("location2.dat", ios::app);

	if (!addLocation) {
		cout << "Error opening files" << endl;
	}
	else {
		while (cin>>ad ) {
			// get the tour name, tour date, tour time, tour price from database
			addLocation << ad.getTourName() << " " << ad.getTourDate() << " " << ad.getTourTime() << " " << ad.getTourPrice() << endl;
			ok = true;
			break;
		}

		addLocation.close();// clode the file
	}
	return ok;// return true or fasle
}

bool Location::callPrivate(Location ad) { // public

   addMoreTour(ad);// call the private function
}


Location::~Location() // destructor
{
}

//Overlaoding >> opeartor for customer signup
istream& operator >> (istream& in, Location& ad){
	cout << "Enter tour location: ";
	in >> ad.t_name;
	cout << "Enter tour date:  ";
	in >> ad.t_date;
	cout << "Enter tour time travel:  ";
	in >> ad.t_time;
	cout << "Enter tour price:  ";
	in >> ad.t_price;
	cout << "Thank You!" << endl;
	return in;
}



