
# Проверяем, есть ли аргументы
if [ "$#" -eq 0 ]; then
    echo "Нет входных аргументов."
    exit 1
fi

# Вычисляем количество и сумму аргументов
count=$#
sum=0

for num in "$@"; do
    sum=$(echo "$sum + $num" | bc)
done

# Вычисляем среднее арифметическое
average=$(echo "$sum / $count" | bc -l)

# Выводим результаты
echo "Количество аргументов: $count"
echo "Среднее арифметическое: $average"
