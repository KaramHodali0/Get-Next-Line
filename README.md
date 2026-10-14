
## Description

**Get Next Line (GNL)** is a project from the 42 curriculum that focuses on file descriptors, buffered reading, dynamic memory allocation, and static variables in C.

The goal of this project is to implement a function called `get_next_line()` that reads a file descriptor and returns one line at a time.

A line is returned whenever a newline character (`\n`) is encountered or when the end of the file is reached. The function must preserve the remaining data between calls so that the next call continues reading from where the previous one stopped.

The function must work with different file descriptors and handle various input sizes, including empty files, long lines, and files that do not end with a newline.

## Instructions

### Requirements

- A C compiler, such as `cc` or `gcc`.
- The standard C library.
- A Unix-like operating system.
- A valid `BUFFER_SIZE` value, which determines how many bytes are read in each call to `read()`.

### Compilation

Clone the repository and enter the project directory:

```bash
git clone <your-repository-url>
cd <your-repository-directory>
```

Compile the source files with your desired buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

Replace `42` with another positive buffer size to test different reading conditions.

Run the program:

```bash
./gnl
```

**Note:** Adjust the source filenames and compilation command to match the files included in your repository. The `main.c` file is only for testing and is not part of the required function implementation.

### Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

- `fd`: The file descriptor to read from.

### Return Value

- Returns a dynamically allocated string containing the next line, including `\n` if one was found.
- Returns the final line if the end of the file is reached before a newline.
- Returns `NULL` if there is nothing left to read or if an error occurs.

The returned line must be freed by the caller when it is no longer needed.

## Algorithm

### Overview

The algorithm reads input in chunks instead of reading the entire file at once. It stores data that has already been read but has not yet been returned, allowing the function to return exactly one line per call.

The implementation uses a persistent buffer, commonly called a **stash**, to preserve unread data between function calls.

### How It Works

1. **Initialize the reading buffer**

   Allocate a temporary buffer with `BUFFER_SIZE + 1` bytes. The extra byte is used to append the null terminator (`\0`) when treating the data as a C string.

2. **Read data**

   Use `read()` to read up to `BUFFER_SIZE` bytes from the file descriptor. Continue reading until a newline is found, the end of the file is reached, or an error occurs.

3. **Store the data**

   Append the newly read data to the stash. The stash retains data across calls, so unread characters are not lost.

4. **Extract a line**

   Find the first newline in the stash. If one exists, allocate a new string containing the characters up to and including that newline. If no newline exists, extract the remaining characters when the end of the file is reached.

5. **Preserve the remainder**

   Remove the returned line from the stash while keeping any characters that follow it. Those characters will be used by the next call to `get_next_line()`.

6. **Manage memory**

   Free temporary buffers and any allocated memory that is no longer needed. If an error occurs, handle allocations carefully to avoid memory leaks and invalid memory access.

### Why This Algorithm Was Chosen

This buffered approach is appropriate because `read()` does not guarantee that a complete line will be returned in a single call. A line may be shorter or longer than `BUFFER_SIZE`, and multiple lines may be read into the buffer at once.

The stash solves this problem by separating the amount of data read from the amount of data returned. It allows the function to return one line at a time without discarding unread characters.

A static variable makes it possible to preserve the stash between calls without requiring the caller to manage the internal reading state.

The algorithm also supports different buffer sizes, making it possible to test the implementation under different reading conditions.

## Features

- Reads one line per function call.
- Supports configurable `BUFFER_SIZE`.
- Handles lines longer than the reading buffer.
- Preserves unread data between calls.
- Handles files that end without a newline.
- Uses dynamic memory allocation to construct returned lines.
- Returns `NULL` when no further line can be returned or when an error occurs.
