#include "ticket.h"
#include <iomanip>
#include <iostream>

using namespace std;

Ticket::Ticket()
{
}

	// encasulation for Tour_name
void Ticket::setTicketName(string tourName){
	ticketName = tourName;
}

string Ticket::getTicketName(){
	return ticketName;
}

// encasulation for Tour_date
void Ticket::setTicketDate(string tourDate){
	ticketDate = tourDate;
}

string Ticket::getTicketDate(){
	return ticketDate;
}

// encasulation for Tour_time
void Ticket::setTicketTime(string tourTime){
	ticketTime = tourTime;
}

string Ticket::getTicketTime(){
		return ticketTime;
}

// encasulation for Tour_price
void Ticket::setTicketPrice(double tourPrice){
	ticketPrice = tourPrice;
}

double Ticket::getTicketPrice(){
	return ticketPrice;
}

// encasulation for Tour_price
void Ticket::setUserName(string userName){
	username = userName;
}

string Ticket::getUserName(){
	return username;
}

// encasulation for Tour_price
void Ticket::setRefNo(double tourRef){
	referenceNo = tourRef;
}

int Ticket::getRefNo(){
	return referenceNo;
}

// input ticket name, date, time, price, username, reference number to the ticket.txt file
bool Ticket::writeToTicketFile(string ticketName,string ticketDate, string ticketTime, double ticketPrice, string username, int referenceNo)
{
	bool ok = false;

	// ofstream to write to ticket.txt file
	ofstream custTicketFile("Ticket.txt", ios::app);

	if (!custTicketFile) {
		cout << "Error opening file" << endl;
	}
	else {
		custTicketFile <<ticketName << " " <<ticketDate << " " << ticketTime<< " " << ticketPrice << " " <<username << " " << referenceNo << endl;
		ok = true;
	}
	return ok;
}

Ticket::~Ticket()
{
}
// print out ticket information
ostream& operator<<(ostream& out, const Ticket& ticket)
{

	cout << setw(40) << "Ticket Information" << endl;
	cout <<	setw(43) << "-------------------------------"<< endl ;
	cout <<	setw(31) << "Event Name : " << ticket.ticketName << endl;
	cout <<	setw(30) << "Event Date :" << ticket.ticketDate << endl;
	cout <<	setw(30) << "Event Time :"<<ticket.ticketTime << endl;
	cout <<	setw(30) << "Ticket Price -:Rs." << ticket.ticketPrice << endl;
	cout <<	setw(30) << "Username :" << ticket.username << endl;
	cout <<	setw(30) << "Refernce Number :" << ticket.referenceNo << endl;
	cout <<	setw(43) << "------------------------------" << endl;
	return out;
}

