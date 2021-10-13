<!-- GETTING STARTED -->
## My_Mouse

### Task Description

Walk in a labyrinth :
◦ This project is about finding the shortest path between entering and leaving

a labyrinth while avoiding obstacles.

◦ A maze is given to you in a file to be passed as an argument to the program

(Maze generator in Appendix).
◦ The first line of the labyrinth contains the information to read the map:

∗ The number of labyrinth lines then the number of columns (LINExCOL);

∗ The "full" character

∗ The "empty" character

∗ The character "path"

∗ The character "entered labyrinth"

∗ The character "exit labyrinth".

◦ The maze is composed of "empty" characters, "full" characters, characters "entering the labyrinth" and characters "exiting the labyrinth".

◦ The purpose of the program is to replace "empty" characters with "path" characters to represent the shortest way to cross the labyrinth.

◦ Movements can only be horizontally or vertically, not diagonally.

◦ In the case where several solutions exist, one will choose to represent the shortest one. In case of equality, it will be the one whose exit where the solution is the most up then the leftmost. If there are 2 solutions for the same output, when crossing from the start we will choose the solutions in this order: up> left> right> down

So if you have a choice between going up or right, you have to take the solution
that goes up.

◦ Definition of a valid map :

∗ All lines must respect the sizes given in the first line (LINExCOL).

∗ There can only be one entrance.

∗ There must be at least one exit and only one.

∗ There must be a solution to the labyrinth.

∗ The labyrinth will not be more than a thousand square.

∗ At the end of each line, there is a new line.

∗ The characters present in the map must be only those shown on the first
line.

∗ If there is an invalid map, you will see the error output: MAP ERROR followed by a new line. The program will then proceed to the next labyrinth
treatment.

* Exit(s) will always be located on "outside walls"


### Requirements


1. you must create a Makefile, and the ouput is the command itself
2. You must not use a Brute Strength solution!
3. Parsing is not to be done with a read() of 1


### Program Usage

1. From the terminal move to my_mouse directory and run the generate_map.rb ruby script with the following command using whatever x + y dimensions you want and followed by "* o12" (this sets the edges and obstacles as * and the start and exit as 1 and 2 respectively. 

   ```sh
   ruby map/generate_map.rb [x] [y] "* o12" > [filename].[map/txt]
   e.g 'ruby map/generate_map.rb 50 20 "* o12" > map/01.map'
   ```
2. Compile the C program by typing 'make' into the terminal and run the program from terminal with the program name followed by the filename of your generated map

   ```sh
   e.g './my_mouse map/01.map'
   ```
3. Your map will be printed with the map parameters above in the terminal with o's denoting the shortest path through the map and below it the number of steps it took.

   ```sh
   10x10* o12
   **1*******
   * o    * *
   * o*   ***
   * oo   * *
   *  o*    *
   *  oo    *
   * * o    *
   *   o  * *
   *** o  ***
   ****2*****
   10 STEPS!
   ```
4. In the case of wrong map file type input or a map without the correct dimensions descriptor at the first line (e.g if not this format "100x100* o12") error messages will be displayed notifying the user. 
 
5. You can clean up '.o' files by typing the following command after usage
    ```sh
   'make clean'
   ```
   


