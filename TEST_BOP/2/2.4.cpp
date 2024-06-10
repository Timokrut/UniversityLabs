// Напишите пример объявления класса (только поля), для которого не требуется конструктор копий.

class Showcase
{
    private:
        int a;
        int b;
    public:
        Showcase(int val1, int val2):a(val1), b(val2) {};
};
