#pragma once
#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


class Ticket
{
	friend ostream& operator<<(ostream&, const Ticket&);
	//friend class Customer;

	public:


		Ticket();// CONSTRUCTOR
		// input ticket name, date, time, price, username, reference number to the ticket.txt file
		bool writeToTicketFile(string ticketName,string ticketDate, string ticketTime, double ticketPrice, string username, int referenceNo);

		//bool viewCustTicket(string username);

		// encasulation for Tour_name
		void setTicketName(string tourName);
	    string getTicketName();

		// encasulation for Tour_date
	    void setTicketDate(string tourDate);
	    string getTicketDate();

		// encasulation for Tour_time
	    void setTicketTime(string tourTime);
	    string getTicketTime();

		// encasulation for Tour_price
	    void setTicketPrice(double tourPrice);
	    double getTicketPrice();

	    // encasulation for Tour_price
	    void setUserName(string userName);
	    string getUserName();

	    // encasulation for Tour_price
	    void setRefNo(double tourRef);
	    int getRefNo();

		~Ticket();// DESTRUCTOR

	private:
		string ticketName;// TICKET NAME
		string ticketDate;// TICKET DATE TRAVEL
		string ticketTime;// TICKET TIME TRAVEL
		double ticketPrice;// TICKET PRICE TRAVEL
		string username;// USERNAME
		int referenceNo;// REFERENCE NUMBER

};


#endif



/*struct ourTicket {// ticket information
	string ticketName;
	string ticketDate;
	string ticketTime;
	double ticketPrice;
	string username;
	int referenceNo;
};

		Ticket tick;
*/