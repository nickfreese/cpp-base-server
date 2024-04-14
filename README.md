# cpp base server
A base http server application to use as a starting point for any cpp server project

### compile

cmake -S . ./build/

(cd build;make)

### run
./build/cpp-base-server


### oneliner

(rm -rf ./build/;cmake -S . ./build/;(cd build;make);./build/cpp-base-server)


### run on another port

./build/cpp-base-server p=8080


