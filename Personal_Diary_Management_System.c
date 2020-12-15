#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define SIZE 1000

int  password();
void addReview();
void searchMovie();
void editpassword();
void deleteReview();
// void movieRank();
void swap();

struct reviewMovie              //menggunakan modul struct
{
    char title[50];
    char year[5];
    char genre[50];
    char rate[5];
    char synopsis[500];
    char review[1000];
    char casts[100];
};

int i;

int main()
{
    int ch,d; 
    printf("                              _.-.  \n");
    printf("                         /  99\\n");
    printf("                        (      `\\n");
    printf("                        |\\ ,  ,|\n");
    printf("                __      | \\____/\n");
    printf("          ,.--`-..   /   `---'\n");
    printf("      _.-'          '-/      |\n");
    printf("  _.-   |   '-.             |_/_\n");
    printf(",__.-'  _,.--\\      \\      ((    /-\\n");
    printf("',_..--'      `\\     \\      \\_ /\n");
    printf("            `-,   )      |\' \n");
    printf("              |   |-.,, (  \n");
    printf("              |   |   `\\   `',_\n");
    printf("              )    \\    \\,(\\(\\-'\n");
    printf("              \\     `-,_\n");
    printf("               \\_(\\-(\\`-`\n");
    printf("                  "  "\n");

    
    printf("                    o \n");
    printf("       o       / \n");
    printf("       \\     / \n");
    printf("        \\   / \n");
    printf("         \\ / \n");
    printf("+--------------v-------------+ \n");
    printf("|  __________________      @ | \n");
    printf("| /                  \\       | \n");
    printf("| |                  |  (\\)  | \n");
    printf("| |                  |       | \n");
    printf("| |                  |  (-)  | \n");
    printf("| |                  |       | \n");
    printf("| \\                   / :|||: | \n");
    printf("|  -ooo--------------  :|||: | \n");
    printf("+----------------------------+ \n");
    printf("   []                    [] \n");


    printf("\n\n\t***********************************\n");
    printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");
    printf("\t***********************************");
    
    while(1)
    {
        printf("\n\n\t\tMAIN MENU:");
        printf("\n\n[1]\tAdd Review");
        printf("\n[2]\tSearch Movie");
        printf("\n[3]\tMovie Ranking");
        printf("\n[4]\tDelete Review");
        printf("\n[5]\tExit");
        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d",&ch);
        
        switch(ch)
        {
        case 1:
            addReview();
            break;
        case 2:
            searchMovie();
            break;
        case 3:
           // movieRank();
            break;
        case 4:
            deleteReview();
            break;
        case 5:
            printf("\n\n\t\tTHANK YOU FOR USING THIS PROGRAM ");
            getch();
            exit(0);

        default:
            printf("\nYOU ENTERED WRONG CHOICE..");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            break;
        }

        system("cls");
    }

    return 0;
}

void addReview()
{ 
    system("cls");
    FILE *fp ;  //menggunakan modul pointer

    char another = 'Y' ,title[50];
    struct reviewMovie e ;
    char filename[30];
    int choice;

    printf("\n\n\t\t***************************\n");
    printf("\t\t* WELCOME TO THE REVIEW MENU! *");
    printf("\n\t\t***************************\n\n");

    printf("\n\n\tEnter The Movie's Name >> ");
    gets(filename);

    fflush(stdin);
    
    sprintf(filename, "%s.txt");

    fp = fopen (filename , "a+" ) ;

    if ( fp == NULL )
    {
        fp=fopen(filename,"w+");
        if(fp==NULL)
        {
            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;
        }
    }

        choice=0;
        fflush(stdin);
        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.title,title)==0)
            {
                printf("\n\tThe Review Already Exists.\n");
                choice=1;
            }
        }

        if(choice==0)
        {
            strcpy(e.title,title);

            fflush(stdin);
            printf("\tYears:");
            gets(e.year);

            fflush(stdin);
            printf("\tGenre:");
            gets(e.genre);

            fflush(stdin);
            printf("\tCasts:");
            gets(e.casts);

            fflush(stdin);
            printf("\tRating:");
            gets(e.rate);

            fflush(stdin);
            printf("\tSynopsis:");
            gets(e.synopsis);

            fflush(stdin);
            printf("\tReview:");
            gets(e.review);

            fwrite ( &e, sizeof ( e ), 1, fp ) ;
            printf("\nYOUR RECORD IS ADDED...\n");

        }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}

