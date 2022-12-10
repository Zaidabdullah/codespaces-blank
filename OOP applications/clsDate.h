#include <iostream>
#include <vector>

#pragma once

using namespace std;

class clsDate
{
    private: 
      short _Day;
      short _Month;
      short _Year;

    vector <string> splitWords(string text, string deli)
    {
      string sWord;
      short pos;
      vector<string> vWords;
      
        while((pos = text.find(deli)) != std::string::npos)
        {
            sWord = text.substr(0, pos);
            if(sWord != "")
            {         
              vWords.push_back(sWord);
            }
            text.erase(0, pos+deli.length());
            }
            
            if(text != "")
            {
                vWords.push_back(text);
            }
        return vWords ;
      }

    public:
      clsDate()
      {
          time_t t = time(NULL);
          tm* now  = localtime(&t);    
          
          _Year  = now->tm_year + 1900;
          _Month = now->tm_mon + 1; 
          _Day   = now->tm_mday;    
      }

      clsDate(short day, int month, int year)
      {	
		_Day   = day;
        _Month = month;
		_Year  = year;
	  }
      
	  clsDate(string sDate)
      {
          vector<string> vDate =  splitWords(sDate, "/");
          _Day   = stoi(vDate[0]);
          _Month = stoi(vDate[1]);
          _Year  = stoi(vDate[2]);
      }

      clsDate(short orderInYear, short Year)
      {
        clsDate Date = dateAfterNumOfDays(orderInYear, Year);

        _Day   = Date.Day();
        _Month = Date.Month();
        _Year  = Date.Year();
      }
       
      static clsDate dateAfterNumOfDays(short numOfDaysInYear, short year)
      {
          clsDate DateAfterDays;
          
          short month = 1;
          while(numOfDaysInYear > findNumOfDayInMonth(year, month) )
          {
              numOfDaysInYear -= findNumOfDayInMonth(year, month);
              month++;   
          }
          short day = numOfDaysInYear; //left day after subtract the days of month is the day in date  
      
          DateAfterDays.setDay(day);
          DateAfterDays.setMonth(month);
          DateAfterDays.setYear(year);

          return DateAfterDays;
      }

      void setDay(short day)
      {
          _Day = day;
      }

      void setMonth(short month)
      {
          _Month = month;
      }

      void setYear(short year)
      {
          _Year = year;
      }
      
      short Day()
      {
          return _Day ;
      }

      short Month()
      {
          return _Month ;
      }

      short Year()
      {
          return _Year ;
      }

      static short findNumOfDayInMonth(short year, short month)
      {
          if(month <1 || month >12)
          { return 0;}
      
          short daysOfMothsArr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
          return month==2? (isLeapYear(year)?29:28):daysOfMothsArr[month];
      }

      short findNumOfDayInMonth()
      {
          return findNumOfDayInMonth(_Year, _Month);
      }
      
      static bool isLeapYear(short year)
      {
        return (year%400==0 || (year%4==0 && year%100!=0));
      }

      bool isLeapYear()
      {
        return isLeapYear(_Year);
      }

      static bool isValidDate(clsDate Date)
      {
          return      Date.Year()  >=1 
                  &&  Date.Month() >=1 && Date.Month() <= 12 
                  &&  Date.Day()   >=1 && Date.Day() <= 31
                  &&  Date.Day()   <= findNumOfDayInMonth(Date.Year(), Date.Month());  
      }

      bool isValidDate()
      {
          return isValidDate(*this);
      }

      void Print( )
    {
      cout << _Day << "/" << _Month << "/" << _Year << "\n";
    }

      static string DateToString(clsDate Date)
      {
        return  to_string(Date.Day()) + "/" + to_string(Date.Month()) + "/" + to_string(Date.Year());
      }

      static short NumberOfDaysInYear(short Year)
      {
        return  isLeapYear(Year) ? 365 : 364;
      }

      static short NumberOfHoursInYear(short Year)
      {
          return  NumberOfDaysInYear(Year) * 24;
      }

