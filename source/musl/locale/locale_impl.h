#ifndef _LOCALE_IMPL_H
#define _LOCALE_IMPL_H

#include <locale.h>
#include <stdlib.h>

#define LOCALE_NAME_MAX 23

struct __locale_map {
    const void *map;
    size_t map_size;
    char name[LOCALE_NAME_MAX + 1];
    const struct __locale_map *next;
};

extern volatile int __locale_lock[1];

extern const struct __locale_map __c_dot_utf8;
extern const struct __locale_struct __c_locale;
extern const struct __locale_struct __c_dot_utf8_locale;

const struct __locale_map *__get_locale(int, const char *);
const char *__mo_lookup(const void *, size_t, const char *);
const char *__lctrans(const char *, const struct __locale_map *);
const char *__lctrans_cur(const char *);
const char *__lctrans_impl(const char *, const struct __locale_map *);
int __loc_is_allocated(locale_t);
char *__gettextdomain(void);

#define LOC_MAP_FAILED ((const struct __locale_map *)-1)

#define C_LOCALE ((locale_t)&__c_locale)
#define UTF8_LOCALE ((locale_t)&__c_dot_utf8_locale)
#define CURRENT_LOCALE C_LOCALE

#undef MB_CUR_MAX
#define MB_CUR_MAX (CURRENT_UTF8 ? 4 : 1)

#endif
