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

#ifndef _LLC_LINK_H
#define _LLC_LINK_H

#include <mqueue.h>
#include <stdint.h>

#include "llcp_pdu.h"
#include "llcp.h"

#ifdef __cplusplus
extern  "C" {
#endif /* __cplusplus */

struct llc_link {
  uint8_t role;
  enum {
    LL_ACTIVATED,
    LL_DEACTIVATED,
  } status;
  struct llcp_version version;
  uint16_t local_miu;
  uint16_t remote_miu;
  uint16_t remote_wks;
  struct timeval local_lto;
  struct timeval remote_lto;
  uint8_t local_lsc;
  uint8_t remote_lsc;
  uint8_t opt;

  pthread_t thread;
  char *mq_up_name;
  char *mq_down_name;
  mqd_t llc_up;
  mqd_t llc_down;

  struct llc_service *available_services[MAX_LLC_LINK_SERVICE + 1];
  struct llc_connection *datagram_handlers[MAX_LOGICAL_DATA_LINK];
  struct llc_connection *transmission_handlers[MAX_LLC_LINK_SERVICE + 1];

  /* Unit tests metadata */
  void *cut_test_context;
  struct mac_link *mac_link;
};

struct llc_link	*llc_link_new(void);
int		 llc_link_service_bind(struct llc_link *link, struct llc_service *service, int8_t sap);
void		 llc_link_service_unbind(struct llc_link *link, uint8_t sap);
int		 llc_link_activate(struct llc_link *link, uint8_t flags, const uint8_t *parameters, size_t length);
int		 llc_link_configure(struct llc_link *link, const uint8_t *parameters, size_t length);
int		 llc_link_encode_parameters(const struct llc_link *link, uint8_t *parameters, size_t length);
uint8_t		 llc_link_find_sap_by_uri(const struct llc_link *link, const char *uri);
int		 llc_link_send_pdu(struct llc_link *link, const struct pdu *pdu);
int		 llc_link_send_data(struct llc_link *link, uint8_t local_sap, uint8_t remote_sap, const uint8_t *data, size_t len);
void		 llc_link_deactivate(struct llc_link *link);
void		 llc_link_free(struct llc_link *link);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_LLC_LINK_H */
