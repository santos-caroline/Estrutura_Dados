# Copilot Instructions for This Codebase

## Overview
This repository contains C++ implementations of queue data structures and related test programs. The main focus is on understanding and manipulating queues using custom classes and memory management. The codebase is organized for educational purposes, with clear separation between interface (`queue.h`), implementation (`queue_vetor.cpp.cpp`), and usage/testing (`queue_teste.cpp.cpp`).

## Key Components
- `queue.h`: Declares the `Queue` class, including methods for enqueue, dequeue, checking if the queue is full/empty, and printing the queue. Uses `ItemType` (defined as `char` in `item_type.h`).
- `item_type.h`: Defines the type used in the queue (`typedef char ItemType;`).
- `queue_vetor.cpp.cpp`: Implements the `Queue` class with a circular buffer using dynamic memory allocation. Handles edge cases for full/empty queues and throws exceptions as strings.
- `queue_teste.cpp.cpp`: Provides a simple CLI for testing the queue. Reads a string from input, enqueues each character, then dequeues and prints them.

## Build and Run
- To compile all C++ files:
  ```sh
  g++ *.cpp
  ```
- To run the resulting executable:
  ```sh
  ./a.out
  ```
- The build process is simple and does not use CMake or other build systems. The output executable may be named `a.exe` or `a.out` depending on your platform.

## Patterns and Conventions
- All queue operations are performed via the `Queue` class. Do not manipulate the internal buffer directly.
- Exception handling uses string literals (e.g., `throw "Queue is empty!"`).
- The queue is implemented as a circular buffer using modulo arithmetic for indexing.
- Input/output is handled via standard streams (`cin`, `cout`).
- The code is intended for small-scale, educational use; there is no persistent storage or advanced error handling.

## Directory Structure
- Source files are in the root folder.
- Compiled executables are placed in the `output/` directory.
- No external dependencies or third-party libraries are used.

## Example Workflow
1. Edit or add queue logic in `queue.h` and `queue_vetor.cpp.cpp`.
2. Test changes by running `queue_teste.cpp.cpp`.
3. Compile and run as described above.

## Additional Notes
- If you add new queue types or features, follow the pattern of separating interface and implementation.
- Keep exception messages clear and use the same string-throwing convention for consistency.
- For new tests, create separate `.cpp` files and follow the CLI pattern in `queue_teste.cpp.cpp`.

---
If any section is unclear or missing details, please provide feedback so this guide can be improved for future AI agents.
