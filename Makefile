SERVER	= 	server

CLIENT =	client

C_SRCS	=	client.c ft_atoi.c ft_itoa.c 

S_SRCS	=	server.c ft_atoi.c ft_itoa.c

C_OBJCT	=	${C_SRCS:.c=.o}

S_OBJCT	=	${S_SRCS:.c=.o}

RM		=	rm -f

CCW		=	cc -Wextra -Wall -Werror

all	: $(SERVER) $(CLIENT)


$(SERVER) : $(S_OBJCT)
	$(CCW) $(S_OBJCT) -o $(SERVER)

$(CLIENT) : $(C_OBJCT)
	$(CCW) $(C_OBJCT) -o $(CLIENT)


clean :
	${RM} ${C_OBJCT}
	${RM} ${S_OBJCT}

fclean : clean
	${RM} ${SERVER}
	${RM} ${CLIENT}

re : fclean all