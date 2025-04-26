# Informe Breve - Tarea 2: Earthquake Alert System

## Estructura General del Proyecto

```
grupoX-T2/
├── Makefile
├── main.c
└── modules/
    ├── processor.h / processor.c
    ├── sorter.h / sorter.c
    └── validator.h / validator.c
```

## Objetivo del Programa

Leer un archivo CSV con información sísmica de distintas ciudades y generar una lista priorizada de ciudades en riesgo, ordenadas según reglas específicas, escribiendo los resultados en un archivo de salida.

## main.c
- Controla la ejecución principal.
- Recibe los parámetros: archivo de entrada, número de ciudades a priorizar, archivo de salida.
- Llama a funciones del módulo `processor` para leer el archivo.
- Ordena los datos usando `quicksort` del módulo `sorter`.
- Escribe los primeros N resultados al archivo de salida.

## modules/processor.h y processor.c
- Define la estructura `CityData`, que representa cada ciudad.
- `read_and_process_file`: Lee el archivo CSV línea por línea, usando `strtok` para dividir por comas.
  - Convierte los datos a formato estructurado.
  - Valida cada entrada usando `validate_city`.
- `write_output`: Escribe las N ciudades más prioritarias al archivo de salida.

## modules/validator.h y validator.c
- Contiene `validate_city`, que revisa que:
  - `seismic_level` esté entre 1 y 5.
  - Si hay valor de `risk_percent`, sea válido.
  - Si no hay riesgo, lo marca adecuadamente.

## modules/sorter.h y sorter.c
- Contiene `quicksort` y `compare`.
- Ordena las ciudades según prioridad:
  1. Mayor `seismic_level`.
  2. Mayor `risk_percent`.
  3. Si faltan datos, orden especial según reglas de la tarea.
  4. Desempate por orden alfabético inverso (Z-A).

## Consideraciones Técnicas
- Se usa `malloc` para manejar más de 1000 registros.
- Se libera memoria con `free` al final.
- Se valida todo: formato, rangos, campos vacíos.
- Optimizado para eficiencia con `quicksort`.

## Ejemplo de Uso
```bash
./tarea2 input.csv 5 output.txt
```

## Ejemplo de Entrada (input.csv)
```
city_name,seismic_level,risk_percent
Dallas,4,
Tucson,5,
San Francisco,5,92.98
New Orleans,5,14.55
Fresno,5,58.79
```

## Salida Esperada (output.txt)
```
city_name seismic_level risk_percent
San Francisco 5 92.98
Fresno 5 58.79
New Orleans 5 14.55
Tucson 5
Dallas 4
```

## Compilación
```bash
make        # Compila todo
make clean  # Limpia archivos objeto y binario
make run    # Ejecuta con input.csv y N=15 por defecto
```

---

Este informe resume la lógica, estructura y funcionamiento del programa completo.