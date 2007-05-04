#ifndef T_ASSERT_H
#define T_ASSERT_H

#if defined(__func__)
  #define test_assert(e) \
    test_assert_core((e) ? 1 : 0, __func__, __LINE__, #e)
#else
  #define test_assert(e) \
    test_assert_core((e) ? 1 : 0, "", __LINE__, #e)
#endif

void test_assert_core(unsigned int, const char *, unsigned long, const char *);

#endif