void searchMovie()
{
    FILE *fpte ;

    system("cls");

    struct reviewMovie movie ;
    char time[6],choice,filename[30];
    int ch;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t* HERE IS THE VIEWING MENU *");
    printf("\n\t\t*******************************\n\n");

    choice=password();

    if(choice!=0)
    {
        return ;
    }

    do
    {
        printf("\n\tEnter the name of the Movie >> ");

        fflush(stdin);
        gets(filename);

        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )
        {
            puts ( "\nSorry, no results found\n" ) ;
            printf("Press any key to back...");
            getch();
            return ;
        }

        printf("\n!! %s Review !!",filename);

        while ( fread ( &movie, sizeof ( movie ), 1, fpte ) == 1 )
        {
            printf("\n");
            printf("\nYears: %s",movie.year);
            printf("\nGenre: %s",movie.genre);
            printf("\nCasts: %s",movie.casts);
            printf("\nRating: %s",movie.rate);
            printf("\nSynopsis: %s",movie.synopsis);
            printf("\nReview: %s", movie.review);
            printf("\n");
        }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);
        scanf("%c",&choice);
    }

    while(choice=='Y'||choice=='y');
    fclose ( fpte ) ;

    return ;
}

int password()
{

    char pass[15]= {0},check[15]= {0},ch;

    FILE *fpp;

    int i=0,j;

    printf("::FOR SECURITY PURPOSE::");
    printf("::ONLY THREE TRIALS ARE ALLOWED::");

    for(j=0; j<3; j++)
    {
        i=0;
        printf("\n\n\tENTER THE PASSWORD:");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }

        pass[i]='\0';

        fpp=fopen("SE","r");

        if (fpp==NULL)
        {
            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");
            getch();
            return 1;
        }

        else
            i=0;
            
        while(1)
        {
            ch=fgetc(fpp);

            if(ch==EOF)
            {
                check[i]='\0';
                break;
            }

            check[i]=ch-5;
            i++;
        }

        if(strcmp(pass,check)==0)
        {
            printf("\n\n\tACCESS GRANTED...\n");
            return 0;
        }

        else
        {
            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
        }
    }

    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");

    getch();

    return 1;
}

void editpassword()
{

    system("cls");
    printf("\n");

    char pass[15]= {0},confirm[15]= {0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("SE","rb");

    if(fp==NULL)
    {
        fp=fopen("SE","wb");

        if(fp==NULL)
        {
            printf("SYSTEM ERROR...");
            getch();
            return ;
        }

        fclose(fp);

        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }

    fclose(fp);

    check=password();

    if(check==1)
    {
        return ;
    }

    do
    {
        if(check==0)
        {
            i=0;
            choice=0;

            printf("\n\n\tENTER THE NEW PASSWORD:");

            fflush(stdin);
            pass[0]=getch();

            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;

                    printf("\b");
                    printf(" ");
                    printf("\b");

                    pass[i]=getch();
                }

                else
                {

                    printf("*");
                    i++;
                    pass[i]=getch();
                }
            }

            pass[i]='\0';
            i=0;

            printf("\n\tCONFIRM PASSWORD:");
            confirm[0]=getch();
            
            while(confirm[i]!='\r')
            {
                if(confirm[i]=='\b')
                {
                    i--;

                    printf("\b");
                    printf(" ");
                    printf("\b");

                    confirm[i]=getch();
                }

                else
                {
                    printf("*");
                    i++;
                    confirm[i]=getch();
                }
            }
            confirm[i]='\0';
            if(strcmp(pass,confirm)==0)
            {
                fp=fopen("SE","wb");
                if(fp==NULL)
                {
                    printf("\n\t\tSYSTEM ERROR");
                    getch();
                    return ;
                }
                i=0;
                while(pass[i]!='\0')
                {
                    ch=pass[i];
                    putc(ch+5,fp);
                    i++;
                }
                putc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                choice=1;
            }
        }
    }
    while(choice==1);
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
}

void deleteReview()
{
    system("cls");
    FILE *fp,*fptr ;
    struct reviewMovie file ;
    char filename[30],another = 'Y' ,time[10];;
    int choice,check;
    printf("\n\n\t\t*************************\n");
    printf("\t\t* WELCOME TO DELETE MENU*");
    printf("\n\t\t*************************\n\n");
    check = password();
    if(check==1)
    {
        return ;
    }
    while ( another == 'Y' )
    {
            printf("\n\tENTER THE MOVIE TO DELETE THE REVIEW : ");
            fflush(stdin);
                gets(filename);
                fp = fopen (filename, "wb" ) ;
                if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXISTS");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
                }
                fclose(fp);
                remove(filename);
                printf("\nDELETED SUCCESFULLY...");
                break;
                

        while(choice<1||choice>2);
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);
    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}

// void movieRank(){
//     int j, swap;

//     for(i=0; i< SIZE; i++){
//         for(j=0; j<SIZE-i-1; j++){
//             if(rate[j]>rate[j+1]){
//                 swap = rate[j];
//                 rate[j] = rate[j+1];
//                 rate[j+1] = swap;
//             }
//         }
//     }

//     printf("Sorted movie by rating");
//     for(i=0; i<SIZE; i++){
//         printf("%d. %s (%s)", i+1, e.title, e.rate);
//     }
// }




