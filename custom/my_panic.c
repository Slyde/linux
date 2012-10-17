#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/notifier.h>

static int my_panic_event(struct notifier_block *this,
                          unsigned long event,
                          void *ptr);

static struct notifier_block my_panic_block = {
	notifier_call:	my_panic_event,
	next:		NULL,
	priority:	INT_MAX
};


int __init register_my_panic(void)
{
	printk("Registering custom panic handler\n");

	atomic_notifier_chain_register(&panic_notifier_list,
                                &my_panic_block);

	return 0;
}

static int my_panic_event(struct notifier_block *this,
                          unsigned long event,
                          void *ptr)
{
	printk("!!!! Custom panic handler !!!!\n");

	return NOTIFY_DONE;
}

module_init(register_my_panic);

