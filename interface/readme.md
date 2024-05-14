# compilar o prografo_app.cpp
g++ -c prografo_app.cpp `wx-config --cxxflags --libs`

# compilar qualquer .c
gcc -c prografo_app_funcs.c

# linkar todos os .o
g++ -o prografo_app prografo_app.o prografo.o setlist.o graph.o `wx-config --cxxflags --libs`


A fazer:
1. Adicionar execução em paralelo;
2. Criar um script de compilação (shellscript ou makefile);
3. Compilação no linux:
  3.1. Compilar de forma estática (Incluir todas as dependências no executável);
  3.2. Criar um flatpak;
4. Compilação no windows;
