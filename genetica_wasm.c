#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPTIONS 5
#define MAX_QUESTIONS 286

typedef struct {
    char question_text[512];
    char options[MAX_OPTIONS][512];
    char correct_answers[10];
    int num_options;
    int original_index;
} Question;

Question quiz[MAX_QUESTIONS];
int total_questions = 286;

// Инициализация вопросов (упрощённый вариант - добавьте все 286 вопросов)
void init_questions() {
    // Вопрос 1
    strcpy(quiz[0].question_text, "Методами генетических исследований являются:");
    strcpy(quiz[0].options[0], "1) гибридологический");
    strcpy(quiz[0].options[1], "2) цитогенетический");
    strcpy(quiz[0].options[2], "3) гистологический");
    strcpy(quiz[0].options[3], "4) генеалогический");
    strcpy(quiz[0].options[4], "5) близнецовый");
    strcpy(quiz[0].correct_answers, "1245");
    quiz[0].num_options = 5;
    quiz[0].original_index = 1;

    // Вопрос 2
    strcpy(quiz[1].question_text, "Наследование признаков живого может быть:");
    strcpy(quiz[1].options[0], "1) моногенным");
    strcpy(quiz[1].options[1], "2) полигенным");
    strcpy(quiz[1].options[2], "3) многократным");
    strcpy(quiz[1].options[3], "4) сцепленным с полом");
    strcpy(quiz[1].options[4], "5) плейотропным");
    strcpy(quiz[1].correct_answers, "1245");
    quiz[1].num_options = 5;
    quiz[1].original_index = 2;

    // Вопрос 3
    strcpy(quiz[2].question_text, "Аллельными называются гены, которые:");
    strcpy(quiz[2].options[0], "1) расположены в одной хромосоме");
    strcpy(quiz[2].options[1], "2) контролируют один признак");
    strcpy(quiz[2].options[2], "3) взаимодействуют при формировании фенотипа организма");
    strcpy(quiz[2].options[3], "4) расположены в одинаковых локусах гомологических хромосом");
    strcpy(quiz[2].options[4], "5) находятся в разных хромосомах");
    strcpy(quiz[2].correct_answers, "4");
    quiz[2].num_options = 5;
    quiz[2].original_index = 3;

    // ... Добавьте остальные 283 вопроса аналогично ...
    // Это очень большой объём данных - рекомендую использовать скрипт для генерации
    
    // Вопрос 286 (последний)
    strcpy(quiz[285].question_text, "Главная задача медико-генетического консультирования:");
    strcpy(quiz[285].options[0], "1) расчет риска рождения больного ребенка");
    strcpy(quiz[285].options[1], "2) лечение мутаций");
    strcpy(quiz[285].options[2], "3) пропаганда знаний");
    strcpy(quiz[285].options[3], "4) пренатальная диагностика");
    strcpy(quiz[285].options[4], "5) изменение генофонда");
    strcpy(quiz[285].correct_answers, "14");
    quiz[285].num_options = 5;
    quiz[285].original_index = 286;
}

// Экспортируемые функции для JavaScript
int get_total_questions() {
    return total_questions;
}

const char* get_question(int index) {
    if (index >= 0 && index < total_questions) {
        return quiz[index].question_text;
    }
    return "";
}

const char* get_option(int question_index, int option_index) {
    if (question_index >= 0 && question_index < total_questions &&
        option_index >= 0 && option_index < quiz[question_index].num_options) {
        return quiz[question_index].options[option_index];
    }
    return "";
}

const char* get_correct_answer(int index) {
    if (index >= 0 && index < total_questions) {
        return quiz[index].correct_answers;
    }
    return "";
}

int get_original_index(int index) {
    if (index >= 0 && index < total_questions) {
        return quiz[index].original_index;
    }
    return -1;
}

int get_num_options(int index) {
    if (index >= 0 && index < total_questions) {
        return quiz[index].num_options;
    }
    return 0;
}

int check_answer(int question_index, const char* user_answer) {
    if (question_index >= 0 && question_index < total_questions) {
        return strcmp(user_answer, quiz[question_index].correct_answers) == 0 ? 1 : 0;
    }
    return 0;
}

// Инициализация при запуске
__attribute__((constructor))
void setup() {
    init_questions();
}