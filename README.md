# Elevator2
This repository contains the first school project I made using C. It simulates an elevator inside your command prompt.

# Usage
I recommand using Ubuntu for this, you may need to install C headers with the following command :

  `sudo apt-get install ncurses.h libncurses-dev`

Then simply type `make run` and the simulation will begin.

Each person using the elevator is represented by two digits, the first one being his/her original floor and the second being their destination floor. Just type any number from 0 to 4 to make the elevator reach the given floor, the elevator's users will automatically leave if the floor corresponds to their destination, and new people will come in.

To quit, just press `q` or `ctrl+c`
