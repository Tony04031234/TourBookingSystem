#ifndef ADMINSTAFF_H
#define ADMINSTAFF_H
#include "user.h"
//#include "location"
#include <string>


using namespace std;


class AdminStaff : public User
{

    public:

    	AdminStaff();// constructor

    	bool isLogin(string, string)override;

        // view all the tour
    	void viewAllTour();


        // cancel the tour
    	bool cancelTour(string usersname);

        // view the total sale based on the customer payment.
    	void viewSaleSummary();

	    ~AdminStaff();// destructor

    private:
    	string adminName;
    	string contactNo;
    	string email;
};
#endif

