import java.util.Scanner;

public class SortSortSort {

    public static void troca(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public static int comparar(int num1, int num2, int mod) {
        int mod1 = num1 % mod;
        int mod2 = num2 % mod;

        if (mod1 < 0) mod1 += mod;
        if (mod2 < 0) mod2 += mod;

        if (mod1 != mod2) {
            return mod1 - mod2;
        }

        int isOdd1 = Math.abs(num1) % 2;
        int isOdd2 = Math.abs(num2) % 2;

        if (isOdd1 != isOdd2) {
            return isOdd1 - isOdd2;
        }

        if (isOdd1 == 1) {
            return num2 - num1;
        }

        return num1 - num2;
    }

    public static int partir(int[] arr, int baixo, int ultimo, int mod) {
        int pivot = arr[ultimo];
        int i = (baixo - 1);

        for (int j = baixo; j <= ultimo - 1; j++) {
            if (comparar(arr[j], pivot, mod) <= 0) {
                i++;
                troca(arr, i, j);
            }
        }
        troca(arr, i + 1, ultimo);
        return (i + 1);
    }

    public static void quickSort(int[] arr, int baixo, int ultimo, int mod) {
        if (baixo < ultimo) {
            int pi = partir(arr, baixo, ultimo, mod);
            quickSort(arr, baixo, pi - 1, mod);
            quickSort(arr, pi + 1, ultimo, mod);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();

            if (N == 0 && M == 0) {
                System.out.println(N + " " + M);
                break;
            }

            int[] numeros = new int[N];
            for (int i = 0; i < N; i++) {
                numeros[i] = scanner.nextInt();
            }

            quickSort(numeros, 0, N - 1, M);

            System.out.println(N + " " + M);
            for (int i = 0; i < N; i++) {
                System.out.println(numeros[i]);
            }
        }

        scanner.close();
    }
} 