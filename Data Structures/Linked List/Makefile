CC=clang++
NAME=Application.exe

Application: main.o;
	clang++ -o $(NAME) main.o

main.o: main.cxx
	clang++ -c main.cxx

.PHONY:
clean:
	rm ./$(NAME)
	rm ./main.o

.PHONY:
run:
	./$(NAME)


