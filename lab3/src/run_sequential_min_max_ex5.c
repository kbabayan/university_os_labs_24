#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Создаем дочерний процесс

    if (pid == 0) {
        // Код дочернего процесса
        char *args[] = {"./sequential_min_max", "12", "10", NULL};
        execv(args[0], args);
        
        // Если execv выполняется успешно, этот код не выполнится
        perror("execv failed");
        exit(1);
    } else if (pid > 0) {
        // Код родительского процесса
        int status;
        waitpid(pid, &status, 0);  // Ожидание завершения дочернего процесса
        printf("Дочерний процесс завершен\n");
    } else {
        // Ошибка при создании дочернего процесса
        perror("fork failed");
        return 1;
    }

    return 0;
}