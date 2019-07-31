#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#if defined(_WIN32) || defined(_WIN64)
//# include <windows.h>
//#endif

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
  char strftime_z[64];
  strftime(strftime_z, sizeof(strftime_z), "%Y-%m-%d %H:%M:%S, z=%z, Z=%Z", tm);
  P("s", strftime_z);
}

static void
print_offset(struct tm *tm)
{
  time_t time_loc = mktime(tm);
  time_t time_utc = timegm(tm);
  time_t offset = (time_utc - time_loc) / 60;
  P("ld", time_loc);
  P("ld", time_utc);
  P("ld", offset);
}

int
main(int argc, char **argv)
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  print_version();
  P("ld", t);
  print_strftime(tm);
  print_is_dst(tm);
  print_offset(tm);

  return EXIT_SUCCESS;
}
