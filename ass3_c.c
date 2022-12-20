#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cred.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


//OS Assignment 3.c) 

MODULE_LICENSE(“GPL”);

long long int temp=0;
static int num_val = 0;
module_param(num_val, int, 0644);
static int __init initLKM(void) {
struct task_struct *tsk_main = pid_task(find_vpid(num_val), PIDTYPE_PID);



printk(KERN_INFO "Process name- %s\n", tsk_main->comm);


printk(KERN_INFO "Process command path- %s\n",tsk_main->comm);


printk(KERN_INFO "Process user ID(uid)- %d\n",tsk_main->cred->uid);
printk(KERN_INFO "Process ID- %d\n", tsk_main->pid);

return temp;
}
static void __exit exitLKM(void) {
}
module_init(initLKM);
module_exit(exitLKM);