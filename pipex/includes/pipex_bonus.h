#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_px
{
	int		f1;
	int		f2;
	int		status;
	int		arg;
	int		*end;
	pid_t	*child;
	char 	***mycmdargs;
	char	**mypath;
}	t_px;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif