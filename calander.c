/*
   CALANDER PROGRAM IN C
                                             -garuda
    writter -AKULA GURU DATTA     
                                     
    options included:
            1.years having same day and date
            2.year calendar
            3.month calendar
            4.to know the day of the date
  */                                           


#include<stdio.h>

//###title box function

void title()
{	
     printf
          ("\n------------------------------------------------------------\n"
 	   "\t\t*****CALENDAR IN \"C\"*****\n"
 	   "\t\t\t-GARUDA\n"
 	   "•••••••••••••••••••••••••••••••••••••••••••••••••••gurudatta"
 	   "\n------------------------------------------------------------\n\n");
}	



//###to find the day of the date

int day ( int date ,int month ,int year)
{
    int prime,century,year_digits,year_code,century_code,day_code;
	
    /*every month have specified codes
    "JANUARY-1","FEBRUVARY-4"," MARCH -4"," APRIL-0 ","MAY-2","JUNE -5"
    "JULY-0","AUGUEST-3","SEPTEMBER-6","OCTOBER-1","NOVEMBER-4","DECEMBER-6"*/
            
    int month_code[12] = {1,4,4,0,2,5,0,3,6,1,4,6};//monthcodes in a array
    
    century = year/100;          //century of the year(e.g:-for 1999 it is 19)
    year_digits = year%100;      //last two digits of the year(e.g:- for 1999 it is 99)
	
    year_code=(( year_digits/4 ) + year_digits )%7;    //year code formula
	
    //century_codes for each century
    if ( century==17 ){ century_code=4; }
    else if ( century==18 ){ century_code=2; }
    else if ( century==19 ){ century_code=0; }
    else if ( century==20 ){ century_code=6; }
    else if ( century==21 ){ century_code=4; }
    else if ( century==22 ){ century_code=2; }
    else if ( century==23 ){ century_code=0; }

    //finding either the month in year is effected by prime or not
    if ( year_digits%4==0 )
    {
     	  if ( month==1 ||	month==2 )
     	       {  prime=1;  }
	        else {  prime=0;  }
    }
    else
    {  prime=0;  }
    
     // formula for day_code
      day_code = ( date + month_code[month-1] + year_code + century_code - prime - 1)%7;
    
    return day_code;
}



// ###to generate a month calander

void month (int day_code,int month,int year)
{
    int i;
    int year_digits = year%100;   //last two digits of the year(e.g:- for 1999 it is 99)
	
    //month list
    char *mon[12] = {"JANUARY","FEBRUVARY","  MARCH  ","  APRIL  ","   MAY   ","   JUNE   ","   JULY  "
                          ,"AUGUEST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};  
	 
    //no of days a month have
    int total_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
     
    printf ( "\n\n\t\t\t**%s**\n\n", mon[month-1] );//to print month name
    
    printf ("   su\t  mo\t  tu\t  we\t  th\t  fr\t  sa\t\n\n ");// to print days of month
    
    //to fill spaces before the starting date 1
    for ( i=1; i<=day_code; i++)
    {
     printf("  \t   ");
    }
     
    //to print dates of a month
    for ( i=1; i<=total_days[month-1]; i++)
    {
    	if ( i<10 )
        {  printf ( "0%d\t  ", i ); }
        else
		{ printf ( "%d\t  ", i ); }//to print the date
		
		if ( (i+day_code) %7 == 0)
		     {   printf ("\n\n   ");  }         //to print the new line
    }
    
    
     if ( year_digits%4==0 && month==2 )
         {  printf("29");  }           //to print the 29 in leap year
         printf("\n\n");
	
}

//###years having same day and date

void same_year(int a,int b,int r)
{
    int p,k,x,y;
    title();
    r=r-1;
    
    int m[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    
     char *mon[12]={"JANUARY","FEBRUVARY","  MARCH  ","  APRIL  ","   MAY   ","   JUNE   ",
      "   JULY   ","AUGUEST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
      
     char *da[7]={"sun","mon","tues","wednes","thurs","fri","satur"};
     
    int t=m[b-1];
     int d=0;
     int c=6;
     
     for  (p=1;d<100;p++){
            x=r+7*p-a-t-c+1;
     
     for (k=1;d<100;k++){
	    	for (y=0;y<4;y++){
   
       if ((28*k+4*x+y)%5==0){
              d=(28*k+4*x+y)/5;
	      
	      		if (d<10&&d>0)
	      	{printf("%d-%s-200%d is %sday\n",a,mon[b-1],d,da[r]);}	
           
             
                 if (d>10&&d<100){printf("%d-%s-20%d is %sday \n",a,mon[b-1],d,da[r]);}
	}	}	}
}
}


int main()
{

    int choice,date,mon,year,day_code,i;
    char option;
    
    char *days[7]={"sun","mon","tues","wednes","thus","fri","satur"};
    
    do 
    {
     title();//printing the title
     printf ( "choose an option\n1.years having same day and date\n2.year calendar\n3.month calendar\n4.to know the day of the date\n\nplease enter your choice:-" );
     
	scanf( "%d" , &choice );//scanning choice
	printf("\n");

   switch (choice)//to satisify the choice
	{
     case 1:
	  printf("enter the date\n");
	  scanf("%d",&date);
	  printf("enter the month\n");
	  scanf("%d",&mon);
	  printf("enter the day(ex:-1 for sunday)\n1.sunday\t2.monday\t3.tuesday\n4.wednesday\t5.thursday\t6.friday\t7.saturday\nenter your option:-");
	  scanf("%d",&day_code);
	  title();
	  same_year(date,mon,day_code);
	  break;


	case 2:
	printf("enter year\n");
	scanf("%d",&year);
	title();
	for (i=1;i<=12;i++)//to print 12 month
	{
	day_code = day (1,i,year);
	month(day_code,i,year);
	}
	break;

	  case 3: 
	printf("enter month\n");
	scanf("%d",&mon);
	printf("enter year\n");
	scanf("%d",&year);
	title();
	day_code=day(1,mon,year);
	month(day_code,mon,year);
	break;
	
       case 4:
 	printf("enter  date\n");
	scanf("%d",&date);
	printf("enter month\n");
	scanf("%d",&mon);
	printf("enter year\n");
	scanf("%d",&year);
	day_code=day(date,mon,year);
	title();
	printf("the day is %sday\n",days[day_code]);
	break;
	  }
    printf ("------------------------------------------------------------\n\n√√THANKYOU for entering the data\n\nif you want to continue press  \n1.continue\n2.stop\nenter the option:");
    //to ask about  continuing
    scanf("%d",&option);
	}
while (option==1);//to continue the options

  printf("\nthankyou");
	return 0;
}
