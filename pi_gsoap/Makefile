#this is a Makefile to build client and server
OBJ_NAME := pi_control
# gsoap source path
GSOAP_ROOT := /media/embedded_CSIP/Tiny6410/FriendlyARM/build_src/gsoap-2.8/gsoap/
INCLUDE := -I$(GSOAP_ROOT)
CC := gcc
GCC := gcc
# CC := arm-linux-gnueabihf-gcc-4.7.2
# GCC := arm-linux-gnueabihf-gcc-4.7.2
OBJ_SERVER := soapC.o stdsoap2.o soapServer.o $(OBJ_NAME)Server.o
OBJ_CLIENT := soapC.o stdsoap2.o soapClient.o $(OBJ_NAME)Client.o
all:server
server: $(OBJ_SERVER)
	$(CC) $(INCLUDE) -lpthread $^ -o $@
client: $(OBJ_CLIENT)
	$(CC) $(INCLUDE) $^ -o $@
soap:
	soapcpp2 -c $(OBJ_NAME).h
.PHONY:clean
clean:
	rm -f server client *.o
distclean:
	rm -f server client *.o soap* *.xml *.nsmap *.xsd *.wsdl
