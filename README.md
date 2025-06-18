# CalendarProject

A simple console-based calendar application written in C for Windows. It displays a month view of the calendar in the console window and allows the user to navigate through months and years using the arrow keys.

>This README describes features and how to build & use the program.n.

---

## Features

- Displays a month calendar for a given month and year in the console.  
- Navigation via arrow keys:
  - Left/Right arrows to move between months (handling year rollover).  
  - Up/Down arrows to increase or decrease the year.  
- Highlights or prints days in a grid aligned under weekdays (Sunday through Saturday).  
- Automatically handles leap years.  
- Clears and redraws the calendar on each navigation action.  
- Uses Windows console functions (`windows.h`) for cursor positioning.  

---

## Prerequisites

- **Operating System:** Windows  
- **Compiler / IDE:**  
  - Microsoft Visual Studio (any recent version supporting C/C++).
  - Code::Blocks is appreciable.
  - Or a Windows-compatible C compiler such as MinGW GCC (with support for `<windows.h>` and `<conio.h>`).  
- **Console:** A typical Windows Command Prompt or PowerShell window. Ensure it is sized adequately so the calendar grid is fully visible.  
- **Permissions:** No special permissions; a normal user account is sufficient.

---

## Directory Structure

just a single file is enough to build and run the application.

