/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * 
 *  Libmemcached library
 *
 *  Copyright (C) 2011 Data Differential, http://datadifferential.com/
 *  Copyright (C) 2006-2009 Brian Aker All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __LIBMEMCACHED_HASH_H__
#define __LIBMEMCACHED_HASH_H__

#ifdef __cplusplus
extern "C" {
#endif

/* The two public hash bits */
LIBMEMCACHED_API
uint32_t memcached_generate_hash_value(const char *key, size_t key_length, memcached_hash_t hash_algorithm);

LIBMEMCACHED_API
const hashkit_st *memcached_get_hashkit(const memcached_st *ptr);

LIBMEMCACHED_API
memcached_return_t memcached_set_hashkit(memcached_st *ptr, hashkit_st *hashk);

LIBMEMCACHED_API
uint32_t memcached_generate_hash(const memcached_st *ptr, const char *key, size_t key_length);

LIBMEMCACHED_LOCAL
uint32_t memcached_generate_hash_with_redistribution(memcached_st *ptr, const char *key, size_t key_length);

LIBMEMCACHED_API
#ifdef CACHELIST_ERROR_HANDLING
memcached_return_t memcached_autoeject(memcached_st *ptr);
#else
void memcached_autoeject(memcached_st *ptr);
#endif

LIBMEMCACHED_API
  const char * libmemcached_string_hash(memcached_hash_t type);

#ifdef __cplusplus
}
#endif

#endif /* __LIBMEMCACHED_HASH_H__ */
