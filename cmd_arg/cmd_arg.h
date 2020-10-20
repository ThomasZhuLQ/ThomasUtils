/*
 * @file    cmd_arg.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Header for Command Line Arguments.
 *
 ******************************************************************************
 * Command format:
 * COMMAND_NAME ARG_NAME1=ARG_VALUE1 ARG_NAME2=ARG_VALUE2 ARGUMENT3 \r\n
 *     There must have at least 1 space or tab between the COMMAND_NAME and 
 * each ARGUMENT. '=' is used to seperate ARG_NAME and ARG_VALUE.
 *     COMMAND_NAME is case no sensitive.
 *     ARG_NAME, ARG_VALUE, ARGUMENT are case sensitive.
 *
 */
 
#ifndef _CMD_ARG_H_
#define _CMD_ARG_H_

#define MAX_SUPPORT_ARG_COUNT		8
#define MAX_ARG_BUF_SIZE			256
#define dp_malloc					malloc
#define dp_free						free

typedef char** CMD_ARG;

/*****************************************************************************/
/*     Allocate and initialize the CMD_ARG target.                           */
/*                                                                           */
/* Parameter list:                                                           */
/*   cmd(in):                                                                */
/*      CString buffer of the command.                                       */
/*   pargv(out):                                                             */
/*      Number of bytes of the buffer.                                       */
/* Return:                                                                   */
/*   The number of argument detected.                                        */
/*****************************************************************************/
size_t CMDARG_Alloc(const char *cmd, CMD_ARG *pargv);

/*****************************************************************************/
/*     Release the CMD_ARG target. And recycle the memory.                   */
/*                                                                           */
/* Parameter list:                                                           */
/*   cmd_arg(in):                                                            */
/*      Target of the CMD_ARG need to be released.                           */
/*****************************************************************************/
void CMDARG_Free(CMD_ARG cmd_arg);

/*****************************************************************************/
/*     Get the argument of the command.                                      */
/*                                                                           */
/* Parameter list:                                                           */
/*   cmd_arg(in):                                                            */
/*      Target of the CMD_ARG need to search.                                */
/*   index(in):                                                              */
/*      Index of the argument.                                               */
/* Return:                                                                   */
/*   The pointer of the argument value. Null means argument not found.       */
/*****************************************************************************/
const char *CMDARG_ArumentGet(CMD_ARG cmd_arg, uint32_t index);

/*****************************************************************************/
/*     Get the value of the command argument.                                */
/*                                                                           */
/* Parameter list:                                                           */
/*   cmd_arg(in):                                                            */
/*      Target of the CMD_ARG need to search.                                */
/*   arg_name(in):                                                           */
/*      CString of the argument name.                                        */
/* Return:                                                                   */
/*   The pointer of the argument value. Null means argument not found.       */
/*****************************************************************************/
const char *CMDARG_ValueGet(CMD_ARG cmd_arg, const char *arg_name);

/*****************************************************************************/
/*     Check the command code is same with the command line.                 */
/*                                                                           */
/* Parameter list:                                                           */
/*   command_name(in):                                                       */
/*      The command name.                                                    */
/*   command_line(in):                                                       */
/*      The command line.                                                    */
/* Return:                                                                   */
/*   If same, return true. else return false.                                */
/*****************************************************************************/
bool CMDARG_Check(const char *command_name, const char *command_line);

#endif
