#include <stdio.h>
#include "campusflow.h"

extern Subject subjects[MAX_SUBJECTS];
extern Assignment assignments[MAX_ASSIGNMENTS];
extern StudySession sessions[MAX_STUDY_SESSIONS];
extern int subject_count, assignment_count, session_count;

void load_data(void) {
    FILE *fp;

    fp = fopen(SUBJECT_FILE, "rb");
    if (fp != NULL) {
        subject_count = (int)fread(subjects, sizeof(Subject), MAX_SUBJECTS, fp);
        fclose(fp);
    }

    fp = fopen(ASSIGNMENT_FILE, "rb");
    if (fp != NULL) {
        assignment_count = (int)fread(assignments, sizeof(Assignment), MAX_ASSIGNMENTS, fp);
        fclose(fp);
    }

    fp = fopen(STUDY_FILE, "rb");
    if (fp != NULL) {
        session_count = (int)fread(sessions, sizeof(StudySession), MAX_STUDY_SESSIONS, fp);
        fclose(fp);
    }
}

void save_all(void) {
    FILE *fp;

    fp = fopen(SUBJECT_FILE, "wb");
    if (fp != NULL) {
        fwrite(subjects, sizeof(Subject), subject_count, fp);
        fclose(fp);
    } else {
        printf("Warning: Could not save subject records.\n");
    }

    fp = fopen(ASSIGNMENT_FILE, "wb");
    if (fp != NULL) {
        fwrite(assignments, sizeof(Assignment), assignment_count, fp);
        fclose(fp);
    } else {
        printf("Warning: Could not save assignment records.\n");
    }

    fp = fopen(STUDY_FILE, "wb");
    if (fp != NULL) {
        fwrite(sessions, sizeof(StudySession), session_count, fp);
        fclose(fp);
    } else {
        printf("Warning: Could not save study sessions.\n");
    }
}
