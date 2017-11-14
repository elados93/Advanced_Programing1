# Elad Aharon
# 311200786

a.out: gccAll
	g++ -Wall *.o 
	rm -f *.o

gccAll: *.h *.cpp
	g++ -Wall -c *.cpp
