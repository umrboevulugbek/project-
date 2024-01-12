class Person {
private:
    std::string name;
    int age;

public:
    // Конструктор класса
    Person(std::string n, int a) : name(n), age(a) {}

    // Метод для вывода информации о человеке
    void displayInfo() {
        std::cout << "Имя: " << name << ", Возраст: " << age << " лет." << std::endl;
    }

    // Геттеры для полей name и age
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

// Тест для проверки метода displayInfo()
TEST(PersonTest, DisplayInfoTest) {
    // Подготовка данных
    std::string expectedOutput = "Имя: Иван, Возраст: 25 лет.\n";
    Person person("Иван", 25);

    // Перенаправление стандартного вывода в строковый поток
    testing::internal::CaptureStdout();
    
    // Вызов тестируемого метода
    person.displayInfo();

    // Получение результата из строкового потока
    std::string actualOutput = testing::internal::GetCapturedStdout();
    
    // Проверка совпадения ожидаемого и фактического вывода
    ASSERT_EQ(expectedOutput, actualOutput);
}

// Тесты для геттеров
TEST(PersonTest, GetNameTest) {
    Person person("Иван", 25);
    ASSERT_EQ("Иван", person.getName());
}

TEST(PersonTest, GetAgeTest) {
    Person person("Иван", 25);
    ASSERT_EQ(25, person.getAge());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
