# Multifunction C++ Calculator

## 🔢 Overview

This is a console-based C++ calculator that supports four main functionalities:

1. **Basic Arithmetic Calculator**
2. **Scientific Calculator**
3. **Complex Number Calculator**
4. **Coordinate Geometry / Vector Calculator**

The project demonstrates principles of object-oriented programming (OOP) including class inheritance, dynamic memory allocation, and modular code design. It also handles edge cases such as division by zero, invalid trigonometric inputs, and dimension mismatches in vectors.

---

## 🧠 Features

### 1. Basic Calculator
- Addition, Subtraction, Multiplication, Division
- Input validation for division by zero

### 2. Scientific Calculator
- `sin(a)`, `cos(a)`, `tan(a)`
- `cosec(a)`, `sec(a)`, `cot(a)`
- Inverse trigonometric functions: `sin⁻¹`, `cos⁻¹`, `tan⁻¹`, etc.
- `ln(a)` and logarithm of any base `logₐ(b)`
- Power operation `a^b`

### 3. Complex Number Calculator
- Complex number input in form `a + bi`
- Addition, Subtraction, Multiplication
- Conjugate
- Square, Cube
- Magnitude and Argument (in radians)

### 4. Coordinate Geometry (Vector Calculator)
- Works for **n-dimensional points**
- Addition, Subtraction of vectors
- Distance between two vectors
- Magnitude of a vector
- Angle between two vectors (in radians)
- Handles **dimension mismatches** gracefully

---

## 💻 How to Run

1. Compile using a C++ compiler like `g++`:
   ```bash
   g++ calculator.cpp -o calculator

2. Run the executables
   ./calculator

