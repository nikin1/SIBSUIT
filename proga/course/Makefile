all: clean create_lib

create_lib: course.c course_functions.c
	gcc -c course.c
	gcc -c -fPIC course_functions.c 
	gcc -shared -o libdate.so course_functions.o
	gcc -o main course.o -L . -l date -Wl,-rpath,.
clean:
	rm -rf *.o *.so main

