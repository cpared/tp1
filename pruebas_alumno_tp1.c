#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "strutil.h"
#include "testing.h"

void pruebas_substr(void){
    char* cadena_vacia = "";
    char* cadena_copia = substr(cadena_vacia,0);
    bool ok = strcmp(cadena_copia,"") == 0;

    print_test("Copia cadena vacía largo 0", ok);

    cadena_copia = substr(cadena_vacia,2);
    ok = strcmp(cadena_copia,"") == 0;

    print_test("Copia cadena vacía largo mayor a 0", ok);

    char* cadena = "riverplate";

    cadena_copia = substr(cadena,5);
    ok = strcmp(cadena_copia,"river") == 0;

    print_test("Copia mitad de la cadena", ok);

    cadena_copia = substr(cadena,15);
    ok = strcmp(cadena_copia,"riverplate") == 0;

    print_test("Copia cadena con k > largo", ok);

    cadena_copia = substr(cadena + 2,10);
    ok = strcmp(cadena_copia,"verplate") == 0;

    print_test("Copia cadena con posicion incial != 0", ok);

    cadena_copia = substr(cadena + 2,20);
    ok = strcmp(cadena_copia,"verplate") == 0;

    print_test("Copia cadena con posicion incial != 0 y k > largo", ok);

}

void pruebas_split(){
    bool ok;

    char** arr0 = split("",'\0');
    print_test("Split cadena vacía separador vacío", *arr0[0] == '\0');


    char** arr1 = split("",',');
    print_test("Split cadena vacía con separador", *arr1[0] == '\0');
    char** arr2 = split("river",'\0');


    print_test("Split cadena con separador vacío", strcmp(arr2[0],"river") == 0);
    char** arr3 = split("river",',');
    print_test("Split cadena con separador que no está en la cadena", strcmp(arr3[0],"river") == 0);


    char** arr4 = split(",river",',');
    ok = (*arr4[0] == '\0' && strcmp(arr4[1],"river") == 0);
    print_test("Split cadena con separador al inicio", ok);


    char** arr5 = split("river,",',');
    ok = (strcmp(arr5[0],"river") == 0 && *arr5[1] == '\0');
    print_test("Split cadena con separador al final", ok);


    char** arr6 = split("river,,plate",',');
    ok = (strcmp(arr6[0],"river") == 0 && *arr6[1] == '\0' && strcmp(arr6[2],"plate") == 0);
    print_test("Split cadena con separador doble separador en el medio", ok);

    char** arr7 = split(",,riverplate",',');
    ok = (*arr7[0] == '\0' && *arr7[1] == '\0' && strcmp(arr7[2],"riverplate") == 0);
    print_test("Split cadena con separador doble separador al inicio", ok);

    char** arr8 = split("riverplate,,",',');
    ok = (strcmp(arr8[0],"riverplate") == 0 && *arr8[1] == '\0' && *arr8[2] == '\0');
    print_test("Split cadena con separador doble separador al final", ok);

    char** arr9 = split(",river,plate,",',');
    ok = (*arr9[0] == '\0' && strcmp(arr9[1],"river") == 0  && strcmp(arr9[2],"plate") == 0 && *arr9[3] == '\0');
    print_test("Split cadena con separador inicio, medio y fin", ok);
    
}


void pruebas_join(void){
    char* arr0[] = {NULL};

    char* str0 = join(arr0,'\0');
    print_test("Join arreglo vacío con separador vacío", *str0 == '\0');

    char* arr1[] = {NULL};

    char* str1 = join(arr1,',');
    print_test("Join arreglo vacío con separador", *str1 == '\0');

    char* arr2[] = {"abc","def","ghi"};

    char* str2 = join(arr2,'\0');
    print_test("Join arreglo con separador vacío", strcmp(str2,"abcdefghi") == 0);

}

void pruebas_tp1_alumno(void){
    printf("\n -----PRUEBAS SUBSTR-----\n");
    pruebas_substr();

    printf("\n -----PRUEBAS SPLIT------\n");
    pruebas_split();

    printf("\n -----PRUEBAS JOIN------\n");
    pruebas_join();
}