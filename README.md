<h1 align="center">
	🚀 push_swap
</h1>

<p align="center">
	<b><i>Sorting integers with limited stack operations - 42 School project</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/TiagoDev88/push_swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/TiagoDev88/push_swap?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/TiagoDev88/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/TiagoDev88/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/TiagoDev88/push_swap?color=green" />
</p>

<h3 align="center">
	<a href="#-about">About</a>
	<span> · </span>
	<a href="#-algorithm">Algorithm</a>
	<span> · </span>
	<a href="#-usage">Usage</a>
	<span> · </span>
	<a href="#-bonus">Bonus</a>
	<span> · </span>
	<a href="#-author">Author</a>
</h3>

---

## 💡 About

> _push_swap is a project from 42 School that challenges you to sort a list of integers using two stacks and a limited set of operations, minimizing the total number of moves._

The program takes a list of integers as input and outputs a sequence of instructions to sort them in ascending order.

---

## ⚙️ Algorithm

The solution implements a **chunk-based sorting method** using the following approach:

- Assign an **index** to each number according to its sorted position.
- Divide the input stack into **chunks** (groups of elements).
- Move elements from stack `a` to stack `b` chunk by chunk:
  - If the element's index is the current target `i`, push it to `b` and rotate `b` (`rb`) to position smaller elements at the bottom.
  - If the element's index is within the current chunk but not equal to `i`, just push it to `b` (`pb`).
  - Otherwise, rotate stack `a` (`ra`) to find suitable elements.
- Once all elements are in `b`, move them back to `a` in sorted order with minimal operations.

This strategy optimizes the number of operations, especially for inputs up to 500 numbers.

---

## 🛠️ Usage

### Requirements

- GCC compiler
- Make

### Instructions

**1. Clone the repository**

```bash
git clone https://github.com/TiagoDev88/push_swap.git
cd push_swap
```

**2. Compile**
```bash
make
```

**3. Run**
```bash
./push_swap 3 2 5 1 4
```
The program outputs the sequence of stack operations (sa, pb, ra, etc.) needed to sort the list.

## 🎁 Bonus - checker

The bonus program checker reads the same list of integers, then reads a sequence of instructions from standard input and verifies if after applying those instructions, the stack is sorted.

**Usage example:**
```bash
./push_swap 5 1 4 3 2 | ./checker 5 1 4 3 2
```
If the instructions sort the list correctly, checker outputs:

```bash
OK
```

Otherwise, it outputs:

```bash
KO
```

## 👤 Author
42 login: tfilipe-

GitHub: @TiagoDev88