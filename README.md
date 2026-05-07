# Data Structures Level 1 - Real-Life Application

This repository contains custom C++ implementations of fundamental data structures along with a real-life application simulating a **Ticket Queue Management System** (commonly found in banks, customer service centers, or clinics).

## 🚀 Overview

This project was built to understand the inner workings of data structures from scratch rather than relying entirely on the standard template library (STL). It demonstrates how low-level memory management and pointers can be used to build dynamic, scalable data collections, and how these collections can be applied to solve real-world problems.

## 📂 Core Data Structures Implemented

- **`clsDblLinkedList.h`**: A custom implementation of a Doubly Linked List with operations for inserting, deleting, finding, and updating nodes.
- **`clsDynamicArray.h`**: A dynamic array class that automatically resizes itself when capacity is reached, providing a flexible alternative to static C++ arrays.
- **`clsMyQueue.h`**: A queue (FIFO - First In, First Out) data structure built from scratch.
- **`clsMyStack.h`**: A stack (LIFO - Last In, First Out) data structure.
- **`clsMyString.h`**: A custom String class that implements **Undo** and **Redo** capabilities using two internal Stacks.

## 🏢 Real-Life Applications

This project showcases how underlying data structures translate to real-world software features.

### 1. Undo / Redo Mechanism (`clsMyString.h`)
An implementation of the classic **Undo/Redo** functionality found in text editors. 
- Uses two **Stack** data structures (LIFO). 
- Every modification pushes the previous state to the `_undo` stack.
- Undoing pushes the current state to the `_redo` stack and pops the previous state from `_undo`.

### 2. Ticket Queue Line System (`clsQueueLine.h`)
Simulates a ticketing system commonly found in banks, customer service centers, or clinics using a **Queue** (FIFO).

### Features of the Queue Line System:
- **Multiple Queues**: Ability to create different queues for different services (e.g., "Pay Bills", "Subscriptions") with custom prefixes (e.g., A0, B0).
- **Ticket Issuance**: Automatically issues incremental tickets to clients (e.g., A01, A02) while recording the exact time of issuance.
- **Serve Time Estimation**: Calculates the expected waiting time for a new client based on the average serve time and the number of people currently waiting.
- **Queue Operations**: 
  - Serve the next client in line.
  - View total tickets issued, served clients, and currently waiting clients.
  - Read the queue from Left-to-Right (LTR) or Right-to-Left (RTL).
  - Print detailed "Client Cards" showing wait times and ticket information.

## 🛠️ Technologies Used
- **C++** (Object-Oriented Programming principles)
- Standard Template Library (STL) used selectively for demonstration in the application layer.

## 💻 How to Run
1. Clone the repository to your local machine.
2. Open the `.sln` or `.vcxproj` file in **Visual Studio**.
3. Set `Data Structures.cpp` as the main entry point if not already configured.
4. Build and Run the project (F5 or Ctrl+F5).
