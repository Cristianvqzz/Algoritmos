# Compilador
CC = gcc

# Opciones del compilador
CFLAGS = -Wall

# Librerías
LIBS = -lm

# Archivos fuente
SRCS = main.c tiempo.c

# Archivos objeto
OBJS = main.o tiempo.o

# Nombre del ejecutable
TARGET = algP2

# Regla por defecto: compilar el programa
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Regla para compilar main.o
main.o: main.c tiempo.h
	$(CC) $(CFLAGS) -c main.c

# Regla para compilar tiempo.o
tiempo.o: tiempo.c tiempo.h
	$(CC) $(CFLAGS) -c tiempo.c

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

