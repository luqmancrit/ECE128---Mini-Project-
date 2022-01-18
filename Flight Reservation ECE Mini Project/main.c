#include <stdio.h>
#include <stdlib.h>
void home();
//
void location(),time_x(),upgrade(),date();
int pricex,pricey,subtotal,loc,gradex,grade;
float time,duration_flight;
char *locationx,*gradey,*day;
//
void booking();
int booking_error(int person);
char *name[150];
int person,pricez;
//
void payment();
int card_id,cvv,not_proceed;
char proceed_payment;
//
void receipt();
void thankyou();
int main(){
    home();
    location();
    date();
    time_x();
    printf("\n                        \t#Type 1 to upgrade class, type 0 to not upgrade#:");
    scanf("%d",&gradex);
    if (gradex==1){
        upgrade();
    }
    booking();
    pricez=pricex+pricey;
    payment();
}

void home(){
    printf("\tHi thankyou for using Mara Airline, Mara Airline is a low cost carrier airline operating domestic & \n");
    printf("\tinternational routes that give the best service and safety for all travelers to go around the world.\n\n");
    printf("\t\t\t  Here is the list of prices for the locations and class upgrade.\n\n");
    printf("\t\t\t\t\t     (1)Bangkok     = RM55\n\t\t\t\t\t     (2)Sao Paulo   = RM5574\n\t\t\t\t\t     (3)Dubai       = RM2020\n");
    printf("\t\t\t\t\t     (4)Hong Kong   = RM1320\n\t\t\t\t\t     (5)New Zealand = RM7170\n\t\t\t\t\t     (6)Tokyo       = RM2292\n \n");
    printf("\n\t\t\t             Class upgrade available and its price.\t\t\t\n\n");
    printf("                           \t\t(1)Economy Plus = +RM150\n");
    printf("                           \t\t(2)Business     = +RM600\n\n\n");
    printf("\t\t                       Time available for the departure:\n\n");
    printf("\t\t                                 * (0800-1200) \n");
    printf("\t\t                                 * (1400-2200) \n\n");
    printf("                             \t\tChoosing system is by numbering.\n\n");
}

void location(){
    printf("\n\t\t\t\t\tLocation                :");
    scanf("%d",&loc);
    if (loc==1){
        pricex=55;
        subtotal=pricex;
        locationx="Bangkok";
        duration_flight=1.58;
    }
    else if (loc==2){
        pricex=5574;
        subtotal=pricex;
        locationx="Sao Paulo";
        duration_flight=36.50;
    }
    else if (loc==3){
        pricex=2020;
        subtotal=pricex;
        locationx="Dubai";
        duration_flight=11.10;
    }
    else if (loc==4){
        pricex=1320;
        subtotal=pricex;
        locationx="Hong Kong";
        duration_flight=8.35;
    }
    else if (loc==5){
        pricex=7170;
        subtotal=pricex;
        locationx="New Zealand";
        duration_flight=32.10;
    }
    else if (loc==6){
        pricex=2292;
        subtotal=pricex;
        locationx="Tokyo";
        duration_flight=6.40;
    }
    else{
        printf("\n             \t##Sorry, location that you chose is not available for now. Please choose again.##\n");
        location();
    }
}

void date(){
    printf("\t\t\t\t\tDate (dd/mm/yyyy)       :");
    scanf("%s",&day);
}

void time_x(){
    printf("\t\t\t\t\tTime                    :");
    scanf("%f",&time);
    if (time<8.00 || time>22.00){
        printf("\n            \t##Sorry, time that you chose is not available for now. Please choose again.##\n\n");
        time_x();
    }
    if (time>12.00 && time<14.00){
        printf("\n            \t##Sorry, time that you chose is not available for now. Please choose again.##\n\n");
        time_x();
    }
}

void upgrade(){
    printf("\n\t\t\t\t\tUpgrade class           :");
    scanf("%d",&grade);
    if (grade==1){
        gradey="Economy Plus";
        pricey=150;
        subtotal+=150;
    }
    else if (grade==2){
        gradey="Business";
        pricey=600;
        subtotal+=600;
    }
    else{
        printf("Sorry, class that you chose is not available for now. Please choose again.");
        upgrade();
    }
    printf("\t\t\t\t\tPrice                   :RM%d\n",subtotal);
    printf("\t\t\t\t\tClass                   :%s\n",gradey);
}

