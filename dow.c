#include <stdio.h>

int dow(int, int, int);

static char *days[] = { "sat", "sun", "mon", "tue", "wed", "thu", "fri" };

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s YYYY-MM-DD\n", *argv);
		return 7;
	}
	int y, m, d, n;
	n = sscanf(*(argv + 1), "%d-%d-%d", &y, &m, &d);
	if (n != 3) {
		fprintf(stderr, "dow: invalid date\n");
		return 22;
	}
	printf("%s\n", days[dow(y, m, d)]);
	return 0;
}

static const int months[] = { 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };

int dow(int y, int m, int d)
{
	int yr = y % 100;
	int dow = yr / 4 + d + months[m - 1];
	int isleap = y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
	if (isleap && m <= 2 ) dow--;
	int coe = y / 100 % 4;
	if (coe == 0) dow += 6;
	if (coe == 1) dow += 2;
	if (coe == 2) dow += 4;
	return (dow + yr) % 7;
}
