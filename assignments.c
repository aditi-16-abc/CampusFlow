#include <stdio.h>
#include <string.h>
#include "campusflow.h"

Assignment assignments[MAX_ASSIGNMENTS];
int assignment_count = 0;

static void read_text(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

static int next_id(void) {
    int i, max_id = 0;
    for (i = 0; i < assignment_count; i++)
        if (assignments[i].id > max_id) max_id = assignments[i].id;
    return max_id + 1;
}

static void list_assignments(void) {
    int i;
    if (assignment_count == 0) {
        printf("No assignments added yet.\n");
        return;
    }
    printf("\n%-5s %-12s %-28s %-14s %-10s\n", "ID", "SUBJECT", "TITLE", "DUE DATE", "STATUS");
    for (i = 0; i < assignment_count; i++) {
        printf("%-5d %-12s %-28.28s %-14s %-10s\n",
               assignments[i].id, assignments[i].subject_code,
               assignments[i].title, assignments[i].due_date,
               assignments[i].completed ? "Completed" : "Pending");
    }
}

void assignment_menu(void) {
    int choice, i, id, found;
    char subject[20], title[100], date[20];

    do {
        printf("\nASSIGNMENTS\n1. Add assignment\n2. View assignments\n3. Mark completed\n4. Delete assignment\n0. Back\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        getchar();

        if (choice == 1) {
            if (assignment_count >= MAX_ASSIGNMENTS) {
                printf("Assignment limit reached.\n");
                continue;
            }
            printf("Subject code: "); read_text(subject, sizeof(subject));
            printf("Assignment title: "); read_text(title, sizeof(title));
            printf("Due date (DD-MM-YYYY): "); read_text(date, sizeof(date));
            if (!subject[0] || !title[0] || !date[0]) {
                printf("All fields are required.\n");
                continue;
            }
            assignments[assignment_count].id = next_id();
            snprintf(assignments[assignment_count].subject_code, sizeof(assignments[assignment_count].subject_code), "%s", subject);
            snprintf(assignments[assignment_count].title, sizeof(assignments[assignment_count].title), "%s", title);
            snprintf(assignments[assignment_count].due_date, sizeof(assignments[assignment_count].due_date), "%s", date);
            assignments[assignment_count].completed = 0;
            assignment_count++;
            save_all();
            printf("Assignment added.\n");
        } else if (choice == 2) {
            list_assignments();
        } else if (choice == 3) {
            list_assignments();
            printf("Enter assignment ID to mark completed: ");
            if (scanf("%d", &id) != 1) { printf("Invalid ID.\n"); int ch; while ((ch=getchar())!='\n' && ch!=EOF){}; continue; }
            found = 0;
            for (i = 0; i < assignment_count; i++) {
                if (assignments[i].id == id) {
                    assignments[i].completed = 1;
                    found = 1;
                    save_all();
                    printf("Assignment marked completed.\n");
                    break;
                }
            }
            if (!found) printf("Assignment ID not found.\n");
        } else if (choice == 4) {
            list_assignments();
            printf("Enter assignment ID to delete: ");
            if (scanf("%d", &id) != 1) { printf("Invalid ID.\n"); int ch; while ((ch=getchar())!='\n' && ch!=EOF){}; continue; }
            found = 0;
            for (i = 0; i < assignment_count; i++) {
                if (assignments[i].id == id) {
                    int j;
                    for (j = i; j < assignment_count - 1; j++) assignments[j] = assignments[j + 1];
                    assignment_count--;
                    found = 1;
                    save_all();
                    printf("Assignment deleted.\n");
                    break;
                }
            }
            if (!found) printf("Assignment ID not found.\n");
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}
