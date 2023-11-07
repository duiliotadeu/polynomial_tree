g++ -c -o prografo_app.o prografo_app.cpp `wx-config --cxxflags --libs`

gcc -c -o prografo_app_funcs.o prografo_app_funcs.c

g++ -o prografo_app prografo_app.o prografo_app_funcs.o `wx-config --cxxflags --libs`