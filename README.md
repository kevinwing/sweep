## About
This is our final project for CS151 at North Idaho College. We have created our own version of the 
classic Minesweeper game. The board is represented using a 2-dimensional vector of a Cell class object.
To handle each cell click event we employed recursion to expand out from the cell which was clicked in
order to determine the state of the surrounding cells and update the board based on the current state
of each individual cell.

### Installation
##### Prerequisites
You need to have gcc, git and sfml installed

##### Step 1
```
git clone https://github.com/kevinwing/sweep.git
```

##### Step2
```
cd path/to/repo
```

##### Step 3
```
make
```

##### Play
```
./bin/main
```

### Contributors
* Kevin Wing: https://github.com/kevinwing
* Caleb Simmons: https://github.com/GlacialStalke
* Connor McElroy: https://github.com/connor-mcelroy

### Future
These are some ideas for features to implement in the future.

* Win/lose animation
* Custom board dimensions/mine count
* Timed game mode with predefined board settings

If you have any other ideas feel free to message one of us with the idea.
Thanks for checking out our project!
