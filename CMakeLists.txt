cmake_minimum_required(VERSION 3.10)

project(prografo_app)

# Definir o diretório raiz do wxWidgets
set(wxWidgets_ROOT_DIR C:/wxWidgets-3.2.5)

# Encontrar o pacote wxWidgets, forçando a ligação estática
find_package(wxWidgets COMPONENTS core base REQUIRED)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
else()
    message(FATAL_ERROR "wxWidgets not found")
endif()

# Garantir que o wxWidgets seja compilado estaticamente
add_definitions(-DwxUSE_GUI=1 -DwxUSE_BASE=1)
set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")

# Encontrar o pacote OpenMP
find_package(OpenMP REQUIRED)

# Defina os arquivos fonte do projeto
set(SOURCES
    src/prografo_app.cpp
    src/prografo.c
    src/setlist.c
    src/include/cliquer/graph.c
)

# Adicionar o executável
add_executable(prografo_app WIN32 ${SOURCES})

# Incluir os diretórios de cabeçalhos
target_include_directories(prografo_app PRIVATE include)

# Vincular as bibliotecas wxWidgets e OpenMP ao executável
target_link_libraries(prografo_app ${wxWidgets_LIBRARIES} OpenMP::OpenMP_C OpenMP::OpenMP_CXX)

# Adicionar flags para o compilador suportar OpenMP
if(OpenMP_CXX_FOUND)
    target_compile_options(prografo_app PRIVATE ${OpenMP_CXX_FLAGS})
endif()

if(OpenMP_C_FOUND)
    target_compile_options(prografo_app PRIVATE ${OpenMP_C_FLAGS})
endif()

# Forçar linkagem estática para a aplicação
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++ -static")

# Excluir as bibliotecas comuns do wxWidgets para evitar duplicação de símbolos
set(wxWidgets_USE_STATIC_LIBS TRUE)
