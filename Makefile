build_and_run: build run

# Construir e Compilar os arquivos
build:
	gcc -c functions.c -o functions.o
	gcc -c car/car.c -o car.o
	gcc -c user/user.c -o user.o
	gcc -c Main.c -o main.o
	gcc functions.o car.o user.o main.o -o cRentCar
	rm *.o

run:
	gnome-terminal -t 'cRentCar' --active -- ./cRentCar
	# Clean
	rm ./cRentCar