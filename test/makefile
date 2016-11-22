#makefile

all: test_server_socket test_sockaddr

lib: mysockaddr.o mysocket.o myserversocket.o

myserversocket.o:  ../lib/myserversocket.cpp
	g++ -c ../lib/myserversocket.cpp -o myserversocket.o

mysockaddr.o: ../lib/mysockaddr.cpp
	g++ -c ../lib/mysockaddr.cpp -o mysockaddr.o

mysocket.o: ../lib/mysocket.cpp mysockaddr.o
	g++ -c ../lib/mysocket.cpp -o mysocket.o

#test_server_socket
test_server_socket: test_server_socket.o myserversocket.o mysockaddr.o mysocket.o
	g++ test_server_socket.o myserversocket.o mysockaddr.o mysocket.o -o test_server_socket
test_server_socket.o: test_serversocket.cpp
	g++ -c test_serversocket.cpp -o test_server_socket.o

#test_sockaddr
test_sockaddr: test_sockaddr.o mysockaddr.o
	g++ test_sockaddr.o mysockaddr.o -o test_sockaddr
test_sockaddr.o: test_sockaddr.cpp
	g++ -c test_sockaddr.cpp -o test_sockaddr.o

#socket测试
test_socket: test_socket.o mysockaddr.o mysocket.o
	g++ test_socket.o mysockaddr.o mysocket.o -o test_socket
test_socket.o: test_socket.cpp
	g++ -c test_socket.cpp -o test_socket.o


clean:
	@echo "clean test_server_socket"
	-rm *.o
	@echo "clean done"

