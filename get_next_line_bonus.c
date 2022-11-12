/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:36:56 by ohaimad           #+#    #+#             */
/*   Updated: 2022/11/12 16:36:43 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *pick_line(char *str)
{
    char *s;
    int i;
    int len_str;
    
    i = 0;
    len_str = 0;
    if (!str[i])
        return (NULL);
    while(str[len_str] && str[len_str] != '\n')
        len_str++;
    s = malloc(len_str + 2);
    if(!s)
        return(NULL);
    while(str[i] && str[i] != '\n')
    {
        s[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return(s);
}

char *full_line(char *p)
{
    char *c;
    int i;
    int j;
    int len_p;
    
    i = 0;
    j = 0;
    len_p = ft_strlen(p);
    while (p[i] && p[i] != '\n')
        i++;
    if (p[i] == '\n')
        i++;
    if (i >= len_p)
        return (free(p), NULL);
    c = malloc(len_p - i + 1);
    if(!c)
        return(NULL);
    while(p[i])
        c[j++] = p[i++];
    c[j] = '\0';
    return (free(p), c);
}
char *get_next_line(int fd)
{
    char *buffer;
    static char *buff_s[OPEN_MAX];
    char *ligne;
    int read_r;

    read_r = 1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buff_s[fd])
        buff_s[fd] = ft_strdup("");
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return(NULL);
    while(read_r && (!ft_strchr(buff_s[fd], '\n')))
    {
        read_r = read(fd, buffer, BUFFER_SIZE);
        if (read_r < 0)
            return (free(buff_s[fd]), buff_s[fd] = NULL,free(buffer), buffer = NULL, NULL);
        buffer[read_r] = '\0';
        buff_s[fd] = ft_strjoin(buff_s[fd], buffer);
    }
    free(buffer);
    ligne = pick_line(buff_s[fd]);
    buff_s[fd] = full_line(buff_s[fd]);
    return (ligne);
}

// int main()
// {
//     int fd  = open("text.txt", O_WRONLY | O_RDONLY);

//     // write(fd, "123456789", 9);
//     // printf("%s", get_next_line(fd));
//     close(fd);
//     fd  = open("text.txt", O_RDONLY, 0777);
//     printf("%s", get_next_line(fd));


//     // int fd1  = open("txt2", O_RDONLY);
//     // printf("%s\n", get_next_line(fd));
//     // printf("%s", get_next_line(fd1));
//     // printf("%s", get_next_line(fd1));
// }