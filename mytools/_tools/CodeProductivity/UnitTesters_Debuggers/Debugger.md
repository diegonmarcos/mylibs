## 1. VS CODE 
	Debugging .launch
``` json
// This file is used to configure the debugger for C++ in Visual Studio Code

  {
    "version": "0.2.0",
    "configurations": [
	  {
		"name": "Launch",
		"type": "lldb",
		"request": "launch",
		"program": "${fileDirname}/a.out",
		//"args": ["-arg1", "-arg2"],
		"reverseDebugging": true,
		//"preLaunchTask": "build",
		//"stopAtEntry": true,
		"settings": {
 		   "lldb.var-display": "all-values" 
		},
	}
    ]
  }
```
## 2. LLDB 
	Debugging Commands (42 Common Core)

**Compilation (gcc):**

Bash

```
cc ft_fun.c -g3  # Compile with debugging symbols (-g)
```

**Debugging (lldb):**

Bash

```
lldb a.out       # Start LLDB and load the executable 'a.out'
```

**Breakpoints:**

Bash

```
b main          # Set a breakpoint at the start of the 'main' function
b <function_name> # Set a breakpoint at any other function
```

**Execution:**

Bash

```
run             # Start running the program (or 'r' for short)
c               # Continue execution after hitting a breakpoint
```

**Stepping Through Code:**

Bash

```
s               # Step over the current line (execute it as one step)
n               # Step into the next line (enter functions if called)
```

**GUI Mode:**

Bash

```
gui             # Launch the LLDB graphical user interface (full screen)
```

**Viewing Variables:**

Bash

```
p <variable_name>  # Print the current value of a variable
v                # View all local variables (useful after hitting a breakpoint)
```

**Additional Tips:**

- Use the `Tab` key for autocompletion of commands and file names.
- `help` in LLDB provides a list of available commands and their descriptions.
- Refer to the LLDB documentation for more advanced features and debugging techniques.

**Example Workflow:**

1. Compile your code with the `-g` flag to include debugging symbols.
2. Start LLDB and load your executable.
3. Set breakpoints at relevant locations (e.g., `main` function, specific lines).
4. Run the program and use `s` and `n` to step through the code.
5. Inspect variables using `p` and `v` as needed.
6. Continue execution or set new breakpoints as required.

Let me know if you'd like any further refinements or have more questions!  
  
## 3. Valgrind

``` bash
cc -Wall -Wextra -Werror -g3
```


``` bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
```

## 4. Asan

``` bash
gcc -fsanitize=address -g3 -O1 my_program.c
```

``` bash
./a.out
```

## Others
### Vimspector  
un sistema de depuración gráfico multi-idioma para Vim1. Vimspector está probado principalmente para C++, Python y TCL, pero en teoría soporta cualquier lenguaje que Visual Studio Code soporte1.

Para comenzar a depurar con Vimspector, necesitarás instalar el plugin y configurar un archivo .vimspector.json para tu proyecto. La página de GitHub de Vimspector ofrece una guía detallada y ejemplos de cómo configurar y utilizar el plugin para la depuración1.  

### TermDebug. 
 que funciona tanto con Vim como con Neovim y es bastante útil para la depuración de C y C++2. También puedes compilar tu código C con símbolos de depuración usando la bandera -g para facilitar el proceso3.



