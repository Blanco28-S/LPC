# Variables
CXX = g++
CXXFLAGS = -g
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = RUN

# Regla por defecto
all: $(EXECUTABLE)

# Regla para crear el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Regla para compilar los archivos .cpp en .o
%.o: %.cpp
	$(CXX) -c $< -o $@

# Comando para ejecutar el programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Comando para limpiar los archivos generados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Regla para evitar recompilaciones innecesarias
.PHONY: all run clean