#include <stdio.h>
#include <unistd.h>

struct Race {
	int numberOfLaps;
	int currentLap;
	char* firstPlaceDriveName;
	char* firstPlaceRaceCarColor;
};


struct RaceCar {
	char* driverName;
	char* raceCarColor;
	int totalLapTime;
};

void printIntro(void){
	
	printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");

}

void printCountDown(void){
	for (int i = 5; i >= 0 ; --i)
	{
		printf("Racers Ready! in.. ");
		sleep(1);
		printf("%d\n", i);
		sleep(1);

		if (i <= 0)
		{
			printf("Race!!!\n");
			
		}

	}
}



void printFirstPlaceAfterLap(struct Race race){

	race.firstPlaceDriveName = "Bob";
	race.firstPlaceRaceCarColor = "yellow";

	race.currentLap = 0;

	race.numberOfLaps = 6;

	printf("After lap number %d\n First Place is: %s in the %s race car",race.currentLap, race.firstPlaceDriveName, race.firstPlaceRaceCarColor);
	

}

int main(int argc, char const *argv[])
{
	printIntro();
	printCountDown();


	return 0;
}

