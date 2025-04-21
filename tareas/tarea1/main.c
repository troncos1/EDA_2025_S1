#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate parameters
int validate_parameters(int argc, char *argv[]) {
    // Check if the program has received 5 arguments
    if (argc != 6) {
        printf("Error: El programa debe recibir 5 argumentos.\n");
        return 0;
    }
    
    // Check if the second argument is "encode" or "decode"
    if (strcmp(argv[2], "encode") != 0 && strcmp(argv[2], "decode") != 0) {
        printf("Error: El segundo argumento debe ser la palabra \"encode\" o \"decode\".\n");
        return 0;
    }
    
    // Check if the keywords have the same length
    if (strlen(argv[3]) != strlen(argv[4])) {
        printf("Error: El largo de las dos palabras clave deben ser iguales.\n");
        return 0;
    }
    
    // Check if the input and output file names are different
    if (strcmp(argv[1], argv[5]) == 0) {
        printf("Error: Los nombres del archivo de entrada y salida deben ser diferentes.\n");
        return 0;
    }
    
    // Check if there are repeated characters between the two keys
    char *key1 = argv[3];
    char *key2 = argv[4];
    int len = strlen(key1);
    
    // Check for duplicate characters within key1
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (key1[i] == key1[j]) {
                printf("Error: Las letras contenidas en las palabras claves deben ser TODAS DIFERENTES.\n");
                return 0;
            }
        }
    }
    
    // Check for duplicate characters within key2
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (key2[i] == key2[j]) {
                printf("Error: Las letras contenidas en las palabras claves deben ser TODAS DIFERENTES.\n");
                return 0;
            }
        }
    }
    
    // Check for duplicate characters between key1 and key2
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (key1[i] == key2[j]) {
                printf("Error: No puede haber ninguna letra repetida entre las dos palabras claves.\n");
                return 0;
            }
        }
    }
    
    return 1;
}

// Function to substitute characters based on the keys
char substitute_char(char c, char *key1, char *key2, int key_length) {
    // checking if theres any characters repeated on key1
    for (int i = 0; i < key_length; i++) {
        if (c == key1[i]) {
            // Preserve case
            if (isupper(c)) {
                return toupper(key2[i]);
            } else {
                return tolower(key2[i]);
            }
        }
    }
    
    // checking if theres any characters repeated
    for (int i = 0; i < key_length; i++) {
        if (c == key2[i]) {
            // Preserve case
            if (isupper(c)) {
                return toupper(key1[i]);
            } else {
                return tolower(key1[i]);
            }
        }
    }
    
    // return unchanged
    return c;
}

// process file function
void process_file(char *input_filename, char *output_filename, char *key1, char *key2, int key_length) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error al abrir el archivo de entrada.\n");
        exit(1);
    }
    
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error al crear el archivo de salida.\n");
        fclose(input_file);
        exit(1);
    }
    
    int c;
    while ((c = fgetc(input_file)) != EOF) {
        char processed_char = substitute_char(c, key1, key2, key_length);
        fputc(processed_char, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    // validando parámetros
    if (!validate_parameters(argc, argv)) {
        return 1;
    }
    
    char *input_filename = argv[1];
    char *operation = argv[2];
    char *key1 = argv[3];
    char *key2 = argv[4];
    char *output_filename = argv[5];
    int key_length = strlen(key1);
    
    // procesando archivo
    process_file(input_filename, output_filename, key1, key2, key_length);
    
    // Print resultado
    if (strcmp(operation, "encode") == 0) {
        printf("El archivo fue codificado exitosamente.\n");
    } if (strcmp(operation, "decode") == 0) {
        printf("El archivo fue decodificado exitosamente.\n");
    }else {
        printf("Ingrese una acción que se pueda realizar.\n");
    }
    
    return 0;
}
