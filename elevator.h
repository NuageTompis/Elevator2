#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "person.h"

typedef struct _Elevator {
    int capacity;    // capacité maximale de la cabine
    int currentFloor;// étage courant
    int targetFloor; // destination
    PersonList *persons; // personnes dans la cabine
} Elevator;

typedef struct _Building {
    int nbFloor; // nombre d’étage des l’immeuble
    Elevator *elevator; // la cabine d’ascenseur
    PersonList **waitingLists; // array of waiting list (one per floor)
} Building;
#endif

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons);
Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists);

PersonList* exitElevator(Elevator *e);
PersonList* enterElevator(Elevator *e, PersonList *waitingList);
void stepElevator(Building *b);


void DisplayPersonList(WINDOW *win, PersonList *list, int level, int offset);
void DisplayElevator(WINDOW *win, int nbFloor, Elevator *e, int offset);
void DisplayBuilding(WINDOW *win, Building *b);