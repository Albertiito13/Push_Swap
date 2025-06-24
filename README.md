# PUSH_SWAP

Sorting algorithm challenge using two stacks and limited operations (42 Madrid project).

## 📦 Requirements

- Linux or macOS  
- make, gcc  

---

## 🚀 Installation & Compilation

    git clone https://github.com/Albertiito13/Push_Swap.git
    cd Push_Swap
    make

🏁 Usage

    ./push_swap [numbers...]

Example:

    ./push_swap 3 1 2 4 5

🔧 Allowed Operations

  sa, sb, ss – swap top 2 elements of stack A, B, or both

  pa, pb – push top element from B to A or A to B

  ra, rb, rr – rotate stacks A, B, or both up by one

  rra, rrb, rrr – reverse rotate stacks A, B, or both down by one

🎯 Goal

  Sort all integers in ascending order in stack A

  Stack B must end empty

  Use the minimal number of operations possible

🧠 How It Works

  Initialize stack A from command-line inputs; start with stack B empty.

  Select an efficient sorting strategy (e.g., recursive quicksort on stack segments).

  Use push, swap, rotate operations to sort numbers.

  Print each instruction to stdout, one per line.

  Validate correct sort with minimal operations.

✅ Good Practices

  Check and handle errors (invalid numbers, duplicates, etc.)

  Manage memory and close resources properly

  Test with edge cases: single number, already sorted, reverse order

🧪 Example

    ./push_swap 2 1 3  
    # Output could be:
    sa
