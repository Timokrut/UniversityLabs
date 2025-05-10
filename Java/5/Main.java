public class Main {
    public static void main(String[] args) {
        int size = 1000;
        int nonZeroElements = 1000;

        UsualMatrix usual1 = new UsualMatrix(size, size);
        UsualMatrix usual2 = new UsualMatrix(size, size);

        System.out.println("Randomize matrix");
        
        usual1.fillRandom(nonZeroElements);
        usual2.fillRandom(nonZeroElements);

        SparseMatrix sparse1 = new SparseMatrix(size, size);
        SparseMatrix sparse2 = new SparseMatrix(size, size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sparse1.setElement(i, j, usual1.getElement(i, j));
                sparse2.setElement(i, j, usual2.getElement(i, j));
            }
        }

        System.out.println("Testing addition...");
        IMatrix usualAdd = usual1.add(usual2);
        IMatrix sparseAdd = sparse1.add(sparse2);

        System.out.println("Addition results equal: " + usualAdd.equals(sparseAdd));
        
        System.out.println("Testing multiplication...");

        IMatrix usualMult = usual1.multiply(usual2);
        IMatrix sparseMult = sparse1.multiply(sparse2);

        System.out.println("Multiplication results equal: " + usualMult.equals(sparseMult));
    }

}
// Создать интерфейс IStack для реализаци стека (push, pop, length, equals, toString) и сделать три его реализации: на основе LinkedList, на основе ArrayList, и на основе массива фиксированной длинны (При окончании места в массиве бросается RuntimeException). Реализовать в классе Main функцию reverse, которая принимает в качестве параметра IStack и int value и меняет порядок цифр в числе value на обратный с помощью стека (12345 -> 54321). Проверить функцию reverse на разных реализациях IStack.
