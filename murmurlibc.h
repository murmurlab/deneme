// ahbasara

#ifndef MURMURLIBC_H
# define MURMURLIBC_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char					*multiRowRead(int fd);
char					*read_to_left_str(int fd, char *left_str);
char					*get_line(char *left_str);
char					*new_left_str(char *left_str);
//UTILS
char					*gnl_strchr(const char *s, int c);
char					*gnl_stradd(char *s1, char *s2);
size_t					gnl_strlen(const char *s);

unsigned long long int	x(unsigned long long int i, char *s, char m);
unsigned long long int	q(char *s, char p, char kar);
int						spaghetti(const char *s2, ...);
unsigned long long int	xp(unsigned long long int i, char *s, char m);
unsigned long long int	qp(char *s, char p, char kar);

void					check_format(va_list argl, \
							const char **str, int *len);
int						p(const char *str, ...);

t_list					*llnew(void *content);
void					lladd(t_list **lst, t_list *new);
int						lllen(t_list *lst);
t_list					*llend(t_list *lst);
void					llprepend(t_list **lst, t_list *new);
void					lldel(t_list *lst, void (*del)(void*));
void					llclr(t_list **lst, void (*del)(void*));
void					lliter(t_list *lst, void (*f)(void *));
t_list					*llmap(t_list *lst, void *(*f)(void *)\
						, void (*del)(void *));

char					*toAscii(int n);
int						isalpha(int c);
int						isnum(int c);
int						isalnum(int c);
int						isascii(int c);
int						isprint(int c);
int						camelCase(int c);
int						gnomeCase(int c);

void					*callocate(size_t count, size_t size);
void					*xmemset(void *b, int c, size_t len);
void					memnull(void *s, size_t n);
void					*xmemcpy(void *dst, const void *src, size_t n);
void					*memmov(void *dest, const void *src, size_t n);
int						xmemcmp(const void *s1, const void *s2, size_t n);
void					*xmemchr(const void *s, int c, size_t n);

char					*xstrchr(const char *s, int c);
char					*strrchr(const char *s, int c);
int						strncmp(const char *s1, const char *s2, size_t n);
char					*strnstr(const char *haystack \
						, const char *needle, size_t len);
int						toInt(const char *str);
char					*strcln(const char *s1);
char					*strcut(char const *s, \
						unsigned int start, size_t len);
char					*stradd(char const *s1, const char *s2);
char					*strtrim(char const *s1, char const *set);
size_t					xstrlen(const char *s);
size_t					xstrlcpy(char *dst, const char *src, size_t dstsize);
size_t					xstrlcat(char *dst, const char *src, size_t dstsize);
char					*strmap(char const *s, \
						char (*f)(unsigned int, char));
void					striter(char *s, void (*f)(unsigned int, char*));

char					**seperate(char const *s, char c);

void					fdWriteChar(char c, int fd);
void					fdWriteStr(char *s, int fd);
void					fdWriteEol(char *s, int fd);
void					fdWriteNum(int n, int fd);

#endif
