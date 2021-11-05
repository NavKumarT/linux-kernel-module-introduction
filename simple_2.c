#include<linux/init.h>
#include<kernel.h>
#include<linux/module.h>
#include<linux/proc_fs.h>
#include<asm/access.h>

#define BUFFER_SIZE 128
#define PROC_NAME "jiffies"

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static struct file_operations proc_ops = {
	.owner = THIS_MODULE,
	.read = proc_read,
}

int proc_init(void)
{
	proc_create(PROC_NAME, 0666, NULL, &proc_ops);
	return 0;
}

void proc_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
}

ssize t proc read(struct file *file, char user *usr buf, size t count, loff t *pos)
{
	int rv = 0;
	char buffer[BUFFER SIZE];
	static int completed = 0;
	if (completed) {
	completed = 0;
	return 0;
	}
	completed = 1;
	rv = sprintf(buffer, jiffies);

	copy_to_user(usr buf, buffer, rv);
	return rv;
}
module init(proc init);
module exit(proc exit);
MODULE LICENSE("GPL");
MODULE DESCRIPTION("Jiffies Module");
MODULE AUTHOR("SGG");