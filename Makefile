build_and_run: build run

# Construir e Compilar os arquivos
build:
	gcc -c car/car.c -o car.o
	gcc -c user/user.c -o user.o
	gcc -c historic/historic.c -o historic.o
	gcc -c functions.c -o functions.o
	gcc -c Main.c -o main.o
	gcc functions.o user.o car.o historic.o main.o -o cRentCar
	rm *.o

run:
	gnome-terminal -t 'cRentCar' --geometry=100x30 --active -- ./cRentCar
	# Clean
	rm ./cRentCar

test:
	gcc test.c -o test
	gnome-terminal -t 'cRentCar' --active -- ./test
	# Clean
	rm ./test
