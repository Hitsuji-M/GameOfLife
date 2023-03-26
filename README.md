<h1 align="center">Conway's game of life in C</h1>

## Informations
This project is a simple implementation of [Conway's game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) in C.
No GUI used, everything in the terminal. It created a grid of 50x50 cells, each cells has 1/3 chance to be alive at the start.

You can provide a set seed at the execution, otherwise time is used as a seed.

## Run it
To run the files use :
- `gcc gol.c main.c -o game`.
- or use the makefile with `make`.

Then just run the executable file with `./game`.

![image_exemple](https://media.discordapp.net/attachments/798648528351789066/1089540042873118780/image.png?width=628&height=660)