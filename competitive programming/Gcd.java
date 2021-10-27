public class Gcd {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(gcd(27,15));
	}
	
	static int gcd(int a,int b) {
		
		if(b==0)
			return a;
		
		return gcd(b,a%b);
		
		//OR ,doing it in one line
		// return a%b==0 ? b : gcd(b,a%b);
	}
}
