public class DSA_3536 {
    public int maxProduct(int n) {
        int first = -1;
        int second = -1;
        int digit;
        while(n > 0){
            digit = n % 10;
            n /= 10;
            if (digit > first){
                second = first;
                first = digit;
            }
            else if( digit > second){
                second = digit;
            }
        }
        return first * second;
    }

}
