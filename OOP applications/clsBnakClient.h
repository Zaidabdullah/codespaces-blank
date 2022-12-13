#include <iostream>

using namespace std;

class clsBankClient : clsPerson
{
   private:
     string _Account_ID;
     string _PinCode;
     int _balance;
     _convert(){}
     _fun(){}
    
    public:
      clsBankClient(string FirstName, string LastName, string Email, string PhoneNumber
      string Account_ID, string PinCode, int balance):clsPerson(FirstName,  LastName, 
       Email,  PhoneNumber)
      {
            _Account_ID = Account_ID;
            _PinCode = PinCode;
            _balance = balance;
      }

      











};