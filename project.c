#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_ORDER_ITEMS 50
#define TAX_RATE 0.10

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
} OrderItem;

MenuItem menu[MAX_ITEMS];
OrderItem orders[MAX_ORDER_ITEMS];
int menu_count = 0;
int order_count = 0;

void initialize_menu() {
    menu[0].id = 1;
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.50;

    menu[1].id = 2;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.50;

    menu[2].id = 3;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 5.00;

    menu[3].id = 4;
    strcpy(menu[3].name, "Cake");
    menu[3].price = 3.50;

    menu[4].id = 5;
    strcpy(menu[4].name, "Pizza");
    menu[4].price = 8.00;

    menu_count = 5;
}

void display_menu() {
    printf("\n========== MENU ==========\n");
    printf("ID\tItem\t\tPrice\n");
    printf("--------------------------\n");
    for(int i = 0; i < menu_count; i++) {
        printf("%d\t%s\t\t$%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("==========================\n");
}

int find_menu_item(int id) {
    for(int i = 0; i < menu_count; i++) {
        if(menu[i].id == id) {
            return i;
        }
    }
    return -1;
}

void add_order() {
    int item_id, quantity;
    printf("Enter item ID: ");
    scanf("%d", &item_id);
    
    int menu_index = find_menu_item(item_id);
    if(menu_index == -1) {
        printf("Invalid item ID!\n");
        return;
    }
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    if(quantity <= 0) {
        printf("Invalid quantity!\n");
        return;
    }
    
    orders[order_count].item_id = item_id;
    strcpy(orders[order_count].item_name, menu[menu_index].name);
    orders[order_count].quantity = quantity;
    orders[order_count].price = menu[menu_index].price;
    order_count++;
    
    printf("Item added to order successfully!\n");
}

void view_order() {
    if(order_count == 0) {
        printf("No items in the order!\n");
        return;
    }
    
    printf("\n========== CURRENT ORDER ==========\n");
    printf("Item\t\tQty\tPrice\tTotal\n");
    printf("----------------------------------\n");
    
    float total = 0;
    for(int i = 0; i < order_count; i++) {
        float item_total = orders[i].quantity * orders[i].price;
        printf("%s\t\t%d\t$%.2f\t$%.2f\n", 
               orders[i].item_name, 
               orders[i].quantity, 
               orders[i].price, 
               item_total);
        total += item_total;
    }
    
    float tax = total * TAX_RATE;
    float final_total = total + tax;
    
    printf("----------------------------------\n");
    printf("Subtotal: $%.2f\n", total);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("Total: $%.2f\n", final_total);
    printf("==================================\n");
}

void generate_bill() {
    if(order_count == 0) {
        printf("No items to generate bill!\n");
        return;
    }
    
    printf("\n========== FINAL BILL ==========\n");
    printf("Item\t\tQty\tPrice\tTotal\n");
    printf("----------------------------------\n");
    
    float total = 0;
    for(int i = 0; i < order_count; i++) {
        float item_total = orders[i].quantity * orders[i].price;
        printf("%s\t\t%d\t$%.2f\t$%.2f\n", 
               orders[i].item_name, 
               orders[i].quantity, 
               orders[i].price, 
               item_total);
        total += item_total;
    }
    
    float tax = total * TAX_RATE;
    float final_total = total + tax;
    
    printf("----------------------------------\n");
    printf("Subtotal: $%.2f\n", total);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("Total: $%.2f\n", final_total);
    printf("==================================\n");
    
    printf("\nThank you for your visit!\n");
    
    order_count = 0;
}

void remove_item() {
    if(order_count == 0) {
        printf("No items to remove!\n");
        return;
    }
    
    int item_id;
    printf("Enter item ID to remove: ");
    scanf("%d", &item_id);
    
    for(int i = 0; i < order_count; i++) {
        if(orders[i].item_id == item_id) {
            for(int j = i; j < order_count - 1; j++) {
                orders[j] = orders[j + 1];
            }
            order_count--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in order!\n");
}

int main() {
    int choice;
    
    initialize_menu();
    
    printf("=== WELCOME TO CAFE BILLING SYSTEM ===\n");
    
    while(1) {
        printf("\n1. Display Menu\n");
        printf("2. Add Item to Order\n");
        printf("3. View Current Order\n");
        printf("4. Remove Item from Order\n");
        printf("5. Generate Bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                display_menu();
                break;
            case 2:
                add_order();
                break;
            case 3:
                view_order();
                break;
            case 4:
                remove_item();
                break;
            case 5:
                generate_bill();
                break;
            case 6:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}