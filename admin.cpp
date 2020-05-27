#include "admin.h"
#include <iomanip>

AdminStaff::AdminStaff()// constructor
{
}



// check the login whether it is matching with the data in system
bool AdminStaff::isLogin(string username, string password)
{
	bool ok = false;

	// set the username/ password default for admin login
	if (username.compare("admin") == 0 && password.compare("admin123") == 0) {
		ok = true;
	}
	return ok; // return true false
}

void AdminStaff::viewAllTour(){
	cout <<"                Adventure Tours Australia            " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout<< "Your location is Adelaide"<<endl;
	cout<< "This is the all the available tour information:  "<< endl;
	cout<<endl;

	//bool flag = false;
	ifstream locationFile("location2.dat");

	if (!locationFile){

		cerr << "File could not be opened \a" << endl;
	}
	else {

		string tourName;
		string tourDate;
		string tourTime;
		double tourPrice;

		//export information from location.dat file
		while (locationFile >>tourName >> tourDate >> tourTime >>  tourPrice) {
		// Print out the ticket here
			cout << setw(15)<<""<< tourName<< endl;
			cout << "|------------------------------------|"  << endl;
			cout << "|"<<"Travel Date:"       << setw(20) << tourDate << setw(5)  << "|" <<endl;
			cout << "|"<<"Travel Time:"       << setw(16) << tourTime << setw(9) << "|"<<endl;
			cout << "|"<<"Ticket Price-($Au):"<< setw(10) << tourPrice<< setw(8) << "|"<<endl;
			cout << "|------------------------------------|" <<endl;
		}
	}
	return;
}

// add more tours to the system

// Cancel the tour
bool AdminStaff::cancelTour(string t_Name){

	bool ok = false;

	string tourName;
	string tourDate;
	string tourTime;
	string tourPrice;

	// get the data from locatio2.dat file
	ifstream locationFile("location2.dat");

	// create a temporary txt file
	ofstream tempFile("temp.txt", ios::app);

	if (!locationFile)
	{
		cerr << "File could not be opened" << endl;
	}
	else
	{	//export and get information from location.dat file
		while (locationFile >> tourName >> tourDate >> tourTime >> tourPrice){

			// compare tour name wanting to cancel with the data in database
			if (t_Name.compare(tourName) != 0) {
				// import all the data from location2.dat to temp.txt except the t_name = tourName
				tempFile << tourName << " " << tourDate << " " << tourTime<< " " << tourPrice << endl;
			}
			if (t_Name.compare(tourName) == 0) {
				ok = true;
			}
		}

		locationFile.close();// close the file
		tempFile.close();// close the file

		remove("location2.dat");// remove the location2.dat file
		rename("temp.txt", "location2.dat"); // change the name of temp.txt to location2.dat file which is updated
	}
	return ok;
}

void AdminStaff::viewSaleSummary()
{
	cout << left << setw(10) << "Tour Name" << setw(15) << "Tour Date" << setw(10) << "Tour Time" << left << setw(10) << right << setw(10) << " Price" << setw(10) << " Booked by" << setw(11) << "Ref. No" << endl;
	cout << left << setw(10) << "-------" << setw(15) << "----------" << setw(10) << "----------" << left << setw(10) << right << setw(10) << " -----" << setw(10) << " --------" << setw(11) << "-------" << endl;

	double sales = 0;

	ifstream ticketCustFile("Ticket.txt");

	if (!ticketCustFile){
		cerr << "File could not be opened" << endl;
	}
	else {

		string tName;
		string tDate;
		string tTime;
		double tPrice;
		string tUsername;
		int tRefNo;

		while (ticketCustFile >>tName >>tDate >>tTime>>tPrice>>tUsername>>tRefNo) {
			cout << left << setw(10) << tName<< setw(15) << tDate << setw(10) << tTime << left << setw(10) << right << tPrice<< setw(10) << tUsername << setw(11) << tRefNo<< endl;
			sales += tPrice;
		}
		cout << endl;
		cout << "Total Sales :$Au." << (int)sales << endl;
	}
}
AdminStaff::~AdminStaff() //destructor
{
	cout << "Logged Out" << endl;
}











































