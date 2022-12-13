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

      string Account_ID()
      {
        return _Account_ID;
      }

      string PinCode()
      {
        return _PinCode;
      }
      
      void setPinCode(string PinCode)
      {
         _PinCode = PinCode;
      }

      string balance()
      {
        return balance;
      }

      void balance(int balance)
      {
        _balance = balance;
      }

      void print()
      {
          cout << "first name "   << FirstName()  << endl;
          cout << "last name "    << LastName()   << endl;
          cout << "email "        << Email()      << endl;
          cout << "phone number " << PhoneNumber()<< endl;
          cout << "account ID "   << Account_ID() << endl;
          cout << "pin code "     << PinCode()    << endl;
          cout << "balance "      << balance()    << endl;
      }

    static find(string acount ID)
    {
        
    }








};