# ft_gc
*A simple garbage collector simulation for C programs.*

---

## ✨ Overview
`ft_gc` provides a wrapper around `malloc` that automatically tracks all allocated pointers in a linked list.  
This allows you to free everything at once, or free specific allocations when needed.  
It’s useful for preventing memory leaks in C projects (e.g., 42 school exercises).

---

## ⚙️ How It Works
- Every call to `gc_malloc(size)`:
  - Allocates memory using `malloc`.
  - Stores the pointer in a linked list of tracked allocations.
  - Returns the pointer back to the user.

- When freeing:
  - `gc_free_all()` frees **all allocations** tracked by the GC.
  - `gc_free(ptr)` frees a **specific pointer** and removes it from the list.

- Allocations are tracked in a **stack-like order** (last allocated → freed first),  
  which ensures that in cases like arrays + members, the members are freed before the array itself.

---

## 🚀 Usage

### 1. Initialize the GC
Before using `gc_malloc`, you must create the GC context:

```c
init_gc(malloc(sizeof(t_gc)));
