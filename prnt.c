#include "structures.h"
extern cln c1,c2;


char seg[16]="---------------";
char seg2[26]="-------------------------";
char seg3[36]="-----------------------------------";

void printing(int j){
    if (j==0){
    printf("%3s|%15s|%15s|%25s|%15s|%15s|%15s|%15s|\n","---",seg,seg,seg2,seg,seg,seg,seg);
    printf("%3s|%15s|%15s|%25s|%15s|%15s|%15s|%15s|\n","  ","First Name","Last Nom","Email","Num","CIN","valid until"," ID");
    printf("%3s|%15s|%15s|%25s|%15s|%15s|%15s|%15s|\n","---",seg,seg,seg2,seg,seg,seg,seg);}
    printf("%3s|%15s|%15s|%25s|%15ld|%15s|  %2d/%2d/%4d   |%15ld|\n","  ",c2.pnom,c2.nom,c2.email,c2.phone,c2.CIN,c2.tof.j,c2.tof.m,c2.tof.a,c2.id);
    printf("%3s|%15s|%15s|%25s|%15s|%15s|%15s|%15s|\n","---",seg,seg,seg2,seg,seg,seg,seg);

}

