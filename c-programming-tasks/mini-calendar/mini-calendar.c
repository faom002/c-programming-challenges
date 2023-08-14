#include <stdbool.h>
#include <stdio.h>

// days in the months like january has 31 days etc
int days_in_month[] = {
	0, 31, 
	28, 31, 
	30, 31, 
	30, 31, 
	31, 30, 
	31, 30, 
	31
};

bool isLeapYear(int year) {
    bool divisible = false;

    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            divisible = true;
        }
    }

    return divisible;
}

void addDaysToDate(int* mm, int* dd, int* yy, int days_left_to_add ){
int days_left_in_month;

	while (days_left_to_add > 0) {
		days_left_in_month = days_in_month[*mm] - *dd;
		if (*mm == 2 && isLeapYear(*yy))
		{
			days_left_in_month+=1;
		}


		if (days_left_to_add > days_left_in_month)
		{
			days_left_to_add -= days_left_in_month + 1;
			*dd = 1;

			if (*mm == 12)
			{

				*mm = 1;
				*yy = *yy +1;


			}else {

				*mm = *mm + 1;
			
			}
		}else {
		*dd += days_left_to_add; 
  		days_left_to_add = 0;
		}
	}

}


int main(void) {
    // int year = 1800;
    // printf("%d\n", isLeapYear(year));

	int mm, dd, yy, days_left_to_add;

	printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date:");

	scanf("%d %d %d %d", &mm,&dd,&yy,&days_left_to_add);

		addDaysToDate( &mm,  &dd, &yy, days_left_to_add);

printf("%d %d %d %d", mm, dd, yy, 0);  // Print "0" for days_left_to_add

    return 0;
}
