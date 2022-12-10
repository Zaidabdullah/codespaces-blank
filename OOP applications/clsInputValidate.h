#pragma once
#include "clsDate.h"

class clsInputValidate

{

public:

   static bool IsNumberBetween(short value, short min, short max)
   {
      return (value >= min && value <= max);
   }

   static bool IsNumberBetween(double value, double min, double max)
   {
      return (value >= min && value <= max);
   }

   static bool IsNumberBetween(float value, float min, float max)
   {
        return (value >= min && value <= max);
   }

   static bool isDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
   {
      return
      clsDate::IsDate1BeforeDate2(Date1, Date)?clsDate::IsDate1AfterDate2(Date2, Date)
      :clsDate::IsDate1BeforeDate2(Date2, Date)?clsDate::IsDate1AfterDate2(Date1, Date)
      :false;
   }

   static int readIntNumber(string msg)
   {
        cout << "enter int number";
        int number;
        cin >> number;
        while (cin.fail())
        {
           cout << msg << endl;
           cout << "enter int number";
           cin >> number;
        }
        return number;
   } 


   static int readDblNumber(string msg)
   {
        cout << "enter int number";
        double number;
        cin >> number;
        while (cin.fail())
        {
           cout << msg << endl;
           cout << "enter int number";
           cin >> number;
        }
        return number;
   } 

   static int isIntbetween(int )
   {

   }
};
