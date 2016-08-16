#ifndef _MODULES_H
#define _MODULES_H
/*
 * Copyright (c) 2016 MariaDB Corporation Ab
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE.TXT file and at www.mariadb.com/bsl.
 *
 * Change Date: 2019-07-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2 or later of the General
 * Public License.
 */
#include <dcb.h>
#include <modinfo.h>
#include <resultset.h>
#include <skygw_debug.h>

EXTERN_C_BLOCK_BEGIN

/**
 * @file modules.h  Utilities for loading modules
 *
 * The module interface used within the gateway
 *
 * @verbatim
 * Revision History
 *
 * Date     Who                 Description
 * 13/06/13 Mark Riddoch        Initial implementation
 * 08/07/13 Mark Riddoch        Addition of monitor modules
 * 29/05/14 Mark Riddoch        Addition of filter modules
 * 01/10/14 Mark Riddoch        Addition of call to unload all modules on shutdown
 * 19/02/15 Mark Riddoch        Addition of moduleGetList
 * 26/02/15 Massimiliano Pinto  Addition of module_feedback_send
 *
 * @endverbatim
 */

/**
 * A structure that represents a loaded module
 */
typedef struct module
{
    char            *name;        /**< The name of the module */
    const char      *type;        /**< The module type */
    void            *handle;      /**< The handle returned by dlopen */
    MODULE_INFO     *info;        /**< The module information */
    struct  module  *next;        /**< Next module in the linked list */
} MODULE;

/**
 * Module types
 */
#define MODULE_PROTOCOL         "Protocol"        /**< A protocol module type */
#define MODULE_AUTHENTICATOR    "Authenticator"   /**< An authenticator module type */
#define MODULE_ROUTER           "Router"          /**< A router module type */
#define MODULE_MONITOR          "Monitor"         /**< A database monitor module type */
#define MODULE_FILTER           "Filter"          /**< A filter module type */
#define MODULE_QUERY_CLASSIFIER "QueryClassifier" /**< A query classifier module type */


extern  void    *load_module(const char *module, const char *type);
extern  void    unload_module(const char *module);
extern  void    unload_all_modules();
extern  void    printModules();
extern  void    dprintAllModules(DCB *);
extern  RESULTSET   *moduleGetList();
extern void module_feedback_send(void*);
extern void moduleShowFeedbackReport(DCB *dcb);

EXTERN_C_BLOCK_END

#endif
