#ifndef __STRING_UTILS_HPP__
#define __STRING_UTILS_HPP__

namespace StringUtils
{
    /**
     * @brief Remove os espaços em branco do começo e final da string
     * @param str char*
     */
    bool trim(char* str);

    /**
     * @brief Reduz os espaços internos para um único espaço
     * @param str char*
     */
    bool reduce_internal_spaces(char* str);

    /**
     * @brief Remove todos os espaços
     * @param str char*
     */
    bool remove_all_spaces(char* str);

}

#endif