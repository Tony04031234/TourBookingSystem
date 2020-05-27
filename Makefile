output: ticket.o location.o admin.o customer.o user.o function.o main.o
	g++ ticket.cpp location.cpp admin.cpp customer.cpp user.cpp function.cpp main.cpp -o out

ticket.o: ticket.cpp
	g++ -std=c++11 -c ticket.cpp

location.o: location.cpp
	g++ -std=c++11 -c location.cpp

admin.o: admin.cpp
	g++ -std=c++11 -c admin.cpp

customer.o: customer.cpp
	g++ -std=c++11 -c customer.cpp

user.o: user.cpp
	g++ -std=c++11 -c user.cpp

function.o: function.cpp
	g++ -std=c++11 -c function.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o out
