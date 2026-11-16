CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
SOURCES = src/main.c src/storage.c src/subjects.c src/assignments.c src/attendance.c src/planner.c
TARGET = campusflow

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) *.dat
