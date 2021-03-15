/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:41:16 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/15 16:24:36 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>


size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, const void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

int main()
{
	int		fd;
	fd = open("test.txt", O_CREAT | O_WRONLY);
	char	*str = "BONJOUR";
	char	*str2 = "";

	/*******************************************/
	printf("----------ft_strlen----------\n");
	printf("Test sur la chaine |%s| :\n", str);
	printf("strlen : %zu\n", strlen(str));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	printf("Test sur la chaine |%s| :\n", str2);
	printf("strlen : %zu\n", strlen(str2));
	printf("ft_strlen : %zu\n", ft_strlen(str2));

	/********************************************/
	printf("\n\n----------ft_strcpy----------\n");
	char	*dest = malloc(sizeof(char) * 10);
	char	*destbis = malloc(sizeof(char) * 10);
	dest = strcpy(dest, str);
	destbis = ft_strcpy(destbis, str);
	printf("Copie de |%s| dans une chaine vide :\n", str);
	printf("strcpy : %s\n", dest);
	printf("ft_strcpy : %s\n", destbis);

	/********************************************/
	printf("\n\n----------ft_strcmp----------\n");
	char	*cmp1 = "Aurevoir";
	char	*cmp2 = "Salut";
	printf("Comparaison de |%s| et |%s|\n", cmp1, cmp2);
	printf("strcmp : %d\n", strcmp(cmp1, cmp2));
	printf("ft_strcmp : %d\n", ft_strcmp(cmp1, cmp2));

	/********************************************/
	printf("\n\n----------ft_write----------\n");
	printf("code errno avant erreur : %d\n", errno);
	int i = write(1, "coucou\n", 7);
	int	j = ft_write(1, "coucou\n", 7);
	printf("retour write : i : %d\n", i);
	printf("retour ft_write : j : %d\n", j);
	int k = write(10, "coucou\n", 7);
	printf("code errno write : %d\n", errno);
	errno = 0;
	printf("reset code errno : %d\n", errno);
	int	l = ft_write(10, "coucou\n", 7);
	printf("code errno ft_write : %d\n", errno);
	printf("retour write : k : %d\n", k);
	printf("retour ft_write : l : %d\n", l);
	ft_write(fd, "Ecriture dans le fd", 19);
	close(fd);

	/********************************************/
	printf("\n\n----------ft_read----------\n");
	errno = 0;
	printf("reset code errno : %d\n", errno);
	fd = open("test.txt", O_RDONLY);
	char buff[20];
	int m = read(fd, &buff, 19);
	buff[19] = '\0';
	printf("%s\n", buff);
	printf("retour read : %d\n", m);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	char buff2[20];
	int n = ft_read(fd, &buff2, 19);
	buff2[19] = '\0';
	printf("%s\n", buff2);
	printf("retour ft_read : %d\n", n);
	close(fd);
	int p = read(10, &buff, 5);
	printf("error avec read : %d\n", p);
	printf("code errno read : %d\n", errno);
	errno = 0;
	printf("reset code errno : %d\n", errno);
	int q = ft_read(10, &buff, 5);
	printf("error avec ft_read : %d\n", q);
	printf("code errno : %d\n", errno);

	/********************************************/
	printf("\n\n----------ft_strdup----------\n");
	char *s = "Je suis la chaine a dupliquer";
	char *s2;
	char *s3;
	printf("Duplication de la chaine : |%s| :\n", s);
	s2 = strdup(s);
	s3 = ft_strdup(s);
	printf("strdup : %s\n", s2);
	printf("ft_strdup : %s\n", s3);
}