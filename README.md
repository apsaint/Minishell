							# Minishell #
Through the Minishell project, you will get to the core of the Unix system and explore
an important part of this system’s API: process creation and synchronisation. Executing
a command inside a shell implies creating a new process, which execution and final state
will be monitored by its parent’s process. This set of functions will be the key to success
for your Minishell, so be sure to code the cleanest, simplest program possible.

						     ##### Road Map #####

# DAY 01 #	
	- Starting the shell loop(base) (DONE)
	- studying new functions offered by the project (DONE)

# DAY 02 #
	- Initialization and copy of env variables (DONE)
	- Implementation of struct for environmment variables (DONE)

# DAY 03 #
	- Initialization of builtin cd and echo (IN PROGRESS)
	- Implementation of builtin of env (DONE)
	- Leak checks (DONE)

# DAY 04 #
	- Finishing environnement variables management:
		* Function add new env var (DONE)
		* Function del env var (DONE)
		* Function env (DONE)
	- Readapt main function: use execute_switch (DONE)
	- Norme the functions already done (IN PROGRESS)
	- Review gnl function (IN PROGRESS)

# DAY 05 #
	- Finish all todo and in progress post above (IN PROGRESS)
	- Implementing the shell exit properly (IN PROGRESS)
	- Studying error prompt (IN PROGRESS)

# DAY 06 #
	- Implementing free function for the char **cmd and input (DONE)
	- Implementing switch command function (DONE)
	- Starting function for executable within PATH (DONE/TO BE TESTED)

# DAY 07 #
	- Clean project: reposition functions (DONE)
	- Implementing final main function (DONE)
	- Valgrind full test for leak and clear all error and leaks (DONE)
	
# DAY 08 #
	- Implement flag for all builtin functions (TODO)
	- Add $, ~ and "" management (TODO)
	- Implement signal handler (TODO)

# DAY 09 #
	- Solve valgrind error gnl (IN PROGRESS)
	- Redo Libft makefile (TODO)
