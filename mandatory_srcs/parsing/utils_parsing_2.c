/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:12:55 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/19 15:50:57 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// void    ft_memcpy_opti_af(void *dest, const void *src, size_t n)
// {
//     size_t    i;

//     if (dest == 0 && src == 0)
//         return ;
//     i = 0;
//     while (i + sizeof(long long) <= n)
//     {
//         *((long long *)(dest + i)) = *((long long *)(src + i));
//         i += sizeof(long long);
//     }
//     while (i < n)
//     {
//         *((char *)dest + i) = ((const char *)src)[i];
//         i++;
//     }
// }

// void    *ft_realloc(void *ptr,
//             size_t ptr_size,
//             size_t new_ptr_size)
// {
//     void    *new_ptr;

//     new_ptr = malloc(new_ptr_size);
//     if (new_ptr == NULL)
//     {
//         if (ptr != NULL)
//             free(ptr);
//         return (NULL);
//     }
//     if (ptr == NULL)
//         return (new_ptr);
//     if (ptr_size > new_ptr_size)
//         ft_memcpy_opti_af(new_ptr, ptr, new_ptr_size);
//     else
//         ft_memcpy_opti_af(new_ptr, ptr, ptr_size);
//     return (free(ptr), new_ptr);
// }

// void    **ft_realloc_array(void **arr_ptr,
//                         size_t arr_ptr_size,
//                         size_t new_arr_ptr_size)
// {
//     void    **new_arr_ptr;

//     new_arr_ptr = (void **) malloc(new_arr_ptr_size);
//     if (new_arr_ptr == NULL)
//     {
//         if (arr_ptr != NULL)
//             ft_free_array(arr_ptr);
//         return (NULL);
//     }
//     if (arr_ptr == NULL)
//         return (new_arr_ptr);
//     if (arr_ptr_size > new_arr_ptr_size)
//         ft_memcpy_opti_af(new_arr_ptr, arr_ptr, new_arr_ptr_size);
//     else
//         ft_memcpy_opti_af(new_arr_ptr, arr_ptr, arr_ptr_size);
//     free(arr_ptr);
//     return (new_arr_ptr);
// }

// void    ft_free_array_of_array(void ***array)
// {
//     size_t    i;

//     i = 0;
//     if (array == NULL)
//         return ;
//     while (array[i] != NULL)
//     {
//         ft_free_array((void **) array[i]);
//         i++;
//     }
//     free(array);
// }

// size_t    ft_get_array_length(void **array)
// {
//     size_t    i;

//     i = 0;
//     while (array[i] != NULL)
//         i++;
//     return (i);
// }