#include <stdio.h>
#include <stdlib.h>
#include "campusflow.h"

int main(void) {
    int choice;

    load_data();

    printf("\n=====================================\n");
    printf("              CAMPUSFLOW\n");
    printf("      Student Academic Organizer\n");
    printf("=====================================\n");

    do {
        printf("\nMAIN MENU\n");
        printf("1. Manage subjects\n");
        printf("2. Manage assignments\n");
        printf("3. Track attendance\n");
        printf("4. Study planner\n");
        printf("5. Save data\n");
        printf("0. Save and exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }

        switch (choice) {
            case 1: subject_menu(); break;
            case 2: assignment_menu(); break;
            case 3: attendance_menu(); break;
            case 4: planner_menu(); break;
            case 5:
                save_all();
                printf("All records saved.\n");
                break;
            case 0:
                save_all();
                printf("Your data has been saved. Goodbye!\n");
                break;
            default:
                printf("Please choose a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
