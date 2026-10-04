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
