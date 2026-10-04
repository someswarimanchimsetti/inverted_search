# Inverted Search

## Overview

Inverted Search is a C-based project that creates an inverted index of words from multiple text files. It allows users to efficiently search for a word and identify the files in which it occurs.

## Features

* Create an inverted database from multiple text files
* Search for a word across the indexed files
* Display the complete database
* Update the database
* Save the database to a file
* Load a previously saved database
* Validate input files
* Handle multiple input text files

## Technologies Used

* **Language:** C
* **Operating System:** Linux
* **Compiler:** GCC
* **Build Tool:** Makefile
* **Concepts:** File handling, pointers, structures, linked lists, hashing and dynamic memory allocation

## Project Structure

| File                   | Description                                         |
| ---------------------- | --------------------------------------------------- |
| `main.c`               | Main program and menu handling                      |
| `create_database.c`    | Creates the inverted database                       |
| `search.c`             | Searches for words                                  |
| `display_database.c`   | Displays the database                               |
| `update_database.c`    | Updates the database                                |
| `save_database.c`      | Saves the database                                  |
| `load_database.c`      | Loads the database                                  |
| `file_validation.c`    | Validates input files                               |
| `hash_function.c`      | Hashing functionality                               |
| `insert_last.c`        | Inserts nodes into the linked list                  |
| `write_databasefile.c` | Writes database information to a file               |
| `inverted_Search.h`    | Header file containing declarations and definitions |
| `Makefile`             | Builds the project                                  |

## How to Build

Clone the repository and enter the project directory:

```bash
git clone https://github.com/someswarimanchimsetti/inverted_search.git
cd inverted_search
```

Build the project:

```bash
make
```

## How to Run

The program accepts text files as command-line arguments.

Example:

```bash
./Slist file1.txt file2.txt
```

You can provide multiple input files according to the program's requirements.
## Sample Output

### Program Startup

```text
Successfully added file1.txt file into Linked List
Successfully added file2.txt file into Linked List

========================================
          INVERTED SEARCH MENU
========================================
1. Create Database
2. Display Database
3. Update Database
4. Search
5. Save Database
6. Exit
========================================
Enter your choice:
```

### Create Database

```text
Enter your choice: 1
Database created successfully
```

### Search

For example, searching for the word `hello`:

```text
Enter your choice: 4
Enter the word to search: hello

Word hello is present in 1 files
In file file1.txt 2
```

This demonstrates that the inverted index can identify the files containing a searched word and the number of occurrences in each file.


## Sample Input Files

The repository contains sample files such as:

```text
file1.txt
file2.txt
file3.txt
file4.txt
```

These can be used to test the program.

## Learning Outcomes

Through this project, I practiced:

* Advanced C programming
* File handling
* Structures and pointers
* Linked lists
* Hashing
* Dynamic memory allocation
* Modular programming
* Makefile-based compilation
* Linux command-line development
* Git and GitHub workflow

## Author

**Someswari Manchimsetti**

B.Tech – Electronics and Communication Engineering
