/*
 * @file    cmd_arg.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Command Line Arguments.
 *
 */
 
#include "cmd_arg.h"
#include <string.h>

#define UPCASE(c)				(IS_az(c)?((c) - 'a' + 'A'):(c))

size_t CMDARG_Alloc(const char *cmd, CMD_ARG *pargv)
{
	size_t n_arg = 0;
	char *p;
	
	while(*cmd == ' ') cmd++;
	if(cmd == NULL) return 0;
	
	size_t cmd_sz = min(MAX_ARG_BUF_SIZE,strlen(cmd)) + 1;
	CMD_ARG cmd_arg = (CMD_ARG)dp_malloc(sizeof(char*) * MAX_SUPPORT_ARG_COUNT);
	
	memset(cmd_arg,0,sizeof(char*) * MAX_SUPPORT_ARG_COUNT);
	cmd_arg[0] = (char*)dp_malloc(cmd_sz);
	strcpy(cmd_arg[0],cmd);
	
	do
	{
		p = strchr(cmd_arg[n_arg++],' ');
		if(p == NULL) break;
		while(*p == ' ' || *p == '\t') *p++ = '\0';
		if(*p == '\0' || *p == '\r' || *p == '\n') break;
		cmd_arg[n_arg] = p;	
	}while(n_arg < MAX_SUPPORT_ARG_COUNT);
	
	*pargv = cmd_arg;
	return n_arg;
}

void CMDARG_Free(CMD_ARG argv)
{
	dp_free(argv[0]);
	dp_free(argv);
}

const char *CMDARG_ArumentGet(CMD_ARG cmd_arg, uint32_t index)
{
	if(index >= MAX_SUPPORT_ARG_COUNT) return NULL;
	return cmd_arg[index];
}

const char *CMDARG_ValueGet(CMD_ARG cmd_arg, const char *arg_name)
{
	const char **arg_item = cmd_arg;
	size_t arg_sz = strlen(arg_name);
	while(*arg_item)
	{
		if(memcmp(*arg_item,arg_name,arg_sz) == 0)
		if((*arg_item)[arg_sz] == '=')
			return (*arg_item + arg_sz + 1);
		arg_item++;
	}
	return NULL;
}

bool CMDARG_Check(const char *command_name, const char *command_line)
{
	if(command_name == NULL) return false;
	if(command_line == NULL) return false;
	while(*command_name && *command_line)
	{
		if(UPCASE(*command_name) != UPCASE(*command_line))
			return false;
		command_name++;
		command_line++;
	}
	if(*command_name) return false;
	if(*command_line != ' ' && *command_line != '\0') return false;
	
	return true;
}

