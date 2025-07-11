# 🧮 Advanced Multi-Functional Calculator in C++

## 🔧 Description

This is a C++ console application that functions as an all-in-one calculator. It covers multiple domains of mathematics:

1. **Basic Arithmetic Calculator**
2. **Scientific Calculator**
3. **Complex Number Calculator**
4. **Coordinate Geometry / Vector Calculator**  
   ➕ **Now with Dot Product & Cross Product**

---

## 🛠️ Features

### 🔢 1. Basic Calculator
Performs standard arithmetic operations:
- Addition
- Subtraction
- Multiplication
- Division (with zero-division error handling)

### 🧪 2. Scientific Calculator
Supports functions such as:
- Power (a^b)
- Trigonometric functions (sin, cos, tan, cosec, sec, cot)
- Inverse trigonometric functions (sin⁻¹, cos⁻¹, tan⁻¹, etc.)
- Natural log (ln)
- Logarithm with custom base

### 🔁 3. Complex Number Calculator
Supports operations on complex numbers:
- Addition
- Subtraction
- Multiplication
- Conjugate
- Square & Cube
- Magnitude
- Argument (angle in radians)

### 📍 4. Coordinate Geometry / Vector Operations
Handles n-dimensional points:
- Magnitude of a vector
- Vector addition & subtraction
- Distance between two points
- Angle between two vectors (in radians)
- ✅ **Dot Product**
- ✅ **Cross Product** *(only in 3D)*

---
📂 Code Structure
simple_calculator → Base class for arithmetic operations.

scientific_calculator → Inherits from simple_calculator, adds trig/log functions.

complex → Class for complex number calculations using friend functions.

point → Class for vector/coordinate operations with dynamic memory.

---

📈 Skills Demonstrated
Object-Oriented Programming in C++

Class Inheritance & Friend Functions

Math/Scientific Computation

Trigonometry & Linear Algebra Basics

Dynamic Memory Management

Console Interaction and Output Formatting

---

📘 Notes
Cross product works only for 3D vectors.

Dimensions must match for dot product, angle, distance, etc.

Inputs must be valid; some mathematical domain checks are implemented

---


## 💻 How to Use

1. **Compile the code using a C++ compiler**:
   ```bash
   g++ calculator.cpp -o calculator
   ./calculator
