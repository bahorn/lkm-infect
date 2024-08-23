#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>

MODULE_LICENSE("GPL");

int OUR_MAIN(void);

extern int SYMBOL_NAME(void);

int OUR_MAIN(void) {
    printk(KERN_ALERT "Init Inject!\n");

    return SYMBOL_NAME();
}
