The repository link for review:
https://github.com/hosseinakbari84/HW1#



# University Restaurant Order Management System

This project is a console-based restaurant order management system for a university, written in C++.  
The main features include registering new orders, displaying the menu, modifying orders, canceling orders, and saving orders to a file.

---

## Quick Start

### Prerequisites
- C++ compiler (g++ recommended, supporting C++11 or later)
- VS Code with C/C++ extension or any other C++ IDE

### Build and Run on Ubuntu/Linux

1. Open a terminal and navigate to the project folder:

```
cd /path/to/your/project
```

2. Compile all `.cpp` files:

```
g++ -g -o main.out *.cpp
```

3. Run the program:

```
./main.out
```

---

### Build and Run on Windows (using MinGW)

1. Install MinGW and add it to your system PATH.  
2. Open Command Prompt or PowerShell and go to the project folder.  
3. Compile all `.cpp` files:

```
g++ -g -o main.exe *.cpp
```

4. Run the program:

```
.\main.exe
```

---

## Additional Notes

- Orders data is saved in the `orders.txt` file and loaded automatically on program start.  
- Console output uses color coding for better readability (e.g., green for completed orders, red for canceled orders).  
- The project is organized with multiple source and header files following standard C++ practices for better maintainability.  
- For detailed documentation, see source code comments and individual class files.

---

This program helps you manage restaurant orders in a simple console environment.
Main Menu Options:

    1. Show Menu
    Displays the list of available food items with prices.

    2. New Order
    Allows you to create a new order:

        Enter your student information (name and ID).

        Select food items from the menu and specify quantity.

        Review and confirm your order.

    3. Order Delivered
    Mark an existing order as completed/delivered.

    4. Cancel Order
    Cancel an existing order by providing its ID.

    5. Change Order
    Modify items or quantities in an existing pending order.

    6. Show My Orders
    View all your active orders with status.

    7. Review All Orders
    Display all orders currently managed by the system.

    8. Save Orders
    Manually save all current orders to the file (orders.txt).
    (Note: The program automatically loads saved orders on startup and you should save before exit.)

    0. Exit
    Close the program safely.

How to Order:

    Choose option 2 from the main menu (New Order).

    Provide your name and student ID (**It must be eight digits.**).

    Choose items you want to order by their menu number and specify quantity, repeat as needed.

    Confirm your order to add it to the system.

Important Notes:

    Orders can only be changed or canceled if they have not been marked as Delivered.

    Orders are saved to a text file so they persist between program runs.

    Order statuses are color-coded for quick identification:

        Completed orders shown in green

        Canceled orders shown in red

If you have further questions or encounter issues, please refer to the source code comments or contact the author.

## Contact

If you have questions or need assistance, feel free to contact the author.

---