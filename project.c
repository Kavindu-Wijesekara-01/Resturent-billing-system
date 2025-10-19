#include <stdio.h>
#include <time.h>
int main(){
    char name[40];
    int customerId;
    int phoneNumber;

    int chocolotPopcone;
    int cheesePopcone;
    int caremalPopcone;

    int hotdog;
    int chikenDrumlets;
    int Steakfrise;
    int slowDog;
    int sandwiches;

    int milkTea;
    int latte;
    int cappuccino;
    int hotchocolate;
    int Americano;

    int total;
    int popcone_total;
    int hotkichenItemTotal;
    int coffee_total;
    


    printf("--------------------------------------\n");
    printf("---------Welcome Our Snak Bar---------\n");
    printf("--------------------------------------\n\n\n");

    printf("Customer Details\n\n");

    printf("Customer Name : ");
    //scanf("%S", &name);
    fgets(name, sizeof(name), stdin);

    printf("Customer Number : ");
    scanf("%d", &phoneNumber);

    printf("Customer ID : ");
    scanf("%d", &customerId);

    printf("--------------------------------------\n");
               //popcone
    printf("Popcones\n\n");

    printf("Chocolate Popcone (RS 1200) : ");
    scanf("%d", &chocolotPopcone);
    printf("Cheese Popcone (RS 1100) : ");
    scanf("%d", &cheesePopcone);
    printf("Caremal Popcone (RS 1200) : ");
    scanf("%d", &caremalPopcone);

    printf("--------------------------------------\n");
              // hot kichen
    printf("Hot kichen Items\n\n");

    printf("Hotdog (RS 2200) : ");
    scanf("%d", &hotdog);
    printf("Chiken Drumlets (RS 1600) : ");
    scanf("%d", &chikenDrumlets);
    printf("Steak Frise (RS 1800) : ");
    scanf("%d", &Steakfrise);
    

    printf("--------------------------------------\n");

           //coffees

    printf("Coffees\n\n");

   
    printf("Cappuccino(RS 700) : ");
    scanf("%d", &cappuccino);
    printf("Hot Chocolate(RS 700) : ");
    scanf("%d", &hotchocolate);
    printf("Americano(RS 700) : ");
    scanf("%d", &Americano);

    printf("--------------------------------------\n");

    int chocopop;
    int cheespop;
    int carepop;

    chocopop = 1200 * chocolotPopcone;
    cheespop = 1100 * cheesePopcone;
    carepop  = 1200 * caremalPopcone;
    popcone_total = chocopop + cheespop + carepop;

    printf("Chocolate popcones : %d.00 RS\n",chocopop);
    printf("Cheese popcones : %d.00 RS\n",cheespop);
    printf("Caremal popcones : %d.00 RS\n\n",carepop);
    printf("Total popcones price : %d.00 RS\n",popcone_total);

    printf("--------------------------------------\n");

    int hdog;
    int drumlets;
    int frice;
    
    hdog = 2200 * hotdog;
    drumlets=1600 * chikenDrumlets;
    frice=1800 * Steakfrise;
    hotkichenItemTotal=hdog+drumlets+frice;

    printf("Hot Dogs : %d.00 RS\n",hdog);
    printf("Chicken Drumlets : %d.00 RS\n",drumlets);
    printf("Steak Frice : %d.00 RS\n\n",hdog);
    printf("Total Hot Kichen Item : %d.00 RS\n",hotkichenItemTotal);

    printf("--------------------------------------\n");

    int cappu;
    int hchoco;
    int amer;

    cappu = 700 * cappuccino;
    hchoco = 700 * hotchocolate;
    amer = 700 * Americano;
    coffee_total=cappu+hchoco+amer;

    printf("Cappuccino : %d.00 RS\n",cappu);
    printf("Hot Chocolate : %d.00 RS\n",hchoco);
    printf("Americano : %d.00 RS\n\n",amer);
    printf("Total Coffee Item : %d.00 RS\n",coffee_total);

    printf("--------------------------------------\n");

    total = popcone_total + hotkichenItemTotal + coffee_total;

    printf("Total Amount is: %d.00 RS\n",total);

    printf("--------------------------------------\n");
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char buffer[100];

    strftime(buffer, sizeof(buffer), "%d-%m-%Y", t);
    printf("Date : %s\t", buffer);
    
    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    printf("Time : %s\n", buffer);

    printf("Thank You Mr/Miss/Mrs ");
    printf("%s\n",name);
  
 

    return 0;
}