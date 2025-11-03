# Taller Integral en C++

## Descripción
Taller que implementa 8 ejercicios prácticos sobre programación en C++ cubriendo bucles, arreglos, funciones, estructuras y punteros.

## Compilación con Code::Blocks

### Configuración recomendada:
- Compiler: GNU GCC Compiler
- C++ standard: C++11 o superior
- Flags: -Wall -Wextra -O2

## Ejemplos de Entrada/Salida

### Ejercicio 1: Estadísticas básicas
**Entrada:**
```
5
3 8 -1 4 4
```
**Salida esperada:**
```
Minimo: -1
Maximo: 8
Promedio: 3.60
```

### Ejercicio 2: Rotación circular
**Entrada:**
```
5
1 2 3 4 5
2
```
**Salida esperada:**
```
Arreglo original: 1 2 3 4 5
Arreglo rotado: 4 5 1 2 3
```

### Ejercicio 3: Normalizar cadenas
**Entrada:**
```
  hola   mundo  C
```
**Salida esperada:**
```
Cadena original: "  hola   mundo  C"
Cadena normalizada: "hola mundo C"
Longitud: 12
```

### Ejercicio 4: Matriz sumas
**Entrada:**
```
3 4
1 2 3 4
5 6 7 8
9 0 1 2
```
**Salida esperada:**
```
Sumas por fila: [10, 26, 12]
Sumas por columna: [15, 8, 11, 14]
```

### Ejercicio 5: Registro estudiantes
**Entrada:**
```
3
Juan
20
8.5
Maria
19
9.2
Pedro
21
7.8
Maria
```
**Salida esperada:**
```
TOP 3 POR PROMEDIO:
1. Maria (Edad: 19, Promedio: 9.20)
2. Juan (Edad: 20, Promedio: 8.50)
3. Pedro (Edad: 21, Promedio: 7.80)

Encontrado en posicion 0: Maria, edad 19, promedio 9.20
```

### Ejercicio 6: Lista enlazada
**Entrada:**
```
pf 3
pf 2
pb 9
pop
pf 7
fin
```
**Salida esperada:**
```
Contenido final de la lista: 7 2 9
Tamaño: 3
```

### Ejercicio 7: Punteros a función
**Entrada:**
```
4
1 2 3 4
1
```
**Salida esperada:**
```
Arreglo original: 1 2 3 4
Despues de doble: 2 4 6 8
```

### Ejercicio 8: Archivo ventas
**Salida esperada:**
```
Archivo 'ventas.csv' creado con datos de ejemplo

ESTADISTICAS DE VENTAS:
Total vendido: $15127.65
Producto mas vendido: Mouse (15 unidades)
Ticket promedio: $3781.91
```

## Estructura del Programa

El programa contiene un menú principal que permite seleccionar cualquiera de los 8 ejercicios:

1. Estadísticas básicas de arreglo
2. Rotación circular  
3. Normalizar cadenas
4. Matriz - sumas por filas y columnas
5. Registro de estudiantes
6. Lista enlazada dinámica
7. Punteros a función
8. Archivo + estructuras - ventas

## Características Técnicas

- Implementado en C++ estándar
- Usa contenedores STL (vector, string)
- Manejo automático de memoria
- Validación de entradas básicas
- Código modular con funciones específicas

## Notas Importantes

- El Ejercicio 8 crea automáticamente el archivo "ventas.csv"
- Todos los ejercicios son interactivos
- Presione 0 para salir del programa
- Los tamaños de arreglos están limitados para evitar desbordamientos
