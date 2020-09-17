#include "structures.h";
extern cln c1,c2;
cln c3;


void vld(){
    char c;
    printf("\n\n>> 1. In");
    printf("\n>> 2. Out");
    printf("\n>> 3. Extend membership");
    printf("\n>> 4. Account Records");
    printf("\n>> 5. Delete Account");
    printf("\n>> 6. Back to Menu\n");
    printf("\nVotre Choix : "); c = getche();
    switch(c){
    case '1' : strcpy(c2.s,"In");rec();break;
    case '2' : strcpy(c2.s,"Out");rec();break;
    case '3' : updat();break;
    case '4' : accrec();break;
    case '5' : delet();
                break;
    default : accmenu();break;
   }
   accmenu();
}

void rec(){
    FILE *vptr;
    vptr = fopen("REC.DAT","ab");
    if(vptr == NULL)
        { printf("Connot open file");
            exit(1);}

        timer();
        fwrite(&c2,sizeof(c2),1,vptr);
        fclose(vptr);
        accmenu();
}

void updat(){
    system("cls");
    c3 = c2;
    printf("\n\t%s %s : extend membership",c3.pnom,c3.nom);
    printf("\n Expiration date: day/month/year : ");scanf("%d/%d/%d",&c3.tof.j,&c3.tof.m,&c3.tof.a);
    FILE *fptr;
    fptr = fopen("CLN.DAT","rb+");
     while(fread(&c2,sizeof(c2),1,fptr)==1)
            { if (c2.id == c3.id) {
            fseek(fptr,-sizeof(c2),SEEK_CUR);
            fwrite(&c3,sizeof(c3),1,fptr);fclose(fptr);
            }}
    system("cls");
    printf("\n\t%s %s's account updated! ",c3.pnom,c3.nom);getch();accmenu();
}

void accrec(){
    int id = c2.id;

    FILE *vptr;
    vptr = fopen("REC.DAT","rb");
    if(vptr == NULL)
        { printf("There is no Records ");getch();
            exit(1);}
            system("cls");
            printf("%s %s : Records",c2.pnom,c2.nom);
            while(fread(&c2,sizeof(c2),1,vptr)==1){
                if (c2.id == id){
                printf("\n%s %s : %s : %d-%d-%d %d:%d:%d",c2.nom,c2.pnom,c2.s,c2.tm.tm_year +1900, c2.tm.tm_mon + 1, c2.tm.tm_mday, c2.tm.tm_hour, c2.tm.tm_min, c2.tm.tm_sec);
            }
            }
        fclose(vptr);
        getch();
        accmenu();

}


void timer(){
    time_t t = time(NULL);
    c2.tm = *localtime(&t);
}

void delet(){
    FILE *fp;
    fp = fopen("CLN.DAT", "rb+");

                FILE *ft;
                ft = fopen("Temp.dat","wb");
                while(fread(&c3,sizeof(c3),1,fp) == 1)
                {
                    if(c3.id != c2.id )
                    {
                        fwrite(&c3,sizeof(c3),1,ft);
                    }
                }

                fclose(fp);
                fclose(ft);
                remove("CLN.DAT");
                rename("Temp.dat","CLN.DAT");
                system("cls");printf("\n%s %s's account has been deleted!",c2.pnom,c2.nom);
                getch();
}
