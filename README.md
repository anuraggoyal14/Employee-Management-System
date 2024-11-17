# Employee Management System

## Overview
The **Employee Management System** is a console-based application implemented in C++ that allows the management of employees in an organization. It provides functionalities for managing two types of employees: Visiting Employees and Permanent Employees. The system supports adding, retrieving, updating, and deleting employee records, along with salary calculations, leave management, and increments.

## Features
- **Employee Types**:
  - **Visiting Employees**: Temporary employees paid based on daily wages.
  - **Permanent Employees**: Employees with a fixed monthly salary.

- **Core Functionalities**:
  1. Add new Visiting or Permanent employees.
  2. Retrieve information by employee ID.
  3. Display information of all employees.
  4. Apply salary increments.
  5. Remove (fire) an employee.
  6. Adjust salary based on leaves taken.

- **Salary Calculation**:
  - Daily wages for Visiting Employees.
  - Monthly salary for Permanent Employees.

- **User-friendly Console Interface**:
  - Intuitive menus to navigate and manage employees.
  - Input validation to handle incorrect user inputs.

## Code Structure
The project is implemented using Object-Oriented Programming (OOP) principles. It uses:
- **Base Class**:
  - `Employee`: Abstract class that serves as a base for all employee types.
- **Derived Classes**:
  - `VisitingEmp`: Handles details and operations for visiting employees.
  - `PermanentEmp`: Handles details and operations for permanent employees.

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/anuraggoyal14/employee-management-system.git
