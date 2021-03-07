LDLIBS = -lcurl

agent: main.o 
	gcc -o agent main.o $(LDLIBS)

main.o: main.c 
	gcc -c main.c
     
clean:
	rm main.o agent
