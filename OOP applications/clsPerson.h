#include <iostream>
#pragma once

using namespace std;
class clsPerson
{
    private:
      string _FirstName;
      string _LastName;
      string _Email;
      string _PhoneNumber;

    public:
      clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
      {
            _FirstName = FirstName;
            _LastName = LastName;
            _Email = Email;
            _PhoneNumber = PhoneNumber;
      };

      string FirstName()
      {
        return _FirstName;
      };

      void setFirstName(string FirstName)
      {
        _FirstName = FirstName;
      };

      string LastName()
      {
        return _LastName;
      };

      void setLastName(string LastName)
      {
        _LastName = LastName;
      };

      string PhoneNumber()
      {
        return _PhoneNumber;
      };

      void setPhoneNumber(string PhoneNumber)
      {
        _PhoneNumber = PhoneNumber;
      };


      string Email()
      {
         return _Email;
      };
    
      void setEmail(string Email)
      {
         _Email = Email;
      };
};