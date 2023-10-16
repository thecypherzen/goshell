#ifndef _GOSH_H
#define _GOSH_H

/*Libraries */
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>

/* External Variables */
extern int errno;
extern char **environ;

char *s_chr(char *str, char c);
ssize_t get_line(char **line, size_t *sz, FILE *stream);
int handle_err(char *msg, int val);
int gcmd_exec(char **agv);
char *s_tok(char *str, char *delim);
size_t s_len(const char *str);
int s_put(char *s);
char *s_cat(char *dest, char *src);
int s_cmp(char *s1, char *s2);
char *s_copy(char *dest, char *src);
int s_write(char c);
void _exit_exec(char **agv);
int _env_exec(char **agv);
int _setenv_exec(char **agv);
int _unsetenv_exec(char **agv);
char **get_args(char *gcmdln);
char  *get_gcmdpath(char **agv); 
char *_gcmdpath_expandr(char *rel_path);
char *_getfull_path(char *rel_path, char *cwd, int slashed);
char *_getparent_path(char *cwd);
int gcmd_fork(char *full_path, char **agv);
int _chdir_helper(char *full_path, char *cwd);
int ch_dir(char *dest);
int logical_exec(char *comd);
int _slops_comp(char *s_lops, char a, char b);
int _syntax_checkr(char **cmdstr, char *gcmdln);
int _logical_ops(char *comd, char **currcmd);
int throw_syntax_err(int num, ...);
int _cpyto_cmdstr(char *token, char **cmdstr);

#endif