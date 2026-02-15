# Contact Management System

A C++ console application designed to manage personal contacts with basic CRUD operations (Create, Read, Update, Delete) and persistent storage.

## Project Overview

The Contact Management System allows users to:

- **Add Contacts**: Store name, email, and phone number.
- **Display All Contacts**: List all saved contacts from the file.
- **Search Contacts**: Quickly find a contact by name.
- **Delete Contacts**: Remove a contact using their phone number.
- **Auto-Sorting**: Contacts are automatically sorted alphabetically when added.

## DSA Concepts Used

This project implements several fundamental Data Structures and Algorithms:

### 1. Linked List

- Used a **Singly Linked List** structure (`Node` class) to represent contacts in memory during certain operations.
- Demonstrates dynamic memory allocation and pointer manipulation.

### 2. Arrays

- Utilized fixed-size arrays for the sorting operation.
- Demonstrates the use of contiguous memory for batch processing.

### 3. Selection Sort

- The project implements a sorting algorithm (nested loops) to arrange contacts alphabetically by name.
- It compares the first characters of names and swaps records to maintain order.

### 4. Linear Search

- Implements a linear search algorithm by iterating through the stored data to find matches for a given name.

### 5. File Persistence (IO Operations)

- Uses `<fstream>` for permanent data storage in `user.txt`.
- Demonstrates reading from and writing to files, ensuring data isn't lost when the program closes.

## How to Run

1. **Prerequisites**: Ensure you have a C++ compiler installed (like MinGW/g++).
2. **Compile**:
   ```bash
   g++ main.cpp -o contact.exe
   ```
3. **Execute**:
   ```bash
   ./contact.exe
   ```

## Built With

- C++
- Windows API (for `Sleep` and `cls` functions)
- Standard Library (`iostream`, `string`, `fstream`)
