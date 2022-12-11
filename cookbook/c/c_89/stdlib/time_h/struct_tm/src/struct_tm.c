#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//struct tm {
//	int tm_sec;   // seconds of minutes from 0 to 61
//	int tm_min;   // minutes of hour from 0 to 59
//	int tm_hour;  // hours of day from 0 to 24
//	int tm_mday;  // day of month from 1 to 31
//	int tm_mon;   // month of year from 0 to 11
//	int tm_year;  // year since 1900
//	int tm_wday;  // days since sunday
//	int tm_yday;  // days since January 1st
//	int tm_isdst; // hours of daylight savings time
//}

int main()
{
	{
		time_t time_00=time(NULL);
		struct tm* tm_00;

		tm_00=localtime(&time_00);

		printf("date: %d/%d/%d\n", 1900+tm_00->tm_year, 1+tm_00->tm_mon, tm_00->tm_mday);
		printf("time: %d:%d:%d\n", 1+tm_00->tm_hour, 1+tm_00->tm_min, 1+tm_00->tm_sec);
	}
	return 0;
}
