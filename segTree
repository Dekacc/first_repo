import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void constructTree(int[] input, int[] segTree, int low, int high, int pos){
        if(low == high){ //terminalen slucaj na rekurzijata
            segTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        constructTree(input, segTree, low, mid, 2*pos+1); //levo poddrvo
        constructTree(input, segTree, mid+1, high, 2*pos+2); //desno poddrvo

        segTree[pos] = Math.min(segTree[2*pos+1], segTree[2*pos+2]); // ova ovde se menuva vo zavisnost na problemot (zaedno so terminalniot slucaj)
    }

    private static int rangeQuery(int[] segTree, int qlow, int qhigh, int low, int high, int pos){
        if(qlow <= low && qhigh >= high) return segTree[pos]; // total overlap
        if(qlow > high || qhigh < low) return Integer.MAX_VALUE; // no overlap (da se smeni ova)

        //else: partial overlap
        int mid = (low + high) / 2;
        return Math.min(rangeQuery(segTree, qlow, qhigh, low, mid, 2*pos+1), rangeQuery(segTree, qlow, qhigh, mid+1, high, 2*pos+2));
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        //INPUT NA NIZA
        int N = sc.nextInt();
        int[] input = new int[N];
        for(int i = 0; i<N; i++){
            input[i] = sc.nextInt();
        }

        //KREIRANJE NA SEG-TREE
        int pow2 = 1;
        while(pow2 < N) pow2 *= 2; //naogjanje na stepen na 2 pogolem ili ednakov na N
        int[] segTree = new int[pow2 * 2 - 1];
        Arrays.fill(segTree, Integer.MAX_VALUE);
        constructTree(input, segTree, 0, N - 1, 0);

        for(int i : segTree) System.out.print(i + " ");

        System.out.println(rangeQuery(segTree, 2, 4, 0, N-1, 0));
    }
}
