# Variables
CXX = g++                # Compilador de C++
CXXFLAGS = -std=c++11     # Opciones de compilación
SOURCES = automata.cpp dinamica_memo.cpp bruta.cpp costo_sub.cpp costo_ins.cpp costo_del.cpp costo_trans.cpp lectura_costos.cpp
OBJECTS = $(SOURCES:.cpp=.o)  # Archivos .o generados a partir de los .cpp
EXEC = fin                # Nombre del ejecutable final

# Regla por defecto (compilar todo)
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -f $(OBJECTS) $(EXEC)

# Regla para ejecutar el programa
run: $(EXEC)
	./$(EXEC)

# Regla para ejecutar el programa en Windows (si es necesario)
run_windows: $(EXEC)
	$(EXEC).exe
