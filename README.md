## UNID-SYSTEM

This is the README file for Unid-System 1.0.1.


Unid system represent a mini operating system made in C language, using dynamic programming. 
This system has its own shell for interpreting commands. Thus a user can work with files 
and directories on the command line.Thus, certain tasks can be automated and become much more efficient.
The system also offers various tools needed by any user and a series of games.

Download and Test:
```
https://github.com/dinuionica/Unid-system.git
```


On Linux:

```
$ make && ./unid_system
```

On Mac:

```
$ open unid_system.c
```

On Windows:

```
$ gcc -o unid_system && ./unid_system
```

The command line interface is quite intuitive, the user will have to enter commands 
that the shell will interpret and execute. The use of dynamic programming gives a plus
to this project because the execution is very fast and the memory is dislocated at the end.

A summary of a few commands:
```
ls [path] -> to list of file and directories of a path
cd [path] -> to cd a path
rmf [filename] -> to delete a file
rmd [directory_name] -> to delete a directory
mkf [filename] -> to make a file
rnm [old_filenmae][new_filename] -> to rename a file
users -> to display all users of system
head [filename] [number_lines] -> to display the first number_lines of a filename
tail [filename] [number_lines] -> to display the last number_lines of a filename
code -> to open the code editor
quiz-game -> to open a quiz game with capitals of countrys
exit -> to stop the program
and more
```

## Login/Singup
For authentication a user must have an account with username and password.
After this registration is done successfully for each user a path will be created
with his name and a series of files and directories. Everything the user will execute
will be executed in his own path. The user's words are kept in the system in a encrypted form.

![alt text](https://user-images.githubusercontent.com/51510817/109278366-72f87100-77e6-11eb-9422-906c345d8cf1.jpg)

# Copyright 2021 Dinu Ion-Irinel
MIT License<br>
   Copyright 2021 Dinu Ion Irinel <br>
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights 
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
