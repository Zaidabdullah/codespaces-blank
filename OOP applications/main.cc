#include <iostream>
#include "clsDate.h"
#include "clsInputValidate.h"
#include "clsString.h"



int main()
{
   clsDate Date1(1,1,2000); clsDate Date2(2,2,2000) ;
    cout << clsInputValidate::isValidDate(clsDate(35,1,2000)) << endl;
    cout << clsInputValidate::isDateBetween(clsDate(4,1,2000), Date1, Date2)  << endl;
    cout << clsInputValidate::isValidDate(clsDate(35,1,2000));
    // cout << clsInputValidate::isValidDate(clsDate(35,1,2000));
    // cout << clsInputValidate::isValidDate(clsDate(35,1,2000));
    // cout << clsInputValidate::isValidDate(clsDate(35,1,2000));
    // cout << clsInputValidate::isValidDate(clsDate(35,1,2000));
}