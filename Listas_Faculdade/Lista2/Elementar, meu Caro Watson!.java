import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            int N = sc.nextInt(); 
            int[] seq = new int[N];
            
            for (int i = 0; i < N; i++) {
                seq[i] = sc.nextInt();
            }
            
            int trocas = contarTrocasMinimas(seq);
            System.out.println(trocas);
        }
        
        sc.close();
    }
    
    private static int contarTrocasMinimas(int[] arr) {
        int trocas = 0;
        boolean[] visitado = new boolean[arr.length];
        
        for (int i = 0; i < arr.length; i++) {
            if (visitado[i] || arr[i] == i + 1) {
                continue;
            }

            int cicloTamanho = 0;
            int j = i;
            while (!visitado[j]) {
                visitado[j] = true;
                j = arr[j] - 1;
                cicloTamanho++;
            }
            
            trocas += (cicloTamanho - 1);
        }
        
        return trocas;
    }
}
