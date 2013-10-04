#include <netdb.h>
#include <stdio.h>

#include <sys/system_properties.h>

#define _PATH_HOSTS	"/system/etc/hosts"
#define _PROP_HOSTS	"persist.sys.hosts"

FILE* __open_hosts(void)
{
	FILE* fp = NULL;
	char path_hosts[PROP_VALUE_MAX];
	path_hosts[0] = 0;
	if (__system_property_get(_PROP_HOSTS, path_hosts) > 0) {
		fp = fopen(path_hosts, "r");
	}
	if (!fp) {
		fp = fopen(_PATH_HOSTS, "r");
	}
	return fp;
}
