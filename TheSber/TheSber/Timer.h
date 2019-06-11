#ifndef Timer_H
#define Timer_H

void setCurentTime(time_t *currentTime);
void printCurrentDay(time_t *currentSimulateTime, int day);

void simulation(time_t *startSimulation, time_t *currentSimulateTime, int simulateDuration);

#endif