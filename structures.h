#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

typedef struct date {
    short int j;
    short int m;
    short int a;
}dt;


typedef struct clients {
    char nom[15]; // last name
    char pnom[15];// first name
    char CIN[10];
    char email[30];
    int id;
    long int phone;
    char s[3];
    struct tm tm;
    dt tof;
}cln;


