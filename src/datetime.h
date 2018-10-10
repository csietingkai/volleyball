#ifndef DATETIME_H
#define DATETIME_H

using namespace std;

// global variables
const string MONTHS[] = 
{
	"December", 
	"Junary", "Feburary", "March", 
	"April", "May", "June", 
	"July", "August", "September", 
	"October", "November", "December"
};

const int DAY_OF_MONTHS[] = 
{
	31,				// Dec,
	31, 28, 31, 	// Jan, Feb, Mar
	30, 31, 30, 	// Apr, May, Jun
	31, 31, 30, 	// Jul, Aug, Sept
	31, 30, 31		// Oct, Nov, Dec
};

const string DAY_OF_WEEK[] = 
{
	"Sunday",
	"Monday",
	"Tuesdy",
	"Wednesday", 
	"Thursday", 
	"Friday", 
	"Saturday" 
};

enum class Week
{
	SUNDAY = 0,
	MONDAY = 1,
	TUESDAY = 2,
	WEDNESDAY = 3,
	THURSDAY = 4,
	FRIDAY = 5,
	SATURDAY = 6
};

//====================/ DateTime class section /====================//

class DateTime
{
	public:
		// constructors
		DateTime(const int year =  1900, const int month = 1, const int day = 1, const int hour = 0, const int minute = 0, const int second = 0);
		
		// getters
		const int get_year() const;		// return the year
		const int get_month() const;	// return the month
		const int get_day() const;		// return the day
		const Week get_week() const;	// return what day is it
		const int get_hour() const;		// return the hour
		const int get_minute() const;	// return the minute
		const int get_second() const;	// return the minute
		const string to_string() const;	// format: yyyy-mm-dd, week, hh:mm:ss
		const int hashcode() const;
		
		// operators
		const DateTime& operator =(const DateTime& other);
		const bool operator ==(const DateTime& other) const;
		const bool operator !=(const DateTime& other) const;
		const bool operator <(const DateTime& other) const;
		const bool operator >(const DateTime& other) const;
		const bool operator <=(const DateTime& other) const;
		const bool operator >=(const DateTime& other) const;
		friend ostream& operator <<(ostream& strm, const DateTime& other);
		// other function
		const DateTime next_section();
		const DateTime previous_section();
		
		// static functions
		const static DateTime Now();
		
	private:
		int year;
		int month; // store -1, range 0~11
		int day;
		Week week;
		int hour;
		int minute;
		int second;
		
		bool is_leap; // 閏年
		
		void check_year();		// check year range in 1900~9999
		void check_month();		// check month range 1~12
		void check_day(); 		// check day range 1~28/29/30/31
		void check_hour(); 		// check hour range 0~23
		void check_minute(); 	// check minute range 0~59
		void check_second(); 	// check second range 0~59
		
		const bool calculate_leap() const; // calculate is leap by year
		const Week calculate_week() const; // calculate week by year, month and day
};

#endif //DATETIME_H
