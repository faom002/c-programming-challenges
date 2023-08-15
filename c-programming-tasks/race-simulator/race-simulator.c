#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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

void printIntro(void) {
    printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown(void) {
    for (int i = 5; i >= 0; --i) {
        printf("Racers Ready! in.. ");
        sleep(1);
        printf("%d\n", i);
        sleep(1);

        if (i <= 0) {
            printf("Race!!!\n");
        }
    }
}

void printCongratulation(struct Race* race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance. It truly was a great race and everybody have a good night!\n",
           race->firstPlaceDriveName, race->firstPlaceRaceCarColor);
}

int calculateTimeToCompleteLap(void) {
    int speed = rand() % 3 + 1;
    int acceleration = rand() % 3 + 1;
    int nerves = rand() % 3 + 1;

    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
    int lapTime = calculateTimeToCompleteLap();
    raceCar->totalLapTime += lapTime;
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        race->firstPlaceDriveName = raceCar1->driverName;
        race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    } else {
        race->firstPlaceDriveName = raceCar2->driverName;
        race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    }
}

void startRace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    for (int lap = 1; lap <= race->numberOfLaps; ++lap) {
        printf("Lap %d:\n", lap);

        // Simulate lap time calculation for both race cars
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);

        // Update first place based on the current lap times
        updateFirstPlace(race, raceCar1, raceCar2);

        printf("First Place: %s in the %s race car\n",
               race->firstPlaceDriveName, race->firstPlaceRaceCarColor);

        printf("\n");
    }

    printCongratulation(race);
}



int main(int argc, char const* argv[]) {
    srand(time(NULL)); // Seed the random number generator

    printIntro();
    printCountDown();

    struct Race race;
    struct RaceCar car1 = {"Bob", "Yellow", 0};
    struct RaceCar car2 = {"Alice", "Blue", 0};

    race.numberOfLaps = 6;

    startRace(&race, &car1, &car2);

    return 0;
}
