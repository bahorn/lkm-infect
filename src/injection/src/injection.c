#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("bah");
MODULE_DESCRIPTION("injection");
MODULE_VERSION("1.0");


int infection_init(void) {
    printk(KERN_ALERT "Init Inject!\n");

    return 0;
}
