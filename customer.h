#include "user.h"
#include "ticket.h"
#include "location.h"
#include <limits>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class Customer: public User
{
	friend istream& operator >> (istream&, Customer&);
	//friend class Ticket;

	public:
		Customer();// construcor

		Customer(string);

		Customer(string, string , string , string , string , string );

		// View all the tours
		void viewAllTour();

		// Function that let customer make the payment
		bool bookTicket(string username);

		// Function that let customer can print out the ticket
		bool printTicket(string username);

		// Check Login whether the password/username matching with data in database
		bool isLogin(string,string) override;

		// Check signup and store the new customer info
		bool isSignUp(Customer cust);

		// firstname (encapsualation)
		void setfName(string firstName);
		string getfName() const;

		// Last name (encapsualation)
		void setlName(string lastName);
		string getlName() const;


		//encapsualtion for contact number
		void setContactNo(string contactNum);
		string getContactNo() const;

		//encapsualtion for contact number
		void setEmail(string emailad);
		string getEmail() const;

		~Customer();//destructor



	private:
		string fName;// first name
		string lName;// last name
		string contactNo;// contact n.o
		string email;// email
};

