
all: num.o main.o
	g++ -o num $^
	@echo "done"

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm -f *.o num
