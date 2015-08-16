import java.util.Scanner;

class CaptainHammer {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			double angle = test(scanner);
			System.out.format("Case #%d: %f\n", i, angle); 
		}
	}
	static double test(Scanner scanner) {
		int V = scanner.nextInt(), D = scanner.nextInt();
		double tmp = 9.8 * D / V / V;
		if (tmp > 1) tmp = 1;
		double angle = Math.asin(tmp) * 90 / Math.PI;
		return angle;
	}
}
