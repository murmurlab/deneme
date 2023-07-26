#include "./murmurlibc.h"

int main()
{
    t_list *a0;
    t_list *a1;
    t_list *a2;
    t_list *a3;
    a0 = llnew(NULL);
    a1 = llnew("asd");
    a2 = llnew("qqqqqq");
    a3 = llnew("mehmet");
    a0->next = a1;
    a1->next = a2;
    a2->next = a3;

    //p("%s", findex(a0, 2)->content);
    int fd;
    int ct;

    ct = 0;
    fd = open("./main.c", 600);
    while (ct++ < 27)
        p("%s", multiRowRead(fd));
}