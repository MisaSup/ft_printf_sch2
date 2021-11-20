NAME = libftprintf.a

HEADER = ft_printf.h

PT1_DIR = ./libft/

LIST = ft_printf.c ${PT1_DIR}ft_strcmp.c ${PT1_DIR}ft_putstr.c ${PT1_DIR}ft_itoa.c\
		${PT1_DIR}ft_strlen.c  ${PT1_DIR}ft_strncmp.c ${PT1_DIR}ft_atoi.c\
		${PT1_DIR}ft_strchr.c ${PT1_DIR}ft_itoa_unsigned.c ${PT1_DIR}ft_itoa_16.c\
		${PT1_DIR}ft_ptoaddress.c ${PT1_DIR}ft_strdup.c 

OBJ = ${patsubst %.c, %.o, ${LIST}}

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} $?

%.o : %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean :
	rm -f ${OBJ} ${OBJ_B}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re 