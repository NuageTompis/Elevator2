#include<stdio.h>
#include<stdlib.h>
#include <ncurses.h>
#include"elevator.h"
#include<ncurses.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator *elevator = malloc(sizeof(Elevator));
    elevator->capacity = capacity;
    elevator->currentFloor = currentFloor;
    elevator->persons = persons;
    return elevator;
}
Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building *building = malloc(sizeof(Building));
    building->elevator = elevator;
    building->nbFloor = nbFloor;
    building->waitingLists = waitingLists;
    return building;
}
void stepElevator(Building *b){
    if(b->elevator->targetFloor == b->elevator->currentFloor){
        PersonList* leavers = malloc(sizeof(PersonList));
        leavers = exitElevator(b->elevator);
        PersonList* newWaiters = malloc(sizeof(PersonList));
        b->waitingLists[b->elevator->currentFloor] = enterElevator(b->elevator, b->waitingLists[b->elevator->currentFloor]);
    }
    else{
        if(b->elevator->targetFloor < b->elevator->currentFloor){
            b->elevator->currentFloor--;
        }
        else{
            b->elevator->currentFloor++;
        }
    }
}

PersonList* exitElevator(Elevator *e){
    PersonList* leavers = NULL;
    
    PersonList* newPersons = NULL;
    PersonList* list = malloc(sizeof(PersonList));
    list = e->persons;
    
    while(list != NULL){
        if(list->person->dest == e->currentFloor){
            leavers = insert(list->person, list);
        }
        else{
            newPersons = insert(list->person, newPersons);
        }
        list = list->next;
    }
    
    e->persons = newPersons;
    
    return leavers;
}

PersonList* enterElevator(Elevator *e, PersonList *waitingList){
    PersonList* newWaiters = NULL;
    int nbPersons = 5;
    int nbFloor = 5;
    // We take the first persons in the waiting list and put them in the elevator, then for the others we put them in the new waiting list
    PersonList* cursor = malloc(sizeof(PersonList));
    cursor = e->persons;
    int i = 0;
    while(cursor != NULL){
        i = i+1;
        cursor = cursor->next;
    }
    for(int k = 0; k<(e->capacity - i); i++){
        e->persons = insert(waitingList->person, e->persons);
        waitingList = waitingList->next;
    }
    
    while(waitingList != NULL){
        newWaiters = insert(waitingList->person, newWaiters);
        waitingList = waitingList->next;
    }

    cursor = newWaiters;
    int j = 0;
    while(cursor != NULL){
        j = j+1;
        cursor = cursor->next;
    }
    for(int k=0; k<(nbPersons-j); k++){
        int dest = rand() % (nbFloor);
        Person *p = createPerson(e->currentFloor, dest);
        newWaiters = insert(p,newWaiters);
    }
    
    // I have to reverse my lists each time I use this function because of the way I created them
    newWaiters = Reverse(newWaiters); 
    e->persons = Reverse(e->persons);
    return newWaiters;
}