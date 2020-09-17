#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

typedef enum	e_errid
{
    WRONG_FILE,
	OPEN_FAILURE,
	MISSING_TEXTURE,
   	INVALID_PARAM,
	MISSING_PARAM,
	MAP_ERROR,
	OPEN_MAP,
	MULTI_SPAWN,
    ERROR_WRITING,
	MEMORY_ERROR,
    DEFAULT_ERROR
}				t_errid;

typedef enum	e_warnid
{
    WRONG_ARG,
    SCREEN_EXIST,
    COLOR_EXIST,
    TEXTURE_EXIST,
	RES_HIGH,
	RES_LOW,
    DEFAULT_WARN
}				t_warnid;

typedef struct  s_err
{
    t_errid		id;
	char		*msg;
}				t_err;

typedef struct  s_warn
{
    t_warnid	id;
	char		*msg;
}				t_warn;

void			print_error(t_errid error_code);

void			print_warning(t_warnid alert);

#endif