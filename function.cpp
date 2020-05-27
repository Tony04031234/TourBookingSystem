#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include "customer.h"
#include "admin.h"
#include "location.h"
#include "ticket.h"

using namespace std;

extern void login();
extern void signup();
extern void custLoggedIn();
extern void adminLoggedIn();
static string username;
static string password;

void login()
{
	system("clear");
	cout <<"                        Login Page            " << endl;
	cout << "--------------------------------------------------------" << endl;

	int choice;
	string  password;

	cout << " 1. CUSTOMER" << endl;
	cout << " 2. ADMINISTRATOR" << endl;
	cout << " 3. BACK \n" << endl;

	while (cout << "Enter a number of choice \n" && !(cin >> choice)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore thr empty inputs
		cout << "Invalid input! Please re-enter.\n";
	}

	if (choice == 1) {
		system("clear"); //Clears screen for user
		cout <<"                        Login Page            " << endl;
		cout << "--------------------------------------------------------" << endl;

		cout << "Username - ";
		cin >> username;// input username

		cout<< "Password - ";
		cin>> password;// input password

		Customer cust;// creat an object cust here
		if (cust.isLogin(username, password)) {/// check the password matching the exsiting data or not
			cout << "" << endl;
			cout << "Login Successful" << endl;
			cout << "Hi " << username << endl;
			system("read -p 'Press Enter to continue...' var");
			custLoggedIn();// go to customer main page
		}
		else {// if the password did not match
			cout << endl<<"Invalid Username or Password !" << endl;
			system("read -p 'Press Enter to continue...' var");
			login();
		}
	}
	else if (choice == 2) {

		system("clear"); //Clears screen for user readability - MS Windows
		cout <<"                        Sign Up Page            " << endl;
		cout << "--------------------------------------------------------" << endl;

		cout << "Username - ";
		cin >> username; // enter username

		cout << "Password - ";
		cin >> password; // enter password

		User *admin; // put on the heap
		admin = new AdminStaff;

		cout << endl;
		if (admin->isLogin(username, password)) {
			cout << "Hi " << username << endl;
			adminLoggedIn();// go to admin main page
		}
		else {
			cout << endl << "Invalid Username or Password !" << endl;
			system("read -p 'Press Enter to continue...' var");
			login();// go back to login
		}
	}

	else if (choice == 3) {
		system("clear");
		cout <<"           Welcome to Adventure Tours Australia            " << endl;
		cout << "--------------------------------------------------------" << endl;
		login();// go back to login
	}
}

void signup()
{
	Customer cu;
	if (cu.isSignUp(cu)) {/// check bool signup here
		cout << "Successfully signed up!" << endl; // if return true
	}
	else {
		cout << "Error Signing up" << endl;// if return false something went wrong
	}
	cout <<"           Welcome to Adventure Tours Australia            " << endl;
	cout << "--------------------------------------------------------" << endl;
	custLoggedIn();// go to customer page
}


// Customer when they login redirecting to main page
void custLoggedIn() {
	system("clear");
	cout <<"                      Customer Main Page            " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Hi " << username<<endl;

	Customer cust;
	//Ticket tick;

	int choice;

	cout << "1-View All Tours\n";
	cout << "2-Book Ticket\n";
	cout << "3-Print Ticket\n";
	cout << "4-Back\n";

	while (cout << "Enter a number of choice\n" && !(cin >> choice)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the empty input
		cout << "Invalid input; please re-enter.\n";
	}
	//View All Tours here
	if (choice==1){
		cust.viewAllTour();
		system("read -p 'Press Enter to continue...' var");
		custLoggedIn();// go back to customer page
	}
	// Book Ticket here
	else if (choice == 2) {
		//check the bool function bookTicket
		if (cust.bookTicket(username)){// its true
			cout << "Payment made successfully" << endl;
			system("read -p 'Press Enter to continue...' var");
			custLoggedIn();
		}
		else {// it is false
			cout << "Payment not made! Try again!" << endl;
			system("read -p 'Press Enter to continue...' var");
			custLoggedIn(); // go back to customer page
		}
	}
	// Print Ticket here
	else if(choice==3){
		system("clear");
		// check the boolean function printTicket
		if (cust.printTicket(username)){// its true
			cout<<endl;
			system("read -p 'Press Enter to continue...' var");
			custLoggedIn();// go back to customer page
		}
		else { // it is false
			cout << "404 Try again!" << endl;
			system("read -p 'Press Enter to continue...' var");
			custLoggedIn();// go back to customer page
		}
	}
	// Go back to main page
	else if(choice==4){
		system("clear");
		login();// go back to login page
		return;
	}
}


// Admin when they login redirecting to main page
void adminLoggedIn(){
    system("clear");
	cout <<"                      Admin Main Page            " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Hi " << username <<endl;

	Location ad;// location object

	AdminStaff admin; //admin object

	int choice;

	cout << "1-View all Tours\n";
	cout << "2-Add more Tours\n";
	cout << "3-Cancle the tour\n";
	cout << "4-View the Sale Summary\n";
	cout << "5-Back\n";

	while (cout << "Enter a number of choice\n" && !(cin >> choice)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore empty input
		cout << "Invalid input; please re-enter.\n";
    }

	// View all the tours here
	if(choice == 1){
		system("clear");
		admin.viewAllTour(); // function to view all the tour
		system("read -p 'Press Enter to continue...' var");
		adminLoggedIn();// go back to admin page
	}

	// Add more tours here
    else if (choice==2){
		system("clear"); //Clears screen for user readability - MS Windows

		cout <<"                    Add Tour Location                   " << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << endl;

		if(ad.callPrivate(ad)){// call the function to add more tours into location2.dat file
			cout << "Added Tour Successfully" << endl;
			system("read -p 'Press Enter to continue...' var");
			adminLoggedIn();// go back to admin page
		}
		else {
			cout << endl << "Oop! Something went wrong!" << endl;
			system("read -p 'Press Enter to continue...' var");
			adminLoggedIn();// go back to admin page
		}
		return;
	}

	// Cancel a tour by admin here
	else if(choice==3){
		system("clear");

		string tourName;
		cout << "Enter Tour name to cancel:" << endl;
		cin >> tourName;

		if (admin.cancelTour(tourName)) {// call the function to cancel the tour data from location2.dat
			cout << "Tour Cancelled" << endl;
			system("read -p 'Press Enter to continue...' var");
			adminLoggedIn();// go back to admin page
		}
		else {
			cout << "Error.Invalid reservationID!\n\n" << endl;
			system("clear");
			adminLoggedIn();// go back to admin page
		}
//		system("read -p 'Press Enter to continue...' var");
//		adminLoggedIn();// go back to admin page
		return;
	}
	// View the Sale Summary here
	else if(choice==4){
		system("clear");
		admin.viewSaleSummary();// view the summary function
		cout<<endl;
		system("read -p 'Press Enter to continue...' var");
		adminLoggedIn();// go back to admin page
		return;
	}
	//go back to login page
	else if(choice==5){
		system("clear");
		login();
		return;
	}
}

