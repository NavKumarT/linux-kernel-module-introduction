#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/hash.h>
#include<linux/gcd.h>
#include<asm/param.h>
#include<linux/jiffies.h>

unsigned long jiffies_1;
unsigned long jiffies_2;

int simple_init(void)
{
	unsigned long answer;
	answer = gcd(3300, 24);
	jiffies_1 = jiffies;
	printk(KERN_INFO "Loading Kernel module...");
	printk(KERN_INFO "Golden Ratio Prime: %lu\n", GOLDEN_RATIO_PRIME);
	printk(KERN_INFO "GCD of 3300 and 24: %lu\n", answer);
	printk(KERN_INFO "Jiffies: %lu\n", jiffies);
	printk(KERN_INFO "HZ: %lu\n", HZ);
	return 0;
}

void simple_exit(void)
{
	jiffies_2 = jiffies;
	float time_in_ms = (jiffies_2 - jiffies_1)/HZ;
	printk(KERN_INFO "Time in ms for which the module was loaded: %f\n", time_in_ms);
	printK(KERN_INFO "Removing Kernel module...");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

