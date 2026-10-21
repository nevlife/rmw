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

#ifndef RMW__INTRA_PROCESS_SERVICE_H_
#define RMW__INTRA_PROCESS_SERVICE_H_
#include "rmw/intra_process.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef rmw_ret_t (*rmw_ipc_request_fn)(
  void *, const void *, const rmw_service_info_t *, const uint8_t *, size_t, bool *);
typedef struct rmw_ipc_service_api_s
{
  size_t size;
  uint32_t version;
  rmw_ret_t (*send_request)(
    const rmw_client_t *, const void *, int64_t *, rmw_ipc_request_fn, void *);
  void (*configure_client)(const rmw_client_t *, rmw_ipc_ready_fn, void *);
  void (*configure_service)(const rmw_service_t *, rmw_ipc_ready_fn, void *, uint8_t *);
  void (*notify_client)(const rmw_client_t *);
  void (*notify_service)(const rmw_service_t *);
} rmw_ipc_service_api_t;
typedef const rmw_ipc_service_api_t * (*rmw_get_ipc_service_api_fn)(void);
#ifdef __cplusplus
}
#endif
#endif  // RMW__INTRA_PROCESS_SERVICE_H_
