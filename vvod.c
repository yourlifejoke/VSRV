#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char name[50]; // Массив для хранения имени пользователя
    
    printf("Введите ваше имя: ");
    scanf("%s", name); // Считываем введенное имя
    
    int file_descriptor;
    file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    
    if (file_descriptor < 0) {
        perror("Ошибка при открытии файла");
        return 1;
    }
    
    if (dup2(file_descriptor, STDOUT_FILENO) < 0) {
        perror("Ошибка при дублировании дескриптора");
        return 1;
    }
    
    printf("Привет, %s! Этот текст будет записан в файл.\n", name);
    
    close(file_descriptor);
    
    return 0;
}
