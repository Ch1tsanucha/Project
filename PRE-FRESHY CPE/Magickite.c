#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    double pocket=1000;
    double math;
    int year = 0,month = 0;
    int lyear=0,lmonth=0;
    int lyear1=0,lyear2=0;
    int lmonth1=0,lmonth2=0;
    int choice=0;
    int decide[20];
    int loop=1;

    srand(time(NULL));
    int tao;

    printf("Start money: %.2f Majikite\n",pocket);
    printf("\n");
    printf("Time past: %d year %d month\n",year,month);
    printf("Current money: %.2f Majikite\n",pocket);
    printf("What do you want to choose next?\n");
    printf("1. Majikleen Fund (3-8%%) 3 months\n");
    printf("2. Bank (6%%) 6 months\n");
     while(1)
    {
    scanf("%d",&choice);            //=============> Input choice 1 or 2

    if(choice == 1 || choice == 2)  //=============> This code can input only 1 or 2
    {
      printf("(select: %d)\n",choice);
      decide[0]=choice;
    break;                          //=============> break out loop check input
    }

    else                            //=============> if u put number and it not= 1 or 2 it will tell u
    {
    printf(" \n");
      printf("Error! You can choose only 1 or 2 !!!\n");
      printf(" \n");
    }

    }
    printf(" \n");

    if( choice == 1 )               //=============> + year depend by choice 1 or 2
    {
       month = month+3;
    }
    else                            //=============> + year depend by choice 1 or 2
    {
       month = month+6;
    }

    if( month >= 12 )               //=============> change  12 month = 1 year
    {
        month=month-12;
        year=year+1;
    }

    //=================================================================================//

    while( 1 )                      //=============> this while will loop until this code have 5 year and it will break
    {

        printf("Time past: %d year %d month\n",year,month);

        if(choice == 1)
        {
        lyear=year;

        lmonth = month-3;

            if(lmonth<0)                 // 1 year 0 month event*** it will be 1 year -3 month fix change year = 12 month  and - by 3 = 9
            {
            lyear = year-1;
            lmonth = 9;
            }

            tao=(rand()%6)+3;
            printf("In %d year %d month, the interest of the fund is %d%%.\n",lyear,lmonth,tao);
            math = ((pocket*tao)/100)*3;
            pocket = pocket+math;

        }
        else if(choice == 2)
        {

        lyear1=year;
        lyear2=year;
        lmonth1 = month-6;
        lmonth2 = month-3;

            if(lmonth1 < 0)             // 1 year 3 month event*** it will be 1 year -3 month fix change year=12 month - 6 + month
            {
            lyear1 = year-1;
            lmonth1= 6+month;
            }

            if(lmonth2<0)                // 1 year 0 month event*** it will be 1 year -3 month fix change year = 12 month  and - by 3 = 9
            {
            lyear2 = year-1;
            lmonth2 = 9;
            }


        tao=(rand()%6)+3;
        printf("In %d year %d month, the interest of the fund is %d%%.\n",lyear1,lmonth1,tao);

        srand(time(NULL));
        tao=(rand()%6)+3;
        printf("In %d year %d month, the interest of the fund is %d%%.\n",lyear2,lmonth2,tao);

        math = ((pocket*6)/100)*6;
        pocket = pocket+math;


    }




    printf("Current money: %.2f Majikite\n",pocket);

    if( year==5 )  //=============> This if will break out this loop if year is = 5
    break;         //=============> put break out loop here because this code will calculate your last input before it will be 5 year

    printf("What do you want to choose next?\n");

    if(year == 4 && month == 9 )
    {
    while(1){
    printf("now is almost 5 year u can choose only option 1\n");
    printf("1. Majikleen Fund (3-8%%) 3 months\n");
     scanf("%d",&choice);
    printf("(select: %d)\n",choice);
    printf(" \n");
        if( choice == 1 )
        {
        month = month+3;
        decide[loop]=choice;
        break;
        }
        else
        {
        printf(" \n");
        printf("error!\n");
        }
            }
    }

    else
    {
        while(1)                            // This loop check your input if your input not = 1 or 2 it will loop again!
        {

    printf("1. Majikleen Fund (3-8%%) 3 months\n");
    printf("2. Bank (6%%) 6 months\n");
     scanf("%d",&choice);                   //=============> Input choice 1 or 2
    printf("(select: %d)\n",choice);
    printf(" \n");
            if( choice == 1 )               //=============> + year depend by choice 1 or 2
            {
            month = month+3;
            decide[loop]=choice;
            break;                          //=============> break out loop check input
            }
            else if( choice == 2 )          //=============> + year depend by choice 1 or 2
            {
            month = month+6;
            decide[loop]=choice;
            break;                          //=============> break out loop check input
            }
            else                            //=============> This code can input only 1 or 2
            {
            printf(" \n");
            printf("Error! You can choose only 1 or 2 !!!\n");
            printf(" \n");
            }

        }

    }
    if( month>= 12 )                        //=============> change  12 month = 1 year
    {
    month=month-12;
    year=year+1;
    }
    loop+=1;

    }

    //=================================================================================//

    printf("\n");
    printf("Final money: %.2f Majikite\n",pocket);
    printf("\n");

    //=================================================================================//

    int a[]={1000,500,100,50,20,10,5,2,1};
    float b[]={0.5,0.25};
    int bill[12];
    int rob;
    double mon = pocket;
    for(rob=0;rob<9;rob++)                  //=============> this for loop calculate money in pocket to bill only int bill
    {
    bill[rob]=mon/a[rob];
    mon=mon-bill[rob]*a[rob];
   }
    for(rob=0;rob<2;rob++)                  //=============> this for loop calculate money in pocket to bill float int bill
    {
    bill[rob+9]=mon/b[rob];
    mon=mon-bill[rob+9]*b[rob];
   }
    for(rob=0;rob<9;rob++)                  //=============> print all bill after calculated
    {
    printf("%d Majikite x%d\n",a[rob],bill[rob]);
   }
    printf("0.5 Majikite x%d\n",bill[9]);
    printf("0.25 Majikite x%d\n",bill[10]);


    //=================================================================================//

    int p;
    printf("\n");
    printf("This is all your decide \n");
    printf("\n");
    for(p=0;p<loop;p++)
    {

        printf("Your decide number %d is = %d\n",p+1,decide[p]);
    }

    //=================================================================================//

    return 0;
}
