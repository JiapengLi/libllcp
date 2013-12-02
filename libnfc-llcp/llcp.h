/*-
 * Copyright (C) 2011, Romain Tartière
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

/*
 * $Id$
 */

#ifndef _LLCP_H
#define _LLCP_H

#include <pthread.h>
#include <stdint.h>

#ifdef __cplusplus
extern  "C" {
#endif /* __cplusplus */

/*
 * Logical Link Control Protocol
 * Technical Specification
 * NFC ForumTM
 * LLCP 1.0
 * NFCForum-TS-LLCP_1.0
 * 2009-12-11
 */

struct llc_link;

#define LLCP_VERSION_MAJOR 1
#define LLCP_VERSION_MINOR 1
struct llcp_version {
  uint8_t major;
  uint8_t minor;
};

int		 llcp_init(void);
int		 llcp_fini(void);

int		 llcp_version_agreement(struct llc_link *link, struct llcp_version version);

void		 llcp_threadslayer(pthread_t thread);

int		 llcp_disconnect(struct llc_link *link);

#define MAX_LOGICAL_DATA_LINK 8
//          DATA_LINK_CONNECTION
#define MAX_LLC_LINK_ADVERTISED_SERVICE 0x1F
#define MAX_LLC_LINK_SERVICE 0x3F
#define SAP_AUTO -1

#define LINK_SERVICE_CLASS_1 1
#define LINK_SERVICE_CLASS_2 2
#define LINK_SERVICE_CLASS_3 (LINK_SERVICE_CLASS_1 | LINK_SERVICE_CLASS_2)

/* LLC Operating modes */
#define LLC_INITIATOR 0
#define LLC_TARGET    1

#define LLC_PAX_PDU_PROHIBITED 0x02

#define LLCP_DEFAULT_RW 1
#define LLCP_DEFAULT_MIU 128

/*
 * http://www.nfc-forum.org/specs/nfc_forum_assigned_numbers_register
 */

/*
 * Well-known LLCP SAP Values
 */

#define LLCP_SDP_SAP  1
#define LLCP_IP_SAP   2
#define LLCP_OBEX_SAP 3
#define LLCP_SNEP_SAP 4

#define LLCP_SDP_URI  "urn:nfc:sn:sdp"
#define LLCP_IP_URI   "urn:nfc:sn:ip"
#define LLCP_OBEX_URI "urn:nfc:sn:obex"
#define LLCP_SNEP_URI "urn:nfc:sn:snep"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_LLCP_H */
