#include <iostream>
#include <limits>
#include <string>

using namespace std;

static string username;

/// Select the options login / signup/ quit
inline int getChoice() {
	int choice;
	cout << "1 - Login" << endl;
	cout << "2 - Sign up" << endl;
	cout << "3 - Quit program" << endl;
	while (cout << "Enter a number of choice \n" && !(cin >> choice)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the space empty value
		cout << "Invalid input; please re-enter.\n";
	}
	return choice;
}

extern void login();
extern void signup();

//extern void viewLocation();

int main(){
	cout <<"           Welcome to Adventure Tours Australia            " << endl;
	cout << "--------------------------------------------------------" << endl;

	int choice;

	while (choice = getChoice()) {
		switch (choice) {

		case 1:// Login
			system("clear");
			login();
			break;
		case 2:// sign up
			system("clear");
			signup();
			break;
		case 3://quit progrm
			system("clear");
			exit(0); // The program is terminated here
			break;
		default:
			system("clear");
			cerr << "invalid choice\n";
		}

	}
	system("read -p 'Press Enter to continue...' var");
	return 0;
}

