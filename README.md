
## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates.

- The programs should not produce any zombie processes.

- The programs have to be documented!



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


