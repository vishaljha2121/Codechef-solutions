//
//  main.c
//  chef of the year
//
//  Created by Vishal Jha on 04/11/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct country{
    char name[10];
    int vot;
    struct country *next;
};

struct chef{
    char name[10];
    int vot;
    struct country * country;
    struct chef * next;
};

struct country * createCountry(char *);
struct chef * createChef(char *, struct country *);
struct chef * insertChef(struct chef *, struct chef *);
struct country * insertCountry(struct country *, struct country *);
struct country * searchCountry(struct country *, char *);
struct chef * searchChef(struct chef *, char *);
void printCountries(struct country *);
void printChefs(struct chef *);
void printCountry(struct country *);
void printChef(struct chef *);
void freeCountries(struct country *);
void freeChefs(struct chef *);

struct country * createCountry(char * countryName){
    struct country *ptr;
    int i =0;
    ptr = (struct country *)malloc(sizeof(struct country));
    ptr->name[0] = countryName[0];
    i++;
    while(countryName[i] != '\0'){
        ptr->name[i] = countryName[i];
        i++;
    }
    ptr->next = NULL;
    return ptr;
}

struct chef * createChef(char * chefName, struct country * countryptr){
    struct chef *ptr;
    int i =0;
    ptr = (struct chef *)malloc(sizeof(struct chef));
    ptr->name[0] = chefName[0];
    i++;
    while(chefName[i] != '\0'){
        ptr->name[i] = chefName[i];
        i++;
    }
    ptr->country = countryptr;
    ptr->next = NULL;
    return ptr;
}

void printCountries(struct country * start){
    struct country * ptr = start;
    while(ptr!=NULL){
        printf("%s %d\n",ptr->name, ptr->vot);
        ptr = ptr->next;
    }
}

void printChefs(struct chef * start){
    struct chef * ptr = start;
    while(ptr!=NULL){
        printf("%s %s %d",ptr->name,ptr->country->name,ptr->vot);
        ptr = ptr->next;
    }
}

void printCountry(struct country * start){
    struct country * ptr = start;
    struct country * win;
    int maxVot = 0;
    while(ptr!=NULL){
        if(ptr->vot > maxVot){
            maxVot = ptr->vot;
            win = ptr;
        }
        ptr = ptr->next;
    }
    printf("%s\n",win->name);
}

void printChef(struct chef * start){
    struct chef * ptr = start;
    struct chef * win;
    int maxVot = 0;
    while(ptr!=NULL){
        if(ptr->vot >maxVot){
            maxVot = ptr->vot;
            win = ptr;
        }
        ptr = ptr->next;
    }
    printf("%s\n",win->name);
}

void freeCountries(struct country * start) {
    struct country * ptr = start;
    struct country * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

void freeChefs(struct chef * start) {
    struct chef * ptr = start;
    struct chef * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct country * insertAtFrontCountry(struct country * start, struct country * newptr) {
    newptr->next = start;
    return(newptr);
}

struct chef * insertAtFrontChef(struct chef * start, struct chef * newptr) {
    newptr->next = start;
    return(newptr);
}

struct chef * insertChef(struct chef *start, struct chef *newChef){
    struct chef *ptr = start;
    struct chef *prev = NULL;
    while((ptr!=NULL)&&(strcmp(ptr->name, newChef->name) < 0)){
        prev = ptr;
        ptr = ptr->next;
    }
    if(prev == NULL){
        start = insertAtFrontChef(start, newChef);
    }else{
        prev->next = newChef;
        newChef->next = ptr;
    }
    return start;
}

struct country * insertCountry(struct country * start, struct country *newCountry){
    struct country *ptr = start;
    struct country *prev = NULL;
    while ((ptr!=NULL)&&(strcmp(ptr->name, newCountry->name) < 0)){
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev==NULL){
        start = insertAtFrontCountry(start, newCountry);
    }else {
        prev->next = newCountry;
        newCountry->next = ptr;
    }
    return (start);
}

struct country * searchCountry(struct country * start, char * countryName) {
    struct country * ptr = start;
    int rez = strcmp(ptr->name, countryName);
    while ((ptr->next!=NULL) && (rez < 0)) {
        ptr = ptr->next;
        rez = strcmp(ptr->name, countryName);
    }
    if (rez != 0) ptr = NULL;
    return(ptr);
}

struct chef * searchChef(struct chef * start, char * chefName) {
    struct chef * ptr = start;
    int rez = strcmp(ptr->name, chefName);
    while ((ptr->next!=NULL) && (rez < 0)) {
        ptr = ptr->next;
        rez = strcmp(ptr->name, chefName);
    }
    if (rez != 0) ptr = NULL;
    return(ptr);
}




int main(int argc, const char * argv[]) {

    int n, m, i;
    struct country * countryNode, * countryStart;
    struct chef * chefNode, * chefStart;
    char chefName[11], countryName[11];
    
    scanf("%d %d", &n, &m);
    scanf("%s %s", chefName, countryName);
    countryStart = createCountry(countryName);
    chefStart = createChef(chefName, countryStart);
    for (i = 1; i < n; i++){
        scanf("%s %s", chefName, countryName);
        countryNode = searchCountry(countryStart, countryName);
        if (countryNode == NULL) {
            countryNode = createCountry(countryName);
            countryStart = insertCountry(countryStart, countryNode);
        }
        chefNode = createChef(chefName, countryNode);
        chefStart = insertChef(chefStart, chefNode);
    }
    
    for (i = 0; i < m; i++)
    {
        scanf("%s", chefName);
        chefNode = searchChef(chefStart, chefName);
        if (chefNode != NULL) {
            chefNode->vot++;
            chefNode->country->vot++;
        }
    }
    
    printCountry(countryStart);
    printChef(chefStart);
    
    //freeChefs(chefStart);
    //freeCountries(countryStart);
    
    
    return 0;
}
