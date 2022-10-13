#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

time_t toEpoc(char* filename) //YYYYMMDD.HHMM
{
	//TODO use strtoul()
	long int year=strtol(filename.substr(0, 4).c_str(), NULL, 10);
	long int month=strtol(filename.substr(4, 2).c_str(), NULL, 10);
	long int day=strtol(filename.substr(6, 2).c_str(), NULL, 10);
	long int hour=strtol(filename.substr(9, 2).c_str(), NULL, 10);
	long int min=strtol(filename.substr(11, 2).c_str(), NULL, 10);

	struct tm t = {0};  // initalize to all 0's
	t.tm_year = year-1900;
	t.tm_mon = month-1;
	t.tm_mday = day;
	t.tm_hour = hour-1;
	t.tm_min = min;
	t.tm_sec = 0;

	return mktime(&t);
}

int main()
{
	{
		time_t now_00;
		time_t now_01;

		now_00=time(NULL);
		time(&now_01);

		//printf("%lld\n", (long long)now_00);
		assert(now_00==now_01); //unless very unlucky
	}
	{
		time_t now_00=time(NULL);

		char* str = ctime(&now_00);
		printf("%s\n", str); //Sat Mar 22 13:37:40 2014
	}
	{
		time_t now_00=time(NULL);

		struct tm* tm_00=gmtime(&now_00);
		char* str=asctime(tm_00);
		printf("%s\n", str); //Sat Mar 22 13:37:40 2014
	}
	{
		assert(toEpoch("20140714.1150")==);
	}
	return 0;
}
