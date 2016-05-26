/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 1999 - 2006, Digium, Inc.
 *
 * Mark Spencer <markster@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*
 * Voximal -- A VoiceXML browser.
 *
 * Copyrigth (C) 2009 - 2016, Ulex Innovative Systems, SARL
 *
 * Authors:
 *   Borja SIXTO (borja.sixto@ulex.fr)
 *   Javier SIXTO (javier.sixto@ulex.fr)
 * See:
 *   https://www.voximal.com
 *   https://github.com/voximal
 *   https://www.ulex.fr
 *
 * Purpose : Macros to help asterisk porting
 */

/*
#if !defined(AST_4) || !defined(AST_6) || !defined(AST_6_1) || !defined(AST_8) || !defined(AST_11) || !defined(AST_12) || !defined(AST_13)
#define AST_4           10400
#define AST_6           10600
#define AST_6_1         10601
#define AST_8           10800
#define AST_11			110000
#define AST_12			120000
#define AST_13			130000
#endif
*/

#if ASTERISK_VERSION_NUM < AST_8
/*** Macros in case of Asterisk version < 8  ***/
#include "version_macros_ast_1-6.h"

#elif ASTERISK_VERSION_NUM >= AST_8 && ASTERISK_VERSION_NUM < AST_11
/*** Macros in case of Asterisk version == 8 ***/
#include "version_macros_ast_1-8.h"

#elif ASTERISK_VERSION_NUM >= AST_11  && ASTERISK_VERSION_NUM < AST_12
/*** Macros in case of Asterisk version == 11 ***/
#include "version_macros_ast_11.h"

#elif ASTERISK_VERSION_NUM >= AST_12  && ASTERISK_VERSION_NUM < AST_13
/*** Macros in case of Asterisk version == 12 ***/
#include "version_macros_ast_12.h"

#else
/*** Macros in case of Asterisk version >= 13 ***/
#include "version_macros_ast_13.h"
	
#endif

