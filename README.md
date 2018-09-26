
## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates.

- The programs should not produce any zombie processes.

- The programs have to be documented! Any file that you edit should have preamble including
your name as the author, description of the purpose of the program and inline comments
in the functions that you implement.
- The code has to follow C programming conventions.
- The code has to be formatted properly.
- The C code has to look like a high level programming language.

In addition, you are required to make at least 5 commits to your repository.
Each time you make a significant change/improvement to your solutions, you
should commit and push the changes to the remote repository. This way, if there
are any problems with your local copy of the files, you have a recent version of
the code available. Your commits should be distributed over time - they should
not be all made within an hour before the due date.



## Problem 1
Write a program called `list_home`. When a user executes this program it should
display the content of their home directory regardless of the actual
working directory.

Running your program should produce results equivalent to running `ls -l ~`,
except your program should not expect any command line arguments.



 

## Problem 2

Write a program called `remind_me`. This program will print a message on the console after a specific number of seconds elapses.

The program's syntax and description is as follows:

```
remind_me   time   [ message-text ]
```

__Description:__

The `remind_me` command displays the `message-text` on the user’s console after at least the integral number of seconds specified by the `time` operand.  The `remind_me` command displays the process-id of the background process that it creates to keep track of the time and returns immediately to the shell to allow the user to continue doing other tasks.

__Operands:__

The following operands are supported:

`time`	A non-negative number of minutes to delay before displaying the `message-text` on the console.

`message-text`	A possibly empty text string of unlimited length. (This string
  may or may not be enclosed in quotes. )

 __Examples:__

 ```
 $ ./remind_me 10 hello earthlings!
 ./remind_me process-id 4471
 $ ls
 total 236
 drwxrwxr-x  2 asia asia  4096 Apr 23 17:37 .
 drwxrwxr-x 10 asia asia  4096 Apr 23 16:47 ..
 ...

 //user continues working

 //10 seconds later

 hello earthlings!

 $

 ```

 ```
 $ ./remind_me 360 "time to go to class!"
 ./remind_me process-id 6616
 $ // user continues working
  ...

  // 10 minutes later

  time to go to class!

  $

 ```
(Note that the user may need to hit the "Enter" key for the prompt to be redisplayed after the message is shown.)

__Restrictions:__

- Your program is not allowed to use the `sleep()` function.
- The program should return control of the terminal back to the user as soon as possible (not only after the message is printed).
- Your program should not create any zombie processes.

__Useful functions:__

`alarm` - arranges for a `SIGALRM` signal to be delivered to the calling process in
 the specified number of seconds. Read the manual page (`man alarm`) for
details on how to use it.

You also will need to use `pause`, `fork` and `signal` calls.



__Your program should be implemented in the file called `remind_me.c`.__
