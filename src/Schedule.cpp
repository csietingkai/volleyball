#include "Schedule.h"

// constructors
Schedule::Schedule(const DateeTime start, const DateeTime finish, const bool enable_four_section)
{
	if(finish <= start)
	{
		//error("finish time must be later than start time");
	}
	this->start = start;
	this->finish = finish;
	this->four_section = enable_four_section;	// default is false
}

// setters

// getters
const DateeTime Schedule::get_start() const
{
	return this->start;
}

const DateeTime Schedule::get_finish() const
{
	return this->finish;
}

// other functions
void Schedule::start_scheduling()
{
	/*vector<DateeTime> times;
	for(DateeTime current = get_start(); current <= get_finish(); current = current.next_section())
	{
		if(std::find(excludes.begin(), excludes.end(), current.get_week()) == excludes.end())
		{
			if(!(!four_section && current.get_hour() >= 23))
			{
				cout << current << endl;
				times.push_back(current);
			}
		}
	}*/
}
