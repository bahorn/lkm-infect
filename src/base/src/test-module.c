#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("bah");
MODULE_DESCRIPTION("test-module");
MODULE_VERSION("1.0");

static int init(void) {

    printk(KERN_ALERT "Init Original!\n");

    return 0;
}

static void clean(void) {

    printk(KERN_ALERT "Exit Original!\n");

    return;
}

module_init(init);
module_exit(clean);
