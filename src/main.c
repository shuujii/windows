#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdarg.h>
#include <inttypes.h>

#if defined(_WIN32) || defined(_WIN64)
# define timegm _mkgmtime
# define PRITIME "lld"
#else
# define PRITIME "ld"
#endif

#define P(specifier, v) printf("%10s = %" specifier "\n", #v, v)

static void
print_version(void)
{
#ifdef _MSC_VER
  P("d", _MSC_VER);
#else
  const char *_MSC_VER = "Unknown";
  P("s", _MSC_VER);
#endif
}

static void
print_is_dst(struct tm *tm)
{
  const char *is_dst = tm->tm_isdst ? "true" : "false";
  P("s", is_dst);
}

static void
print_strftime(struct tm *tm)
{
  char strftime_z[128];
  strftime(strftime_z, sizeof(strftime_z), "%Y-%m-%d %H:%M:%S [%z]", tm);
  P("s", strftime_z);

  char strftime_Z[128];
  strftime(strftime_Z, sizeof(strftime_Z), "%Z", tm);
  P("s", strftime_Z);
}

static void
print_offset(struct tm *tm)
{
  time_t time_loc = mktime(tm);
  time_t time_utc = timegm(tm);
  time_t offset = (time_utc - time_loc) / 60;
  P(PRITIME, time_loc);
  P(PRITIME, time_utc);
  P(PRITIME, offset);
}

//static void
//test_varg(int argc, ...)
//{
//  va_list ap;
//  char *s;
//  int64_t i64;
//
//  va_start(ap, argc);
//  for (int i = 0; i < argc; i++) {
//    switch (i) {
//      case 0:
//        s = va_arg(ap, char*);
//        printf("[%d] %s\n", i, s);
//        break;
//      default:
//        i64 = va_arg(ap, int64_t);
//        printf("[%d] %" PRId64 "\n", i, i64);
//        break;
//    }
//  }
//  va_end(ap);
//}

int
main(int argc, char **argv)
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

//  struct backtrace_location {
//    int32_t lineno;
//    uint32_t method_id;
//    const char *filename;
//  } bt, *btp;

  print_version();
  P(PRITIME, t);
  print_strftime(tm);
  print_is_dst(tm);
  print_offset(tm);

//  bt.lineno = 32;
//  bt.filename = "C:\\projects\\mruby\\test\\t\\exception.rb";
//  printf("bt = %s:%" PRId64 "\n", bt.filename, bt.lineno);

//  int32_t dummy1 = INT32_MAX;
//  int32_t i32 = 32;
//  int32_t dummy2 = INT32_MAX;
//  int64_t i64 = 64;
//  test_varg(2, "s1", dummy1);
//  test_varg(2, "s2", i32);
//  test_varg(2, "s3", dummy2);
//  test_varg(2, "s4", i64);

//  test_varg(2, bt.filename, bt.lineno);
//
//  btp = malloc(sizeof(struct backtrace_location));
//  btp->lineno = 33;
//  btp->method_id = 108;
//  btp->filename = "heep";
//  test_varg(2, btp->filename, btp->lineno);
//  free(btp);

  return EXIT_SUCCESS;
}
