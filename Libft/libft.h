/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 18:06:48 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 13:45:25 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				**ft_swap_line(char **tab);
char				**ft_colchr(char **tab, int c);
char				**ft_swap_col(char **tab, char c);
void				ft_swap(int *a, int *b);
int					ft_ltab(char **tab);
void				ft_fail(void);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *htack, const char *ndle, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_strsplit(char *str, char c);
int					ft_atoi(const char *str);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del) (void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstnew(void const	*content, size_t content_size);
void				*ft_memcpy(void *dest, void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putnbr(int nb);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *dest, char *src);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putchar(char c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_itoa(int n);
int					ft_isprint(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strmap(const char *s, char (*f)(char));
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_isdigit(int c);
int					ft_isascii(int c);
void				ft_memdel(void **ap);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
char				*ft_strrev(char *str);
void				ft_putstr(char *str);
void				ft_putchar(char c);
char				*ft_strcat(char *dest, char *src);
char				*ft_strdup(char *str);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *str);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char*));
size_t				ft_strlcat(char *dst, const char *src, size_t siz);

#endif
