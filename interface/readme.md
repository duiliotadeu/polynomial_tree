# compilar o prografo_app.cpp
g++ -c prografo_app.cpp `wx-config --cxxflags --libs`

# compilar qualquer .c
gcc -c prografo_app_funcs.c

# linkar todos os .o
g++ -o prografo_app prografo_app.o prografo.o setlist.o graph.o `wx-config --cxxflags --libs`