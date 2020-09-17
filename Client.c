#include "structures.h";
cln c1,c2;


void accmenu(){
    system("cls");
    char c;
    printf("\n\t\t * Fitness club Reda *\n\n");
    printf("\n>> 1. New Member");
    printf("\n>> 2. Existing Member");
    printf("\n>> 3. All members");
    printf("\n\nYour choice : "); c = getche();

    switch(c){
    case '1' : accnew();system("cls");printf("\nYour account has been created!");getch();break;
    case '2' : acc();break;
    case '3' : all();break;
    default : accmenu();break;
   }
    accmenu();
}

void accnew(){
    int c;
    system("cls");
    printf("\n>> Last Name :");fflush(stdin);fgets(c1.nom,15,stdin);c1.nom[strcspn(c1.nom,"\n")]=0;
    printf("\n>> First Name :");fflush(stdin);fgets(c1.pnom,15,stdin);c1.pnom[strcspn(c1.pnom,"\n")]=0;
    printf("\n>> CIN :");fflush(stdin);fgets(c1.CIN,10,stdin);c1.CIN[strcspn(c1.CIN,"\n")]=0;
    printf("\n>> Email :");fflush(stdin);fgets(c1.email,30,stdin);c1.email[strcspn(c1.email,"\n")]=0;
    printf("\n>> Phone : ");scanf("%ld",&c1.phone);
    printf("\n Expiration date: day/month/year : ");scanf("%d/%d/%d",&c1.tof.j,&c1.tof.m,&c1.tof.a);
    check();



}

void check() {
    static int i=1;
    int c;
    char x;
    FILE *fptr;
    fptr = fopen("CLN.DAT","rb+");
if(fptr == NULL)
{
        fptr = fopen("CLN.DAT","wb+");
        if(fptr == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    while(fread(&c2,sizeof(c2),1,fptr)==1)
            {

        c = strcmp(c1.CIN, c2.CIN); if (c == 0){system("cls");printf("\n Your CIN is already connected to another account!\n");break;}
        c = strcmp(c1.email, c2.email); if (c == 0){system("cls");printf("\n Your Email is already connected to another account!\n");break;}
        if (c1.phone == c2.phone){system("cls");c=0; printf("\n Your Phone number is already connected to another account!\n");break;}
            }

    if (c == 0) {printf("Try again ? (y/n)");fclose(fptr);c=1;fflush(stdin);x = getche();
    switch (x){
    case 'y':accnew();
    case 'n':accmenu();
    default : check();}}

    rewind(fptr);
    fseek(fptr,0,SEEK_END);
    c1.id = c2.id + 1;
    fwrite(&c1,sizeof(c1),1,fptr);
    fclose(fptr);


}

void acc(){
    system("cls");
    int ID,x=0;
    FILE *fptr;

    fptr = fopen("CLN.DAT","rb+");
    if(fptr == NULL){
        fptr = fopen("CLN.DAT","wb+");
        if(fptr == NULL){
            printf("Connot open file");
            exit(1);}}

    printf("Client ID : ");scanf("%d",&ID);
    while(fread(&c2,sizeof(c2),1,fptr)==1)
            {
        if (c2.id == ID){fclose(fptr);system("cls");x=1;printing(0);getch();vld();}}
        if (x==0) {fclose(fptr);printf("\nThere is no account with this ID\n");getch();accmenu();}

}

void all(){
char c;
int i =0;
FILE *fptr;

    fptr = fopen("CLN.DAT","rb+");
    if(fptr == NULL){
        fptr = fopen("CLN.DAT","wb+");
        if(fptr == NULL){
            printf("Connot open file");
                exit(1);}}


            system("cls");
            while(fread(&c2,sizeof(c2),1,fptr)==1)
            {  printing(i);i++; }
                fclose(fptr);
                if (i==0){printf("There is no members yet!");}
                i=0;
                getch();accmenu();


}
