
all: main.o lib/libtime.a
	g++ -static -o Time $^
	@echo "done"

libtime.a:
	g++ -c -o lib/Time.o lib/Time.cpp
	ar rcs lib/libtime.a lib/Time.o

%.o: %.cpp
	g++ -c -I./lib -o $@ $<

clean:
	rm -f *.o Time lib/*.o lib/libtime.a
