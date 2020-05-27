// Customer cpp file
#include <iomanip>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "customer.h"
#include "ticket.h"
//#include "location.h"

using namespace std;

Customer::Customer()// constructor
{
}

Customer::Customer(string userName)
{
	username = userName;
}

Customer::Customer(string username, string password, string fName, string lName, string contactNo, string email)
	// USERNAME, PASSWORD, FIRST_NAME, LAST_NAME, CONTACT_NUMBER, EMAIL.
	:User(username, password) {// inherit user class

}

// Set and Get  First_name, Last_name, Contact_number, Email.
void Customer::setfName(string firstName){
	fName = firstName;
}

string Customer::getfName() const{
	return fName;
}

void Customer::setlName(string lastName){
	lName = lastName;
}

string Customer::getlName() const{
	return lName;
}

void Customer::setContactNo(string contactNum){
	contactNo = contactNum;
}

string Customer::getContactNo() const{
	return contactNo;
}

void Customer::setEmail(string emailad){
	email = emailad;
}

string Customer::getEmail() const{
	return email;
}

Customer::~Customer(){ // destructor
}



 // check the username and password matching the system database or not
bool Customer::isLogin(string username, string password)
{
	bool ok = false;
	/// read the .dat file
	ifstream custFile("customer.dat");

	// can't open the customer.dat file
	if (!custFile)
	{
		cerr << "File could not be opened" << endl;
	}
	// opened the file
	else {
		string uName; // username
		string pass; // password

		while (custFile >> uName >> pass >> fName >> lName >> contactNo >> email) {
			// compare to pasword and username
			if (username.compare(uName) == 0 && password.compare(pass) == 0) {
				ok = true;
				setUsername(uName);
				break;
			}
			else {
				ok = false;
			}
		}
		custFile.close();
	}
	return ok;
}

// creat a customer.dat and input username password and store it to customer.dat file
bool Customer::isSignUp(Customer cust) // pass objest as a parameter
{
	bool ok = false;

	// create the customer database containing customer information
	// ios::app tell the system go to the end of the file
	ofstream outCustFile("customer.dat", ios::app);

	if (!outCustFile) { // check the file which is available or not
		cout << "Error opening file" << endl;
	}
	else {
		while (cin >> cust) { /// store username/password/first_name/last_name/contact_no/email
			outCustFile << cust.getUsername() << " " << cust.getPassword() << " " << cust.getfName() << " " << cust.getlName() << " " << cust.getContactNo() << " " << cust.getEmail() << endl;
			ok = true;
			break;
		}
	}

	outCustFile.close();// close the file

	return ok;// return true/false
}

void Customer::viewAllTour(){

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

		//cout << left << setw(20) << "Destination" << setw(20) << " Date" << setw(20) << "Time Travel" << left << setw(10) << right << "Price" << endl;
		//cout << endl;
		while (locationFile >>tourName >> tourDate >> tourTime >>  tourPrice) {
			//cout << left << setw(20) << tourName << setw(20) << tourDate << setw(17) <<  tourTime<< left << setw(10) << right << "$Au." << tourPrice << endl;
		cout << setw(15)<<""<< tourName<< endl;
		cout << "|------------------------------------|"  << endl;
		cout << "|"<<"Travel Date:"       << setw(20) << tourDate << setw(5) << "|" <<endl;
		cout << "|"<<"Travel Time:"       << setw(16) << tourTime << setw(9) << "|"<<endl;
		cout << "|"<<"Ticket Price-($Au):"<< setw(10) << tourPrice<< setw(8) << "|"<<endl;
		cout << "|------------------------------------|" <<endl;
		}
	}

	return;
}

