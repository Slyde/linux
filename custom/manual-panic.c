#include <linux/kernel.h>
#include <linux/init.h>

int __init manual_panic_init(void)
{
	printk(KERN_ERR "This panic is caused by the manual panic module !!!\n");
	BUG();
	return 0;
}

module_init(manual_panic_init);

