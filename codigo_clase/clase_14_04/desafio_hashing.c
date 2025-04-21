#include <stdio.h>

int hash(int clave){
	return (2 * clave + 3) % 9;
}

int main() {

	int arreglo[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
	int numero_tabla_hash[]={13,5,28,9,43,39,23,27,17};

	for(int i = 0;i<9;i++){
		int clave = numero_tabla_hash[i];
		int indice=hash(clave);

		while (arreglo[indice] != -1) {
            indice = (indice + 1) % 9;

        }

        arreglo[indice] = clave;
    }
	    // Mostrar la tabla hash resultante
		printf("\nTabla hash resultante:\n");
		for (int i = 0; i < 9; i++) {
			printf("Índice %d: %d\n", i, arreglo[i]);
		}
	
	return 0;
}
