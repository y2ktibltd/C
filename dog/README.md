# DOG (An alternative to 'cat | grep')
## Video Demo:  <https://youtu.be/JUvjoPgYUDk>
## Description: A C-based program to print out file contents along with formatting and search functionaility

I started my programming journey using VIM and trying to learn Python. Python is very specific about tabs vs spaces in the formatting of the document. I was unable to see in VIM or in terminal where the spacing was wrong and this caused me to have multiple issues on working with my own code or other users code pulled from github. I decided to create a program in C that will show all document formatting (tabs, spaces, newlines, returns, etc, etc) so I could pick out the issue and resolve it. My initial code only showed newlines and tabs and didnt account for counting of spaces, returns or the ability to search within the file for text. Using what I learned at my courses on CS50 i was amble to implement my own struct and devise logic to search within strings for subtrings.

I decided to make this a command line program since I primarily work in the terminal on my linux machines. This flexibility means I can compile the code and run it across my platforms at home in my lab. Being able to SSH into a server and utilize the same functionality was alsoa key reason I decided to make this program in C for use with the terminal.

I had to research several things that were not covered in CS50's course to complete this project. I was able to look up and implment ANSI color codes on terminal ouptu via printf. I was able to define my own struct and then use it across externally defined functions and header files. I was able to parse strings into smaller sections then create terminating '\0' characters so C would know where the string ended.

My biggest challenge was keeping all the code clean, easily readable and logical so that a lay person would be able to peruse and make modification of their own if need be. I included several comments for the start of each function or loop explaining in detail what happens inthat particular section of code. This will, hopefully, not only help future revisions of this code but also helped me tremendously when troubleshooting certain features that were difficult to implement.


# Files and their uses....

dog.c: This file contains the main program loop, variables, file opening, argv parameters and struct that will contain all of the items I wanted to count in the output. Once this file got over a couple hundred lines I decided to split the larger individual functions out into their own respective c and header files. The file will take argv[1] as input to open a file and read each individual line into a string variable that then gets passed through several functions before printing the results on the screen. At the end it will ouput all the counts of each formatting modifier and character from the count struct and print those totals to the screen.

dog.h: This file contains all the macros associated with dog.c. Mostly these are variables that I wanted to be consistent across the program like temrinal color codes.

is_substring.c: This file contains the logic to search the individual lines sent from dog.c for the search terms, if any, that were used when calling the program from the command line. This program will return a true or false value based on that search.

is_substring.h: this file contains function declarations and any macros needed from main dog.c program.

print_line.c: This file takes the input from dog.c as a line from the file being read and uses logic to detemine if the searched for keyword is found inside the line in any position(s). If found it will put the text in RED to help it show up in the terminal better. This function also updates the variables inside the struct defined in dog.c and tallies them based on the number of occurances as each line is being printed individually.

print_line.h: this file contains macros and function delarations for its related c file.


!!SCREENSHOT!!

![Alt text](./screenshot.png?raw=true "Screenshot")