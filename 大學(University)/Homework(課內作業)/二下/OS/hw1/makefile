all:
	g++ master.c -o master.out
	g++ mmv.c -o mmv.out

test:
	cat blake.txt
	ls
	./master.out
	cat happy.tmp
	ls
	./master.out blake.txt happy2.tmp
	cat happy2.tmp

clean:
	rm -f master.out
	rm -f mmv.out
	rm -f *.tmp