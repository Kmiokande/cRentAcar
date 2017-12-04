build_and_run: build run

# Construir e Compilar os arquivos
build:
	clang -c car/car.c -o car.o
	clang -c user/user.c -o user.o
	clang -c historic/historic.c -o historic.o
	clang -c functions.c -o functions.o
	clang -c Main.c -o main.o
	clang historic.o functions.o car.o user.o main.o -o cRentCar
	rm *.o

run:
	gnome-terminal -t 'cRentCar' --geometry=100x30 --active -- ./cRentCar
	# Clean
	# rm ./cRentCar

test:
	clang test.c -o test
	gnome-terminal -t 'cRentCar' --active -- ./test
	# Clean
	rm ./test
