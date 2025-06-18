#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define TLC 218
#define TRC 191
#define BLC 192
#define BRC 217
#define HL 196
#define VL 179
#define PLUS 197
#define TT 194
#define BT 193
#define RT 180
#define LT 195
#define SPACE 32

#define MAX_COL 150
#define MAX_ROW 30

#define WIDTH 5
#define DIM 7

#define BS 8
#define BEEP 7

void gotoxy(int col,int row)
{
    COORD coord;
    coord.X=col;
    coord.Y=row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int DayOfWeek( int y, int m, int d ) /* returns Day of Week:
0 = Sunday, 1= Monday...
*/
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
} /*--DayOfWeek( )--------*/

int isLeap(int year)
{
    return ( (year%4==0 && year%100!=0) || (year%400==0) ) ? 1 : 0;
}

void printCalendar(int month,int year)
{
    system("cls");
    drawTable();
    tableHeads();
    int row;
    int col;
    int ctr;
    int day;
    col = (MAX_COL - ((DIM*WIDTH) + (DIM+1)) ) / 2;
    row = (MAX_ROW - ((DIM+1)+DIM) ) / 2;
    char *months_name[]={"0","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    gotoxy(col,row-1);
    printf("%d",year);
    gotoxy(col+20,row-1);
    printf("%s",months_name[month]);
    row+=3;
    col+=3;
    int no_of_days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    no_of_days[2]=isLeap(year) ? 29 : 28;
    for(ctr=1,day=DayOfWeek(year,month,1);ctr<=no_of_days[month];ctr+=1,day+=1)
    {
        if(day==7)
        {
            day=0;
            row+=2;
        }
        gotoxy(col+(day*(WIDTH+1)),row);
        printf("%02d",ctr);
    }
    gotoxy(0,23);
    printf("Use Top and Bottom ARROW to change Years..\nUse Right and Left ARROW to change Months..\nPress any other key to exit...\n");
    return;

}

void tableHeads()
{
    int row;
    int col;
    char *days[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

    col = (MAX_COL - ((DIM*WIDTH) + (DIM+1)) ) / 2;
    row = (MAX_ROW - ((DIM+1)+DIM) ) / 2;

    row+=1;
    col+=2;

    int ctr;
    for(ctr=0;ctr<DIM;ctr+=1)
    {
        gotoxy(col+(ctr*(WIDTH+1)),row);
        printf("%s",days[ctr]);
    }

}


void drawTable()
{
    int row;
    int col;
    int ctr1;
    int ctr2;
    int ctr3;

    col = (MAX_COL - ((DIM*WIDTH) + (DIM+1)) ) / 2;
    row = (MAX_ROW - ((DIM+1)+DIM) ) / 2;

    gotoxy(col,row);
    printf("%c",TLC);

    for(ctr2=0;ctr2<DIM;ctr2+=1)
    {
        for(ctr1=0;ctr1<WIDTH;ctr1+=1)
        {
            printf("%c",HL);
        }
        printf("%c",TT);
    }
    printf("%c%c%c",BS,TRC,BEEP);

    for(ctr3=0;ctr3<DIM-1;ctr3+=1)
    {
        row+=1;
        gotoxy(col,row);
        for(ctr2=0;ctr2<=DIM;ctr2+=1)
        {
            printf("%c",VL);
            for(ctr1=0;ctr1<WIDTH;ctr1+=1)
            {
                printf("%c",SPACE);
            }
        }
        row+=1;
        gotoxy(col,row);

        printf("%c",LT);
        for(ctr2=0;ctr2<DIM;ctr2+=1)
        {
            for(ctr1=0;ctr1<WIDTH;ctr1+=1)
            {
                printf("%c",HL);
            }
            printf("%c",PLUS);
        }
        printf("%c%c%c",BS,RT,BEEP);

    }

    row+=1;
    gotoxy(col,row);
    for(ctr2=0;ctr2<=DIM;ctr2+=1)
    {
        printf("%c",VL);
        for(ctr1=0;ctr1<WIDTH;ctr1+=1)
        {
            printf("%c",SPACE);
        }
    }

    row+=1;
    gotoxy(col,row);
    printf("%c",BLC);
    for(ctr2=0;ctr2<DIM;ctr2+=1)
    {
        for(ctr1=0;ctr1<WIDTH;ctr1+=1)
        {
            printf("%c",HL);
        }
        printf("%c",BT);
    }
    printf("%c%c%c",BS,BRC,BEEP);

}


int main()
{
    int month=1;
    int year=2025;
    int key;
    int ch;
    //printf("Enter month and year number to see the calendar: \n");
    //scanf("%d",&month);
    //scanf("%d",&year);
    drawTable();
    tableHeads();
    printCalendar(month,year);
    ch=_getch();
    while(ch==0 || ch==224)
    {
        key=_getch();
        //system("cls");
        //drawTable();
        //tableHeads();
        switch(key)
        {
            case 72:
                year+=1;
                printCalendar(month,year);
                break;
            case 80:
                year-=1;
                printCalendar(month,year);
                break;
            case 77:
                if(month==12){
                    month=1;
                    year+=1;
                }
                else{
                month+=1;}
                printCalendar(month,year);
                break;
            case 75:
                if(month==1){
                    month=12;
                    year-=1;
                }
                else{
                month-=1;}
                printCalendar(month,year);
                break;
            default:
                printf("Exiting!!!");
                return EXIT_SUCCESS;
        }
        ch=_getch();
    }


}
