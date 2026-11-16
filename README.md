# CampusFlow – Student Academic Organizer

CampusFlow is a beginner-friendly, menu-driven C application that helps students organise subjects, assignments, attendance and study sessions.

## Features

- **Subject manager:** add and view subjects using unique subject codes.
- **Assignment manager:** add, view, complete and delete assignments.
- **Attendance tracker:** record attended/missed classes and calculate subject-wise attendance percentages.
- **Study planner:** create and view planned study sessions.
- **Persistent storage:** records are saved locally in binary data files and loaded when the program starts.

## Technologies and C concepts

- Language: C (C99)
- Structures (`struct`)
- Arrays and strings
- Functions and modular programming
- Loops and switch-case
- Pointers (used by standard C library/file operations)
- File handling (`fopen`, `fread`, `fwrite`, `fclose`)

## Requirements

- GCC compiler (or another C99-compatible compiler)
- Windows, Linux or macOS terminal

## Compile

### Linux / macOS
```bash
make
./campusflow
```

If `make` is unavailable:
```bash
gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o campusflow
./campusflow
```

### Windows (MinGW GCC)
```bash
gcc -Wall -Wextra -std=c99 -Iinclude src\*.c -o campusflow.exe
campusflow.exe
```

## How to use

1. Run the program.
2. Add subjects first. Give each subject a short unique code, such as `CSE101`.
3. Use the same subject code when adding assignments, recording attendance or planning study sessions.
4. Use the menu to view or update your records.
5. Select **Save and exit** before closing.

The program creates `subjects.dat`, `assignments.dat` and `study_sessions.dat` in the current working directory. These files contain your local data and are intentionally excluded from Git.

## Project structure

```text
CampusFlow/
├── include/
│   └── campusflow.h
├── src/
│   ├── main.c
│   ├── storage.c
│   ├── subjects.c
│   ├── assignments.c
│   ├── attendance.c
│   └── planner.c
├── docs/
│   └── PROJECT_REPORT.md
├── .gitignore
├── Makefile
└── README.md
```

## Current limitations

- This is a local, single-user console application.
- Dates are stored as text; the program does not yet validate calendar dates or send reminders.
- Binary data files are intended for this version of the program and may not be portable between different compiler/structure layouts.
- The attendance percentage is calculated from the classes recorded in this application.

## Future improvements

1. Validate dates and add sorting by nearest deadline.
2. Add editing for subjects and study sessions.
3. Add low-attendance warnings and attendance target calculations.
4. Replace binary files with SQLite.
5. Build a graphical or web interface.
6. Add user accounts and cloud synchronisation.
7. Add optional AI-assisted study planning.

## GitHub setup

Create a repository named `CampusFlow`, then from this folder run:

```bash
git init
git add .
git commit -m "Build CampusFlow C student organizer"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/CampusFlow.git
git push -u origin main
```

Replace `YOUR-USERNAME` with your GitHub username.

## Academic integrity

Understand each module and be prepared to explain the structures, arrays, functions, menu flow and file operations during your capstone demonstration. Extend the project with your own improvements.
