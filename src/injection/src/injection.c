#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>

MODULE_LICENSE("GPL");

extern int SYMBOL_NAME(void);

int infection_init(void) {
    printk(KERN_ALERT "Init Inject!\n");

    return SYMBOL_NAME();
}
