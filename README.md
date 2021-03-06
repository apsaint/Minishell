							# Minishell #
Through the Minishell project, you will get to the core of the Unix system and explore
an important part of this system’s API: process creation and synchronisation. Executing
a command inside a shell implies creating a new process, which execution and final state
will be monitored by its parent’s process.

Builtins: echo, cd, env, setenv, unsetenv and exit.

Bonus: <br />
- Signals handlers (Ctrl + C and Ctrl + D) <br />
- ';' for multiple commandes<br />
- Check the rights to every executable called (user rights in Path) <br />
	
****************************************************************************************************************************
						    
						    ##### Road Map #####

# DAY 01 #	
	- Starting the shell loop(base) (DONE)
	- studying new functions offered by the project (DONE)

# DAY 02 #
	- Initialization and copy of env variables (DONE)
	- Implementation of struct for environmment variables (DONE)

# DAY 03 #
	- Initialization of builtin cd and echo (DONE)
	- Implementation of builtin of env (DONE)
	- Leak checks (DONE)

# DAY 04 #
	- Finishing environnement variables management:
		* Function add new env var (DONE)
		* Function del env var (DONE)
		* Function env (DONE)
	- Readapt main function: use execute_switch (DONE)
	- Norme the functions already done (DONE)
	- Review gnl function (DONE)

# DAY 05 #
	- Finish all todo and in progress post above (DONE)
	- Implementing the shell exit properly (DONE)
	- Studying error prompt (DONE)

# DAY 06 #
	- Implementing free function for the char **cmd and input (DONE)
	- Implementing switch command function (DONE)
	- Starting function for executable within PATH (DONE)
	
# DAY 07 #
	- Clean project: reposition functions (DONE)
	- Implementing final main function (DONE)
	- Valgrind full test for leak and clear all error and leaks (DONE)
	
# DAY 08 #
	- Implement flag for all builtin functions (DONE)
	- Add $, ~ management (DONE)
	- Implement signal handler (DONE)

# DAY 09 #
	- Solve valgrind error gnl (DONE)
	- Redo Libft makefile (DONE)

# DAY 10 #
	- Rewrite of input read function (DONE)
	- Delete gnl and check leak (DONE)

# DAY 11 #
	- Implement env builtin with flag (DONE)
 	- Check libft (DONE)
	- Finish flag for cd builtin (DONE)
	
# DAY 12 #
	- Check pipe and file input (DONE)
	- Regulate Shell level env (DONE)
	- Regulate exec of name similar to existing executable (DONE)
