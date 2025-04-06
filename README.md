# Embeddded_Linux

# Pico Shell

A simple shell that supports:
- Built-in commands: `echo`, `pwd`, `cd`, `exit`
- Execution of external programs using `fork` and `execvp`
- Command parsing with dynamic memory allocation
- Safe and modular code with error handling

---

## 🧪 How to Compile

```bash
gcc -o pico-shell src/*.c
