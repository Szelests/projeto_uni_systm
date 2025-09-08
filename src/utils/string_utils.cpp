#include "utils/string_utils.hpp"

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdint>

namespace StringUtils
{

    bool trim(char* str)
    {
        bool check = false;

        if(!str || str[0] == '\0') return check;

        // Cópia da string para verificação futura
        char str_cpy[strlen(str)+1];
        strcpy(str_cpy, str);

        uint8_t inicio = 0;
        uint8_t fim = strlen(str) - 1;

        while(isspace((unsigned char)str[inicio]))
        {
            inicio++;
        }

        while(fim >= inicio && isspace((unsigned char)str[fim]))
        {
            fim--;
        }

        uint8_t len = fim - inicio + 1; 
        if(str + inicio != str)
        {
            memmove(str, str+inicio, len);
        }

        if(strcmp(str_cpy, str)) check = true;

        str[len] = '\0';

        return check;
    }

    bool reduce_internal_spaces(char* str) {
        bool check = false;

        if(!str || str[0] == '\0') return check;

        // Cópia da string para verificação futura
        char str_cpy[strlen(str)+1];
        strcpy(str_cpy, str);

        char* dest = str;
        char* src = str;
        while (*src) {
            *dest++ = *src;
            if (isspace((unsigned char)*src++)) {
                while (isspace((unsigned char)*src)) {
                    src++;
                }
            }
        }
        *dest = '\0';

        if(strcmp(str_cpy, str)) check = true;

        return check;

    }

    bool remove_all_spaces(char* str) {
        bool check = false;

        if(!str || str[0] == '\0') return check;

        // Cópia da string para verificação futura
        char str_cpy[strlen(str)+1];
        strcpy(str_cpy, str);

        char* dest = str;
        char* src = str;
        while (*src) {
            if (!isspace((unsigned char)*src)) {
                *dest++ = *src;
            }
            src++;
        }
        *dest = '\0';

        if(strcmp(str_cpy, str)) check = true;

        return check;
    }

}