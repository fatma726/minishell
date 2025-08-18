#include <stdio.h>      // علشان printf
#include <stddef.h>     // فيه تعريف NULL
#include "exec.h"       // هنا تصريح الدالة ms_exec_abs اللي كتبناها في exec.c

int main(int argc, char **argv, char **envp)
{
    (void)argc; (void)argv;   // هنا بس بقول للـ compiler إن المتغيّرات دي موجودة 
                              // لكن مش هستخدمها → عشان ما يطلعليش تحذير "unused"

    // هنا بجهّز الوسائط للأمر ls -l
    char *const args[] = { 
        "ls",   // اسم البرنامج نفسه (لازم يبقى أول عنصر)
        "-l",   // الاختيار اللي هيخلي ls يعرض تفاصيل أكتر
        NULL    // نهاية المصفوفة (execve لازم تلاقي NULL عشان تعرف فين توقف)
    };

    // هنا بنادي الدالة اللي كتبناها قبل كده، وأقولها: 
    // "شغّلي /bin/ls ومعاه الوسائط args، وفي البيئة envp"
    int st = ms_exec_abs("/bin/ls", args, envp);

    // هنا بطبع كود الخروج اللي رجع من ms_exec_abs
    // 0 = نجاح، 126 = exec error، 127 = command not found، إلخ
    printf("status(ls) = %d\n", st);

    return 0;  // برنامج main نفسه خلص بنجاح
}
