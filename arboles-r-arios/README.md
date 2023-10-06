# TP arboles r-arios - Estructura de datos - UCA 2023

Resolucion del TP arboles r-arios de la materia estructura de datos. Implementacion sobre c++.

---

## Integrantes

- Ignacio Basara
- Valentín Nave
- Valentín Schiaffino
- Francisco Seijas
- Santiago Tamarit

---

## Como probar el codigo

_Aclaración: Para ejecutar el codigo, en el equipo utilizamos un entorno unix y solamente ejecutamos pruebas del codigo en el mismo, por lo que recomendamos utilizar un entorno similar para asegurar su funcionamiento. Si se quiere ejecutar sobre windows, se puede usar [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) o [MinGW](https://www.mingw-w64.org/), que es lo que nosotros usamos._

### Requerimientos:

- instalar el compilador de c++: `g++`
- _(opcional, pero sugerido)_ `make`, para la compilacion de todos los archivos mas facil

### Compilacion

Para hacerlo mas facil, hicimos un archivo Makefile para compilar todo de una. Si se tiene instalado make, simplemente ejecutamos `make all` en la carpeta `arboles-r-arios`

Para compilar los archivos de forma separada:

ejecutar `g++` sobre cada archivo .cpp.

Ejemplo: `g++ pre_orden_memoria.cpp -o out/pre_orden_memoria`

### Ejecución

Para ejecutar el codigo de cada archivo, una vez que ya fue compilado, simplemente debemos ejecutarlo de la siguiente forma:

Ejemplo de ejecucion:

Pre orden:

```
./out/crear_arbol_lleno 3
./out/pre_orden_memoria
```

Niveles:

```
./out/crear_arbol_lleno 3
./out/niveles_archivo
```

Busqueda:
_Aclaracion: crear_arbol_ordenado imprime un valor sugerido a buscar (uno que este en el ultimo nivel del arbol) y ademas buscar_valor_memoria requiere el parametro de que valor queremos buscar_

```
./out/crear_arbol_ordenado 3
./out/buscar_valor_memoria <valor_buscado>
```

Es importante aclarar que todos estos scripts utilizan un archivo llamado `arbol` para leer los datos a utilizar.

Nosotros generamos dos scripts adicionales para llenar un arbol y escribirlo en disco. Ambos reciben un parametro `<niveles_deseados>` y de esta forma crea un arbol lleno del nivel especificado.

La unica diferencia entre ambos es que el primero lo crea con un orden arbitrario y valores aleatorios, mientras que el segundo lo crea ordenado segun un arbol binario de busqueda.

- `./out/crear_arbol_lleno <niveles_deseados>`
- `./out/crear_arbol_ordenado <niveles_deseados>`
