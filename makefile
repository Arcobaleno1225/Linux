main: main.c menu.o zsgc.o demo.o
	g++ main.c menu.o zsgc.o -o main 
menu.o:menu.c
	g++ -c menu.c
zsgc.o:zsgc.c
	g++ -c zsgc.c
demo.o:demo.c
	g++ -c demo.c
clean:
	rm *.o main
	
