#ifndef CAMPUSFLOW_H
#define CAMPUSFLOW_H

#define MAX_SUBJECTS 100
#define MAX_ASSIGNMENTS 200
#define MAX_STUDY_SESSIONS 200

#define SUBJECT_FILE "subjects.dat"
#define ASSIGNMENT_FILE "assignments.dat"
#define STUDY_FILE "study_sessions.dat"

typedef struct {
    int id;
    char code[20];
    char name[60];
    int classes_held;
    int classes_attended;
} Subject;

typedef struct {
    int id;
    char subject_code[20];
    char title[100];
    char due_date[20];
    int completed; /* 0 = pending, 1 = completed */
} Assignment;

typedef struct {
    int id;
    char subject_code[20];
    char topic[100];
    char study_date[20];
    int duration_minutes;
} StudySession;

void load_data(void);
void subject_menu(void);
void assignment_menu(void);
void attendance_menu(void);
void planner_menu(void);
void save_all(void);

#endif