void booking(){
    int i;
    printf("\n\t\t\t\t\tHow many guests to book?:");
    scanf("%d",&person);
    printf("\n");

    if (person<=150){
        int i;
        for (i=0;i<person;i++){
        printf("\t\t\t\t\tName                    :");
        scanf("%s",&name[i]);
        }
        subtotal=subtotal*person;
    }
    else
        booking_error(person);
}
//booking over limit seats//
int booking_error(int person){
    int rechoose;
    printf("\n                             \t\tSorry, there are only 150 seats available for this time, please type 1 to re-choose, type 2 to cancel order.\nChoose number: ");
    scanf("                             \t\t%d",&rechoose);
    if (rechoose==1){
        booking();
    }
    if (rechoose==2)
        printf("\n                             \t\tThankyou for using Mara Airline, till we meet again :)");
}

void payment(){
    printf("\n\t\t\t\t\t             ***PAYMENT***\n");
    printf("\n\t\t\t\t             Card number:");
    scanf("%d",&card_id);
    printf("\n\t\t\t\t                     CVV:");
    scanf("%d",&cvv);
    printf("\n\n\t\t\t\t\tPayment details: \n\n\t\t\t\t\t(1)Location: %s = RM%d\n\t\t\t\t\t(2)Class: %s = RM%d\n\t\t\t\t\t(3)Number of tickets for guests = %d.",locationx,pricex,gradey,pricey,person);
    printf("\n\t\t\t\t\t(4)Date departure: %s",&day);
    printf("\n\n\t\t\t\t\t(*)RM%d x %d = RM%d\n\n\t\t\t\t\t      ***SUBTOTAL IS RM%d***",pricez,person,subtotal,subtotal);
    printf("\n\n\n\t\t\t\t      Type y to proceed payment, else for more.");
    scanf(" %c",&proceed_payment);
    if (proceed_payment=='y'){
        printf("\n\t\t\t\t\t      ***PAYMENT SUCCESSFUL***");
        receipt();
        thankyou();
    }
    else{
        printf("\n\n\t\t\t\t\t ## ***PAYMENT IS UNSUCCESSFUL*** ##");
        printf("\n\n\t\t\t\t\t(1)Re-enter payment details.\n");
        printf("\t\t\t\t\t(2)Adjust booking details.\n");
        printf("\t\t\t\t\t(3)Cancel booking.\n");
        printf("\n\t\t\t\t\tEnter number:");
        scanf("%d",&not_proceed);
        if (not_proceed == 1){
            payment();
        }
        else if (not_proceed == 2){
            main();
        }
        else if (not_proceed == 3){
            thankyou();
        }
    }
}

void receipt(){
    int i;
    printf("\n\n\n\t\t\t\t\t        **CHECKOUT RECEIPT**\n");
    printf("\n\t\t\t\t\t        Number of guests: %d\n",person);
    for (i=0;i<person;i++){
        printf("\t\t\t\t %d.Name = %s\n",i+1,&name[i]);
    }
    printf("\n\t\t\t\t Location:           %s",locationx);
    printf("              RM%d",pricex);
    printf("\n\t\t\t\t Class:              %s",gradey);
    printf("              RM%d",pricey);
    printf("\n\t\t\t\t Date Departure:     %s",&day);
    printf("\n\t\t\t\t Time Departure:     %.2f",time);
    printf("\n\t\t\t\t Flight Duration:    %.2f Hour",duration_flight);
    printf("\n\t\t\t\t Subtotal :          RM%d x %d =          RM%d",pricez,person,subtotal);
    printf("\n\n\t\t\t\t\t\t Status: **PAID**\n\n");
}

void thankyou(){
    printf("\n\n\t\tThank you and we really appreciate you for choosing us, Mara Airline, till we meet again :)\n\n");
    printf("\t\t\t   ### F L Y   B E T T E R   W I T H   M A R A   A I R L I N E ###\t\t\t\n\n");
}






