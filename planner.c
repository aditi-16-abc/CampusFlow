#include <stdio.h>
#include <string.h>
#include "campusflow.h"

StudySession sessions[MAX_STUDY_SESSIONS];
int session_count = 0;

void planner_menu(void) {
    int choice, i, minutes;
    char subject[20], topic[100], date[20];

    do {
        printf("\nSTUDY PLANNER\n1. Add study session\n2. View study sessions\n0. Back\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        getchar();

        if (choice == 1) {
            if (session_count >= MAX_STUDY_SESSIONS) {
                printf("Study session limit reached.\n");
                continue;
            }
            printf("Subject code: ");
            if (fgets(subject, sizeof(subject), stdin) == NULL) continue;
            subject[strcspn(subject, "\n")] = '\0';
            printf("Topic to study: ");
            if (fgets(topic, sizeof(topic), stdin) == NULL) continue;
            topic[strcspn(topic, "\n")] = '\0';
            printf("Study date (DD-MM-YYYY): ");
            if (fgets(date, sizeof(date), stdin) == NULL) continue;
            date[strcspn(date, "\n")] = '\0';
            printf("Duration in minutes: ");
            if (scanf("%d", &minutes) != 1 || minutes <= 0) {
                printf("Enter a positive number of minutes.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
                continue;
            }
            getchar();

            sessions[session_count].id = session_count + 1;
            snprintf(sessions[session_count].subject_code, sizeof(sessions[session_count].subject_code), "%s", subject);
            snprintf(sessions[session_count].topic, sizeof(sessions[session_count].topic), "%s", topic);
            snprintf(sessions[session_count].study_date, sizeof(sessions[session_count].study_date), "%s", date);
            sessions[session_count].duration_minutes = minutes;
            session_count++;
            save_all();
            printf("Study session added.\n");
        } else if (choice == 2) {
            if (session_count == 0) printf("No study sessions planned yet.\n");
            for (i = 0; i < session_count; i++) {
                printf("%d. %s | %s | %s | %d minutes\n",
                       sessions[i].id, sessions[i].subject_code, sessions[i].topic,
                       sessions[i].study_date, sessions[i].duration_minutes);
            }
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}
