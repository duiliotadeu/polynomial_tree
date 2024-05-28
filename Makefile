TARGET = prografo_app

CC = gcc
CXX = g++

WXFLAGS = `wx-config --cxxflags --libs`

SRC_DIR = src
INCLUDE_DIR = $(SRC_DIR)/include
CLIQ_DIR = $(INCLUDE_DIR)/cliquer

OBJS = prografo_app.o prografo.o setlist.o $(CLIQ_DIR)/graph.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(WXFLAGS)

prografo_app.o: $(SRC_DIR)/prografo_app.cpp $(INCLUDE_DIR)/prografo.h
	$(CXX) -c $(SRC_DIR)/prografo_app.cpp $(WXFLAGS) -o prografo_app.o

prografo.o: $(SRC_DIR)/prografo.c $(INCLUDE_DIR)/prografo.h
	$(CC) -c $(SRC_DIR)/prografo.c -I$(INCLUDE_DIR) -o prografo.o

setlist.o: $(SRC_DIR)/setlist.c $(INCLUDE_DIR)/setlist.h
	$(CC) -c $(SRC_DIR)/setlist.c -I$(INCLUDE_DIR) -o setlist.o

$(CLIQ_DIR)/graph.o: $(CLIQ_DIR)/graph.c $(CLIQ_DIR)/graph.h
	$(CC) -c $(CLIQ_DIR)/graph.c -I$(INCLUDE_DIR) -o $(CLIQ_DIR)/graph.o

clean:
	rm -f $(OBJS)

.PHONY: all clean
