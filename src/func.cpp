#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

std::vector<float> inputFloatVectorWithValidation() {
    std::vector<float> numbers;
    std::string input;
    
    while (true) {
        std::cout << "Введите числа через пробелы: ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Ввод не может быть пустым. Попробуйте снова." << std::endl;
            continue;
        }
        
        std::stringstream ss(input);
        float num;
        bool valid = true;
        
        numbers.clear();
        while (ss >> num) {
            numbers.push_back(num);
        }
        
        // Проверяем, что весь ввод был корректным
        if (ss.eof() && !numbers.empty()) {
            break;
        } else {
            std::cout << "Обнаружены некорректные данные. Введите только числа." << std::endl;
            // Очищаем флаг ошибки
            ss.clear();
        }
    }
    
    return numbers;
}


std::vector<float> bucketSort(std::vector<float> arr) {
    int n = arr.size();
    if (n <= 1) return arr;
    
    // 1. Создаем n пустых блоков (ведер)
    std::vector<std::vector<float>> buckets(n);
    
    // 2. Находим минимальное и максимальное значение
    float minVal = *std::min_element(arr.begin(), arr.end());
    float maxVal = *std::max_element(arr.begin(), arr.end());
    
    // Если все элементы одинаковые, массив уже отсортирован
    if (minVal == maxVal) return arr;
    
    // 3. Распределяем элементы по блокам
    for (int i = 0; i < n; i++) {
        // Вычисляем индекс блока для текущего элемента
        int bucketIndex = (int)((arr[i] - minVal) * (n - 1) / (maxVal - minVal));
        buckets[bucketIndex].push_back(arr[i]);
    }
    
    // 4. Сортируем каждый блок (можно использовать любую сортировку)
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    
    // 5. Объединяем все блоки обратно в исходный массив
    int index = 0;
    std::vector<float> rez(n);
    for (int i = 0; i < n; i++) {
        for (double num : buckets[i]) {
            rez[index++] = num;
        }
    }
    return rez;
}

float Median(std::vector<float> arr){
    int n = arr.size();
    if (n <= 1) return arr[0];
    if (n%2 != 0) return arr[n/2];
    return (arr[n/2-1] + arr[n/2])/2;
}