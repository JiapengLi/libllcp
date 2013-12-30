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

#ifndef _LLC_SERVICE_H
#define _LLC_SERVICE_H

#include <pthread.h>
#include <stdint.h>

#ifdef __cplusplus
extern  "C" {
#endif /* __cplusplus */

struct llc_service {
  char *uri;
  void *(*accept_routine)(void *);
  void *(*thread_routine)(void *);
  int8_t sap;
  uint8_t rw;
  uint16_t miu;
  void *user_data;
};

struct llc_service *llc_service_new(void * (*accept_routine)(void *), void * (*thread_routine)(void *), void *user_data);
struct llc_service *llc_service_new_with_uri(void * (*accept_routine)(void *), void * (*thread_routine)(void *), const char *uri, void *user_data);
uint16_t	 llc_service_get_miu(const struct llc_service *service);
void		 llc_service_set_miu(struct llc_service *service, uint16_t miu);
uint8_t		 llc_service_get_rw(const struct llc_service *service);
void		 llc_service_set_rw(struct llc_service *service, uint8_t rw);
const char	*llc_service_get_uri(const struct llc_service *service);
const char	*llc_service_set_uri(struct llc_service *service, const char *uri);
void		 llc_service_free(struct llc_service *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_LLC_SERVICE_H */
