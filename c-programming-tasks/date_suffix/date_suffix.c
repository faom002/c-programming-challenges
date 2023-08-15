#include <stdio.h>


 int suffix(int day){
  	if (day == 1)
  	{
  		printf("%dst", day);
  	}else if (day == 2) {
  		printf("%dnd", day);
  	}else if (day == 3)
  	{
  	printf("%drd", day);
  	} else {
  	printf("%dth", day);
  	}
  	

  	return day;
 }

int main(void) {
  int month, day, year;

  // Standard date form
  printf("Enter date (mm/dd/yyyy): ");
  // Split the user input into 3 variables for the date
  // Don't worry about the `scanf()` below, you'll learn more about these later!
  scanf("%d /%d /%d", &month, &day, &year);





  switch (month) {
 
  		case 1:
printf("January/");
  		suffix(day);
  		printf("/%d",year);

  		break;
  		case 2:

printf("February/");
  		suffix(day);
  		printf("/%d",year);

  		break;
  		case 3:


printf("Mars/");
  		suffix(day);
  		printf("/%d",year);


  		break;
  		case 4:

printf("April/");
  		suffix(day);
  		printf("/%d",year);

  		break;
  		case 5:
  		printf("May/");
  		suffix(day);
  		printf("/%d",year);


  		break;
  		case 6:
  		 printf("June/");
  		suffix(day);
  		printf("/%d",year);


  		break;
  		case 7:
  		printf("July/");
  		suffix(day);
  		printf("/%d",year);


  		break;
  		case 8:
  		
  		printf("August/");
  		suffix(day);
  		printf("/%d",year);
  		break;
  		case 9:

printf("Septemeber/");
  		suffix(day);
  		printf("/%d",year);
  		break;
  		case 10:

printf("October/");
  		suffix(day);
  		printf("/%d",year);



  		break;

 		case 11:

printf("November/");
  		suffix(day);
  		printf("/%d",year);



  		break;



 		case 12:

printf("December/");
  		suffix(day);
  		printf("/%d",year);



  		break;

  	default:
  		printf("not an actual date");
  }
  
  
  return 0;
}

