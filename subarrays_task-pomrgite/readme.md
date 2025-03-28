Это шаблонны проект для выполнения ДЗ

### Запуск Сборки и тестов через терминал

```bash
cmake -B build # Генерируем файлы сборки
cmake --build build # Собираем
cd build # Заходим в дерикторию сборки
ctest --output-on-failure # Запуск тестов
```

### **Задача 2: Поиск наибольшего повторяющегося подмассива (Binary Search + Hash Set)**

---

#### **Цель задания**
Реализовать алгоритм для поиска длины наибольшего подмассива, который встречается в массиве **минимум два раза**.  
**Используемые структуры данных:**
- `std::unordered_set` для эффективной проверки дубликатов.
- Бинарный поиск для оптимизации проверки длин.

---

#### **Описание задачи**
Дан массив целых чисел. Подмассив — это последовательность **смежных** элементов.  
**Требуется:**  
Найти максимальную длину `L`, такую что существует хотя бы один подмассив длины `L`, который встречается в массиве **как минимум дважды**.

---

#### **Входные данные**
- Массив `nums` типа `std::vector<int>`.
- Длина массива: `1 <= nums.size() <= 10^5`.

---

#### **Требования к реализации**
1. **Функция `longest_duplicate_subarray`:**
    - Принимает `const std::vector<int>& nums`.
    - Возвращает `int` — максимальную длину повторяющегося подмассива.
    - Если повторяющихся подмассивов нет, возвращает `0`.

2. **Алгоритм:**
    - Использовать **бинарный поиск** по возможным длинам подмассивов (`low = 1`, `high = nums.size() - 1`).
    - Для каждой длины `L` проверять наличие дубликатов через `std::unordered_set<std::string>` (хэширование подмассивов).

3. **Оптимизация:**
    - Преобразовывать подмассив в строку для хранения в сете (например, `"2,3,4"`).
    - Сложность: **O(n log n)**.

---

#### **Примеры**

**Пример 1**
```cpp
std::vector<int> nums = {1, 2, 3, 4, 2, 3, 4, 5};
int result = longest_duplicate_subarray(nums); 
// Результат: 3 (подмассив {2, 3, 4})
```

**Пример 2**
```cpp
std::vector<int> nums = {1, 2, 1, 2, 1, 2};
int result = longest_duplicate_subarray(nums);
// Результат: 4 (например, {1, 2, 1, 2})
```

**Пример 3 (Нет дубликатов)**
```cpp
std::vector<int> nums = {1, 2, 3};
int result = longest_duplicate_subarray(nums); // Результат: 0
```

---

#### **Примечания**
1. **Подмассив vs Подпоследовательность:**  
   Подмассив обязан быть непрерывным (как срез массива). Подпоследовательность может быть разрывной — это **не наш случай**.

2. **Советы по реализации:**
    - Используйте бинарный поиск для уменьшения количества проверок.
    - Для длины `L` перебирайте все подмассивы этой длины и сохраняйте их строковое представление в сете.
    - Если для текущей длины `L` найден дубликат, пробуйте увеличить длину (`low = L + 1`).

---

#### **Тестирование**
**Краевые случаи:**
1. Все элементы одинаковые:
   ```cpp
   nums = {5, 5, 5, 5} → результат: 3
   ```

2. Дубликаты перекрываются:
   ```cpp
   nums = {1, 2, 1, 2, 3} → результат: 2 (подмассивы {1, 2})
   ```

3. Максимальная длина в конце массива:
   ```cpp
   nums = {1, 2, 3, 1, 2, 3} → результат: 3
   ```
