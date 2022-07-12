#include<stdio.h>
#include<stdlib.h>
#include"person.h"
#include<ncurses.h>

Person* createPerson(int src, int dest){
    Person *person = malloc(sizeof(Person));
    person->src = src;
    person->dest = dest;
    return person;
}

PersonList* insert(Person *p, PersonList *list){
    PersonList* newList = (PersonList*)malloc(sizeof(PersonList));
    newList->person = p;
    newList->next = list;
    return newList;
}

// I stole this code
PersonList* Reverse(PersonList* list){
    PersonList* prev = NULL;
    PersonList* current = list;
    PersonList* next;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
    return list;
}