#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
	int yearday;

	if (yearday = day_of_year(1988, 2, 20))
		printf("%d\n", yearday);
	else
		printf("error: wrong day_of_year input");

	int m, d;
	if(month_day(1988, 51, &m, &d))
		printf("%d %d\n", m, d);
	else
		printf("error: wrong month_day input");
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return 0;

	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day > daytab[leap][month])
		return 0;

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month & day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (year < 1 || yearday < 1)
		return 0;
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yearday > (leap? 366 : 365))
		return 0;

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;

	return 1;
}
