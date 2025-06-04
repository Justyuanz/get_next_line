# GET_NEXT_LINE

> A C function that reads and returns the next line from a file descriptor, one line at a time.

## About

`get_next_line` is a project from Hive Helsinki. The goal is to make a function in C that reads from a file or input and gives back one line each time, handling memory allocation and buffering without leaking or duplicating data. 

##  Features

- Return one line at a time from a file descriptor
- Handle reading with dynamic buffer
- Bonus: support multiple file descriptors
- Norm-compliant and leak-free

##  Project Structure

```
get_next_line/
├── get_next_line.h              # Header for mandatory part
├── get_next_line.c              # Core logic for mandatory part
├── get_next_line_utils.c        # Helper functions for mandatory part
├── get_next_line_bonus.h        # Header for bonus part
├── get_next_line_bonus.c        # Bonus logic with multi-FD support
├── get_next_line_utils_bonus.c  # Helper functions for bonus part
├── main.c                       # Test file for mandatory version
├── main_bonus.c                 # Test file for bonus version
└── testfiles/                   # Text files for testing
```
## Installation & Usage

```bash
# Clone the repository
git clone https://github.com/Justyuanz/get_next_line.git
cd get_next_line
```

### Compile 

```bash
# Mandatory version
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
./a.out

# Bonus version (multi-FD)
cc -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
./a.out
```
> 💡 Adjust `BUFFER_SIZE` depending on your testing needs. Try 1, 3, 42, 1000...

#### Run example

```bash
./a.out testfiles/normal.txt
```
#### Run with standard input (stdin)

```bash
./a.out
# Type your input line by line. Press Ctrl+D (EOF) to stop.
```

## Skills Learned

- Working with file descriptors and `open()` `read()` system calls
- Managing `static` memory and handling partial reads
- Dynamic memory allocation and safe string manipulation
- Respecting system limits (`ulimit`, file descriptor limits)
- Understanding how memory segments (stack, heap, BSS) affect program behavior
- Debugging memory issues and avoiding leaks with `valgrind` and `gdb`

## Example

### Read from a file
```bash
./a.out test.txt
```
> Output:
```
First line of test file
Second line of test file
Third line of test file
...
(null)
```


### Read from standard input
```bash
./a.out
```
Type lines like:
```
Hello there
This is a test
<Ctrl+D>
```

## Bonus: Read from multiple files

```bash
./a.out file1.txt file2.txt
```

```
[file1] First line of file 1
[file2] First line of file 2
[file1] Second line of file 1
[file2] Second line of file 2
...
(null)
```