      short NumberOfHoursInYear()
      {
          return NumberOfHoursInYear(_Year);
      }

      static short NumberOfMinutesInYear(short Year)
      {
         return  NumberOfHoursInYear(Year) * 60;
      }

      short NumberOfMinutesInYear()
      {
         return NumberOfMinutesInYear(_Year);
      }
      
      static short NumberOfSecondsInAYear(short Year)
      {
         return  NumberOfMinutesInYear(Year) * 60;
      }

      short NumberOfSecondsInAYear()
      {
         return NumberOfSecondsInAYear(_Year);
      }

      static short NumberOfDaysInMonth(short Month, short Year)
      {
          if (Month < 1 || Month>12)
          return  0;

        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
      }
      
      short NumberOfDaysInMonth()
      {
          return NumberOfDaysInMonth(_Month, _Year);
      }

      static short DayOfWeekOrder(short Day, short Month, short Year)
      {
          short a, y, m;
          a = (14 - Month) / 12;
          y = Year - a;
          m = Month + (12 * a) - 2;
          // Gregorian:
          //0:sun, 1:Mon, 2:Tue...etc
          return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
      }

      short DayOfWeekOrder()
      {
          return DayOfWeekOrder(_Day, _Month, _Year);
      }

      static string DayShortName(short DayOfWeekOrder)
      {
        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder];

      }

      string currentDayShortName()
      {
          return DayShortName(DayOfWeekOrder());
      }

      static string MonthShortName(short MonthNumber)
      {
        string Months[12] = { "Jan", "Feb", "Mar",
                              "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep",
                              "Oct", "Nov", "Dec"};

        return (Months[MonthNumber - 1]);
      }

      string MonthShortName()
      {
        return MonthShortName(_Month);
      }

      static void PrintMonthCalendar(short Month, short Year)
      {
          int NumberOfDays;

          // Index of the day from 0 to 6
          int current = DayOfWeekOrder(1, Month, Year);

          NumberOfDays = NumberOfDaysInMonth(Month, Year);

          // Print the current month name
          printf("\n  _______________%s_______________\n\n",
            MonthShortName(Month).c_str());

          // Print the columns
          printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

          // Print appropriate spaces
          int i;
          for (i = 0; i < current; i++)
            printf("     ");

          for (int j = 1; j <= NumberOfDays; j++)
          {
            printf("%5d", j);


            if (++i == 7)
            {
              i = 0;
              printf("\n");
            }
          }

          printf("\n  _________________________________\n");

      }

      void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

      static void PrintYearCalendar(int Year)
      {
          printf("\n  _________________________________\n\n");
          printf("           Calendar - %d\n", Year);
          printf("  _________________________________\n");


          for (int i = 1; i <= 12; i++)
          {
            PrintMonthCalendar(i, Year);
          }

          return;
      }

      void PrintYearCalendar()
      {
          printf("\n  _________________________________\n\n");
          printf("           Calendar - %d\n", _Year);
          printf("  _________________________________\n");


          for (int i = 1; i <= 12; i++)
          {
            PrintMonthCalendar(i, _Year);
          }

          return;
      }

      static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
      {
          short TotalDays = 0;

          for (int i = 1; i <= Month - 1; i++)
          {
            TotalDays += NumberOfDaysInMonth(i, Year);
          }

          TotalDays += Day;

          return TotalDays;
      }

      short DaysFromTheBeginingOfTheYear()
      {
          short TotalDays = 0;

          for (int i = 1; i <= _Month - 1; i++)
          {
            TotalDays += NumberOfDaysInMonth(i, _Year);
          }

          TotalDays += _Day;

          return TotalDays;
      }

      static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
      {
          clsDate Date;
          short RemainingDays = DateOrderInYear;
          short MonthDays = 0;

          Date.setYear(Year);
          Date.setMonth(1);

          while (true)
          {
            MonthDays = NumberOfDaysInMonth(Date.Month(), Year);

            if(RemainingDays > MonthDays)
            {
              RemainingDays -= MonthDays;
              Date._Month++;
            }
            else
            {
              Date.setDay(RemainingDays);
              break;
            }
        }
          return Date;
      }

      void AddDays(short Days)
      {
          short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
          short MonthDays = 0;

          _Month = 1;

          while (true)
          {
            MonthDays = NumberOfDaysInMonth(_Month, _Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12)
                {
                  _Month = 1;
                  _Year++;
                }
            }
            else
            {
              _Day = RemainingDays;
              break;
            }

          }


      }

      static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
      {
        return  (Date1.Year() < Date2.Year()) ? true : ((Date1.Year() == Date2.Year()) ? (Date1.Month() < Date2.Month() ? true : (Date1.Month() == Date2.Month() ? Date1.Day() < Date2.Day() : false)) : false);
      }

	bool IsDateBeforeDate2(clsDate Date2)
	{
		//note: *this sends the current object :-) 
		return  IsDate1BeforeDate2(*this, Date2);

	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year() == Date2.Year()) ? ((Date1.Month() == Date2.Month()) ? ((Date1.Day() == Date2.Day()) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(clsDate Date2)
	{
		return  IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{

		return (Date.Day() == NumberOfDaysInMonth(Date.Month(), Date.Year()));

	}

	bool IsLastDayInMonth()
	{

		return IsLastDayInMonth(*this);

	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month()))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date.setDay(1);
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}

	static void  SwapDates(clsDate & Date1, clsDate & Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;

		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}

		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static clsDate GetSystemDate()
	{
		clsDate Date;
		
			time_t t = time(NULL);
			tm* now  = localtime(&t);    
			
			Date.setYear(now->tm_year + 1900);
			Date.setMonth(now->tm_mon + 1); 
			Date.setDay(now->tm_mday); 

		return Date;
	}
	
	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
	}
	//above no need to have nonstatic function for the object because it does not depend on any data from it.

	static clsDate IncreaseDateByOneWeek(clsDate & Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	clsDate IncreaseDateByOneMonth(clsDate& Date)
	{

		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month(), Date.Year());
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date._Year += Years;
		return Date;
		
	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date._Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date._Year += 1000;
		return Date;
	}

	clsDate IncreaseDateByOneMillennium()
	{
		return IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day() == 1)
		{
			if (Date.Month() == 1)
			{
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else
			{

				Date._Month--;
				Date._Day = NumberOfDaysInMonth(Date.Month(), Date.Year());
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate &Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate &Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks ,*this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate &Date)
	{

		if (Date.Month() == 1)
		{
			Date.setMonth(12);
			Date._Year--;
		}
		else
			Date._Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month(), Date.Year());
		if (Date.Day() > NumberOfDaysInCurrentMonth)
		{
			Date.setDay(NumberOfDaysInCurrentMonth);
		}


		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate &Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate &Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths( Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate &Date)
	{

		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate &Date)
	{

		Date._Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years ,*this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate &Date)
	{
		//Period of 10 years
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate &Date)
	{

		Date._Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate &Date)
	{
		//Period of 100 years
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate &Date)
	{
		//Period of 1000 years
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static short IsEndOfWeek(clsDate Date)
	{
		return  DayOfWeekOrder(Date.Day(), Date.Month(), Date.Year()) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date.Day(), Date.Month(), Date.Year());
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day(), Date.Month(), Date.Year());
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{

		clsDate EndOfMontDate;
		EndOfMontDate.setDay(NumberOfDaysInMonth(Date1.Month(), Date1.Year()));
		EndOfMontDate.setMonth(Date1.Month());
		EndOfMontDate.setYear(Date1.Year());

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1)
	{

		clsDate EndOfYearDate;
		EndOfYearDate.setDay(31);
		EndOfYearDate.setMonth(12);
		EndOfYearDate.setYear(Date1.Year());

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{

		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;

	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		return CalculateBusinessDays(DateFrom, DateTo);

	}
	//above method is eough , no need to have method for the object

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)

{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDateAfterDate2( clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare CompareDates( clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	

};


