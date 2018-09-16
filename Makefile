cat: cat.o
	g++ -o cat cat.o

cat.o: cat.cpp
	g++ -c cat.cpp -pedantic-errors -Wall -std=c++11 -g -O0

mv: mv.o
	g++ -o mv mv.o

mv.o: mv.cpp
	g++ -c mv.cpp -pedantic-errors -Wall -std=c++11 -g -O0

ls: ls.o
	g++ -o ls ls.o

ls.o: ls.cpp
	g++ -c ls.cpp -pedantic-errors -Wall -std=c++11 -g -O0

rm: rm.o
	g++ -o rm rm.o

rm.o: rm.cpp
	g++ -c rm.cpp -pedantic-errors -Wall -std=c++11 -g -O0

ln: ln.o
	g++ -o ln ln.o

ln.o: ln.cpp
	g++ -c ln.cpp -pedantic-errors -Wall -std=c++11 -g -O0

stat: stat.o
	g++ -o stat stat.o

stat.o: stat.cpp
	g++ -c stat.cpp -pedantic-errors -Wall -std=c++11 -g -O0

pwd: pwd.o
	g++ -o pwd pwd.o

pwd.o: pwd.cpp
	g++ -c pwd.cpp -pedantic-errors -Wall -std=c++11 -g -O0

penv: penv.o
	g++ -o penv penv.o

penv.o: penv.cpp
	g++ -c penv.cpp -pedantic-errors -Wall -std=c++11 -g -O0
