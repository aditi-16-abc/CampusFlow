#include <stdio.h>
#include <string.h>
#include "campusflow.h"

extern Subject subjects[MAX_SUBJECTS];
extern int subject_count;

void attendance_menu(void) {
    int choice, i, index, attended, held;
    char code[20];
    double percentage;

    do {
        printf("\nATTENDANCE\n1. Record a class\n2. View attendance report\n0. Back\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        getchar();

        if (choice == 1) {
            if (subject_count == 0) {
                printf("Add a subject first.\n");
                continue;
            }
            printf("Enter subject code: ");
            if (fgets(code, sizeof(code), stdin) == NULL) continue;
            code[strcspn(code, "\n")] = '\0';

            index = -1;
            for (i = 0; i < subject_count; i++)
                if (strcmp(subjects[i].code, code) == 0) index = i;

            if (index == -1) {
                printf("Subject code not found. Add it in Subject Manager first.\n");
                continue;
            }

            printf("Was the class attended? (1 = Yes, 0 = No): ");
            if (scanf("%d", &attended) != 1 || (attended != 0 && attended != 1)) {
                printf("Enter 1 or 0.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
                continue;
            }
            subjects[index].classes_held++;
            if (attended == 1) subjects[index].classes_attended++;
            save_all();
            printf("Attendance recorded.\n");
        } else if (choice == 2) {
            if (subject_count == 0) printf("No subjects available.\n");
            printf("\n%-12s %-24s %-10s %-10s %-12s\n", "CODE", "SUBJECT", "ATTENDED", "HELD", "PERCENT");
            for (i = 0; i < subject_count; i++) {
                held = subjects[i].classes_held;
                attended = subjects[i].classes_attended;
                percentage = held ? (100.0 * attended / held) : 0.0;
                printf("%-12s %-24.24s %-10d %-10d %8.2f%%\n",
                       subjects[i].code, subjects[i].name, attended, held, percentage);
            }
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}
