//the header for doomsday.c


#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

void testCode(void);
int dayOfWeek(int doomsday, int leapYear,
              int month, int day);
int daysTillNextThur(int dayOfWeek);
