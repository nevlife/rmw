// Copyright 2026 nev
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RMW__INTRA_PROCESS_H_
#define RMW__INTRA_PROCESS_H_
#include "rmw/rmw.h"
#ifdef __cplusplus
extern "C" {
#endif
// Optional provider extension. Existing RMW entry points and public layouts are unchanged.
typedef struct rmw_ipc_route_s
{
  const uint8_t * excluded_gids;
  size_t excluded_count;
} rmw_ipc_route_t;
typedef rmw_ret_t (*rmw_ipc_prepare_fn)(
  void *, const void *, const rmw_message_info_t *, const uint8_t *, size_t,
  rmw_ipc_route_t *);
typedef bool (*rmw_ipc_decode_fn)(void *, void *);
typedef struct rmw_ipc_ingress_result_s
{
  int status;
  void * retired;
  void (*release)(void *);
} rmw_ipc_ingress_result_t;
typedef rmw_ipc_ingress_result_t (*rmw_ipc_ingress_fn)(
  void *, void *, rmw_ipc_decode_fn,
  const rmw_message_info_t *);
typedef bool (*rmw_ipc_ready_fn)(void *);
typedef struct rmw_ipc_api_s
{
  size_t size;
  uint32_t version;
  rmw_ret_t (*publish)(const rmw_publisher_t *, const void *, rmw_ipc_prepare_fn, void *);
  void (*configure_subscription)(
    const rmw_subscription_t *, rmw_ipc_ready_fn, rmw_ipc_ingress_fn,
    void *, uint8_t *);
  void (*notify)(const rmw_subscription_t *);
} rmw_ipc_api_t;
typedef const rmw_ipc_api_t * (*rmw_get_ipc_api_fn)(void);
#ifdef __cplusplus
}
#endif
#endif  // RMW__INTRA_PROCESS_H_