bool Customer::bookTicket(string username)
{
	string ticketDesName;
	string ticketDate;
	string ticketTime;
	double ticketPrice;

	//username,refereenceno
	bool ok = false;

	//generate a random reference number !!!! assummption the random reference number is from 1 - 10000
	int i = 0;
	srand((int)time(0));
	int ticketRefNo = (rand() % 10000) + 1;
	cout << "Your reference number is " << ticketRefNo << endl;

	cout << " Credit Card(C) or Debit Card (D):\n";

	string input;
	cin >> input;

	while (input.length() != 1) // invalid input 'D' or 'C'
	{
		cout << "Invalid input. Enter valid type of payment\n";
		getline(cin, input);// get input
	}

	if (input[0] == 'D' || input[0] == 'C') {
		char paymentType = input[0];
	}
	else {
		cout << "Invalid input\n";
	}

	string cardCodeNo;
	cout << "Enter the 3 Digit card Code \n";
	cin >> cardCodeNo;

	while (cardCodeNo.length() != 3) // it must be 3 digits on the back of the card
	{
		cout << "Invalid input.Read Instructions and enter valid type\n";
		getline(cin, cardCodeNo);
	}

	cout<<"Enter the place you want to travel to...\n";
	string desti;
	cin >> desti;

	ifstream locationFile("location2.dat");// get the data from location2.dat file

	if (!locationFile)
	{
		cerr << "File could not be opened" << endl;
	}
	else {
		string tourName;
		string tourDate;
		string tourTime;
		double tourPrice;

		while (locationFile >> tourName >> tourDate>> tourTime >> tourPrice) {

			if (desti == tourName) {
				ticketDesName = tourName;// get the tour name
				ticketDate = tourDate;// get the tour date
				ticketTime = tourTime;// get the tour time
				ticketPrice = tourPrice;// get the tour price
			}
		}
		locationFile.close(); // close the file
	}

	// Print out the ticket
	cout << setw(30) << "Ticket Information" << endl;
	cout <<	setw(43) << "-------------------------------" << endl;
	cout << setw(31) << "Event Name : " << ticketDesName << endl;
	cout << setw(30) << "Event Date :" << ticketDate << endl;
	cout <<	setw(30) << "Event Time :" << ticketTime << endl;
	cout <<	setw(30) << "Ticket Price -:$Au." << ticketPrice << endl;
	cout <<	setw(30) << "Username :" << username << endl ;
	cout <<	setw(30) << "Refernce Number :" << ticketRefNo << endl;
	cout <<	setw(43) << "------------------------------" << endl;
	cout<<endl;

	char c;
	cout << "Confirm payemnt[Y/N]" << endl;
	cin >> c;

	Ticket tick;// create a object ticket

	if (c == 'Y')
	{
		// import the destination, date, time , price , username , refno to ticket.txt file
		if (tick.writeToTicketFile(ticketDesName ,ticketDate,  ticketTime,  ticketPrice,  username, ticketRefNo))
		{
			cout << "Ticket Succesfully paid" << endl;
			ok = true;
		}
	}else if (c == 'N') {
		ok = false;
	}
	//ok = true;
	return ok;// return boolean true or false
}


bool Customer::printTicket(string username)
{
//	cout<< tick.getRefNo()<<endl;

	bool ok = false;

	ifstream ticketCustFile("Ticket.txt");

	if (!ticketCustFile)
	{
		cerr << "File could not be opened" << endl;
	}
	else {
		string tName;
		string tDate;
		string tTime;
		double tPrice;
		string tUsername;
		int tRefNo;

		// get the tour name, tour date, tour time, username, reference number from ticket.txt file
		while (ticketCustFile >>tName >>tDate >>tTime>>tPrice>>tUsername>>tRefNo) {
			// compare the username with the username associate with the ticket
			// if it matchs with the data, print out ticket
			if (username.compare(tUsername) == 0) {

				cout << setw(40) << "Ticket Information" << endl;
				cout << setw(43) << "-------------------------------"<< endl;
				cout << setw(31) << "Event Name : " <<  tName << endl;
				cout << setw(30) << "Event Date :" <<tDate << endl;
				cout << setw(30) << "Event Time :"<<tTime<< endl;
				cout << setw(30) << "Ticket Price -:$Au." << tPrice<< endl;
				cout << setw(30) << "Username :" << tUsername << endl ;
				cout << setw(30) << "Refernce Number :" << tRefNo<< endl;
				cout << setw(43) << "------------------------------" << endl;

				ok = true;
			}
			else {
				ok = false;
			}
		}
		ticketCustFile.close();// close the file
	}

	return ok; // return boolean
}


//Overlaoding >> opeartor for customer signup
istream& operator >> (istream& in, Customer& Cust){
	cout <<  "                    Signup Page                  " << endl;
	cout << " ------------------------------------------------ " << endl;
	cout << endl; // to clear the buffer
	cout << "Enter Username ";
	in >> Cust.username;
	cout << "Enter Password  ";
	in >> Cust.password;
	cout << "Enter First Name  ";
	in >> Cust.fName;
	cout << "Enter Last Name  ";
	in >> Cust.lName;
	cout << "Enter Contact Number  ";
	in >> Cust.contactNo;
	cout << "Enter Email  ";
	in >> Cust.email;
	cout << "Thank You!" << endl;
	return in;
}


