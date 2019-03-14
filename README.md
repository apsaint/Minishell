							# Minishell #
Through the Minishell project, you will get to the core of the Unix system and explore
an important part of this system’s API: process creation and synchronisation. Executing
a command inside a shell implies creating a new process, which execution and final state
will be monitored by its parent’s process. This set of functions will be the key to success
for your Minishell, so be sure to code the cleanest, simplest program possible.

						##### Road Map #####

# Day 01 #	
	- Starting the shell loop(base) (DONE)
	- studying new functions offered by the project (DONE)

# Day 02 #
	- Initialization and copy of env variables (DONE)
	- Implementation of struct for environmment variables (DONE)

# Day 03 #
	- Initialization of builtin cd and echo (IN PROGRESS)
	- Implementation of builtin of env (IN PROGRESS)
	- Leak checks (DONE)

# Day 04 #
	- Finishing environnement variables management:
		* Function add new env var (DONE)
		* Function del env var (DONE)
		* Function env (TODO)
	- Readapt main function: use execute_switch (TODO)
	- Norme the functions already done (TODO)
	- Review gnl function (TODO)

# DAY 05 #
	- Finish all todo and in progress post above
	- Implementing the shell exit properly (TODO)
	- Studying error prompt (TODO)
