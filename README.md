# 🔢 Arbitrary Precision Calculator in C

This project implements an **arbitrary-precision arithmetic calculator** in C using **Abstract Data Types (ADTs)** like **doubly linked lists**. Unlike traditional arithmetic limited by fixed-size integer types, this calculator can perform operations on numbers of *any length*, limited only by the available system memory.

---

## 📘 What is Arbitrary Precision Arithmetic?

Arbitrary (or multiple) precision arithmetic handles extremely large numbers by storing them as a sequence of smaller chunks (digits or groups of digits) in memory. This allows calculations with:
- Hundreds or thousands of digits
- Decimal support
- Cryptographic-sized integers  
It contrasts with standard arithmetic which is limited to 32/64-bit data types.

---

## 💡 Use Cases

- 🔐 **Cryptography** (e.g., RSA, ECC algorithms with 1024+ bit integers)  
- 🧮 **Scientific computations** involving very large/small values  
- 🧠 **Learning tool** to understand ADTs, memory management, and algorithm optimization

---

## ✨ Features

- 🧩 Handles **big integers and decimals**  
- ➕ Mathematical operations supported:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Modulus (%)
  - Power (^)
- ♻️ Optimized handling for special cases:
  - Inputs with zero
  - Carry/borrow management
  - Skipping unnecessary computation
- 🛠️ Portable: Slicing based on `sizeof(int)` for platform independence

---

## 🧰 Tech Stack

- **Language:** C  
- **Data Structures:** Doubly Linked List  
- **Concepts:** Abstract Data Types, Memory Management, Arithmetic Algorithms  

---

## 🧪 Sample Algorithm Highlights

- **Input Parsing**: Slices each input number and stores across nodes  
- **Computation Engine**: Operates on lists, handles carry/borrow, produces a result list  
- **Output Formatting**: Traverses result list to print final output correctly  
- **Zero Handling Optimization**:  
  - If `Num1 = 0` and `Num2 = x` → Output = x  
  - If both are 0 → Output = 0  

---

## 📁 Project Structure

