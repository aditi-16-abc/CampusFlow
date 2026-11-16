#include <stdio.h>
#include <string.h>
#include "campusflow.h"

Subject subjects[MAX_SUBJECTS];
int subject_count = 0;

static void read_line(char *buffer, int size) {
    int ch;
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strchr(buffer, '\0') == NULL) return;
    }
    /* Remove any remaining characters if input was longer than the buffer. */
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int find_subject(const char *code) {
    int i;
    for (i = 0; i < subject_count; i++) {
        if (strcmp(subjects[i].code, code) == 0) return i;
    }
    return -1;
}

void subject_menu(void) {
    int choice, i;
    char code[20], name[60];

    do {
        printf("\nSUBJECTS\n1. Add subject\n2. View subjects\n0. Back\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        getchar();

        if (choice == 1) {
            if (subject_count >= MAX_SUBJECTS) {
                printf("Subject limit reached.\n");
                continue;
            }
            printf("Enter subject code (e.g. CSE101): ");
            read_line(code, sizeof(code));
            if (code[0] == '\0' || find_subject(code) != -1) {
                printf("Code is empty or already exists.\n");
                continue;
            }
            printf("Enter subject name: ");
            read_line(name, sizeof(name));
            if (name[0] == '\0') {
                printf("Subject name cannot be empty.\n");
                continue;
            }
            subjects[subject_count].id = subject_count + 1;
            snprintf(subjects[subject_count].code, sizeof(subjects[subject_count].code), "%s", code);
            snprintf(subjects[subject_count].name, sizeof(subjects[subject_count].name), "%s", name);
            subjects[subject_count].classes_held = 0;
            subjects[subject_count].classes_attended = 0;
            subject_count++;
            save_all();
            printf("Subject added successfully.\n");
        } else if (choice == 2) {
            if (subject_count == 0) printf("No subjects added yet.\n");
            for (i = 0; i < subject_count; i++) {
                printf("%d. [%s] %s\n", i + 1, subjects[i].code, subjects[i].name);
            }
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}
