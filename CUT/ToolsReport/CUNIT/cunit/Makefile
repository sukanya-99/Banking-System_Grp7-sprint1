OBJ=bin/main_test_driver.o

test: main_test_driver.o
	gcc -o bin/test $(OBJ) -lcunit

main_test_driver.o: src/main_test_driver.c
	gcc -o $(OBJ) -c src/main_test_driver.c

clean: 
	echo "Cleaning files ..."
	rm $(OBJ) bin/test.exe
