/*
 * collection.h
 *
 * Copyright (C) 2009 Hector Martin <hector@marcansoft.com>
 * Copyright (C) 2009 Nikias Bassen <nikias@gmx.li>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include <libimobiledevice-glue/glue.h>

struct collection {
	void **list;
	int capacity;
};

#ifdef __cplusplus
extern "C" {
#endif

LIMD_GLUE_API void collection_init(struct collection *col);
LIMD_GLUE_API void collection_add(struct collection *col, void *element);
LIMD_GLUE_API int collection_remove(struct collection *col, void *element);
LIMD_GLUE_API int collection_count(struct collection *col);
LIMD_GLUE_API void collection_free(struct collection *col);
LIMD_GLUE_API void collection_copy(struct collection *dest, struct collection *src);

#define MERGE_(a,b) a ## _ ## b
#define LABEL_(a,b) MERGE_(a, b)
#define UNIQUE_VAR(a) LABEL_(a, __LINE__)

#define FOREACH(var, col) \
	do { \
		int UNIQUE_VAR(_iter); \
		for(UNIQUE_VAR(_iter)=0; UNIQUE_VAR(_iter)<(col)->capacity; UNIQUE_VAR(_iter)++) { \
			if(!(col)->list[UNIQUE_VAR(_iter)]) continue; \
			var = (col)->list[UNIQUE_VAR(_iter)];

#define ENDFOREACH \
		} \
	} while(0);

#ifdef __cplusplus
}
#endif

#endif
