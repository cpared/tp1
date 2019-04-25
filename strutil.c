#include <stdlib.h>
#include <string.h>

#define BITE_FIN_CADENA 1
#define VALOR_VEC_INICIAL 1

char *substr(const char *str, size_t k){
    size_t largo_cadena = strlen(str);
    if (largo_cadena > k) largo_cadena = k;

    char* cadena = malloc((largo_cadena * sizeof(char)) + BITE_FIN_CADENA);
    if (!cadena) return NULL;

    strncpy(cadena,str,largo_cadena);
    cadena[largo_cadena] = '\0';
    return cadena;
}


char **split(const char *str, char sep){
    size_t pos_inicial = 0;
    size_t i = 0;
    size_t cant_sep = 0;
    size_t pos_vector = 0;
    size_t LARGO = strlen(str) - 1;
    size_t esta_pos_final = 0;

    while(str[i]){ // Cuento la cantidad de apariciones para armar el vector
        if(str[i] == sep){
            cant_sep++;
        }
        i++;
    }

    char** arr_split = malloc(sizeof(char*) * (cant_sep + VALOR_VEC_INICIAL));
    if (!arr_split) return NULL;
    
    if (LARGO == -1){ //Caso borde
      char* cadena = substr("",0);
      arr_split[pos_vector] = cadena;
      return arr_split;
    }
    
    if (sep == '\0'){ //Caso borde
      char* str_copia = substr(str,LARGO + 1);
      arr_split[pos_vector] = str_copia;
      return arr_split;
    }

    i = 0;
    while(str[i]){
        if(str[i] == sep && i == LARGO){
          char* cadena = substr(str + pos_inicial,i - pos_inicial);
          char* cadena_final = substr("",0);
          arr_split[pos_vector] = cadena;
          arr_split[pos_vector + 1] = cadena_final;
          break;
        }
        if(str[i] == sep && i == 0){
          char* cadena = substr("",0);
          arr_split[pos_vector] = cadena;
          pos_vector ++;
          pos_inicial = i + 1;
          i++;
          continue;
        }
        if(str[i] == sep || i == LARGO){
          if (i == LARGO) esta_pos_final ++;
          char* cadena = substr(str + pos_inicial,i - pos_inicial + esta_pos_final);
          arr_split[pos_vector] = cadena;
          pos_vector ++;
          pos_inicial = i + 1;
        }
        i++;
    }
    return arr_split;
}

char *join(char **strv, char sep){
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t largo_cadena = 0;
    size_t cant_elementos = sizeof(strv) / sizeof(strv[0]);

    if (*strv == NULL){ //Caso borde, vector vacío
      char* cadena = malloc(sizeof(char));
      if (!cadena) return NULL;
      cadena[0] = '\0';
      return cadena;
    }

    for(i = 0; i < cant_elementos; i++){
        largo_cadena = largo_cadena + strlen(strv[i]);
    }
    
    size_t largo_total = sizeof(char) * largo_cadena + cant_elementos;
    char* cadena = malloc(largo_total);

    for(i = 0; i < largo_total; i++){       
      if (strv[j][k] == '\0'){
        cadena[i] = sep;
        k = 0;
        j++;
        continue;
      }
      cadena[i] = strv[j][k];
      k++;
    }
    cadena[i - 1] = '\0';
    return cadena;
}

void free_strv(char *strv[]);
